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

#define kDefaultAudioCompressionBitrate 128000
#define kDefaultVideoCompressionBitrate 512000
#define kDefaultMaxEdgeSize 640
#define kDefaultMaxFramesBetweenKeyFrames 30

@interface KandyVideoCompressionSettings : NSObject

/**
 *  Audio compression bitrate - default value is 128000
 */
@property (nonatomic, assign) NSInteger audioBitrate;
/**
 *  Video compression bitrate - default value is 512000
 */
@property (nonatomic, assign) NSInteger videoBitrate;
/**
 *  Max edge size - default value is 640
 */
@property (nonatomic, assign) NSInteger maxEdgeSize;
/**
 *  Max frames between key frames - default value is 30
 */
@property (nonatomic, assign) NSInteger maxFramesBetweenKeyFrames;

@end
