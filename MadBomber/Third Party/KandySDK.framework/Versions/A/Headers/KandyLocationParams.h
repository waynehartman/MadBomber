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
#import <CoreLocation/CoreLocation.h>
#import "KandyLocationServiceEnums.h"

@interface KandyLocationParams : NSObject

-(id) initWithLocation:(CLLocation *)location status:(EKandyLocationStatus)status countryName:(NSString*)countryName countryCode:(NSString*)countryCode;
/**
 *  The location 
 */
@property (strong, nonatomic) CLLocation* location;
/**
 *  The location status
 */
@property EKandyLocationStatus locationStatus;
/**
 *  The country name
 */
@property (strong, nonatomic) NSString *countryName;
/**
 *  Two letter codes that represents the country
 */
@property (strong, nonatomic) NSString *countryCode;

@end
