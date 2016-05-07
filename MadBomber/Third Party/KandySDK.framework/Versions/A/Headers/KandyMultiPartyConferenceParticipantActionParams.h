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
#import "KandyMultiPartyConferenceServiceEnums.h"

/**
 *  Contains data about a participant control action
 */
@interface KandyMultiPartyConferenceParticipantActionParams : NSObject

/**
 *  The participant ID
 */
@property(nonatomic,strong)NSString *  participantID;
/**
 *  The action type
 */
@property(nonatomic,assign)EKandyMultiPartyConferenceAction action;

/**
 *  Create a KandyMultiPartyConferenceParticipantActionParams object
 *
 *  @param participantID The participant ID
 *  @param action        The action type
 *
 *  @return A new KandyMultiPartyConferenceParticipantActionParams object
 */
- (instancetype)initWithParticipantID:(NSString *)participantID action:(EKandyMultiPartyConferenceAction)action;
@end
