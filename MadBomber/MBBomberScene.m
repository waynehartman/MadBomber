//
//  MBMyScene.m
//  MadBomber
//
//  Created by Wayne Hartman on 2/18/14.
//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import "MBBomberScene.h"
@import AVFoundation;
@import GameController;

#import "MBToken.h"

#if TARGET_OS_TV

#elif TARGET_OS_IPHONE
@import CoreMotion;
#else
#import "MBMouseMotionManager.h"
#endif

@interface MBBomberScene() {
    double _nextBombToSpawn;
    double _nextDropToSpawn;
    int _nextBomb;
    BOOL _gameOver;
}

@property (nonatomic, strong) SKLabelNode *scoreNode;
@property (nonatomic, strong) NSMutableArray *bombs;
@property (nonatomic, strong) SKSpriteNode *bomber;
@property (nonatomic, strong) SKSpriteNode *player;
@property (nonatomic, assign) NSInteger points;
@property (nonatomic, strong) SKLabelNode *restartLabel;
@property (nonatomic, strong) AVAudioPlayer *backgroundAudioPlayer;
@property (nonatomic, strong) GCController *gameController;
@property (nonatomic, assign) CGFloat currentLevel;
@property (nonatomic, strong) SKShapeNode *waterLevelMeter;
@property (nonatomic, strong) SKLabelNode *meterLabel;
@property (nonatomic, strong) MBToken *waterDropNode;

@property (nonatomic, assign) CGFloat lastPosition;
@property (nonatomic, assign) CGFloat maxMeterSize;
@property (nonatomic, strong) NSArray<SKColor *> *meterColors;
@property (nonatomic, assign) NSInteger stageLevel;
@property (nonatomic, strong) NSArray<NSString *> *noSFX;
@property (nonatomic, strong) NSArray<NSString *> *yesSFX;



#if TARGET_OS_TV

#elif TARGET_OS_IPHONE
@property (nonatomic, strong) CMMotionManager *motionManager;
#else
@property (nonatomic, strong) MBMouseMotionManager *motionManager;
#endif

@end

#define USER_DEFAULTS_HIGH_SCORE    @"USER_DEFAULTS_HIGH_SCORE"
#define NAME_RESTART_LABEL          @"NAME_RESTART_LABEL"
#define NAME_PAUSE_LABEL            @"NAME_PAUSE_LABEL"

static NSTimeInterval kWaterDropInterval = 20.0;

#if TARGET_OS_TV

static CGFloat meterWidth = 100.0f;
static CGFloat meterLabelTextSize = 50.0f;
static CGFloat meterX = 100.0f;

#elif TARGET_OS_IPHONE

static CGFloat meterWidth = 50.0f;
static CGFloat meterLabelTextSize = 20.0f;
static CGFloat meterX = 20.0f;

#else

static CGFloat meterWidth = 100.0f;
static CGFloat meterLabelTextSize = 20.0f;
static CGFloat meterX = 20.0f;

#endif


@implementation MBBomberScene

