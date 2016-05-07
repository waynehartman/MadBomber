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
#import "KandyCallServiceNotificationDelegate.h"
#import "KandyOutgoingCallProtocol.h"
#import "KandyRecord.h"
#import "KandyCallServiceEnums.h"
#import "KandyCallServiceSettings.h"
/**
 * This interface handles listening to notifications
 */
@interface KandyCallService : NSObject


/**
 *  The available audio outputs (of type EKandyCallAudioRoute)
 */
@property (readonly) NSArray *_Nullable availableAudioOutputs;

/**
 *  YES if currently in call
 */
@property (readonly) BOOL isInCall;

/**
 *  YES if currently in active GSM call
 */
@property (readonly) BOOL isInGSMCall;

/**
 *  Get an array of calls currently in progress
 */
@property (readonly) NSArray<id<KandyCallProtocol>>* _Nullable callsInProgress;

/**
 *  retrive the call by specific opponent
 *
 *  @param remoteRecord KandyRecord - can be found in KandyCallProtocol
 *
 *  @return KandyCallProtocol. in case call is not found for this record, will return nil
 */
-(id<KandyCallProtocol> _Nullable) getCallByRemoteRecord:(KandyRecord*_Nonnull)remoteRecord;

/**
 *  Start listening to notification on call service
 *
 *  @param notificationDelegate conforms to protocol KandyCallServiceNotificationDelegate
 */
-(void) registerNotifications:(id<KandyCallServiceNotificationDelegate> _Nonnull)notificationDelegate;

/**
 *  Stop listening to notification on call service
 *
 *  @param notificationDelegate conforms to protocol KandyCallServiceNotificationDelegate
 */
-(void) unregisterNotifications:(id<KandyCallServiceNotificationDelegate> _Nonnull)notificationDelegate;

/**
 *  Call service settings
 */
-(KandyCallServiceSettings* _Nullable)settings;

/**
 *  Creates and returns an outgoing call object conforms to protocol KandyOutgoingCallProtocol
 *  Please call establishWithResponseBlock to initiate the call
 *  Note - You must set localVideoView and remoteVideoView in order to display video in VoIP call
 *
 *  @param caller       KandyRecord optional - contains the source details, nil for default caller
 *  @param callee       KandyRecord contaning the destination details
 *  @param outgoingCallOptions The options for initialized outgoing call
 *
 *  @return outgoing call object conforms to protocol KandyOutgoingCallProtocol
 */
-(id<KandyOutgoingCallProtocol>_Nullable) createVoipCall:(KandyRecord*_Nullable)caller callee:(KandyRecord*_Nonnull)callee options:(EKandyOutgingVoIPCallOptions)outgoingCallOption __attribute__((deprecated("Use async method instead.")));

/**
 *  Creates and returns an outgoing call object conforms to protocol KandyOutgoingCallProtocol
 *  Please call establishWithResponseBlock to initiate the call
 *  Note - You must set localVideoView and remoteVideoView in order to display video in VoIP call
 *
 *  @param caller               Optional - contains the source details, nil for default caller
 *  @param callee               KandyRecord contaning the destination details
 *  @param outgoingCallOptions  The options for initialized outgoing call
 *  @param responseCallback     Returns outgoing call object, or error if request failed
 */
-(void) createVoipCall:(KandyRecord*_Nullable)caller callee:(KandyRecord*_Nonnull)callee options:(EKandyOutgingVoIPCallOptions)outgoingCallOption responseCallback:(void(^_Nullable)(NSError *_Nullable error, id<KandyOutgoingCallProtocol> _Nullable outgoingCall))responseCallback;

/**
 *  Creates and returns an outgoing PSTN call object conforms to protocol KandyOutgoingCallProtocol
 *  Please call establishWithResponseBlock to initiate the call
 *
 *  @param caller       NSString optional - contains the source details, nil for default caller
 *  @param internationalPhoneNumber international phone number string (e164 format)
 *  @param PSTNCallOption The options for initialized outgoing call
 *
 *  @return outgoing call object conforms to protocol KandyOutgoingCallProtocol
 */
-(id<KandyOutgoingCallProtocol>_Nullable) createPSTNCall:(NSString* _Nullable)caller destination:(NSString*_Nonnull)internationalPhoneNumber options:(EKandyOutgingPSTNCallOptions)PSTNCallOption __attribute__((deprecated("Use async method instead.")));

/**
 *  Creates and returns an outgoing PSTN call object conforms to protocol KandyOutgoingCallProtocol
 *  Please call establishWithResponseBlock to initiate the call
 *
 *  @param caller                   Optional - contains the source details, nil for default caller
 *  @param internationalPhoneNumber International phone number as a string (e164 format)
 *  @param PSTNCallOption           The options for initialized outgoing call
 *  @param responseCallback         Returns outgoing call object, or error if request failed
 */
-(void) createPSTNCall:(NSString* _Nullable)caller destination:(NSString*_Nonnull)internationalPhoneNumber options:(EKandyOutgingPSTNCallOptions)PSTNCallOption responseCallback:(void(^_Nullable)(NSError * _Nullable error, id<KandyOutgoingCallProtocol> _Nullable outgoingCall))responseCallback;

/**
 *  Create SIPTrunk call
 *  Using makeSIPtrunkCall requires a SIP trunk to be configured for your domain in Kandy.
    Note that when a SIP trunk is configured, the makePSTNCall command will be disabled
 *
 *  @param caller       NSString optional - contains the source details, nil for default caller
 *  @param internationalPhoneNumber international phone number string (e164 format)
 *
 *  @return The outgoing call object, will return nil incase callee is invalid
 */
-(id<KandyOutgoingCallProtocol> _Nullable) createSIPTrunkCall:(NSString* _Nullable)caller destination:(NSString* _Nonnull)internationalPhoneNumber __attribute__((deprecated("Use async method instead.")));

/**
 *  Create SIPTrunk call
 *  Using makeSIPtrunkCall requires a SIP trunk to be configured for your domain in Kandy.
 Note that when a SIP trunk is configured, the makePSTNCall command will be disabled
 *
 *  @param caller                   Optional - contains the source details, nil for default caller
 *  @param internationalPhoneNumber International phone number as a string (e164 format)
 *  @param responseCallback         Returns outgoing call object, or error if request failed
 */
-(void) createSIPTrunkCall:(NSString*_Nullable)caller destination:(NSString*_Nonnull)internationalPhoneNumber responseCallback:(void(^_Nullable)(NSError * _Nullable error, id<KandyOutgoingCallProtocol> _Nullable outgoingCall))responseCallback;

/**
 *  Associate DID
 *
 *  @param did              the DID
 *  @param responseCallback a callback that will be called upon completion. Will contain error incase of failure
 */
-(void)associateDID:(NSString*_Nonnull)did responseCallback:(void(^_Nullable)(NSError* _Nullable error))responseCallback;

/**
 *  Disassociate DID
 *
 *  @param did              the DID
 *  @param responseCallback a callback that will be called upon completion. Will contain error incase of failure
 */
-(void)disassociateDID:(NSString*_Nonnull)did responseCallback:(void(^_Nullable)(NSError* _Nullable error))responseCallback;
@end
