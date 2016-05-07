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
 *  The domain access token key (for dataByKey)
 */
static NSString * const kKandyDomainAccessTokenKey = @"kandyDomain_accessToken";
/**
 *  The domain image key (for dataByKey)
 */
static NSString * const kKandyDomainImageURIKey = @"kandyDomain_imageURI";

/**
 KandyDomainData object holds the data about the domain
 */
@interface KandyDomain : NSObject <NSCoding>
/**
 *  The domain API key
 */
@property (readonly) NSString * key;
/**
 *  The domain API secret
 */
@property (readonly) NSString * secret;
/**
 *  The domain API name
 */
@property (readonly) NSString * name;
/**
 *  Extra data about the domain
 */
@property (readonly) NSMutableDictionary * dataByKey;

/**
 *  Create a KandyDomain with Domain Key only. this object holds the data about the domain
 *
 *  @param apiKey    The domain API key
 *
 *  @return A new KandyDomainData object
 */
- (instancetype)initWithAPIKey:(NSString *)apiKey;

/**
 *  Create a KandyDomainData. This object holds the data about the domain
 *
 *  @param apiKey    The domain API key
 *  @param apiSecret The domain API secret
 *
 *  @return A new KandyDomainData object
 */
- (instancetype)initWithAPIKey:(NSString *)apiKey APISecret:(NSString *)apiSecret andAPIName:(NSString*)apiName;

/**
 Create a KandyDomainData. this object holds the data about the domain
 @param apiKey    The domain API key
 @param apiSecret The domain API secret
 @param data      The domain extra data
 
 @return A new KandyDomainData object
 */
- (instancetype)initWithAPIKey:(NSString *)apiKey APISecret:(NSString *)apiSecret APIName:(NSString*)apiName andData:(NSDictionary*)data;

@end
