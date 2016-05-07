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
#import "KandyMultiPartyConferenceRoomProtocol.h"
#import "KandyMultiPartyConferenceEvent.h"

/**
 *  A multi party conference invite event
 */
@interface KandyMultiPartyConferenceInvite : KandyMultiPartyConferenceEvent

/**
 *  An object containing conference room details
 */
@property (readonly) id<KandyMultiPartyConferenceRoomProtocol> conferenceRoomDetails;

/**
 *  Initialization method for KandyMultiPartyConferenceInvite
 *
 *  @param uuid                  event UUID
 *  @param timestamp             event timestamp
 *  @param sender                the sender
 *  @param destination           the destination
 *  @param conferenceRoomDetails room details - conforms to protocol KandyMultiPartyConferenceRoomProtocol
 *
 *  @return Initialized instance of KandyMultiPartyConferenceInvite object
 */
- (instancetype)initWithUUID:(NSString *)uuid
                   timestamp:(NSDate *)timestamp
                      sender:(KandyRecord *)sender
                 destination:(KandyRecord *)destination
       conferenceRoomDetails:(id<KandyMultiPartyConferenceRoomProtocol>)conferenceRoomDetails
              isHistoryEvent:(BOOL)isHistoryEvent;

@end
