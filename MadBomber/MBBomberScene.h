//
//  MBMyScene.h
//  MadBomber
//

//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import <SpriteKit/SpriteKit.h>

typedef NS_ENUM(NSInteger, MBSwipeDirection) {
    MBSwipeDirectionLeft = 0,
    MBSwipeDirectionRight
};

@interface MBBomberScene : SKScene

@property (nonatomic, assign) CGFloat startingWaterLevel;

- (void)togglePlayPause;
- (void)swipeWithDirection:(MBSwipeDirection)direction velocity:(CGPoint)velocity;

@end