-(id)initWithSize:(CGSize)size {    
    if (self = [super initWithSize:size]) {
        /* Setup your scene here */
        self.waterDropNode = [MBToken spriteNodeWithImageNamed:@"drop"];
        self.waterDropNode.value = 100;

        self.backgroundColor = [SKColor colorWithRed:0.15 green:0.15 blue:0.3 alpha:1.0];
        self.physicsBody = [SKPhysicsBody bodyWithEdgeLoopFromRect:self.frame];
        self.maxMeterSize = self.size.height * 0.75;
        self.meterColors = @[
                                [SKColor blueColor],
                                [SKColor greenColor],
                                [SKColor yellowColor],
                                [SKColor orangeColor],
                                [SKColor redColor],
                                [SKColor colorWithRed:0.5f green:0.0f blue:0.0f alpha:1.0f],
                             ];

        if ([GCController controllers].count > 0) {
            self.gameController = [[GCController controllers] firstObject];
            [self setupController];
        }
        
        self.noSFX = @[
                        @"no1",
                        @"no2",
                        @"no3",
                        @"no4",
                        @"no5",
                        @"no6",
                        @"no7",
                       ];
        
        self.yesSFX = @[
                        @"yes1",
                        @"yes2",
                        @"yes3",
                        @"yes4",
                        @"yes5",
                        @"yes6",
                        ];

        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(controllerDidConnect:)
                                                     name:GCControllerDidConnectNotification
                                                   object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(controllerDidDisconnect:)
                                                     name:GCControllerDidDisconnectNotification
                                                   object:nil];

        [self addChild:self.scoreNode];
        [self addChild:self.bomber];
        [self addChild:self.waterLevelMeter];
        [self addChild:self.waterDropNode];
        
        self.waterDropNode.hidden = YES;
        
        [self.waterLevelMeter addChild:self.meterLabel];
        self.meterLabel.position = CGPointMake(self.waterLevelMeter.frame.size.width * 0.5f, self.waterLevelMeter.frame.size.height);
        self.waterLevelMeter.fillColor = [[SKColor blueColor] colorWithAlphaComponent:0.75f];
        [self addChild:self.player];

        [self refreshHighScore];
#if TARGET_OS_TV
        CGFloat topMargin = 40.0f;
#else
        CGFloat topMargin = 0.0f;
#endif
        
        
        self.scoreNode.position = CGPointMake(CGRectGetMidX(self.frame), self.frame.size.height - self.scoreNode.frame.size.height - topMargin);

        for (SKNode *bomb in self.bombs) {
            bomb.hidden = YES;
            [self addChild:bomb];
        }

        self.player.zPosition = 100;

        [self startTheGame];
        
        [self startBackgroundMusic];
    }

    return self;
}

#pragma mark - Super Overrides

- (void)setPaused:(BOOL)paused {
    [super setPaused:paused];

    if (self.paused) {
        [self.backgroundAudioPlayer stop];
        SKLabelNode *pausedNode = [SKLabelNode labelNodeWithFontNamed:@"Avenir"];
        pausedNode.name = NAME_PAUSE_LABEL;
        pausedNode.fontSize = 50.0f;
        pausedNode.text = @"Paused";
        pausedNode.position = CGPointMake(self.frame.size.width * 0.5, self.frame.size.height * 0.5);

        [self addChild:pausedNode];
    } else {
        [self.backgroundAudioPlayer play];
        SKNode *node = [self childNodeWithName:NAME_PAUSE_LABEL];
        [node removeFromParent];
    }
}

#pragma mark - Lazy Loaders

- (void)setStartingWaterLevel:(CGFloat)startingWaterLevel {
    _startingWaterLevel = startingWaterLevel;
    _currentLevel = startingWaterLevel;
}

- (NSMutableArray *)bombs {
    if (!_bombs) {
        NSDictionary *tokenData = @{
                                    @(-30): @"sink",
                                    @(-50): @"washer",
                                    @(-100): @"sprinkler",
                                    };
        
        NSInteger bombCount = tokenData.allKeys.count * 7;

        NSMutableArray *bombs = [[NSMutableArray alloc] initWithCapacity:bombCount];

        NSArray *allKeys = tokenData.allKeys;

        for (int i = 0; i < bombCount; i++) {
            NSUInteger index = (NSUInteger)arc4random_uniform((u_int32_t)allKeys.count);
            id key = allKeys[index];

            NSString *imageName = tokenData[key];

            MBToken *bomb = [[MBToken alloc] initWithImageNamed:imageName];
            bomb.value = [key integerValue];

            [bombs addObject:bomb];
        }

        _bombs = bombs;
    }

    return _bombs;
}

- (SKSpriteNode *)bomber {
    if (!_bomber) {
        _bomber = [[SKSpriteNode alloc] initWithImageNamed:@"bomber"];
    }

    return _bomber;
}

- (SKLabelNode *)scoreNode {
    if (!_scoreNode) {
        SKLabelNode *scoreNode = [SKLabelNode labelNodeWithFontNamed:@"Avenir"];
#if TARGET_OS_TV
        scoreNode.fontSize = 50;
#else
        scoreNode.fontSize = 20;
#endif
        _scoreNode = scoreNode;
    }
    
    return _scoreNode;
}

- (SKLabelNode *)meterLabel {
    if (!_meterLabel) {
        _meterLabel = [SKLabelNode labelNodeWithFontNamed:@"Avenir"];
        _meterLabel.fontSize = meterLabelTextSize;
        _meterLabel.fontColor = [SKColor whiteColor];
    }

    return _meterLabel;
}

