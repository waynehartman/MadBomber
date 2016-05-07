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
#import "KandyContactsServiceEnums.h"

/**
 *  Protocol for social profiles entries in a contact.
 */
@protocol KandySocialProfileContactRecordProtocol <NSObject, KandyContactRecordProtocol>

/**
 *  An enum indicating the type of social network (Facebook, LinkedIn, etc.)
 */
@property (nonatomic, assign) EKandyContactRecordSocialProfileType socialNetwork;

/**
 *  The social network's user name
 */
@property (nonatomic, strong) NSString *username;

/**
 *  The social network's user identifier
 */
@property (nonatomic, strong) NSString *userIdentifier;

/**
 *  The social network's user URL
 */
@property (nonatomic, strong) NSURL *url;

@end
