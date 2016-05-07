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

@protocol KandyServerRegistrationConfigurationProtocol <NSObject, NSCoding>

/**
 *  The address of the host we want to connect
 */
@property(readonly) NSString *hostAddress;
/**
 *  The port of the host we want to connect
 */
@property(readonly) NSInteger hostPort;
/**
 *  YES if should connect
 */
@property(readonly) BOOL isEnable;
/**
 *  YES if the connection to the host secure i.e. wss/tls/https
 */
@property(readonly) BOOL isSecure;

@end
