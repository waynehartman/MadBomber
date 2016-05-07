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
#import "KandySocialProfileContactRecordProtocol.h"

/**
 *  Class representing a KandySocialProfileContactRecord, conforming to KandySocialProfileContactRecordProtocol.
 Used to set the ReadOnly properties of the protocol.
 */
@interface KandySocialProfileContactRecord : NSObject<KandySocialProfileContactRecordProtocol>

/**
 *  Initializtion method for KandySocialProfileContactRecord
 *
 *  @param newServerIdentifier KandyRecord - the server identifier
 *  @param aSocialNetwork      the social network type
 *  @param aUsername           the user name (optional)
 *  @param aUserIdentifier     the user identifier (optional)
 *  @param aUrl                the URL (optional)
 *  @param aDataByKey          extra data for the record
 *
 *  @return Initialized KandySocialProfileContactRecord
 */
-(instancetype)initWithServerIdentifier:(KandyRecord*)newServerIdentifier socialNetwork:(EKandyContactRecordSocialProfileType)aSocialNetwork userName:(NSString*)aUsername userIdentifier:(NSString*)aUserIdentifier url:(NSURL*)aUrl dataByKey:(NSDictionary*)aDataByKey;

@end
