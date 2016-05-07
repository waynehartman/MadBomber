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

#ifndef KandySDK_KandyLoggerProtocol_h
#define KandySDK_KandyLoggerProtocol_h

#import "KandyLoggingFormatterProtocol.h"
/**
 *  This class incorporates the Kandy SDK logs to provide the developer the resposibilty of printing them the required way
 */
@protocol KandyLoggerProtocol <NSObject>

/**
 *  Prints to log
 *
 *  @param level     the log level
 *  @param logString the string to print
 */
-(void) logWithLevel:(EKandyLogLevel)level andLogString:(NSString*)logString;

/**
 *  Logging formatter to determine the log printing layout
 */
@property (nonatomic, strong) id<KandyLoggingFormatterProtocol> loggingFormatter;

@end

#endif
