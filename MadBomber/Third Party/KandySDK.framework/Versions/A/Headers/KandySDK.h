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

#ifndef KandySDK_KandySDK_h
#define KandySDK_KandySDK_h

#import "Kandy.h"

#import "KandyUserInfo.h"
#import "KandyMDLInfo.h"
#import "KandyUserProvisionInfo.h"
#import "KandyRecord.h"
#import "KandyAreaCode.h"
#import "KandySession.h"
#import "KandyDomain.h"
#import "KandyEventProtocol.h"
#import "KandyMessageProtocol.h"
#import "KandySMSMessage.h"
#import "KandyChatMessage.h"
#import "KandyDeliveryAck.h"
#import "KandyGroupDestroyed.h"
#import "KandyGroupUpdated.h"
#import "KandyGroupParticipantJoined.h"
#import "KandyGroupParticipantKicked.h"
#import "KandyGroupParticipantLeft.h"
#import "KandyPendingIncomingCallEvent.h"
#import "KandyMissedCall.h"
#import "KandyPendingVoiceMail.h"
#import "KandyTransferProgress.h"
#import "KandyMediaUtils.h"
#import "KandyVideoCompressionSettings.h"
#import "KandyGroupParams.h"
#import "KandyGroup.h"
#import "KandyGroup+Actions.h"
#import "KandyLocationParams.h"

#import "KandyCredit.h"
#import "KandyBillingPackage.h"
#import "KandyBillingPackageProperty.h"


#import "KandyAudioItemProtocol.h"
#import "KandyVideoItemProtocol.h"
#import "KandyImageItemProtocol.h"
#import "KandyMediaItemProtocol.h"
#import "KandyTextItemProtocol.h"
#import "KandyLocationItemProtocol.h"
#import "KandyCustomItemProtocol.h"
#import "KandyFileItemProtocol.h"

#import "KandyPresenceProtocol.h"
#import "KandyLoggerProtocol.h"
#import "KandyAccess.h"
#import "KandyGlobalSettings.h"
#import "KandySessionManagement.h"
#import "KandySubscriberProvision.h"
#import "KandyServices.h"
#import "KandyServiceErrors.h"
#import "KandyMessageBuilder.h"

#import "KandyContactProtocol.h"
#import "KandyContactRecordProtocol.h"
#import "KandyPhoneContactRecord.h"
#import "KandyEmailContactRecord.h"
#import "KandyAddressContactRecord.h"
#import "KandySocialProfileContactRecord.h"
#import "KandyContactParams.h"

#import "KandyMultiPartyConferenceRoomProtocol.h"
#import "KandyMultiPartyConferenceParams.h"
#import "KandyMultiPartyConferenceFailedInviteesProtocol.h"
#import "KandyMultiPartyConferenceInvite.h"
#import "KandyMultiPartyConferenceParticipantJoined.h"
#import "KandyMultiPartyConferenceParticipantLeft.h"
#import "KandyMultiPartyConferenceParticipantNameChanged.h"
#import "KandyMultiPartyConferenceParticipantMute.h"
#import "KandyMultiPartyConferenceParticipantUnmute.h"
#import "KandyMultiPartyConferenceParticipantVideoEnabled.h"
#import "KandyMultiPartyConferenceParticipantVideoDisabled.h"
#import "KandyMultiPartyConferenceParticipantHold.h"
#import "KandyMultiPartyConferenceParticipantUnhold.h"
#import "KandyMultiPartyConferenceParticipantRemoved.h"
#import "KandyMultiPartyConferenceRoomRemoved.h"
#import "KandyMultiPartyConferenceInvitees.h"
#import "KandyMultiPartyConferenceFailedChatInvitee.h"
#import "KandyMultiPartyConferenceFailedSMSInvitee.h"
#import "KandyMultiPartyConferenceFailedEMailInvitee.h"
#import "KandyMultiPartyConferenceSuccessfulInviteesProtocol.h"
#import "KandyMultiPartyConferenceParticipantActionParams.h"
#import "KandyMultiPartyConferenceCallDetailsProtocol.h"
#import "KandyMultiPartyConferenceParticipantProtocol.h"

#import "KandyCallReceiveAudioRTPStatisticsProtocol.h"
#import "KandyCallSendAudioRTPStatisticsProtocol.h"
#import "KandyCallSendVideoRTPStatisticsProtocol.h"
#import "KandyCallReceiveVideoRTPStatisticsProtocol.h"
#import "KandyCallGeneralVideoRTPStatisticsProtocol.h"
#import "KandyCallGeneralAudioRTPStatisticsProtocol.h"

#endif