- (SKSpriteNode *)player {
    if (!_player) {
        _player = [[SKSpriteNode alloc] initWithImageNamed:@"player"];
    }
    
    return _player;
}

- (SKShapeNode *)waterLevelMeter {
    if (!_waterLevelMeter) {
        _waterLevelMeter = [SKShapeNode shapeNodeWithRect:CGRectMake(meterX, 0.0f, meterWidth, self.maxMeterSize)];
    }
    
    return _waterLevelMeter;
}

#if TARGET_OS_TV
#elif TARGET_OS_IPHONE
- (CMMotionManager *)motionManager {
    if (!_motionManager) {
        _motionManager = [[CMMotionManager alloc] init];
    }

    return _motionManager;
}
#else
- (MBMouseMotionManager *)motionManager {
    if (!_motionManager) {
        _motionManager = [[MBMouseMotionManager alloc] init];
    }

    return _motionManager;
}
#endif

- (SKLabelNode *)restartLabel {
    if (!_restartLabel) {
        _restartLabel = [[SKLabelNode alloc] initWithFontNamed:@"Avenir"];
#if TARGET_OS_TV
        _restartLabel.fontSize = 70.0f;
#else
        _restartLabel.fontSize = 40.0f;
#endif
    }

    return _restartLabel;
}

- (NSString *)randomSoundFileNameFromArray:(NSArray *)array {
    NSInteger index = arc4random_uniform((u_int32_t)array.count);
    return array[index];
}

#pragma mark - Touches / Mouse

#if TARGET_OS_TV
    // DO NOTHING
#elif TARGET_OS_IPHONE

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    /* Called when a touch begins */
    
    for (UITouch *touch in touches) {
        SKNode *n = [self nodeAtPoint:[touch locationInNode:self]];
        if (n == self.restartLabel) {
            [self.restartLabel removeFromParent];
            [self startTheGame];
            return;
        }
    }
}

#else 

- (void)mouseUp:(NSEvent *)theEvent {
    CGPoint point = [theEvent locationInNode:self];
    
    SKNode *n = [self nodeAtPoint:point];
    if (n == self.restartLabel) {
        [self.restartLabel removeFromParent];
        [self startTheGame];
    }
}

#endif

#pragma mark - Update

