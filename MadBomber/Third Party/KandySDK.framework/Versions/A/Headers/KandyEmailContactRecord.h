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
#import "KandyEmailContactRecordProtocol.h"

/**
 *  The concrete, private class representing a KandyEmailContactRecord, conforming to KandyEmailContactRecordProtocol.
 Used to set the ReadOnly properties of the protocol.
 */
@interface KandyEmailContactRecord : NSObject<KandyEmailContactRecordProtocol>

/**
 *  Inits with Server Identifier, Email and Email descriptor
 */
-(id)initWithServerIdentifier:(KandyRecord*)aServerIdentifier email:(NSString*)aEmail andEmailDescriptor:(NSString*)aEmailDescriptor dataByKey:(NSDictionary*)dataByKey;

@end
