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

#import <UIKit/UIKit.h>

/**
 *  Class that represents country details
 */
@interface KandyAreaCode : NSObject

/**
 *  The country name
 */
@property (readonly) NSString *countryName;
/**
 *  Two letter codes that represents the country
 */
@property (readonly) NSString *isoCode;
/**
 *  The country phone prefix
 */
@property (readonly) NSString *phonePrefix;

/**
 *  Initialization method for KandyAreaCode
 *
 *  @param isoCode     The ISO code for the country
 *  @param name        The name of the country
 *  @param phonePrefix The country phone prefix
 *
 *  @return an initialized KandyAreaCode object with the given parameters
 */
-(id) initWithISOCode:(NSString*)isoCode andCountryName:(NSString *)name andPhonePrefix:(NSString *)phonePrefix;

@end
