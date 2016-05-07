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
#import "KandyEventProtocol.h"
#import "KandyRecord.h"

@interface KandyGroupParticipantKicked : NSObject <KandyEventProtocol>

/**
 *  Initialization method for KandyGroupParticipantKicked
 *
 *  @param aUuid       the event UUID
 *  @param aTimestamp  the event timestamp
 *  @param aGroupId    the group ID
 *  @param aBooter     the booter
 *  @param aBooted     NSArray of booted (KandyRecords)
 *
 *  @return initialized KandyGroupParticipantKicked
 */
-(instancetype)initWithUUID:(NSString*)aUuid timestamp:(NSDate*)aTimestamp groupId:(KandyRecord*)aGroupId booter:(KandyRecord*)aBooter bootedParticipants:(NSArray*)aBooted isHistoryEvent:(BOOL)isHistoryEvent;
/**
 *  The group ID
 */
@property (nonatomic, readonly) KandyRecord* groupId;
/**
 *  The booter
 */
@property (nonatomic, readonly) KandyRecord* booter;
/**
 *  Array of booted records of kind KandyRecord
 */
@property (nonatomic, readonly) NSArray* bootedParticipants;

@end
