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

#ifndef KandySDK_KandyGroupServiceNotificationDelegate_h
#define KandySDK_KandyGroupServiceNotificationDelegate_h

#import <Foundation/Foundation.h>
@class KandyGroupDestroyed;
@class KandyGroupUpdated;
@class KandyGroupParticipantJoined;
@class KandyGroupParticipantKicked;
@class KandyGroupParticipantLeft;

@protocol KandyGroupServiceNotificationDelegate <NSObject>

/**
 *  Will be called when group is destroyed.
 *  You should mark this event as received in order not to get it again
 *
 *  @param groupDestroyedEvent the event
 */
-(void)onGroupDestroyed:(KandyGroupDestroyed*)groupDestroyedEvent;
/**
 *  Will be called when group is updated
 *  You should mark this event as received in order not to get it again
 *
 *  @param groupUpdatedEvent the event
 */
-(void)onGroupUpdated:(KandyGroupUpdated*)groupUpdatedEvent;
/**
 *  Will be called when group participant joins
 *  You should mark this event as received in order not to get it again
 *
 *  @param groupParticipantJoinedEvent the event
 */
-(void)onParticipantJoined:(KandyGroupParticipantJoined*)groupParticipantJoinedEvent;
/**
 *  Will be called when group participant is kicked
 *  You should mark this event as received in order not to get it again
 *
 *  @param groupParticipantKickedEvent the event
 */
-(void)onParticipantKicked:(KandyGroupParticipantKicked*)groupParticipantKickedEvent;
/**
 *  Will be called when group participant leaves
 *  You should mark this event as received in order not to get it again
 *
 *  @param groupParticipantKickedEvent the event
 */
-(void)onParticipantLeft:(KandyGroupParticipantLeft*)groupParticipantLeftEvent;

@end

#endif
