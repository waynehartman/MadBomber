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

/**
 *  Multi party conference room protocol
 */
@protocol KandyMultiPartyConferenceRoomProtocol <NSObject>

/**
 *  The conference ID
 */
@property (readonly) NSString * conferenceID;
/**
 *  The room number - make a free call to this number
 */
@property (readonly) NSString * roomNumber;
/**
 *  The room PSTN number
 */
@property (readonly) NSString * roomPSTNNumber;
/**
 *  The room pin code, will be nil in case there is no pin code
 */
@property (readonly) NSString * pinCode;
@end