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
#import "KandyMessageProtocol.h"
#import "KandyRecord.h"

/**
 * This interface handles the range of messages for the Chat
 */
@interface KandyChatMessage : NSObject<KandyMessageProtocol>

/**
 *  Initializing method for KandyChatMessage
 *
 *  @param aMediaItem the Kandy message data
 *  @param aRecipient the recipient
 *
 *  @return initialized KandyChatMessage
 */
-(id)initWithMediaItem:(id<KandyMediaItemProtocol>)aMediaItem recipient:(KandyRecord*)aRecipient;

/**
 *  Initializing method for KandyChatMessage
 *
 *  @param aText the text message data
 *  @param aRecipient the recipient
 *
 *  @return initialized KandyChatMessage
 */
-(id)initWithText:(NSString*)aText recipient:(KandyRecord*)aRecipient;

@end
