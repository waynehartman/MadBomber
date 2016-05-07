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
#import "KandyCallServiceEnums.h"

@interface KandyCallServiceSettings : NSObject

/**
 *  The default camera position when initiating video (on call start or during call). Default value is EKandyCameraPosition_front
 */
@property (nonatomic, assign) EKandyCameraPosition defaultCameraPosition;

/**
 *  The camera orienation support (while video call). Default value is EKandyCameraOrientationSupport_statusBar
 */
@property (nonatomic, assign) EKandyCameraOrientationSupport cameraOrientationSupport;

/**
 *  Should the incoming call be automatically rejected incase already in GSM call. Default value is YES
 */
@property (nonatomic, assign) BOOL shouldRejectIncomingCallsWhileInGSMCall;

/**
 *  YES if the call termination events are being sent by push
 */
@property (assign, nonatomic) BOOL isCallTerminationPushEnabled;

@end
