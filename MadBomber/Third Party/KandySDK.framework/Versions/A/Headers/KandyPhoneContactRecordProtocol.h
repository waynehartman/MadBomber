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
 *  Protocol for phone entries in a contact.
 */
@protocol KandyPhoneContactRecordProtocol <NSObject, KandyContactRecordProtocol>

/**
 *  The cotact's phone
 */
@property (nonatomic, strong) NSString * phone;

/**
 *  The contact's phone description
 */
@property (nonatomic, strong) NSString * phoneDescriptor;

@end