-(void)update:(CFTimeInterval)currentTime {
    /* Called before each frame is rendered */
    
    double curTime = CACurrentMediaTime();
    if (curTime > _nextBombToSpawn && !_gameOver && !self.paused) {
        float randSecs = [self randomValueBetween:0.20 andValue:1.0];
        _nextBombToSpawn = randSecs + curTime;

        float randDuration = [self randomValueBetween:5.0 andValue:7.0];

        SKSpriteNode *bomb = [_bombs objectAtIndex:_nextBomb];
        _nextBomb++;
        
        if (_nextBomb >= _bombs.count) {
            _nextBomb = 0;
        }

        [bomb removeAllActions];
        bomb.position = CGPointMake(self.bomber.position.x, self.bomber.position.y - 10.0f);
        bomb.hidden = NO;

        CGPoint location = CGPointMake(self.bomber.position.x, 0.0f);

        SKAction *moveAction = [SKAction moveTo:location duration:randDuration];
        SKAction *doneAction = [SKAction runBlock:^{
            bomb.hidden = YES;
        }];
        
        SKAction *moveBombSequence = [SKAction sequence:@[moveAction, doneAction]];
        [bomb runAction:moveBombSequence withKey:@"bombMoving"];
        [bomb runAction:[SKAction playSoundFileNamed:@"bombDrop.caf" waitForCompletion:NO]];
    }
    
    if (curTime > _nextDropToSpawn && !_gameOver && !self.paused) {
        [_waterDropNode removeAllActions];
        _waterDropNode.position = CGPointMake(self.bomber.position.x, self.bomber.position.y - 10.0f);
        _waterDropNode.hidden = NO;
        
        CGPoint location = CGPointMake(self.bomber.position.x, 0.0f);
        float randDuration = [self randomValueBetween:5.0 andValue:7.0];
        
        SKAction *moveAction = [SKAction moveTo:location duration:randDuration];
        SKAction *doneAction = [SKAction runBlock:^{
            self.waterDropNode.hidden = YES;
        }];
        
        SKAction *moveBombSequence = [SKAction sequence:@[moveAction, doneAction]];
        [_waterDropNode runAction:moveBombSequence withKey:@"bombMoving"];
        [_waterDropNode runAction:[SKAction playSoundFileNamed:@"bombDrop.caf" waitForCompletion:NO]];
        _nextDropToSpawn = curTime + kWaterDropInterval;
    }

    if (!_gameOver) {
        

        if (_gameController) {
            [self updatePlayerFromGameController];
        } else {
            [self updatePlayerPositionFromMotionManager];
        }

        self.lastPosition = self.player.position.x;
        
        for (MBToken *bomb in self.bombs) {
            if (bomb.hidden) {
                continue;
            }

            if ([bomb intersectsNode:self.player]) {    //  check player collision
                [bomb removeAllActions];
                bomb.hidden = YES;

                [self incrementScoreByPoints:labs(bomb.value)];
                [self.player runAction:[SKAction playSoundFileNamed:@"drop.caf" waitForCompletion:NO]];
            } else if (bomb.position.y < (bomb.frame.size.width * 0.5)) { //    check touched bottom
                if (!bomb.hidden) {
                    self.currentLevel += bomb.value;
                    bomb.hidden = YES;
                    
                    NSString *filename = [self randomSoundFileNameFromArray:self.noSFX];
                    
                    [bomb runAction:[SKAction playSoundFileNamed:filename waitForCompletion:NO]];
                }
                break;
            }
        }

        if (!_waterDropNode.hidden && [_waterDropNode intersectsNode:self.player]) { // caught it!
            self.currentLevel += _waterDropNode.value;
            _waterDropNode.hidden = YES;
            NSString *filename = [self randomSoundFileNameFromArray:self.yesSFX];
            [_waterDropNode runAction:[SKAction playSoundFileNamed:filename waitForCompletion:NO]];
        } else if (_waterDropNode.position.y < (_waterDropNode.frame.size.width * 0.5)) { // reached bottom
            _waterDropNode.hidden = YES;
        }

        CGFloat newMeterHeight = (self.currentLevel / self.startingWaterLevel) * self.maxMeterSize;
        
        if (newMeterHeight > self.maxMeterSize) {
            newMeterHeight = self.maxMeterSize;
        }

        self.waterLevelMeter.path = [UIBezierPath bezierPathWithRect:CGRectMake(meterX,
                                                                                0.0f,
                                                                                meterWidth, newMeterHeight)].CGPath;
        self.meterLabel.position = CGPointMake((self.waterLevelMeter.frame.size.width * 0.5f) + meterX,
                                               newMeterHeight + 10.0f);

        if (self.currentLevel <= 0.0f) {
            self.currentLevel = 0.0f;
            [self endTheGame];
        }
        
        // Updates the stage level
        CGFloat percentage = self.currentLevel / self.startingWaterLevel;
        CGFloat increments = 1.0f / (CGFloat)self.meterColors.count;
        NSInteger calculatedStageLevel = self.meterColors.count - (percentage / increments);
        
        if (calculatedStageLevel != self.stageLevel) {
            if (calculatedStageLevel > self.meterColors.count - 1) {
                calculatedStageLevel = self.meterColors.count - 1;
            }

            self.stageLevel = calculatedStageLevel;
            
            SKAction *action = [self getColorFadeActionFrom:self.waterLevelMeter.fillColor
                                                    toColor:self.meterColors[calculatedStageLevel]];
            [self.waterLevelMeter runAction:action];
        }

        self.meterLabel.text = [NSString stringWithFormat:@"%li ft.", (long)self.currentLevel];
    }
}



#pragma mark - Setup

