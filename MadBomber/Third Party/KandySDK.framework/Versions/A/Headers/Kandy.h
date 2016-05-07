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

@protocol KandyLoggerProtocol;
@class KandyAccess;
@class KandyGlobalSettings;
@class KandySessionManagement;
@class KandySubscriberProvision;
@class KandyServices;
@class KandySession;

/**
 * This interface:
 *   - initializes/resets the SDK
 *   - gets the shared instance of the Kandy SDK
 *   - provisions users in the system
 *   - gives access to the system
 *   - gets the wrappers packages to save service method calls
 *   - sets the Global settings for the SDK
 *   - gives session management
 *   - changes logger
 *   - gives SDK version
 */
 
@interface Kandy : NSObject

/**
 *  Initialize the Kandy SDK.
 *
 *  @param domainKey                 The domain key for getting domain services
 *  @param domainSecret              The domain secret for getting domain services. (optional, relevant for provisioning operations)
 */
+(void) initializeSDKWithDomainKey:(NSString*)domainKey domainSecret:(NSString*)domainSecret;
/**
 *  Initialize the Kandy SDK
 *
 *  @param session The user session to use in the SDK. Make sure user session holds the Kandy domain key and secret
 */
+(void) initializeSDKWithKandySession:(KandySession*)session;
/**
 *  Reset the session of the SDK, to let the application create a new shared instance of it
 */
+(void) resetSDKWithResponseCallback:(void(^)())responseCallback;
/**
 *  Get the shared instance of the Kandy SDK. NOTE: You should first call initialize.
 *
 *  @return The Kandy SDK
 */
+(instancetype) sharedInstance;

/**
 *  Provision users in the system
 */
@property (readonly) KandySubscriberProvision *provisioning;
/**
 *  Access to the system
 */
@property (readonly) KandyAccess *access;
/**
 *  Get the wrappers packages to save service method calls
 */
@property (readonly) KandyServices *services;

/**
 *  Global settings for the SDK
 */
@property (readonly) KandyGlobalSettings* globalSettings;
/**
 *  The user session the application uses while using the SDK. The SDK will save here important session data.
 */
@property (readonly) KandySessionManagement* sessionManagement;
/**
 *  Changable logging interface - default uses KandyLogger - you may replaces it with object that conforms to KandyLoggerProtocol
 */
@property (nonatomic, strong) id<KandyLoggerProtocol> loggingInterface;
/**
 *  SDK version
 */
@property (readonly) NSString *version;

@end
