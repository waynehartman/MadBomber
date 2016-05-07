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
#import "KandyChatServiceNotificationDelegate.h"
#import "KandySMSMessage.h"
#import "KandyChatMessage.h"
#import "KandyTransferProgress.h"
#import "KandyMessageBuilder.h"
#import "KandyChatServiceSettings.h"

/**
 * This interface handles the:
 *   - register/unregister Chat notifications
 *   - sends Kandy message
 *   - sends SMS Kandy message
 *   - downloads media
 *   - downloads media thumbnail
 *   - cancels media download
 *   - marks message as received
 *   - pulls pending chat events from the server
 */
@interface KandyChatService : NSObject

/**
 *  Chat service settings
 */
@property (readonly) KandyChatServiceSettings* settings;

/**
 *  Register the incoming messages the client receives from the service
 *
 *  @param chatServiceResponseDelegate the delegate
 */
-(void) registerNotifications:(NSObject<KandyChatServiceNotificationDelegate>*)notificationDelegate;

/**
 *  Stop listening to chat notifications
 *
 *  @param notificationDelegate conforms to protocol KandyProvisionNotificationDelegate
 */
-(void) unregisterNotifications:(id<KandyChatServiceNotificationDelegate>)notificationDelegate;

/**
 *  Send a KandyMessage
 *
 *  @param kandyChatMessage the Kandy chat message to send
 *  @param progressCallback callback for the progress - will be active if currently sending files (image/video/audio)
 *  @param responseCallback callback for handling the respone - will contain error in case of failure
 */
-(void) sendChat:(KandyChatMessage*)kandyChatMessage progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  Send an SMS
 *
 *  @param kandySMSMessage     the Kandy SMS message to send
 *  @param responseCallback callback for handling the respone - will contain error in case of failure
 */
-(void) sendSMS:(KandySMSMessage*)kandySMSMessage responseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  Download media associated with the received KandyMessage - this method should be used only for non automatic downloads / auto download temporary failure
 *
 *  @param kandyMessage     the KandyMessage for which to download the media 
 *  @param progressCallback callback for the progress
 *  @param responseCallback callback for handling the respone - will contain final absolute downloaded file path / error in case of failure
 */
-(void) downloadMedia:(id<KandyMessageProtocol>)kandyMessage progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, NSString *fileAbsolutePath))responseCallback;

/**
 *  Download thumbnail associated with the received KandyMessage - this method should be used only for non automatic downloads / auto download temporary failure
 *
 *  @param kandyMessage     the KandyMessage for which to download the media 
 *  @param thumbnailSize    EKandyThumbnailSize requested thumbnail size
 *  @param progressCallback callback for the progress
 *  @param responseCallback callback for handling the respone - will contain final absolute downloaded thumbnail path / error in case of failure
 */
-(void) downloadMediaThumbnail:(id<KandyMessageProtocol>)kandyMessage thumbnailSize:(EKandyThumbnailSize)thumbnailSize progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, NSString *fileAbsolutePath))responseCallback;

/**
 *  Cancel the transfer progress
 *
 *  @param kandyMessage KandyMessage associated with the received KandyMessage
 *  @param responseCallback block will contain error in case of failure to cancel
 */
-(void) cancel:(id<KandyMessageProtocol>)kandyMessage responseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  Marks messages as received
 *
 *  @param kandyEvents      an array of KandyEvents to Ack
 *  @param responseCallback a callback containing a possible error
 */
-(void) markAsReceived:(NSArray*)kandyEvents responseCallback:(void(^)(NSError* error))responseCallback __attribute__((deprecated("Use [[Kandy sharedInstance].service.events markEventsAsReceived:responseCallback:] instead")));

/**
 *  Pull pending Chat events from server
 *
 *  @param responseCallback in case of error, get error in the response callback, otherwise get the chat events
 */
-(void) pullEventsWithResponseCallback:(void(^)(NSError* error))responseCallback __attribute__((deprecated("Use [[Kandy sharedInstance].service.events pullPendingEventsWithResponseCallback:] instead")));

@end
