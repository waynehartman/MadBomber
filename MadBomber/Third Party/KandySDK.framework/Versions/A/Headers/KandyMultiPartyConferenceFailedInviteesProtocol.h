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

@protocol KandyMultiPartyConferenceFailedInviteesProtocol <NSObject>

/**
 *  Failed invitees by chat. An array of KandyMultiPartyConferenceFailedChatInvitee objects.
 */
@property (readonly)NSArray *failedInviteeByChatArray;
/**
 *  Failed invitees by eMail. An array of KandyMultiPartyConferenceFailedEMailInvitee objects.
 */
@property (readonly)NSArray *failedInviteeByMailArray;
/**
 *  Failed invitees by SMS. An array of KandyMultiPartyConferenceFailedSMSInvitee objects.
 */
@property (readonly)NSArray *failedInviteeBySMSArray;

@end
