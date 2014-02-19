//
//  MBMyScene.m
//  MadBomber
//
//  Created by Wayne Hartman on 2/18/14.
//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import "MBBomberScene.h"

@interface MBBomberScene()

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
}

- (void)refreshHighScore {
    NSInteger highScore = [[NSUserDefaults standardUserDefaults] integerForKey:USER_DEFAULTS_HIGH_SCORE];
    NSString *text = [NSString stringWithFormat:@"Hi Score: %i", highScore];
    self.scoreNode.text = text;
}

#pragma mark - Setup

- (void)startTheGame {
    [self moveTheBomber];
}

- (void)moveTheBomber {
    static float delta = 200;
    float min = self.bomber.position.x - delta;
    float max = self.bomber.position.x + delta;

    if (min < self.bomber.size.width) {
        min = self.bomber.size.width;
    }

    if (max > (self.frame.size.width - self.bomber.size.width)) {
        max = self.frame.size.width - self.bomber.size.width;
    }
    
    float randomX = [self randomValueBetween:min
                                    andValue:max];
    //Set position instead of running action with duration 0
    SKAction *moveAction = [SKAction moveToX:randomX duration:0.25f];

    __weak typeof(self) weakSelf = self;

    SKAction *waitAction = [SKAction waitForDuration:0.15 withRange:0.4];
    SKAction *completionAction = [SKAction customActionWithDuration:0 actionBlock:^(SKNode *node, CGFloat elapsedTime) {
        [weakSelf moveTheBomber];
    }];
    
    SKAction *sequence = [SKAction sequence:@[moveAction, waitAction, completionAction]];

    [self.bomber runAction:sequence];
}

#pragma mark - Utility Methods

- (float)randomValueBetween:(float)low andValue:(float)high {
    return (((float) arc4random() / 0xFFFFFFFFu) * (high - low)) + low;
}

@end
