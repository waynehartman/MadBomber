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
 *  Protocol for email entries in a contact.
 */
@protocol KandyEmailContactRecordProtocol <NSObject, KandyContactRecordProtocol>

/**
 *  The contact's email
 */
@property (nonatomic, strong) NSString * email;

/**
 *  The contact's email description
 */
@property (nonatomic, strong) NSString * emailDescriptor;

@end
