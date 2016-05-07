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
#import "KandyContactProtocol.h"

@interface KandyContactParams : NSObject

/**
 *  Helper initialization for KandyContactParams
 *
 *  @param kandyContact the KandyContact to create the params from
 *
 *  @return initialized for KandyContactParams
 */
-(instancetype)initWithKandyContact:(id<KandyContactProtocol>)kandyContact;

/**
 *  Represents an identifier that is recognized by the server. For example: for making calls.
 */
@property (nonatomic, strong) KandyRecord * serverIdentifier;
/**
 *  Kandy contact display name
 */
@property (nonatomic, strong) NSString* displayName;

/**
 *  Array of phones. Objects in array of <KandyPhoneContactRecordProtocol>.
 */
@property (nonatomic, strong) NSArray* phones;

/**
 *  Array of emails. Objects in array of <KandyEmailContactRecordProtocol>.
 */
@property (nonatomic, strong) NSArray* emails;

/**
 *  Array of addresses. Objects in array of <KandyAddressContactRecordProtocol>.
 */
@property (nonatomic, strong) NSArray* addresses;

/**
 *  Array of social profiles. Objects in array of <KandySocialProfileContactRecordProtocol>.
 */
@property (nonatomic, strong) NSArray* socialProfiles;

/**
 *  Dictionary that contains additional data.
 */
@property (nonatomic, strong) NSDictionary* dataByType;

@end
