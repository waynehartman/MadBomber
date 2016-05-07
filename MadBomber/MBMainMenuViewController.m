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

#if TARGET_OS_TV
#elif TARGET_OS_IPHONE
#import <KandySDK/KandySDK.h>

@interface MBMainMenuViewController (KANDY) <KandyChatServiceNotificationDelegate>

@end

#endif

@interface MBMainMenuViewController () <MBViewControllerDelegate>

@property (strong, nonatomic) IBOutlet UILabel *aquiferLevelLabel;
@property (strong, nonatomic) IBOutlet UILabel *historicalDayLevelLabel;
@property (strong, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) EAANetworkController *networkController;
@property (nonatomic, strong) EAAWellReading *currentReading;

@end

@implementation MBMainMenuViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.networkController = [[EAANetworkController alloc] init];
    [self updateData];
    
#if TARGET_OS_TV
#elif TARGET_OS_IPHONE
    [[Kandy sharedInstance].services.chat registerNotifications:self];
    [Kandy initializeSDKWithDomainKey:@"DAK954df05fe18b4d2b82fa2cc6ce6b6ff1" domainSecret:@"DAS16de9a7d8fc7429385ac8ad95a27df93"];
    
    KandyUserInfo * kandyUserInfo = [[KandyUserInfo alloc] initWithUserId:@"13858884140@aquifer.waynehartman.com.gmail.com"
                                                                 password:@"3b459d9ed79743"];
    [[Kandy sharedInstance].access login:kandyUserInfo responseCallback:^(NSError *error) {
        if (error) {
            NSLog(@">>>>>>>>> There was a problem registering with Kandy...");
        }
    }];
#endif
}

- (void)updateData {
    __weak typeof(self) weakSelf = self;

    self.activityIndicator.hidden = NO;
    
    EAAWellLocation location = EAAWellLocationSanAntonio;
    
    dispatch_group_t activity = dispatch_group_create();
    
    dispatch_group_enter(activity);
    [self.networkController fetchCurrentLevelFromWell:location completion:^(EAAWellReading *reading, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            weakSelf.currentReading = reading;

            if (!error) {
                weakSelf.aquiferLevelLabel.text = [NSString stringWithFormat:@"Current Aquifer Level: %li ft.", [reading.level integerValue]];
            } else {
                weakSelf.aquiferLevelLabel.text = @"";
            }

            dispatch_group_leave(activity);
        });
    }];
    
    dispatch_group_enter(activity);
    [self.networkController fetchWellDataFromWell:location completion:^(EAAWell *well, NSError *error)
    {
        long average = [[well historicalAverageForDate:[NSDate date]] longValue];

        if (!error) {
            weakSelf.historicalDayLevelLabel.text = [NSString stringWithFormat:@"Historical Average: %li ft.", average];
        } else {
            NSLog(@"uh oh");
        }
        
        dispatch_group_leave(activity);
    }];
    
    dispatch_group_notify(activity, dispatch_get_main_queue(), ^{
        weakSelf.activityIndicator.hidden = YES;
    });
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
    mainVC.delegate = self;

    [self.presentedViewController presentViewController:mainVC animated:YES completion:NULL];
}

#pragma mark - MBViewControllerDelegate

- (void)gameViewController:(MBViewController *)gameVC didFinishGameWithScore:(NSInteger)score highscore:(NSInteger)highscore {
#if TARGET_OS_TV
#elif TARGET_OS_IPHONE
    if (YES) {//score > highscore) { commented this logic out for the demo
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"SMS your high score?" message:nil preferredStyle:UIAlertControllerStyleAlert];
        [alert addAction:[UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:NULL]];
        [alert addAction:[UIAlertAction actionWithTitle:@"Send" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            NSString *phoneNumber = [[alert.textFields firstObject] text];
            NSString *message = [[alert.textFields lastObject] text];
            
            KandySMSMessage *smsMessage = [[KandySMSMessage alloc] initWithText:message recipient:phoneNumber displayName:@"Wayne"];

            [[Kandy sharedInstance].services.chat sendSMS:smsMessage responseCallback:^(NSError *error) {
                if (!error) {
                    NSLog(@"message sent!");
                } else {
                    NSLog(@"message failed! %@", error);
                }
            }];
        }]];
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.keyboardType = UIKeyboardTypePhonePad;
            textField.placeholder = @"Phone Number";
            textField.text = @"13858884140";
        }];
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            textField.keyboardType = UIKeyboardTypeDefault;
            textField.text = [NSString stringWithFormat:@"I just one upped ya! 'Save The Aquifer!' High Score: %li", (long)score];
            textField.placeholder = @"Message";
        }];

        [gameVC presentViewController:alert animated:YES completion:NULL];
    }
#endif
}

#pragma mark -
#if TARGET_OS_TV
#elif TARGET_OS_IPHONE
-(void) onMessageReceived:(id<KandyMessageProtocol>)kandyMessage recipientType:(EKandyRecordType)recipientType {
    
}

-(void) onMessageDelivered:(KandyDeliveryAck*)ackData {
    
}

-(void) onAutoDownloadProgress:(KandyTransferProgress*)transferProgress kandyMessage:(id<KandyMessageProtocol>)kandyMessage {
    
}

-(void) onAutoDownloadFinished:(NSError*)error fileAbsolutePath:(NSString*)path kandyMessage:(id<KandyMessageProtocol>)kandyMessage {
    
}
#endif

@end
