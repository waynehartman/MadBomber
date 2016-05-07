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
#import "KandyMultiPartyConferenceParticipantProtocol.h"

/**
 *  Containing data about the multi party conference call
 */
@protocol KandyMultiPartyConferenceCallDetailsProtocol <NSObject>

/**
 *  Containg data about a conference room
 */
@property (readonly) id<KandyMultiPartyConferenceRoomProtocol> conferenceRoom;

/**
 *  Conference call duration
 */
@property (readonly) NSUInteger duration;

/**
 *  An array of conference call articipants
 */
@property (readonly) NSArray<id<KandyMultiPartyConferenceParticipantProtocol>>* participants;

/**
 *  An array administrator ID's
 */
@property (readonly) NSArray<NSString*>* admins;

@end
