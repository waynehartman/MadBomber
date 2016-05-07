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

#import <CoreLocation/CoreLocation.h>
#import "KandyMediaItemProtocol.h"

/**
 * Handles the location media item
 */
@protocol KandyLocationItemProtocol <KandyMediaItemProtocol>

/**
 *  The location
 */
@property (readonly) CLLocation* location;

@end


