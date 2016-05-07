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
#import "KandyMultiPartyConferenceRoomProtocol.h"
#import "KandyMultiPartyConferenceFailedInviteesProtocol.h"
#import "KandyMultiPartyConferenceSuccessfulInviteesProtocol.h"
#import "KandyMultiPartyConferenceCallDetailsProtocol.h"
#import "KandyMultiPartyConferenceNotificationDelegate.h"

@class KandyRecord;
@class KandyMultiPartyConferenceInvitees;
@class KandyMultiPartyConferenceParticipantActionParams;
/**
 *  Kandy multi party conference service
 */
@interface KandyMultiPartyConferenceService : NSObject


/**
 *  Register to incoming events the client receives from multi party conference service
 *
 *  @param notificationDelegate the delegate
 */
-(void) registerNotifications:(id<KandyMultiPartyConferenceNotificationDelegate>)notificationDelegate;

/**
 *  Stop listening to multi party conference events
 *
 *  @param notificationDelegate conforms to protocol KandyGroupServiceNotificationDelegate
 */
-(void) unregisterNotifications:(id<KandyMultiPartyConferenceNotificationDelegate>)notificationDelegate;

/**
 *  Create a room and invite users
 *
 *  @param invitees           The invitees
 *  @param responseCallback   A block of code to be called upon response arrival
 */
- (void)createRoomAndInvite:(KandyMultiPartyConferenceInvitees *)invitees
           responseCallback:(void(^)(NSError * error, id<KandyMultiPartyConferenceRoomProtocol> conferenceRoomDetails, id<KandyMultiPartyConferenceSuccessfulInviteesProtocol> successfulInvitees, id<KandyMultiPartyConferenceFailedInviteesProtocol> failedInvitees))responseCallback;

/**
 *  Create a multi party room that users can call
 *
 *  @param responseCallback   A block of code to be called upon response arrival
 */
- (void)createRoomWithResponseCallback:(void(^)(NSError * error, id<KandyMultiPartyConferenceRoomProtocol> conferenceRoomDetails))responseCallback;

/**
 *  Invite users to join a multi party conference room
 *
 *  @param invitees         The invitees
 *  @param conferenceID     The multi party conference ID
 *  @param responseCallback A block of code to be called upon response arrival
 */
- (void)invite:(KandyMultiPartyConferenceInvitees *)invitees conferenceID:(NSString *)conferenceID responseCallback:(void(^)(NSError * error, id<KandyMultiPartyConferenceSuccessfulInviteesProtocol> successfulInvitees, id<KandyMultiPartyConferenceFailedInviteesProtocol> failedInvitees))responseCallback;

/**
 *  Join a multi party conference
 *
 *  @param conferenceID     The conference ID
 *  @param nickName         The name that will be shown in room
 *  @param responseCallback A block of code to be called upon response arrival
 */
-(void)join:(NSString *)conferenceID nickName:(NSString *)nickName responseCallback:(void(^)(NSError * error))responseCallback;

/**
 *  Leave a multi party conference
 *
 *  @param conferenceID The   conference ID
 *  @param responseCallback   A block of code to be called upon response arrival
 */
-(void)leave:(NSString *)conferenceID responseCallback:(void(^)(NSError * error))responseCallback;

/**
 *  Destroy a multi party conference room
 *
 *  @param conferenceID The   conference ID
 *  @param responseCallback   A block of code to be called upon response arrival
 */
-(void)destroyRoom:(NSString *)conferenceID responseCallback:(void(^)(NSError * error))responseCallback;

/**
 *  Get Conference call status
 *
 *  @param conferenceId     The conference ID
 *  @param responseCallback A block of code to be called upon response arrival
 */
-(void) getConferenceCallDetailsWithConferenceID:(NSString*)conferenceID responseCallback:(void(^)(NSError * error, id<KandyMultiPartyConferenceCallDetailsProtocol> conferenceCallDetails))responseCallback;

/**
 *  Change a conference call participant nickname
 *
 *  @param name             The new nickname
 *  @param participantID    The participant ID
 *  @param conferenceID     The conference ID
 *  @param responseCallback A block of code to be called upon response arrival
 */
-(void) updateParticipantName:(NSString *)name participantID:(NSString *)participantID conferenceID:(NSString *)conferenceID responseCallback:(void(^)(NSError * error))responseCallback;

/**
 *  Manipulate a conference call participant with actions
 *
 *  @param participantActionParams An array of actions
 *  @param conferenceId            The conference ID
 *  @param responseCallback        A block of code to be called upon response arrival
 */
-(void) updateRoomParticipantActions:(NSArray<KandyMultiPartyConferenceParticipantActionParams *>*)participantActionParams conferenceID:(NSString *)conferenceID responseCallback:(void(^)(NSError *))responseCallback;

@end
