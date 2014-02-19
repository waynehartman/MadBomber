//
//  MBViewController.m
//  MadBomber
//
//  Created by Wayne Hartman on 2/18/14.
//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import "MBViewController.h"
#import "MBBomberScene.h"

@interface MBViewController ()

@property (nonatomic, strong) SKScene *scene;

@end

@implementation MBViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Configure the view.
    SKView * skView = (SKView *)self.view;
    skView.showsFPS = YES;
    skView.showsNodeCount = YES;
}

- (void)viewWillLayoutSubviews {
    if (!_scene) {
        SKView *view = (SKView *)self.view;
        
        // Create and configure the scene.
        SKScene * scene = [MBBomberScene sceneWithSize:view.bounds.size];
        scene.scaleMode = SKSceneScaleModeAspectFill;

        self.scene = scene;

        // Present the scene.
        [view presentScene:scene];
    }
}

- (BOOL)shouldAutorotate {
    return YES;
}

- (NSUInteger)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskLandscape;
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

@end
