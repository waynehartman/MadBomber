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
#import "KandyContactsServiceEnums.h"

@class KandyRecord;
/**
 *  A base protocol for representing field entries in Contact. For example addresses, phones, emails.
 */
@protocol KandyContactRecordProtocol <NSObject>

/**
 *  Represents an identifier that is recognized by the server. For example for making calls.
 */
@property (nonatomic, readonly) KandyRecord * serverIdentifier;

/**
 *  The field's value
 */
@property (nonatomic, readonly) id value;

/**
 *  The field's text description
 */
@property (nonatomic, readonly) NSString * valueDescriptor;

/**
 *  An enum representing the field's value type
 */
@property (nonatomic, readonly) EKandyContactRecordType valueType;

/**
 *  Extra data that is relevant for the user
 */
@property (nonatomic, readonly) NSDictionary *dataByKey;

@end
