//
//  MBMouseMotionManager.h
//  MadBomber
//
//  Created by Wayne Hartman on 2/20/14.
//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct {
	double x;
	double y;
} MBMouseAcceleration;

@interface MBMouseMotionManager : NSObject

@property (nonatomic, assign, readonly) MBMouseAcceleration acceleration;

- (void)startMouseMotionUpdates;
- (void)stopMouseMotionUpdates;

@end
