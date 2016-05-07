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
@class KandyMultiPartyConferenceParticipantMute;
@class KandyMultiPartyConferenceParticipantUnmute;
@class KandyMultiPartyConferenceParticipantJoined;
@class KandyMultiPartyConferenceParticipantLeft;
@class KandyMultiPartyConferenceParticipantHold;
@class KandyMultiPartyConferenceParticipantUnhold;
@class KandyMultiPartyConferenceParticipantNameChanged;
@class KandyMultiPartyConferenceParticipantRemoved;
@class KandyMultiPartyConferenceParticipantVideoEnabled;
@class KandyMultiPartyConferenceParticipantVideoDisabled;
@class KandyMultiPartyConferenceRoomRemoved;
@class KandyMultiPartyConferenceInvite;

@protocol KandyMultiPartyConferenceNotificationDelegate <NSObject>

/**
 *  Will be called when invite to multi party conference room arrived.
 *  You should mark this event as received in order not to get it again
 *
 *  @param inviteEvent the event
 */
-(void)onInviteReceived:(KandyMultiPartyConferenceInvite*)inviteEvent;

@optional
/**
 *  Will be called when a multi party conference was destroyed
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onConferenceRoomRemovedReceived:(KandyMultiPartyConferenceRoomRemoved*)event;
/**
 *  Will be called when a multi party conference participant audio was muted
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantMuteReceived:(KandyMultiPartyConferenceParticipantMute*)event;
/**
 *  Will be called when a multi party conference participant audio was unmuted
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantUnmuteReceived:(KandyMultiPartyConferenceParticipantUnmute*)event;
/**
 *  Will be called when a multi party conference participant joined the room
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantJoinedRoomReceived:(KandyMultiPartyConferenceParticipantJoined*)event;
/**
 *  Will be called when a multi party conference participant left the room
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantLeftRoomReceived:(KandyMultiPartyConferenceParticipantLeft*)event;
/**
 *  Will be called when a multi party conference participant name was changed
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantNameChangeReceived:(KandyMultiPartyConferenceParticipantNameChanged*)event;
/**
 *  Will be called when a multi party conference participant video was enabled
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantVideoEnableReceived:(KandyMultiPartyConferenceParticipantVideoEnabled*)event;
/**
 *  Will be called when a multi party conference participant video was disabled
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantVideoDisableReceived:(KandyMultiPartyConferenceParticipantVideoDisabled*)event;
/**
 *  Will be called when a multi party conference participant enter into hold
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantHoldReceived:(KandyMultiPartyConferenceParticipantHold*)event;
/**
 *  Will be called when a multi party conference participant exit from hold
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantUnholdReceived:(KandyMultiPartyConferenceParticipantUnhold*)event;
/**
 *  Will be called when a multi party conference participant was kicked from the room
 *  You should mark this event as received in order not to get it again
 *
 *  @param event the event
 */
-(void)onParticipantRemovedReceived:(KandyMultiPartyConferenceParticipantRemoved*)event;
@end
