//
//  MBInterstitialViewController.m
//  Aquifer
//
//  Created by Wayne Hartman on 5/7/16.
//  Copyright © 2016 Wayne Hartman. All rights reserved.
//

#import "MBInterstitialViewController.h"

@interface MBInterstitialViewController ()

@property (nonatomic, strong) IBOutlet UIImageView *imageView;

@end

@implementation MBInterstitialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSArray *interstitialNames = @[
                                   @"interstitial-1",
                                   @"interstitial-2",
                                   @"interstitial-3",
                                   ];
    
    NSInteger index = arc4random_uniform((u_int32_t)interstitialNames.count);
    self.imageView.image = [UIImage imageNamed:interstitialNames[index]];
}

@end
