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
#import "KandyCredit.h"

@interface KandyBillingService : NSObject

/**
 *  Get current user's credits
 *
 *  @param responseCallBack callback will be called upon completion with error incase of failure or KandyCredit (@see KandyCredit) otherwise
 */
-(void) getUserCreditWithResponseCallback:(void(^)(NSError* error, KandyCredit* kandyCredit))responseCallBack;

@end
