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
#import "KandyEventProtocol.h"
#import "KandyCallServiceEnums.h"
#import "KandyRecord.h"

@interface KandyPendingIncomingCallEvent : NSObject <KandyEventProtocol>

/**
 *  The call ID
 */
@property(readonly, nonatomic) NSString *callId;
/**
 *  The caller record
 */
@property(readonly, nonatomic) KandyRecord *caller;
/**
 *  The call type
 */
@property(readonly, nonatomic) EKandyCallType callType;
/**
 *  Is video call
 */
@property(readonly, nonatomic) BOOL isVideo;
/**
 *  Via (only in PSTN to IP calls, DID number)
 */
@property(readonly, nonatomic) NSString *via;
/**
 *  Actual SDP configuration, or nil if not provided
 */
@property(readonly, nonatomic) NSString * sdp;
/**
 *  The type of the push this event received from
 */
@property(readonly, nonatomic) EKandyEventPushType pushType;
/**
 *  Is event received via passive push
 */
@property(readonly, nonatomic) BOOL isPassive;
/**
 *  YES if this pending incoming call event already expired
 */
@property (readonly, nonatomic) BOOL isExpired;

/**
 *  Initialize Kandy pending incoming call
 *
 *  @param callId           The call ID
 *  @param caller           The caller record
 *  @param callType         The call type
 *  @param isVideo          The call is video call
 *  @param callUUID         The UUID of the incoming call
 *  @param callTimestamp    The timestamp of the incoming call
 *  @param via              The number the call comes through (in PSTN to IP)
 *  @param sdp              The SDP configuration, or nil if not provided
 *  @param pushType         The push type of this event
 *
 *  @return Initialized KandyPendingIncomingCall
 */
-(id) initWithCallId:(NSString*)aCallId caller:(KandyRecord*)aCaller callType:(EKandyCallType)aCallType isVideo:(BOOL)aIsVideo timestamp:(NSDate*)aTimestamp via:(NSString*)aVia sdp:(NSString*)sdp isHistoryEvent:(BOOL)isHistoryEvent pushType:(EKandyEventPushType)pushType;

/**
 *  Make the SDK notify the application about pending incoming call
 *
 *  @param answerType The answer type when the incoming call will connect
 */
-(void) handlePendingIncomingCall:(EKandyIncomingCallAnswerType)answerType;

/**
 *  Update the pending call event with the relevant SDP
 *
 *  @param sdp the SDP to update
 */
-(void) updateSDP:(NSString*)sdp;

@end
