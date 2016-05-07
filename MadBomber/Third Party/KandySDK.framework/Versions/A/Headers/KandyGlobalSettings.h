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
#import "KandyAnalyticsReportingSettings.h"

@class KandyDomain;
/**
 * This interface handles the
 *     - URL to the Kandy host
 *     - request timeout
 *     - access to the Internet
 */
@interface KandyGlobalSettings : NSObject

/**
 *  The URL to the kandy host. Default is https://api.kandy.io
 */
@property(nonatomic, strong) NSString* kandyServiceHost;
/**
 *  Request timeout in seconds. Default is 20 seconds
 */
@property(nonatomic, assign) int kandyServiceTimeout;
/**
 *  Allow access to the Internet when using cellular data. Default is YES
 */
@property(nonatomic, assign) BOOL isAllowInternetOnCellularData;
/**
 *  Boolean indicating wether the session is automatically renewed upon expiration. Default is NO
 */
@property (nonatomic, assign) BOOL isAutoRenewSession;
/**
 *  Boolean indicating if to use certificate pinning. Default is NO
 */
@property (nonatomic, assign) BOOL isEnableCertificatePinning;
/**
 *  Boolean indicating if to print webRTC call logs. Default is NO
 */
@property (nonatomic, assign) BOOL isPrintRTCCallLogs;
/**
 *  Boolean defining if need to send wake up notification to callee before establishing call. Default is NO
 */
@property (nonatomic, assign) BOOL shouldWakeupDestinationBeforeCall;

/**
 *  defines the configuration regarding analytics reports
 */
@property (nonatomic, readonly) KandyAnalyticsReportingSettings *analyticsReportingSettings;
/**
 *  Changes the Kandy SDK domain secret
 *
 *  @param domainSecret New domain secret
 */
-(void)changeDomainSecret:(NSString*)domainSecret;

/**
 *  Retreive information regarding the KandySDK, KandyAPI, SPiDR, PushServer
 *
 *  @return a JSON string containing the information
 */
-(NSString*)getReport;

@end
