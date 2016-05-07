//
//  MBViewController.h
//  MadBomber
//

//  Copyright (c) 2014 Wayne Hartman. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SpriteKit/SpriteKit.h>

@protocol MBViewControllerDelegate;

@interface MBViewController : UIViewController

@property (nonatomic, strong) NSNumber *currentLevel;
@property (nonatomic, weak) id<MBViewControllerDelegate> delegate;

@end


@protocol MBViewControllerDelegate <NSObject>

- (void)gameViewController:(MBViewController *)gameVC didFinishGameWithScore:(NSInteger)score highscore:(NSInteger)highscore;

@end
