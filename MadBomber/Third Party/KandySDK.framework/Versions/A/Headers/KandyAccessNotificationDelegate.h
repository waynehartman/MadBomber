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

#import "KandyConnectServiceEnums.h"
#import "KandyServerRegistrationConfigurationProtocol.h"

@protocol KandyAccessNotificationDelegate <NSObject>

/**
 *  Notification when the connection state to the server changes
 *
 *  @param connectionState The new connection status
 */
-(void) connectionStatusChanged:(EKandyConnectionState)connectionState;
/**
 *  Notification when the registration state to the server changes
 *
 *  @param registrationState The new registration status
 */
-(void) registrationStatusChanged:(EKandyRegistrationState)registrationState;
/**
 *  The user is not valid anymore, Kandy must get a new user
 */
-(void) gotInvalidUser:(NSError*)error;

/**
 *  The session has expired
 */
-(void) sessionExpired:(NSError*)error;

/**
 *  The Kandy SDK version in not supported
 */
-(void) SDKNotSupported:(NSError*)error;

@optional
/**
 *  Certificate error will be triggered incase your certificate expired or you have a MIT
 *  It is recommended to implement this if isEnableCertificatePinning under globalSettings is YES
 */
-(void) certificateError:(NSError*)error;

/**
 *  Invoked when the server configuration is updated
 */
-(void) serverConfigurationReceived:(id<KandyServerRegistrationConfigurationProtocol>)serverConfiguration;

@end
