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

#ifndef KandyMultiPartyConferenceServiceEnums_h
#define KandyMultiPartyConferenceServiceEnums_h

static NSString * const KandyMultiPartConferenceServiceErrorDomain = @"MultiPartiConferenceServiceErrorDomain";

typedef NS_ENUM(NSInteger,EKandyMultiPartyConferenceCreateRoomError)
{
    EKandyMultiPartyConferenceCreateRoomError_unknown
};

typedef NS_ENUM(NSInteger,EKandyMultiPartyConferenceInviteError)
{
    EKandyMultiPartyConferenceInviteError_unknown
};

typedef NS_ENUM(NSUInteger, EKandyMultiPartyConferenceAction) {
    
    /**
     *  None
     */
    EKandyMultiPartyConferenceAction_none = 0,
    /**
     *  Mute action
     */
    EKandyMultiPartyConferenceAction_mute,
    /**
     *  Unmute action
     */
    EKandyMultiPartyConferenceAction_unmute,
    /**
     *  Enable video action
     */
    EKandyMultiPartyConferenceAction_enableVideo,
    /**
     *  Disable video action
     */
    EKandyMultiPartyConferenceAction_disableVideo,
    /**
     *  Enter hold action
     */
    EKandyMultiPartyConferenceAction_hold,
    /**
     *  Exit hold action
     */
    EKandyMultiPartyConferenceAction_unhold,
    /**
     *  Remove participant action
     */
    EKandyMultiPartyConferenceAction_remove,
};
#endif/* KandyMultiPartyConferenceServiceEnums_h */