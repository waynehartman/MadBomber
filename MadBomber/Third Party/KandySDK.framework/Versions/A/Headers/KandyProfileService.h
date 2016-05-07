/*
 * Copyright © 2016 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
*/

#import <Foundation/Foundation.h>
#import "KandyDeviceProfileParams.h"

@interface KandyProfileService : NSObject

/**
 *  Get all of the user's device profiles
 *
 *  @param responseCallBack callback that will be called upon completion. Will return an array of KandyDeviceProfile or an error in case of failure
 */
-(void)getUserDeviceProfilesWithResponseCallback:(void(^)(NSError* error, NSArray* userDeviceProfiles))responseCallBack;

/**
 *  Update the current device profile
 *
 *  @param deviceProfileParams the params to update
 *  @param responseCallBack    callback that will be called upon completion. will return an error incase of failure
 */
-(void)updateDeviceProfile:(KandyDeviceProfileParams*)deviceProfileParams responseCallback:(void(^)(NSError* error))responseCallBack;

@end
