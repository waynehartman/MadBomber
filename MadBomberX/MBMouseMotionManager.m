//
//  MBMouseMotionManager.m
//  MadBomber
//
//  Created by Wayne Hartman on 2/20/14.
//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import "MBMouseMotionManager.h"

@interface MBMouseMotionManager ()

@property (nonatomic, assign, readwrite) MBMouseAcceleration acceleration;

@property (nonatomic, strong) id motionEventHandler;
@property (nonatomic, assign) CGPoint previousPoint;
@property (nonatomic, strong) NSTimer *timer;

@end

static NSTimeInterval timeInterval = 0.05;

@implementation MBMouseMotionManager

- (void)startMouseMotionUpdates {
    self.previousPoint = [NSEvent mouseLocation];
    self.timer = [NSTimer scheduledTimerWithTimeInterval:timeInterval
                                                  target:self
                                                selector:@selector(timerDidFire:)
                                                userInfo:nil
                                                 repeats:YES];
}

- (void)setMotionEventHandler:(id)motionEventHandler {
    if (_motionEventHandler) {
        [NSEvent removeMonitor:_motionEventHandler];
    }

    _motionEventHandler = motionEventHandler;
}

- (void)stopMouseMotionUpdates {
    [self.timer invalidate];
    self.motionEventHandler = nil;

    MBMouseAcceleration acceleration = {0, 0};

    self.acceleration = acceleration;
}

- (void)timerDidFire:(NSTimer *)timer {
    CGPoint current = [NSEvent mouseLocation];
    CGPoint prev = self.previousPoint;

    float deltaX = current.x - prev.x;
    float deltaY = current.y - prev.y;

    static float multiplier = 30.0f;

    float velocityX = deltaX / (timeInterval * multiplier);
    float velocityY = deltaY / (timeInterval * multiplier);
    
    float accelerationX = velocityX / (timeInterval * multiplier);
    float accelerationY = velocityY / (timeInterval * multiplier);

    MBMouseAcceleration acceleration = {accelerationX, accelerationY};
    self.acceleration = acceleration;

    self.previousPoint = current;
}

- (void)dealloc {
    [self stopMouseMotionUpdates];
}

@end
