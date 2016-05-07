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

@class KandyRecord;

/**
 *  Billing user ID
 */
static NSString * const kKandyUserInfoBillingUserIdKey = @"kandyUserInfo_billingUserId";
/**
 *  Billing password
 */
static NSString * const kKandyUserInfoBillingPasswordKey = @"kandyUserInfo_billingPassword";
/**
 *  Access token that the system requires
 */
static NSString * const kKandyUserInfoAccessTokenKey = @"kandyUserInfo_accessToken";
/**
 *  Device ID that the system requieres
 */
static NSString * const kKandyUserInfoDeviceIdKey = @"kandyUserInfo_devicId";
/**
 *  Short user ID (userId without the domain)
 */
static NSString * const kKandyUserInfoShortUserIdKey = @"kandyUserInfo_shortUserId";
/**
 *  User's domain
 */
static NSString * const kKandyUserInfoDomainKey = @"kandyUserInfo_domain";
/**
 *  User's phone number
 */
static NSString * const kKandyUserInfoPhoneNumber = @"kandyUserInfo_phoneNumber";
/**
 *  User's country code
 */
static NSString * const kKandyUserInfoCountryCode = @"kandyUserInfo_countryCode";
/**
 *  User's first name
 */
static NSString * const kKandyUserInfoFirstName = @"kandyUserInfo_firstName";
/**
 *  User's last name
 */
static NSString * const kKandyUserInfoLastName = @"kandyUserInfo_lastName";
/**
 *  User's email
 */
static NSString * const kKandyUserInfoEmail = @"kandyUserInfo_email";

/**
 * User's virtual number
 */
static NSString * const kKandyUserInfoVirtualNumber = @"kandyUserInfo_virtualNumber";

/**
 * extra provision info
 */
static NSString *const kKandyUserProvisionInfo = @"kandyUser_provisionInfo";

/**
 *  Contains the data arrived upon signing up a user
 */
@interface KandyUserInfo : NSObject <NSCoding>

/**
 *  Full user name for login to the system
 */
@property (nonatomic, readonly) NSString *userId;
/**
 *  Password for the user to login to the system
 */
@property (nonatomic, readonly) NSString *password;
/**
 *  The Kandy record that represents the userInfo
 */
@property (nonatomic, readonly) KandyRecord *record;
/**
 *  Extra data that is relevant for the user
 */
@property (nonatomic, readonly) NSMutableDictionary *dataByKey;

- (instancetype)initWithUserId:(NSString *)userId password:(NSString*)password;

/**
 *  Initialize a KandyUserInfo
 *
 *  @param userId   UserId
 *  @param password Password
 *  @param data     Data of the user
 *
 *  @return Initialized KandyUserInfo
 */
- (instancetype)initWithUserId:(NSString *)userId password:(NSString*)password data:(NSDictionary*)data;


@end
