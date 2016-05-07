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
/**
 KandySignupInfo holds the data about multi registeration with a userId
 */
@interface KandySignupInfo : NSObject
/**
 Returns YES if the current userId is registered with atleast one other device
 */
@property (assign) BOOL isUserExistsOnOtherDevice;
/**
 Returns YES if registration with the same userId is allowed on more than one device
 */
@property (assign) BOOL isMDLAllowed;

@end
