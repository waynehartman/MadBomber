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
#import "KandyCallReceiveVideoRTPStatistics.h"
#import "KandyCallReceiveAudioRTPStatistics.h"
#import "KandyCallSendAudioRTPStatistics.h"
#import "KandyCallReceiveVideoRTPStatistics.h"
#import "KandyCallSendVideoRTPStatistics.h"
#import "KandyCallGeneralAudioRTPStatistics.h"
#import "KandyCallGeneralVideoRTPStatistics.h"


@protocol KandyCallRTPStatisticsProtocol <NSObject>

/**
 *  Satistics of Audio incoming data
 */
@property (strong, nonatomic, readonly) KandyCallReceiveAudioRTPStatistics *receiveAudioRTPStatistics;
/**
 *  Satistics of Audio outgoing data
 */
@property (strong, nonatomic, readonly) KandyCallSendAudioRTPStatistics *sendAudioRTPStatistics;
/**
 *  Satistics of Video incoming data
 */
@property (strong, nonatomic, readonly) KandyCallReceiveVideoRTPStatistics *receiveVideoRTPStatistics;
/**
 *  Satistics of Video outgoing data
 */
@property (strong, nonatomic, readonly) KandyCallSendVideoRTPStatistics *sendVideoRTPStatistics;
/**
 *  Satistics of Audio, genral info
 */
@property (strong, nonatomic, readonly) KandyCallGeneralAudioRTPStatistics *generalAudioRTPStatistics;
/**
 *  Satistics of Video, genral info
 */
@property (strong, nonatomic, readonly) KandyCallGeneralVideoRTPStatistics *generalVideoRTPStatistics;

/**
 *  An allStatistics is Raw WebRTC Statistics
 */
@property (strong, nonatomic, readonly) NSArray *allStatistics;

/**
 *  The caller full user name and domain
 */
@property (strong, nonatomic, readonly) NSString *callerUri;

/**
 *  The callee full user name and domain
 */
@property (strong, nonatomic, readonly) NSString *calleeUri;



@end
