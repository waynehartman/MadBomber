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

@interface KandyMissedCall : NSObject<KandyEventProtocol>

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
 *  Is event received via passive push
 */
@property(readonly, nonatomic) EKandyEventPushType pushType;
/**
 *  Is event received via passive push
 */
@property(readonly, nonatomic) BOOL isPassive;

/**
 *  Initialize KandyMissedCall
 *
 *  @param callId            Id of the missed call
 *  @param aUUID             UUID of the missed call
 *  @param auserId           The caller userId
 *  @param aCallType         The call type
 *  @param aIsVideo          Is missed call was with video
 *  @param aCallTimestamp    The timestamp of the missed call
 *  @param aVia              The number the call comes through (in PSTN to IP)
 *  @param pushType          The type of the push this event received from
 *
 *  @return Initialized KandyMissedCall
 */
-(id) initWithCallId:(NSString*)callId uuid:(NSString*)aUUID caller:(KandyRecord*)aCaller callType:(EKandyCallType)aCallType isVideo:(BOOL)aIsVideo timestamp:(NSDate*)aTimestamp via:(NSString*)aVia isHistoryEvent:(BOOL)isHistoryEvent pushType:(EKandyEventPushType)pushType;


@end
