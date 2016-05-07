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

#ifndef KandySDK_KandyLoggingEnums_h
#define KandySDK_KandyLoggingEnums_h

/**
 *  Log level enumaration
 */
typedef NS_ENUM(NSUInteger, EKandyLogLevel)
{
    /**
     *  debug level
     */
    EKandyLogLevel_debug,
    /**
     *  info level
     */
    EKandyLogLevel_info,
    /**
     *  warning level
     */
    EKandyLogLevel_warning,
    /**
     *  error level
     */
    EKandyLogLevel_error,
};



#endif
