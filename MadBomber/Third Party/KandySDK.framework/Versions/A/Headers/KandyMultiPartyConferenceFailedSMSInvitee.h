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
 *  A SMS fail invitee object
 */
@interface KandyMultiPartyConferenceFailedSMSInvitee : NSObject

/**
 *  An error describing the failure reason
 */
@property (readonly)NSError * inviteeError;

/**
 *  The invitee PSTN number
 */
@property (readonly)NSString * PSTNNumber;

/**
 *  Create a new KandyMultiPartyConferenceFailedSMSInvitee object
 *
 *  @param error        An error containing the failure reason
 *  @param PSTNNumber  The invitee PSTN number
 *
 *  @return A new KandyMultiPartyConferenceFailedSMSInvitee object
 */
-(instancetype)initWithError:(NSError *)error PSTNNumber:(NSString *)PSTNNumber;
@end
