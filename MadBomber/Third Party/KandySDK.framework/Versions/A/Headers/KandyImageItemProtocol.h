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

#import "KandyFileItemProtocol.h"
#import <CoreLocation/CoreLocation.h>
#import "KandyTransferProgress.h"
#import "KandyChatServiceEnums.h"

/**
 * Handles the image media item
 */
@protocol KandyImageItemProtocol <KandyFileItemProtocol>

/**
 *  The capture location
 */
@property (readonly) CLLocation* captureLocation;
/**
 *  The height
 */
@property (readonly) double height;
/**
 *  The width
 */
@property (readonly) double width;
/**
 *  The orientation
 */
@property (readonly) EKandyMediaOrientation orientation;
@end