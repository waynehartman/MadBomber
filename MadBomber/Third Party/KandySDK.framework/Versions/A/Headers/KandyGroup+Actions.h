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
#import "KandyGroup.h"
#import "KandyGroupParticipant.h"

@interface KandyGroup (Actions)

/**
 *  Get all admin participants for current group
 *
 *  @return NSArray of KandyGroupParticipants
 */
-(NSArray*)getAdminParticipants;
/**
 *  Get all muted participants for current group
 *
 *  @return NSArray of KandyGroupParticipants
 */
-(NSArray*)getMutedParticipants;
/**
 *  Get all unmuted participants for current group
 *
 *  @return NSArray of KandyGroupParticipants
 */
-(NSArray*)getUnmutedParticipants;
/**
 *  Get self participant in the group
 *
 *  @return KandyGroupParticipant, nil if self not found in group
 */
-(KandyGroupParticipant*)getSelfParticipant;

@end
