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
#import "KandyDomain.h"
#import "KandyUserInfo.h"
#import "KandyServerRegistrationConfigurationProtocol.h"

/**
 * This interface handles the:
 *     -  KandyDomain information
 *     -  list of all provisioned/logged in users
 *     -  initialization of the user session
 *     -  Serialize/Deseralize the Session to/from data
 */
 
@interface KandySession : NSObject <NSCoding>

/**
 *  The KandyDomain information
 *  @see KandyDomain.h
 */
@property(nonatomic, strong) KandyDomain* kandyDomain;

/**
 *  Current server configuation
 */
@property(nonatomic, strong) id<KandyServerRegistrationConfigurationProtocol> serverConfiguration;
 
/**
 *  Current push server configuration
 */
@property(nonatomic, strong) id<KandyServerRegistrationConfigurationProtocol> pushConfiguration;

/**
 *  All provisioned users of type KandyUserInfo, that the user provisioned with the SDK
 *  @see KandyUserInfo.h
 */
@property(nonatomic, strong) NSMutableDictionary* provisionedUsers;
/**
 *  Currently loggedIn user info
 *  @see KandyUserInfo.h
 */
@property(nonatomic, strong) KandyUserInfo* currentUser;
/**
 *  The difference between the system time and the received server timestamp in seconds.
 *  Add this value to all received events timestamp
 *  This value is updated upon login success to Kandy
 */
@property(nonatomic, assign) NSTimeInterval UTCTimestampCorrection;

/**
 *  Init the user session
 *
 *  @param key    The Kandy domain key
 *  @param secret The Kandy domain secret
 *
 *  @return Initialized KandySession obj
 */
-(id) initWithDomainKey:(NSString*)key andDomainSecret:(NSString*)secret;

/**
 *  Init the user session
 *
 *  @param key    The Kandy domain key
 *
 *  @return Initialized KandySession obj
 */
-(id) initWithDomainKey:(NSString*)key;

/**
 *  Serialize the Session to data
 *
 *  @return The data we got from de-serilizing the data
 */
-(NSData*) serialize;
/**
 *  Deserialze the Session from data
 *
 *  @param SessionData The data from which to de-serialize 
 */
-(void) deserialize:(NSData*)sessionData;

@end
