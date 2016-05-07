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
#import <UIKit/UIKit.h>
#import "KandyCallServiceEnums.h"

@class KandyRecord;

/**
 *  Represent a participant in the call
 */
@protocol KandyCallParticipantProtocol <NSObject>

/**
 *  The participant obj @see KandyRecord
 */
@property(readonly) KandyRecord* record;
/**
 *  Is this participant displaying video
 */
@property(readonly) BOOL isDisplayingVideo;
/**
 *  Is the participant's audio muted
 */
@property(readonly) BOOL isAudioMute;
/**
 *  Is the participant on hold
 */
@property(readonly) BOOL isOnHold;

@end
