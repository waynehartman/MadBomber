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
#import "KandyChatServiceEnums.h"
#import "KandyEventProtocol.h"


/**
 *  An object representing a delivered message, Ack'ed by the recipient
 */
@interface KandyDeliveryAck : NSObject<KandyEventProtocol>

/**
 *  EKandyChatMessageAckErrorType_none or an Ack error
 */
@property (readonly) EKandyChatMessageAckErrorType errorType;

/**
 *  Init a KandyDeliveryAck Object
 *
 *  @param aUuid        The message UUID to Ack
 *  @param aTimestamp   Time of Acking
 *  @param aError       EKandyChatMessageAckErrorType_none or an Ack error
 *
 *  @return A new KandyDeliveryAck instance
 */
-(instancetype)initWithUUID:(NSString*)aUuid andTimeStamp:(NSDate*)aTimestamp andErrorType:(EKandyChatMessageAckErrorType)aError isHistoryEvent:(BOOL)isHistoryEvent;

@end