- (void)startTheGame {
    [self killAllActions];

    _nextDropToSpawn = kWaterDropInterval;
    self.stageLevel = 0;
    self.waterLevelMeter.fillColor = self.meterColors[self.stageLevel];
    
    [self.bomber runAction:[SKAction playSoundFileNamed:@"saveTheAquifer.caf" waitForCompletion:NO]];

    self.bomber.position = CGPointMake(self.frame.size.width * 0.5f, self.frame.size.height - self.bomber.size.height);
    self.player.position = CGPointMake(self.frame.size.width * 0.5f, (self.player.size.height * 0.5f) + 5.0f);

    self.points = 0;
    self.player.hidden = NO;
    self.scoreNode.scale = 1.0f;

    if (self.startingWaterLevel == 0.0) {
        self.startingWaterLevel = 600.0f;
    }

    self.currentLevel = self.startingWaterLevel;

    [self incrementScoreByPoints:0];

    for (SKSpriteNode *bomb in self.bombs) {
        bomb.hidden = YES;
        bomb.alpha = 1.0f;
        bomb.scale = 1.0f;
    }

    self.player.physicsBody = [SKPhysicsBody bodyWithRectangleOfSize:self.player.frame.size];
    self.player.physicsBody.dynamic = YES;
    self.player.physicsBody.affectedByGravity = NO;
    self.player.physicsBody.mass = 0.01;
    self.player.physicsBody.allowsRotation = NO;

    if (!_gameController) {
        [self startMonitoringAcceleration];
    }

    _gameOver = NO;
    [self moveTheBomber];
}

- (void)endTheGame {
    [self killAllActions];
    [self runAction:[SKAction playSoundFileNamed:@"sadtrombone.caf" waitForCompletion:NO]];

    self.player.hidden = YES;
    
    NSArray *filteredBombs = [self.bombs filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"hidden == NO"]];
    NSArray *sortedBombs = [filteredBombs sortedArrayUsingComparator:^NSComparisonResult(SKSpriteNode *obj1, SKSpriteNode *obj2) {
        if (obj1.position.y > obj2.position.y) {
            return NSOrderedDescending;
        } else if (obj1.position.y < obj2.position.y) {
            return NSOrderedAscending;
        } else {
            return NSOrderedSame;
        }
    }];
    
    for (int i = 0; i < sortedBombs.count; i++) {
        SKSpriteNode *bomb = sortedBombs[i];
        
        SKAction *wait = [SKAction waitForDuration:0.15 * i];
        SKAction *scale = [SKAction scaleTo:1.5f duration:0.15];
        SKAction *fade = [SKAction fadeAlphaTo:0.0f duration:0.15];
        SKAction *fx = [SKAction playSoundFileNamed:@"smallExplosion.caf" waitForCompletion:NO];
        SKAction *transform = [SKAction group:@[scale, fade, fx]];

        SKAction *sequence = [SKAction sequence:@[wait, transform]];

        [bomb runAction:sequence];
    }

    [self addChild:self.restartLabel];
#if TARGET_OS_TV
    self.restartLabel.text = @"GAME OVER!\nPress Play/Pause to Start Again!";
#else
    self.restartLabel.text = @"GAME OVER...Restart?";
#endif
    self.restartLabel.position = CGPointMake(self.frame.size.width * 0.5f, self.frame.size.height * 0.5f);
    self.restartLabel.scale = 0.01;

    SKAction *labelScaleAction = [SKAction scaleTo:1.0 duration:0.5];
    [self.restartLabel runAction:labelScaleAction];

    _gameOver = YES;
    
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    
    if (self.points > [defaults integerForKey:USER_DEFAULTS_HIGH_SCORE]) {
        [defaults setInteger:self.points forKey:USER_DEFAULTS_HIGH_SCORE];
        [defaults synchronize];

        SKAction *scaleUp = [SKAction scaleTo:1.5f duration:0.15];
        SKAction *scaleDown = [SKAction scaleTo:1.0f duration:0.15];
        SKAction *scaleSequence = [SKAction sequence:@[scaleUp, scaleDown]];

        [self.scoreNode runAction:[SKAction repeatAction:scaleSequence count:5]];
    } else {
        double delayInSeconds = 2.0;
        dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delayInSeconds * NSEC_PER_SEC));
        dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
            if (_gameOver) {
                [self refreshHighScore];
            }
        });
    }

    [self stopMonitoringAcceleration];
    
    if (self.gameEndHandler) {
        NSInteger highScore = [[NSUserDefaults standardUserDefaults] integerForKey:USER_DEFAULTS_HIGH_SCORE];
        self.gameEndHandler(self.points, highScore);
    }
}

- (void)killAllActions {
    [self removeAllActions];
    
    for (SKSpriteNode *bomb in self.bombs) {
        [bomb removeAllActions];
    }

    [self.bomber removeAllActions];
    [self.scoreNode removeAllActions];
}

