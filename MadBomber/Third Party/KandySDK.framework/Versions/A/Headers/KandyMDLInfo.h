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

@interface KandyMDLInfo : NSObject<NSCoding>

- (instancetype)initWithNumberOfRegisteredDevices:(NSUInteger)numberOfRegisteredDevices maximumOfRegisteredDevices:(NSUInteger)maximumOfRegisteredDevices allowRegister:(BOOL)allowRegister registrationTimeststamp:(NSString *)registrationTimeststamp;
/**
 *  number Of Registered Devices
 */
@property (nonatomic, readonly) NSUInteger numberOfRegisteredDevices;

/**
 *  maximum Of Registered Devices
 */
@property (nonatomic, readonly) NSUInteger maximumOfRegisteredDevices;

/**
 * state if the user can register
 */
@property (nonatomic, readonly) BOOL allowRegister;


/**
 * registration timestamp
 */
@property (nonatomic, readonly) NSString *registrationTimestamp;
@end
