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

@interface KandyBillingPackage : NSObject

/**
 *  The billing package Id
 */
@property(strong) NSString* Id;
/**
 *  The billing package name
 */
@property(strong) NSString* name;
/**
 *  The package start date
 */
@property(strong) NSDate* startDate;
/**
 *  The expiry date of the package
 */
@property(strong) NSDate *exiparyDate;
/**
 *  The package properties (@see KandyBillingPackageProperty)
 */
@property(strong) NSArray* properties;
/**
 *  The balance left to the user in the package
 */
@property(assign) double balance;
/**
 *  The billing package currency
 */
@property(strong) NSString* currency;
/**
 *  The package remaining time (in minutes)
 */
@property(assign) double remainingTime;

@end