- (void)moveTheBomber {
    __weak typeof(self) weakSelf = self;
    __weak typeof(self.bomber) weakBomber = self.bomber;

    float duration = 0.25f;

    SKAction *moveAction = [SKAction runBlock:^{
#if TARGET_OS_TV
        static float maxDelta = 1100;
#else
        static float maxDelta = 200;
#endif
        float min = weakSelf.bomber.position.x - maxDelta;
        float max = weakSelf.bomber.position.x + maxDelta;

        if (min < weakSelf.bomber.size.width) {
            min = weakSelf.bomber.size.width;
        }

        if (max > (weakSelf.frame.size.width - weakSelf.bomber.size.width)) {
            max = weakSelf.frame.size.width - weakSelf.bomber.size.width;
        }

        float randomX = [weakSelf randomValueBetween:min
                                        andValue:max];

        SKAction *moveX = [SKAction moveToX:randomX duration:duration];

        [weakBomber runAction:moveX];
    }];

    SKAction *waitAction = [SKAction waitForDuration:0.15 withRange:0.4];
    SKAction *bufferWait = [SKAction waitForDuration:duration];
    SKAction *sequence = [SKAction sequence:@[moveAction, bufferWait, waitAction]];
    SKAction *repeat = [SKAction repeatActionForever:sequence];

    [self.bomber runAction:repeat];
}

#pragma mark - Acceleration

- (void)swipeWithDirection:(MBSwipeDirection)direction velocity:(CGPoint)velocity {
    if (!_gameOver) {
        [self applyPlayerForce:CGVectorMake(velocity.x * 0.01, 0.0f)];
    }
}

- (void)startMonitoringAcceleration {
#if TARGET_OS_TV
    //DO NOTHING
#elif TARGET_OS_IPHONE
    if (self.motionManager.accelerometerAvailable) {
        [self.motionManager startAccelerometerUpdates];
    }
#else
    [self.motionManager startMouseMotionUpdates];
#endif
}

- (void)stopMonitoringAcceleration {
#if TARGET_OS_TV
    // DO NOTHING
#elif TARGET_OS_IPHONE
    if (self.motionManager.accelerometerAvailable && self.motionManager.accelerometerActive) {
        [self.motionManager stopAccelerometerUpdates];
    }
#else
    [self.motionManager stopMouseMotionUpdates];
#endif
}

- (void)updatePlayerPositionFromMotionManager {
#if TARGET_OS_TV
    // DO NOTHING
#elif TARGET_OS_IPHONE
    CMAccelerometerData* data = self.motionManager.accelerometerData;
    if (fabs(data.acceleration.y) > 0.1) {
        [self applyPlayerForce:CGVectorMake(-20.0f * data.acceleration.y, 0.0f)];
    }
#else
    [self applyPlayerForce:CGVectorMake(self.motionManager.acceleration.x, 0.0f)];
#endif
}

- (void)updatePlayerFromGameController {
    float force = 0.0f;
    BOOL shouldApplyForce = NO;

    if (_gameController.extendedGamepad) {
        BOOL leftTriggerPressed = _gameController.extendedGamepad.leftTrigger.value > 0.0f;
        BOOL leftShoulderPressed = _gameController.extendedGamepad.leftShoulder.value > 0.0f;

        BOOL rightTriggerPressed = _gameController.extendedGamepad.rightTrigger.value > 0.0f;
        BOOL rightShoulderPressed = _gameController.extendedGamepad.rightShoulder.value > 0.0f;

        if (leftShoulderPressed || leftTriggerPressed) {
            force = -MAX(_gameController.extendedGamepad.leftShoulder.value, _gameController.extendedGamepad.leftTrigger.value);
            shouldApplyForce = YES;
        } else if (rightShoulderPressed || rightTriggerPressed) {
            force = MAX(_gameController.extendedGamepad.rightShoulder.value, _gameController.extendedGamepad.rightTrigger.value);
            shouldApplyForce = YES;
        }
    } else {
        BOOL leftPressed = _gameController.gamepad.leftShoulder.value > 0.0f;
        BOOL rightPressed = _gameController.gamepad.rightShoulder.value > 0.0f;

        if (leftPressed || rightPressed) {
            if (leftPressed && rightPressed) {
                force = -_gameController.gamepad.leftShoulder.value;
            } else if (leftPressed){
                force = -_gameController.gamepad.leftShoulder.value;
            } else if (rightPressed) {
                force = _gameController.gamepad.rightShoulder.value;
            }

            shouldApplyForce = YES;
        }
    }

    if (shouldApplyForce) {
        [self applyPlayerForce:CGVectorMake(20.0f * force, 0.0f)];
    }
}

