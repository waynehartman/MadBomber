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

@interface KandyCredit : NSObject

/**
 *  Current credit
 */
@property (assign) double credit;
/**
 *  Currency of credit
 */
@property (strong) NSString* currency;
/**
 *  Array of packages (@see KandyBillingPackage)
 */
@property (strong) NSArray* packages;
/**
 *  Array of DIDs (NSString*)
 */
@property (strong) NSArray* DIDs;

@end
