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
#import "KandyPresenceProtocol.h"

/**
 KandyPresenceServiceNotificationDelegate - Represents classes that catch the presence response.
 
 In order to get presence responses for your your class must conform to this protocol and register himself as the 
 notificationDelegate (see KandyPresenceServiceNotificationDelegate protocol)
 */
@protocol KandyPresenceServiceNotificationDelegate <NSObject>

/**
 Got presence update from server
 
 @param The updated presence objects (objects are conformed to <KandyPresenceProtocol> protocol)
 */
- (void) presenceArrived:(NSArray *)presenceObjects;
@end
