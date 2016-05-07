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

#ifndef KandyAnalyticsEnums_h
#define KandyAnalyticsEnums_h

static NSString * const KandyAnalyticsServiceErrorDomain = @"AnalticsServiceErrorDomain";

typedef NS_ENUM(NSInteger, EKandyReportSeverity)
{
    EKandyReportSeverity_none = 0,
    EKandyReportSeverity_assert,
    EKandyReportSeverity_log,
    EKandyReportSeverity_debug,
    EKandyReportSeverity_warning,
    EKandyReportSeverity_verbose,
    EKandyReportSeverity_last
};

typedef NS_ENUM(NSInteger, EKandyAnalyticsReportType){
    EKandyAnalyticsReportType_registeration, // action on registration phase
    EKandyAnalyticsReportType_chat,// chat/message action
    EKandyAnalyticsReportType_call, // call action (voice or video)
    EKandyAnalyticsReportType_last,
};

typedef NS_ENUM(NSInteger, EKandyAnalyticsClientAction){
    /**
     * register spidr started
     */
    EKandyAnalyticsClientAction_register,
    /**
     *  got succeed for register spidr
     */
    EKandyAnalyticsClientAction_registerSucceeded,
    /**
     *  got failed for register spidr
     */
    EKandyAnalyticsClientAction_registerFail,
    /**
     *  got connected
     */
    EKandyAnalyticsClientAction_socketConnected,
    /**
     *  the client got voip push
     */
    EKandyAnalyticsClientAction_pushReceived,
    /**
     *  incoming call from spidr
     */
    EKandyAnalyticsClientAction_callIncomming,
    /**
     *  forward call called
     */
    EKandyAnalyticsClientAction_callForward,
    /**
     *  accept call started
     */
    EKandyAnalyticsClientAction_callAccept,
    /**
     *  accept call finished succesfuly
     */
    EKandyAnalyticsClientAction_callAcceptSuccess,
    /**
     *  accept call failed
     */
    EKandyAnalyticsClientAction_callAcceptFail,
    /**
     *  establish call started
     */
    EKandyAnalyticsClientAction_callEstablish,
    /**
     *  establish call completed successfully
     */
    EKandyAnalyticsClientAction_callEstablishSuccess,
    /**
     *  establish call failed
     */
    EKandyAnalyticsClientAction_callEstablishFail,
    /**
     *  call was terminated
     */
    EKandyAnalyticsClientAction_callTerminated,
    /**
     *  call state was changed
     */
    EKandyAnalyticsClientAction_callStateChanged,
    
    /**
     *  The client send to the server wakeup message before call
     */
    EKandyAnalyticsClientAction_callSendWakeupMessage,
    
    /**
     *   The client received from the server wakeup message before call
     */
    EKandyAnalyticsClientAction_callReceiveWakeupMessage,
    
    /**
     *  call was ignored
     */
    EKandyAnalyticsClientAction_callIgnore,
    /**
     *  ignore call success
     */
    EKandyAnalyticsClientAction_callIgnoreSucceed,
    /**
     *  ignre call failed
     */
    EKandyAnalyticsClientAction_callIgnoreFailed,
    /**
     *  call was rejected
     */
    EKandyAnalyticsClientAction_callReject,
    /**
     *  reject call success
     */
    EKandyAnalyticsClientAction_callRejectSucceed,
    /**
     *  reject call failed
     */
    EKandyAnalyticsClientAction_callRejectFailed,
    /**
     *  call unhold
     */
    EKandyAnalyticsClientAction_callUnhold,
    /**
     *  unhold success
     */
    EKandyAnalyticsClientAction_callUnHoldSucceed,
    /**
     *  unhold failed
     */
    EKandyAnalyticsClientAction_callUnholdFailed,
    /**
     *  call hold
     */
    EKandyAnalyticsClientAction_callHold,
    /**
     *  hold success
     */
    EKandyAnalyticsClientAction_callHoldSucceed,
    /**
     *  hold failed
     */
    EKandyAnalyticsClientAction_callHoldFailed,
    /**
     *  hangup call
     */
    EKandyAnalyticsClientAction_callHangup,
    /**
     *  send DTMF
     */
    EKandyAnalyticsClientAction_callSendDTMF,
    /**
     *  tranfer call
     */
    EKandyAnalyticsClientAction_callTransfer,
    /**
     *  transfer success
     */
    EKandyAnalyticsClientAction_callTransferSucceed,
    /**
     *  transfer failed
     */
    EKandyAnalyticsClientAction_callTransferFailed
  
};

#if defined __cplusplus
extern "C" {
#endif

// methods to convert enums to strings
NSString* EKandyAnalyticsReportTypeToString(EKandyAnalyticsReportType type);
NSString* EKandyAnalyticsClientActionToString(EKandyAnalyticsClientAction action);
NSString* KandyAnalyticsReportSeverityToString(EKandyReportSeverity severity);

#if defined __cplusplus
};
#endif

#endif /* KandyAnalyticsEnums_h */
