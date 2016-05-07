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
#import "KandyPhoneContactRecordProtocol.h"

/**
 *  The concrete, private class representing a KandyPhoneContactRecord, conforming to KandyPhoneContactRecordProtocol.
 Used to set the ReadOnly properties of the protocol.
 */
@interface KandyPhoneContactRecord : NSObject<KandyPhoneContactRecordProtocol>

/**
 *  Inits with Server Identifier, Phone and Phone descriptor
 */
-(id)initWithServerIdentifier:(KandyRecord*)aServerIdentifier phone:(NSString*)aPhone andPhoneDescriptor:(NSString*)aPhoneDescriptor dataByKey:(NSDictionary*)dataByKey;
@end
