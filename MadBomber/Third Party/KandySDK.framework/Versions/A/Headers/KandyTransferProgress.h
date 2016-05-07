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

/**
 * This interface shows the file transfer progress
 */
@interface KandyTransferProgress : NSObject

/**
 *  Initialization method for KandytransferProgress
 *
 *  @param transferredSize     bytes transferred
 *  @param expectedSize        expected amount of size
 *  @param transferState       the current status of the transfer state
 *
 *  @return initialized KandytransferProgress with the received params
 */
-(id)initWithTransferredSize:(NSUInteger)transferredSize expectedSize:(NSUInteger)expectedSize transferState:(EKandyMediaTransferState)transferState;

/**
 *  Bytes transferred
 */
@property (readonly) NSUInteger transferredSize;
/**
 *  Expected amount of size (Bytes)
 */
@property (readonly) NSUInteger expectedSize;
/**
 *  Transfer progress percentage
 */
@property (readonly) NSUInteger transferProgressPercentage;
/**
 *  Enum describing the transfer state
 */
@property (readonly) EKandyMediaTransferState transferState;

/**
 *  Check whether the file transfer was completed
 *
 *  @return YES if file transfer was completed
 */
-(BOOL) isDoneTransferring;

@end