- (void)applyPlayerForce:(CGVector)vector {
    [self.player.physicsBody applyForce:vector];

//    if (self.player.position.x > self.lastPosition && self.player.xScale > 0) {
//        NSLog(@"xscale = %f", self.player.xScale);
//        self.player.xScale = -1;
//    } else {
//        self.player.xScale = 1;
//    }
}

#pragma mark - Controller setup

- (void)togglePlayPause {
    if (_gameOver) {
        [self.restartLabel removeFromParent];
        [self startTheGame];
    } else {
        [self.scene setPaused:!self.scene.isPaused];
    }
}

- (void) setupController {
    __weak typeof(self) weakSelf = self;

    self.gameController.controllerPausedHandler = ^(GCController *controller) {
        weakSelf.paused = !weakSelf.paused;
    };
}

#pragma mark - Utility Methods

- (float)randomValueBetween:(float)low andValue:(float)high {
    return (((float) arc4random() / 0xFFFFFFFFu) * (high - low)) + low;
}

- (void)incrementScoreByPoints:(NSInteger)points {
    self.points += points;
    self.scoreNode.text = [NSString stringWithFormat:@"Score: %li", (long)self.points];
}

- (void)refreshHighScore {
    NSInteger highScore = [[NSUserDefaults standardUserDefaults] integerForKey:USER_DEFAULTS_HIGH_SCORE];
    NSString *text = [NSString stringWithFormat:@"Hi Score: %li", (long)highScore];
    self.scoreNode.text = text;
}

#pragma mark - Notifications

- (void)controllerDidConnect:(NSNotification *)notification {
    _gameController = notification.object;
    [self setupController];
    [self stopMonitoringAcceleration];
}

- (void)controllerDidDisconnect:(NSNotification *)notification {
    _gameController = nil;
    if (!_gameOver) {
        [self startMonitoringAcceleration];
    }
}

#pragma mark - Music

- (void)startBackgroundMusic {
    NSError *err;
    NSURL *file = [NSURL fileURLWithPath:[[NSBundle mainBundle] pathForResource:@"BlownAway.mp3" ofType:nil]];
    self.backgroundAudioPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:file error:&err];
    if (err) {
        NSLog(@"error in audio play %@",[err userInfo]);
        return;
    }
    [self.backgroundAudioPlayer prepareToPlay];

    self.backgroundAudioPlayer.numberOfLoops = -1;
    [self.backgroundAudioPlayer setVolume:0.15];
    [self.backgroundAudioPlayer play];
}

#pragma mark - Shape Animations

-(SKAction*)getColorFadeActionFrom:(SKColor*)col1 toColor:(SKColor*)col2 {
    
    // get the Color components of col1 and col2
    CGFloat r1 = 0.0, g1 = 0.0, b1 = 0.0, a1 =0.0;
    CGFloat r2 = 0.0, g2 = 0.0, b2 = 0.0, a2 =0.0;
    [col1 getRed:&r1 green:&g1 blue:&b1 alpha:&a1];
    [col2 getRed:&r2 green:&g2 blue:&b2 alpha:&a2];
    
    // return a color fading on the fill color
    CGFloat timeToRun = 0.3;
    
    return [SKAction customActionWithDuration:timeToRun actionBlock:^(SKNode *node, CGFloat elapsedTime) {
        
        CGFloat fraction = elapsedTime / timeToRun;
        
        SKColor *col3 = [SKColor colorWithRed:lerp(r1,r2,fraction)
                                        green:lerp(g1,g2,fraction)
                                         blue:lerp(b1,b2,fraction)
                                        alpha:lerp(a1,a2,fraction)];
        
        [(SKShapeNode*)node setFillColor:col3];
//        [(SKShapeNode*)node setStrokeColor:col3];
    }];
}

double lerp(double a, double b, double fraction) {
    return (b-a)*fraction + a;
}

#pragma mark - Memory

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
