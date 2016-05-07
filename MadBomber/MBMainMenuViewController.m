//
//  MBMainMenuViewController.m
//  MadBomber
//
//  Created by Wayne Hartman on 5/7/16.
//  Copyright © 2016 Wayne Hartman. All rights reserved.
//

#import "MBMainMenuViewController.h"
#import "MBInterstitialViewController.h"
#import "MBViewController.h"
#import <EAACommon/EAACommon.h>

@interface MBMainMenuViewController ()

@property (strong, nonatomic) IBOutlet UILabel *aquiferLevelLabel;
@property (strong, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) EAANetworkController *networkController;
@property (nonatomic, strong) EAAWellReading *currentReading;

@end

@implementation MBMainMenuViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.networkController = [[EAANetworkController alloc] init];
    [self updateData];
}

- (void)updateData {
    __weak typeof(self) weakSelf = self;

    self.activityIndicator.hidden = NO;
    [self.networkController fetchCurrentLevelFromWell:EAAWellLocationSanAntonio completion:^(EAAWellReading *reading, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            weakSelf.activityIndicator.hidden = YES;
            weakSelf.currentReading = reading;

            if (!error) {
                weakSelf.aquiferLevelLabel.text = [NSString stringWithFormat:@"Current Aquifer Level: %li ft.", [reading.level integerValue]];
            } else {
                weakSelf.aquiferLevelLabel.text = @"";
            }
        });
    }];
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (IBAction)didSelectStart:(id)sender {
    MBInterstitialViewController *interstitialVC = [self.storyboard instantiateViewControllerWithIdentifier:@"MBInterstitialViewController"];
    interstitialVC.modalTransitionStyle = UIModalTransitionStyleCrossDissolve;

    [self presentViewController:interstitialVC animated:YES completion:^{
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [self presentGame];
        });
    }];
}

- (void)presentGame {
    MBViewController *mainVC = [self.storyboard instantiateViewControllerWithIdentifier:@"MAIN_GAME"];
    mainVC.currentLevel = self.currentReading.level;
    [self.presentedViewController presentViewController:mainVC animated:YES completion:NULL];
}

@end
