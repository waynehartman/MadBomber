//
//  MBMyScene.m
//  MadBomber
//
//  Created by Wayne Hartman on 2/18/14.
//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import "MBBomberScene.h"
@import CoreMotion;

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

@property (nonatomic, strong) CMMotionManager *motionManager;

@end

#define USER_DEFAULTS_HIGH_SCORE    @"USER_DEFAULTS_HIGH_SCORE"
#define NUMBER_OF_BOMBS_IN_QUEUE    15
#define NAME_RESTART_LABEL          @"NAME_RESTART_LABEL"

@implementation MBBomberScene

-(id)initWithSize:(CGSize)size {    
    if (self = [super initWithSize:size]) {
        /* Setup your scene here */
        self.backgroundColor = [SKColor colorWithRed:0.15 green:0.15 blue:0.3 alpha:1.0];
        self.physicsBody = [SKPhysicsBody bodyWithEdgeLoopFromRect:self.frame];

        [self addChild:self.scoreNode];
        [self addChild:self.bomber];
        [self addChild:self.player];

        [self refreshHighScore];

        self.scoreNode.position = CGPointMake(CGRectGetMidX(self.frame), self.frame.size.height - self.scoreNode.frame.size.height);
        self.bomber.position = CGPointMake(100.0f, self.frame.size.height - self.bomber.size.height);
        self.player.position = CGPointMake(100.0f, (self.player.size.height * 0.5f) + 5.0f);

        for (SKNode *bomb in self.bombs) {
            bomb.hidden = YES;
            [self addChild:bomb];
        }

        [self insertChild:self.player atIndex:self.children.count - 1];

        [self startTheGame];
    }
    return self;
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

- (CMMotionManager *)motionManager {
    if (!_motionManager) {
        _motionManager = [[CMMotionManager alloc] init];
    }

    return _motionManager;
}

#pragma mark - Touches

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    /* Called when a touch begins */
    
    for (UITouch *touch in touches) {
        CGPoint location = [touch locationInNode:self];
        
        SKNode *n = [self nodeAtPoint:[touch locationInNode:self]];
        if (n != self && [n.name isEqual: @"restartLabel"]) {
            [[self childNodeWithName:@"restartLabel"] removeFromParent];
            [[self childNodeWithName:@"winLoseLabel"] removeFromParent];
            [self startTheGame];
            return;
        }
    }
}

#pragma mark - Update

-(void)update:(CFTimeInterval)currentTime {
    /* Called before each frame is rendered */
    
    double curTime = CACurrentMediaTime();
    if (curTime > _nextBombToSpawn) {
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
    }
    
    if (!_gameOver) {
        [self updatePlayerPositionFromMotionManager];

        for (SKSpriteNode *bomb in self.bombs) {
            if (bomb.hidden) {
                continue;
            }

            if ([bomb intersectsNode:self.player]) {
                [bomb removeAllActions];
                bomb.hidden = YES;

                [self incrementScoreByPoints:50];
            }
        }
    }
}

#pragma mark - Setup

- (void)startTheGame {
    self.points = 0;
    [self incrementScoreByPoints:0];

    self.player.physicsBody = [SKPhysicsBody bodyWithRectangleOfSize:self.player.frame.size];
    self.player.physicsBody.dynamic = YES;
    self.player.physicsBody.affectedByGravity = NO;
    self.player.physicsBody.mass = 0.01;

    [self startMonitoringAcceleration];

    _gameOver = NO;
    [self moveTheBomber];
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
    if (self.motionManager.accelerometerAvailable) {
        [self.motionManager startAccelerometerUpdates];
    }
}

- (void)stopMonitoringAcceleration {
    if (self.motionManager.accelerometerAvailable && self.motionManager.accelerometerActive) {
        [self.motionManager stopAccelerometerUpdates];
        NSLog(@"accelerometer updates off...");
    }
}

- (void)updatePlayerPositionFromMotionManager {
    CMAccelerometerData* data = self.motionManager.accelerometerData;
    if (fabs(data.acceleration.y) > 0.1) {
        [self applyPlayerForce:CGVectorMake(-20.0f * data.acceleration.y, 0.0f)];
    }
}

- (void)applyPlayerForce:(CGVector)vector {
    [self.player.physicsBody applyForce:vector];
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

@end
