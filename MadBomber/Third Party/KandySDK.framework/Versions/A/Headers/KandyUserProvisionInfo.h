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
@class KandyMDLInfo;

typedef NS_ENUM(NSUInteger, EKandyProvisonType)
{
    EKandyProvisonType_none,
    EKandyProvisonType_domestic,
    EKandyProvisonType_internetional,
    EKandyProvisonType_last
};

@interface KandyUserProvisionInfo : NSObject <NSCoding>

-(instancetype)initWithUserProvisionInfo:(KandyUserProvisionInfo *)provisionInfo;

- (instancetype)initWithMDL:(KandyMDLInfo *)mdlInfo jsonData:(NSDictionary *)jsonData;

/**
 * The userId
 */
@property(nonatomic, readonly) NSString *userId;

/**
 * The date the of the registration
 */

@property (nonatomic, readonly)  NSString *registrationTimestamp;
/**
 * The date the of the provisioned state initiated
 */

@property (nonatomic, readonly)  NSString *provisionTimestamp;
/**
 * The date the of the current provisioned state changed
 */
@property (nonatomic, readonly)  NSString *modifyProvisionTimestamp;

/**
 * The date the user deprovision
 */
@property (nonatomic, readonly)  NSString *deprovisionTimestamp;

/**
 * The date of the first registration for the user
 */
@property (nonatomic, readonly)  NSString *firstRegistrationTimestamp;

/**
 * last device name used to register
 */
@property(nonatomic, readonly) NSString *lastRegisteredDeviceName;


/**
 * The date the user deactivated
 */
@property (nonatomic, readonly)  NSString *deactivateTimestamp;


/**
 * phone number of the user
 */
@property(nonatomic, readonly) NSString *userPhoneNumber;

/**
 * iso country code of user
 */

@property(nonatomic, readonly) NSString *userCountryCode;

/**
 * extra provision data
 */
@property(nonatomic, readonly) NSDictionary *provisionData;

/**
 * defines the type of proviosioned
 */
@property (nonatomic, assign) EKandyProvisonType provisionType;

/**
 * defined if the current user already registered
 */
@property (nonatomic, readonly) BOOL isProvisioned;

/**
 * info about the multi device login
 */

@property (nonatomic, readonly) KandyMDLInfo *mdlInfo;
/**
 *  Initialize a KandyUserInfo
 *
 *  @param userId   UserId
 *  @param password Password
 *
 *  @return Initialized KandyUserInfo
 */

@end
