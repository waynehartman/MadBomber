//
//  MBAppDelegate.m
//  MadBomberX
//
//  Created by Wayne Hartman on 2/20/14.
//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import "MBAppDelegate.h"
#import "MBBomberScene.h"

@implementation MBAppDelegate

@synthesize window = _window;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    /* Pick a size for the scene */
    SKScene *scene = [MBBomberScene sceneWithSize:CGSizeMake(1024, 768)];

    /* Set the scale mode to scale to fit the window */
    scene.scaleMode = SKSceneScaleModeAspectFit;

    [self.skView presentScene:scene];

    self.skView.showsFPS = YES;
    self.skView.showsNodeCount = YES;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return YES;
}

@end
