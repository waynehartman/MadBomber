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
#import "KandyAreaCode.h"
#import "KandyLocationParams.h"
#import "KandyLocationServiceEnums.h"
#import <CoreLocation/CoreLocation.h>

/**
 * This interface gets the country info.
 */
 
@interface KandyLocationService : NSObject

/**
 *  Get the country information by MCC/IP
 *
 *  @param responseCallback Callback contains the error and KandyAreaCode with the relevant information
 */
-(void) getCountryInfoWithResponseCallback:(void(^)(NSError* error, KandyAreaCode* areaCode))responseCallback;

/**
 *  Report a location to the server
 *
 *  @param locationParams   the location params to be sent to the server
 *  @param responseCallback callback to be called upon completion, will contain error incase of failure
 */
-(void)reportLocation:(KandyLocationParams *)locationParams responseCallback:(void(^)(NSError* error))responseCallback;

@end
