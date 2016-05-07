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
#import "KandyChatServiceEnums.h"
#import "KandyMediaItemProtocol.h"
#import "KandyRecord.h"

/**
 * This interface handles the range of messages for the Chat
 */
@protocol KandyMessageProtocol <KandyEventProtocol>

/**
 *  KandyRecord representing the recipient
 */
@property (nonatomic,strong) KandyRecord* recipient;
/**
 *  The KandyRecord of the sender
 */
@property (nonatomic,strong) KandyRecord* sender;
/**
 *  Type of KandyMessage (EKandyMessageType)
 */
@property (nonatomic,readonly) EKandyMessageType type;
/**
 *  The KandyMessage data
 */
@property (nonatomic,strong) id<KandyMediaItemProtocol> mediaItem;
/**
 *  Whether this KandyMessage is incoming (NO, if outgoing)
 */
@property (nonatomic,assign) BOOL isIncoming;
/**
 *  This dictionary allows you to store any additional data with the KandyMessage
 */
@property (nonatomic,strong) NSMutableDictionary* additionalData;

/**
 *  Update the KandyMessage timestamp
 *  Timestamp will be set when sending the message, unless set menually
 *
 *  @param aTimestamp the timestamp
 */
-(void)updateTimestamp:(NSDate*)aTimestamp;

/**
 *  Update the KandyMessage UUID
 *
 *  @param aUuid the UUID
 */
-(void)updateUUID:(NSString*)aUuid;

@end
