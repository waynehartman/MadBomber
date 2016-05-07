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
@class KandyRecord;

/**
 *  A chat fail invitee object
 */
@interface KandyMultiPartyConferenceFailedChatInvitee : NSObject

/**
 *  An error describing the failure reason
 */
@property (readonly)NSError * inviteeError;

/**
 *  The invitee userId
 */
@property (readonly)KandyRecord * destination;

/**
 *  Create a new KandyMultiPartyConferenceFailedChatInvitee object
 *
 *  @param error       An error containing the failure reason
 *  @param destination The invitee
 *
 *  @return A new KandyMultiPartyConferenceFailedChatInvitee object
 */
-(instancetype)initWithError:(NSError *)error destination:(KandyRecord *)destination;
@end
