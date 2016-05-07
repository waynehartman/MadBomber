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
#import "KandyCallProtocol.h"

@protocol KandyOutgoingCallProtocol <KandyCallProtocol>
/**
 *  Establish an outgoing call
 *
 *  @param responseCallback will return error incase of failure
 */
-(void) establishWithResponseBlock:(void (^)(NSError *error))responseCallback;

@end
