//
//  MBMyScene.m
//  MadBomber
//
//  Created by Wayne Hartman on 2/18/14.
//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import "MBBomberScene.h"

@interface MBBomberScene() {
    double _nextBombToSpawn;
    int _nextBomb;
}

@property (nonatomic, strong) SKLabelNode *scoreNode;
@property (nonatomic, strong) NSMutableArray *bombs;
@property (nonatomic, strong) SKSpriteNode *bomber;

@end

#define USER_DEFAULTS_HIGH_SCORE    @"USER_DEFAULTS_HIGH_SCORE"
#define NUMBER_OF_BOMBS_IN_QUEUE    15
#define NAME_RESTART_LABEL          @"NAME_RESTART_LABEL"

@implementation MBBomberScene

-(id)initWithSize:(CGSize)size {    
    if (self = [super initWithSize:size]) {
        /* Setup your scene here */
        self.backgroundColor = [SKColor colorWithRed:0.15 green:0.15 blue:0.3 alpha:1.0];

        [self addChild:self.scoreNode];
        [self addChild:self.bomber];

        [self refreshHighScore];

        self.scoreNode.position = CGPointMake(CGRectGetMidX(self.frame), self.frame.size.height - self.scoreNode.frame.size.height);
        self.bomber.position = CGPointMake(100.0f, self.frame.size.height - self.bomber.size.height);
        for (SKNode *bomb in self.bombs) {
            bomb.hidden = YES;
            [self addChild:bomb];
        }

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
}

#pragma mark - Setup

- (void)startTheGame {
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

#pragma mark - Utility Methods

- (float)randomValueBetween:(float)low andValue:(float)high {
    return (((float) arc4random() / 0xFFFFFFFFu) * (high - low)) + low;
}

- (void)refreshHighScore {
    NSInteger highScore = [[NSUserDefaults standardUserDefaults] integerForKey:USER_DEFAULTS_HIGH_SCORE];
    NSString *text = [NSString stringWithFormat:@"Hi Score: %li", (long)highScore];
    self.scoreNode.text = text;
}

@end
