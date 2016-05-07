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

@property (nonatomic, strong) MBBomberScene *scene;

@end

@implementation MBViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Configure the view.
    SKView * skView = (SKView *)self.view;
    skView.showsFPS = YES;
    skView.showsNodeCount = YES;
    
    
    
    
    
    [[UIApplication sharedApplication] setIdleTimerDisabled:YES];
}

- (void)viewWillLayoutSubviews {
    if (!_scene) {
        SKView *view = (SKView *)self.view;
        
        // Create and configure the scene.
        MBBomberScene * scene = [MBBomberScene sceneWithSize:view.bounds.size];
        scene.scaleMode = SKSceneScaleModeAspectFill;
#if TARGET_OS_TV
        UITapGestureRecognizer *playRecognizer = [[UITapGestureRecognizer alloc] init];
        playRecognizer.allowedPressTypes = @[@(UIPressTypePlayPause)];
        [playRecognizer addTarget:scene action:@selector(togglePlayPause)];
        
        UIPanGestureRecognizer *swipeRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handleSwipe:)];
        
        [self.view addGestureRecognizer:swipeRecognizer];
        [self.view addGestureRecognizer:playRecognizer];
#endif
        self.scene = scene;

        // Present the scene.
        [view presentScene:scene];
    }
}

- (void)handleSwipe:(UIPanGestureRecognizer *)recognizer {
    CGPoint velocity = [recognizer velocityInView:self.view];
    MBSwipeDirection direction = velocity.x > 0;
    [self.scene swipeWithDirection:direction velocity:velocity];
}

- (BOOL)shouldAutorotate {
    return YES;
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskLandscape;
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (void)dealloc {
    [[UIApplication sharedApplication] setIdleTimerDisabled:NO];
}

@end
