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
#import "KandyImageItemProtocol.h"
#import "KandyRecord.h"

@interface KandyGroupUpdated : NSObject <KandyEventProtocol>

/**
 *  Initialization method for KandyGroupUpdated
 *
 *  @param aUuid        the event UUID
 *  @param aTimestamp   the event timestamp
 *  @param aGroupId     the group ID
 *  @param aGroupName   the group name
 *  @param aGroupImage  the group image
 *  @param anUpdater    the KandyRecord that made the change
 *
 *  @return initialized KandyGroupUpdated
 */
-(instancetype)initWithUUID:(NSString*)aUuid timestamp:(NSDate*)aTimestamp groupId:(KandyRecord*)aGroupId groupName:(NSString*)aGroupName groupImage:(id<KandyImageItemProtocol>)aGroupImage updater:(KandyRecord*)anUpdater isHistoryEvent:(BOOL)isHistoryEvent;
/**
 *  The group ID
 */
@property (nonatomic, readonly) KandyRecord* groupId;
/**
 *  The group name - This value may be nil in case name was not updated
 */
@property (nonatomic, readonly) NSString* groupName;
/**
 *  The group image item - This value may be nil in case image was not updated
 */
@property (nonatomic, readonly) id<KandyImageItemProtocol> groupImage;
/**
 *  The KandyRecord that made the change
 */
@property (nonatomic, readonly) KandyRecord* updater;

@end
