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

typedef NS_OPTIONS(NSUInteger, EKandyMultiPartyConferenceParticipantCallMediaState) {
    
    /**
     *  <#Description#>
     */
    EKandyMultiPartyConferenceParticipantCallMediaState_none    = 0,
    
    /**
     *  <#Description#>
     */
    EKandyMultiPartyConferenceParticipantCallMediaState_incoming = 1 << 0,
    
    /**
     *  <#Description#>
     */
    EKandyMultiPartyConferenceParticipantCallMediaState_outgoing    = 1 << 1,
    
    /**
     *  <#Description#>
     */
    EKandyMultiPartyConferenceParticipantCallMediaState_incomingAndOutgoing    = EKandyMultiPartyConferenceParticipantCallMediaState_incoming | EKandyMultiPartyConferenceParticipantCallMediaState_outgoing
};

/**
 *  <#Description#>
 */
@protocol KandyMultiPartyConferenceParticipantProtocol <NSObject>

/**
 *  <#Description#>
 */
@property(readonly)NSString * participantID;

/**
 *  <#Description#>
 */
@property(readonly)NSString * nickname;

/**
 *  <#Description#>
 */
@property(readonly)NSUInteger callDuration;

/**
 *  <#Description#>
 */
@property(readonly)EKandyMultiPartyConferenceParticipantCallMediaState audioState;

/**
 *  <#Description#>
 */
@property(readonly)EKandyMultiPartyConferenceParticipantCallMediaState videoState;
@end
