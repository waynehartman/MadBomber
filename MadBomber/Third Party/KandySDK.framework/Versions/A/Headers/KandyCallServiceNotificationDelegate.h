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
#import "KandyCallProtocol.h"
#import "KandyIncomingCallProtocol.h"
#import "KandyMissedCall.h"
#import "KandyPendingVoiceMail.h"

@protocol KandyCallServiceNotificationDelegate <NSObject>

#pragma mark - call notifications
/**
 *  Got incoming call
 *
 *  @param call the incoming call object
 */
-(void) gotIncomingCall:(id<KandyIncomingCallProtocol>)call;
/**
 *  Got missed call.
 *  Should mark the missed Call as recieved in order notify the server that we got it.
 *
 *  @param call the missed call object
 */
-(void) gotMissedCall:(KandyMissedCall*)missedCall;
/**
 *  Call state changed
 *
 *  @param callState the new call state
 *  @param call      the call object
 */
-(void) stateChanged:(EKandyCallState)callState forCall:(id<KandyCallProtocol>)call;
/**
 *  Call participants changed. Relevant for conference calls
 *
 *  @param participants the current participants in the call
 *  @param call         the call object
 */
-(void) participantsChanged:(NSArray*)participants forCall:(id<KandyCallProtocol>)call;
/**
 *  Video state changed for the call
 *
 *  @param call the call object
 */
-(void) videoStateChangedForCall:(id<KandyCallProtocol>)call;
//#warning Yoni - support transfered call when getting it from the SPiDR
///**
// *  The call has been transfered to new callee
// *
// *  @param call the call object
// */
//-(void) callTransfered:(id<KandyCallProtocol>)call;
/**
 *  The orientation for the images we get from the video call changed
 *
 *  @param newImageOrientation the new image orientation
 *  @param call                the call obj
 */
-(void) videoCallImageOrientationChanged:(EKandyVideoCallImageOrientation)newImageOrientation forCall:(id<KandyCallProtocol>)call;
/**
 *  The outgoing audio route changed
 *
 *  @param audioRoute the new audio route
 *  @param call       the call object
 */
-(void) audioRouteChanged:(EKandyCallAudioRoute)audioRoute forCall:(id<KandyCallProtocol>)call;
/**
 *  Available audio outputs is currently changed
 *
 *  @param updatedAvailableAudioOutputs The updated available audio outputs (of type EKandyCallAudioRoute)
 */
-(void) availableAudioOutputChanged:(NSArray*)updatedAvailableAudioOutputs;

#pragma mark - GSM call notifications
/**
 *  Got incoming GSM call. Waiting the user to accept the call
 */
-(void) GSMCallIncoming;
/**
 *  GSM call in dialing state, waiting for destination to accept the call
 */
-(void) GSMCallDialing;
/**
 *  The GSM call is connected
 */
-(void) GSMCallConnected;
/**
 *  The GSM call ended
 */
-(void) GSMCallDisconnected;

#pragma mark - Voice mail notifications
/**
 *  Got pending voicemail message
 *  Should mark the pendingVoiceMail as recieved in order notify the server that we got it.
 *
 *  @param pendingVoiceMail the pendingVoiceMail object
 */
-(void)gotPendingVoiceMailMessage:(KandyPendingVoiceMail*)pendingVoiceMail;

@end
