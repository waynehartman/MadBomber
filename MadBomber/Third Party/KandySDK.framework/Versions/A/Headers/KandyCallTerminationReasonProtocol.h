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
#import "KandyCallServiceEnums.h"
@protocol KandyCallTerminationReasonProtocol

/**
 *  The termination code
 */
@property(nonatomic, readonly) NSInteger reasonCode;
/**
 *  The reason why the call was terminated
 */
@property(nonatomic, readonly) NSString* reason;
/**
 *  Yes if the call was not terminated by the user
 */
@property(nonatomic, readonly) BOOL isNetworkTermination;

@end