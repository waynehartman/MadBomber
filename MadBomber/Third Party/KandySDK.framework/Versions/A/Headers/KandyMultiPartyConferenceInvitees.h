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
 *  Holds all the multi party conference invitees
 */
@interface KandyMultiPartyConferenceInvitees : NSObject
/**
 *  An array representing user ID's
 */
@property (nonatomic,copy)NSArray<KandyRecord*> * inviteeByChatArray;
/**
 *  An array representing eMails
 */
@property (nonatomic,copy)NSArray<NSString*> * inviteeByMailArray;
/**
 *  An array representing phone numbers
 */
@property (nonatomic,copy)NSArray<NSString*> * inviteeBySMSArray;

/**
 *  Create a new KandyMultiPartyConferenceInvitees object
 *
 *  @param chatInvitees    An array of KandyReord objects, for contacts that will be invited by chat message
 *  @param mailInvitees      An array of NSString objects, for contacts that will be invited by SMS message
 *  @param SMSInvitees       An array of NSString objects, for contacts that will be invited by eMail
 *
 *  @return A new KandyMultiPartyConferenceInvitees object
 */
- (instancetype)initWithChatInvitees:(NSArray<KandyRecord*> *)chatInvitees
                        mailInvitees:(NSArray<NSString*> *)mailInvitees
                         SMSInvitees:(NSArray<NSString*> *)SMSInvitees;
@end
