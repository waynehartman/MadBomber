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

typedef NS_ENUM(NSUInteger, EKandyEventType) {
    /**
     *  Kandy event which the SDK does not recognize
     */
    EKandyEventType_unknown = 0,
    /**
     *  Fetch the messages from the server
     */
    EKandyEventType_fetchPendingMessages,
    /**
     *  New incoming message arrived
     */
    EKandyEventType_message,
    /**
     *  Sent message was received by other client
     */
    EKandyEventType_messageDelivered,
    /**
     *  Missed call event
     */
    EKandyEventType_missedCall,
    /**
     *  Incoming call
     */
    EKandyEventType_incomingCall,
    /**
     *  Group destroyed
     */
    EKandyEventType_groupDestroyed,
    /**
     *  Group updated
     */
    EKandyEventType_groupUpdated,
    /**
     *  Group participant joined
     */
    EKandyEventType_groupParticipantJoined,
    /**
     *  Group participant kicked
     */
    EKandyEventType_groupParticipantKicked,
    /**
     *  Group participant left
     */
    EKandyEventType_groupParticipantLeft,
    /**
     *  Pending voice mail event
     */
    EKandyEventType_pendingVoiceMail,
    /**
     Call already answered on other device
     */
    EKandyEventType_answeredCall,
    /**
     *  Custom private event, will not dispatched to application
     */
    EKandyEventType_privateEvent,
    /**
     *  Invite to join multi party conference room
     */
    EKandyEventType_multiPartyConferenceInvite,
    /**
     *  Multi party conference participant enter into mute
     */
    EKandyEventType_multiPartyConferenceParticipantMute,
    /**
     *  Multi party conference participant exit from mute
     */
    EKandyEventType_multiPartyConferenceParticipantUnmute,
    /**
     *  Multi party conference participant joined
     */
    EKandyEventType_multiPartyConferenceParticipantJoinedRoom,
    /**
     *  Multi party conference participant left
     */
    EKandyEventType_multiPartyConferenceParticipantLeftRoom,
    /**
     *  Multi party conference participant name changed
     */
    EKandyEventType_multiPartyConferenceParticipantNameChange,
    /**
     *  Multi party conference participant video enbaled
     */
    EKandyEventType_multiPartyConferenceParticipantVideoEnable,
    /**
     *  Multi party conference participant video disabled
     */
    EKandyEventType_multiPartyConferenceParticipantVideoDisabled,
    /**
     *  Multi party conference participant entered into hold
     */
    EKandyEventType_multiPartyConferenceParticipantHold,
    /**
     *  Multi party conference participant exit from hold
     */
    EKandyEventType_multiPartyConferenceParticipantUnhold,
    /**
     *  Multi party conference participant participant removed
     */
    EKandyEventType_multiPartyConferenceParticipantRemoved,
    /**
     *  Multi party conference room removed
     */
    EKandyEventType_multiPartyConferenceRoomRemoved
    
};

/**
 *  The push type for event
 */
typedef NS_ENUM(NSUInteger, EKandyEventPushType) {
    /**
     *  Push type is unknown
     */
    EKandyEventPushType_none = 0,
    /**
     *  Event should be treated as "passive" event (in case of MDL)
     */
    EKandyEventPushType_passive = 1,
    /**
     *  Event should be treated as "active" event
     */
    EKandyEventPushType_active  = 2,
};

/**
 *  Represents class for message we can get / send to the Kandy system
 */
@protocol KandyEventProtocol <NSObject>

@required
/**
 *  Unique identifier of the KandyEvent
 */
@property (readonly) NSString* uuid;
/**
 *  KandyEvent timestamp
 */
@property (readonly) NSDate* timestamp;
/**
 *  Type of KandyEvent (EKandyEventType)
 */
@property (readonly) EKandyEventType eventType;
/**
 *  Flag indicating that the event is pulled from history
 */
@property (readonly) BOOL isHistoryEvent;
/**
 *  Mark the event as recieved
 *
 *  @param responseCallback Callback for error if failed to mark
 */
-(void) markAsReceivedWithResponseCallback:(void(^)(NSError* error))responseCallback;

@end
