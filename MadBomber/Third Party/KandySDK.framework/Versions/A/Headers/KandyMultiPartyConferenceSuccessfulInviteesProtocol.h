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
/**
 *  Holds all the multi party conference successful invitees
 */
@protocol KandyMultiPartyConferenceSuccessfulInviteesProtocol <NSObject>
/**
 *  An array of KandyRecords
 */
@property (readonly)NSArray * inviteeByChatArray;
/**
 *  An array of NSStrings
 */
@property (readonly)NSArray * inviteeByMailArray;
/**
 *  An array of NSStrings
 */
@property (readonly)NSArray * inviteeBySMSArray;

@end
