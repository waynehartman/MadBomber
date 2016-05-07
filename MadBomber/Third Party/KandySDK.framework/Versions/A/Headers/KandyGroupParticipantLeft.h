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

@interface KandyGroupParticipantLeft : NSObject <KandyEventProtocol>

/**
 *  Initialization method for KandyGroupParticipantLeft
 *
 *  @param aUuid      the event UUID
 *  @param aTimestamp the event timestamp
 *  @param aGroupId   the group ID
 *  @param aLeaver    the leaver
 *  @param aAdmins    the group admins - optional
 *
 *  @return initialized KandyGroupParticipantLeft
 */
-(instancetype)initWithUUID:(NSString*)aUuid timestamp:(NSDate*)aTimestamp groupId:(KandyRecord*)aGroupId leaver:(KandyRecord*)aLeaver admins:(NSArray*)aAdmins isHistoryEvent:(BOOL)isHistoryEvent;
/**
 *  The group ID
 */
@property (nonatomic, readonly) KandyRecord* groupId;
/**
 *  The leaver
 */
@property (nonatomic, readonly) KandyRecord* leaver;
/**
 *  Optional - in case of an admin change, the new admin list (KandyRecord) will be added to the event, otherwise nil
 */
@property (nonatomic, readonly) NSArray* admins;
@end
