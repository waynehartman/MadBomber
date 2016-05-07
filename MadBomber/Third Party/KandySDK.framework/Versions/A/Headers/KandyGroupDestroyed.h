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

@interface KandyGroupDestroyed : NSObject <KandyEventProtocol>

/**
 *  Initialization method for KandyGroupParticipantJoined
 *
 *  @param aUuid      the event UUID
 *  @param aTimestamp the event timestamp
 *  @param aGroupId   the group ID
 *  @param aEraser    the group destroyer
 *
 *  @return initialized KandyGroupParticipantJoined
 */
-(instancetype)initWithUUID:(NSString*)aUuid timestamp:(NSDate*)aTimestamp groupId:(KandyRecord*)aGroupId eraser:(KandyRecord*)aEraser isHistoryEvent:(BOOL)isHistoryEvent;
/**
 *  The group ID
 */
@property (nonatomic, readonly) KandyRecord* groupId;
/**
 *  The eraser
 */
@property (nonatomic, readonly) KandyRecord* eraser;

@end
