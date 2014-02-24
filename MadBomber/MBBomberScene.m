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

#if TARGET_OS_IPHONE
@import CoreMotion;
#else
#import "MBMouseMotionManager.h"
#endif

@interface MBBomberScene() {
    double _nextBombToSpawn;
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

#if TARGET_OS_IPHONE
@property (nonatomic, strong) CMMotionManager *motionManager;
#else
@property (nonatomic, strong) MBMouseMotionManager *motionManager;
#endif

@end

#define USER_DEFAULTS_HIGH_SCORE    @"USER_DEFAULTS_HIGH_SCORE"
#define NUMBER_OF_BOMBS_IN_QUEUE    15
#define NAME_RESTART_LABEL          @"NAME_RESTART_LABEL"
#define NAME_PAUSE_LABEL            @"NAME_PAUSE_LABEL"

@implementation MBBomberScene

-(id)initWithSize:(CGSize)size {    
    if (self = [super initWithSize:size]) {
        /* Setup your scene here */
        self.backgroundColor = [SKColor colorWithRed:0.15 green:0.15 blue:0.3 alpha:1.0];
        self.physicsBody = [SKPhysicsBody bodyWithEdgeLoopFromRect:self.frame];

        if ([GCController controllers].count > 0) {
            self.gameController = [[GCController controllers] firstObject];
            [self setupController];
        }

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
        [self addChild:self.player];

        [self refreshHighScore];

        self.scoreNode.position = CGPointMake(CGRectGetMidX(self.frame), self.frame.size.height - self.scoreNode.frame.size.height);

        for (SKNode *bomb in self.bombs) {
            bomb.hidden = YES;
            [self addChild:bomb];
        }

        [self insertChild:self.player atIndex:self.children.count - 1];

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

- (NSMutableArray *)bombs {
    if (!_bombs) {
        NSMutableArray *bombs = [[NSMutableArray alloc] initWithCapacity:NUMBER_OF_BOMBS_IN_QUEUE];

        for (int i = 0; i < NUMBER_OF_BOMBS_IN_QUEUE; i++) {
            SKSpriteNode *bomb = [[SKSpriteNode alloc] initWithImageNamed:@"bomb"];
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
        scoreNode.fontSize = 20;
        _scoreNode = scoreNode;
    }
    
    return _scoreNode;
}

- (SKSpriteNode *)player {
    if (!_player) {
        _player = [[SKSpriteNode alloc] initWithImageNamed:@"player"];
    }
    
    return _player;
}

#if TARGET_OS_IPHONE
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
        _restartLabel.fontSize = 40.0f;
    }

    return _restartLabel;
}

#pragma mark - Touches / Mouse
#if TARGET_OS_IPHONE

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
    
    if (!_gameOver) {
        if (_gameController) {
            [self updatePlayerFromGameController];
        } else {
            [self updatePlayerPositionFromMotionManager];
        }

        for (SKSpriteNode *bomb in self.bombs) {
            if (bomb.hidden) {
                continue;
            }

            if ([bomb intersectsNode:self.player]) {    //  check player collision
                [bomb removeAllActions];
                bomb.hidden = YES;

                [self incrementScoreByPoints:50];
                [self.player runAction:[SKAction playSoundFileNamed:@"drop.caf" waitForCompletion:NO]];
            } else if (bomb.position.y < (bomb.frame.size.width * 0.5)) { //    check touched bottom
                [self endTheGame];
                break;
            }
        }
    }
}

#pragma mark - Setup

- (void)startTheGame {
    [self killAllActions];

    [self.bomber runAction:[SKAction playSoundFileNamed:@"evilLaugh.caf" waitForCompletion:NO]];

    self.bomber.position = CGPointMake(self.frame.size.width * 0.5f, self.frame.size.height - self.bomber.size.height);
    self.player.position = CGPointMake(self.frame.size.width * 0.5f, (self.player.size.height * 0.5f) + 5.0f);

    self.points = 0;
    self.player.hidden = NO;
    self.scoreNode.scale = 1.0f;

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
    [self runAction:[SKAction playSoundFileNamed:@"crazyLaugh.caf" waitForCompletion:NO]];

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
    self.restartLabel.text = @"GAME OVER...Restart?";
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
        static float maxDelta = 200;
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

- (void)startMonitoringAcceleration {
#if TARGET_OS_IPHONE
    if (self.motionManager.accelerometerAvailable) {
        [self.motionManager startAccelerometerUpdates];
    }
#else
    [self.motionManager startMouseMotionUpdates];
#endif
}

- (void)stopMonitoringAcceleration {
#if TARGET_OS_IPHONE
    if (self.motionManager.accelerometerAvailable && self.motionManager.accelerometerActive) {
        [self.motionManager stopAccelerometerUpdates];
    }
#else
    [self.motionManager stopMouseMotionUpdates];
#endif
}

- (void)updatePlayerPositionFromMotionManager {
#if TARGET_OS_IPHONE
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
}

#pragma mark - Controller setup

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
    [self.backgroundAudioPlayer setVolume:0.33];
    [self.backgroundAudioPlayer play];
}

#pragma mark - Memory

- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
