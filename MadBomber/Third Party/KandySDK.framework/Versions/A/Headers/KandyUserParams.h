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

@interface KandyUserParams : NSObject

@property(nonatomic, strong) NSString* userId;

@property(nonatomic, strong) NSString* password;

@property(nonatomic, strong) NSString* phoneNumber;

@property(nonatomic, strong) NSString* countryCode;

@property(nonatomic, strong) NSString* firstName;

@property(nonatomic, strong) NSString* lastName;

@property(nonatomic, strong) NSString* email;

@end
