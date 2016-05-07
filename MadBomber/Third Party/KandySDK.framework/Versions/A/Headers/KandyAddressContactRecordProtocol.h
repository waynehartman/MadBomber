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
#import "KandyContactRecordProtocol.h"
/**
 * This protocol handles address contact records
 */
@protocol KandyAddressContactRecordProtocol <NSObject, KandyContactRecordProtocol>

/**
 *  Address Street
 */
@property (nonatomic, strong) NSString *street;

/**
 *  Address City
 */
@property (nonatomic, strong) NSString *city;

/**
 *  Address State
 */
@property (nonatomic, strong) NSString *state;

/**
 *  Address Zip
 */
@property (nonatomic, strong) NSString *zip;

/**
 *  Address Country
 */
@property (nonatomic, strong) NSString *country;

/**
 *  Address Country Code
 */
@property (nonatomic, strong) NSString *countryCode;

@end
