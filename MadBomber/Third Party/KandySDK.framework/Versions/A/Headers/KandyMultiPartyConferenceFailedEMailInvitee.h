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
 *  An eMail fail invitee object
 */
@interface KandyMultiPartyConferenceFailedEMailInvitee : NSObject

/**
 *  An error describing the failure reason
 */
@property (readonly)NSError * inviteeError;

/**
 *  The invitee eMail
 */
@property (readonly)NSString * eMail;

/**
 *  Create a new KandyMultiPartyConferenceFailedEMailInvitee object
 *
 *  @param error  An error containing the failure reason
 *  @param eMail  The invitee eMail
 *
 *  @return A new KandyMultiPartyConferenceFailedEMailInvitee object
 */
- (instancetype)initWithError:(NSError *)error eMail:(NSString *)eMail;
@end
