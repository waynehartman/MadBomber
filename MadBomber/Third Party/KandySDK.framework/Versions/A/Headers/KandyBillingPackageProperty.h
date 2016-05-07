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
 *  Text message
 */
#define kKandyBillingPackageProperty_Name_TextMessageKey @"Text message"
/**
 *  Contact message
 */
#define kKandyBillingPackageProperty_Name_ContactMessageKey @"Contact message"
/**
 *  File message
 */
#define kKandyBillingPackageProperty_Name_FileMessageKey @"File message"
/**
 *  Location message
 */
#define kKandyBillingPackageProperty_Name_LocationMessageKey @"Location message"
/**
 *  Picture message
 */
#define kKandyBillingPackageProperty_Name_ImageMessageKey @"Picture message"
/**
 *  Audio message
 */
#define kKandyBillingPackageProperty_Name_AudioMessageKey @"Audio message"
/**
 *  Outgoing SMS
 */
#define kKandyBillingPackageProperty_Name_OutgoingSMSKey @"Outgoing SMS"
/**
 *  IP to PSTN
 */
#define kKandyBillingPackageProperty_Name_IPtoPSTNKey @"IP to PSTN"
/**
 *  IP to IP voice call
 */
#define kKandyBillingPackageProperty_Name_IPtoIPVoiceCallKey @"IP to IP voice call"

/**
 *  Quota units of type message
 */
#define kKandyBillingPackageProperty_QuotaUnits_MessagesKey @"messages"
/**
 *  Quota units of type seconds
 */
#define kKandyBillingPackageProperty_QuotaUnits_SecondsKey @"seconds"

@interface KandyBillingPackageProperty : NSObject

/**
 *  The package name
 */
@property (strong) NSString* name;
/**
 *  the remaining quota
 */
@property (assign) NSInteger remainingQuota;
/**
 *  the quota units
 */
@property (strong) NSString* quotaUnits;

@end
