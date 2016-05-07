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

#ifndef KandySDK_KandyNotificationServiceEnums_h
#define KandySDK_KandyNotificationServiceEnums_h

static NSString * const KandyNotificationServiceErrorDomain = @"NotificationServiceErrorDomain";

/**
 *  The errors that the developer can get while using the notification service
 */
typedef NS_ENUM(NSInteger, EKandyNotificationServiceError) {
    /**
     *  None
     */
    EKandyNotificationServiceError_none = 0,
    /**
     *  The push format got is not supported by the SDK
     */
    EKandyNotificationServiceError_pushFormatNotSupported,
    /**
     *  For development
     */
    EKandyNotificationServiceError_count,
};

#endif
