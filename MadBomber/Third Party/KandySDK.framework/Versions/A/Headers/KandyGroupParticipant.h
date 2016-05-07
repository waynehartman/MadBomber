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
#import "KandyRecord.h"

@interface KandyGroupParticipant : NSObject

/**
 *  Initialization method for KandyGroupChatParticipent
 *
 *  @param kandyRecord the KandyRecord associated with this KandyGroupChatParticipent
 *
 *  @return initialized KandyGroupChatParticipent
 */
-(instancetype)initWithKandyRecord:(KandyRecord*)kandyRecord;
/**
 *  The KandyRecord associated with this KandyGroupChatParticipent
 */
@property (nonatomic, strong) KandyRecord* kandyRecord;
/**
 *  YES if this KandyGroupChatParticipent is muted
 */
@property (nonatomic, assign) BOOL isMuted;
/**
 *  YES if this KandyGroupChatParticipent is admin
 */
@property (nonatomic, assign) BOOL isAdmin;

@end
