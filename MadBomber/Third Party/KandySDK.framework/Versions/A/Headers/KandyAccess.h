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
#import "KandyConnectServiceEnums.h"
#import "KandyAccessNotificationDelegate.h"
#import "KandyUserInfo.h"

/**
 * This interface gets the system connection state, starts/stops listening to access notifications
 * and connects/disconnects to/from the server.
 */
 @interface KandyAccess : NSObject

/**
 *  Get the system registration state
 */
@property (readonly) EKandyRegistrationState registrationState;

/**
 *  Get the system connection state
 */
@property (readonly) EKandyConnectionState connectionState;

/**
 *  Start listening to access notifications
 *
 *  @param notificationDelegate conforms to protocol KandyAccessNotificationDelegate
 */
-(void) registerNotifications:(id<KandyAccessNotificationDelegate>)notificationDelegate;

/**
 *  Stop listening to access notifications
 *
 *  @param notificationDelegate conforms to protocol KandyAccessNotificationDelegate
 */
-(void) unregisterNotifications:(id<KandyAccessNotificationDelegate>)notificationDelegate;

/**
 *  Connect to the server
 *
 *  @param userInfo The user to connect the server and the push server
 *  @param responseCallback Callback, which returns if there was error connecting the server
 */
-(void) login:(KandyUserInfo*)userInfo responseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  Connect to the server (with access token)
 *
 *  @param userAccessToken  the user access token to login with
 *  @param responseCallback responseCallback Callback, which returns if there was error connecting the server
 */
-(void) loginWithAccessToken:(NSString*)userAccessToken responseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  Disconnect the server
 *
 *  @param userInfo   The user to logout. If nil, logout the currently logged in user
 *  @param responseCallback Callback, which returns when disconnect is finished
 */
-(void) logoutWithResponseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  Renew expired user session
 *
 *  @param responseCallback Returns an error if such occured
 */
-(void) renewExpiredSession:(void(^)(NSError* error))responseCallback;

/**
 *  When setting in your application UIApllication setKeepAliveTimeout:handler: set this method as a part of the handler code
 * this will enable Kandy to verify its connection
 */
-(void) keepAliveTimeoutHandler;

@end
