//
//  KandyCallReceiveAudioRTPStatisticsProtocol.h
//  KandySDK
//
//  Created by Yaron Jackoby on 19/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KandyCallReceiveAudioRTPStatisticsProtocol <NSObject>
/**
 *   weighted average call delay in msec
 */
@property (strong, nonatomic, readonly) NSString *weightedAverageLatency;
/**
 *  weighted average call delay in msec
 */
@property (strong, nonatomic, readonly) NSString *jitter;
/**
 *   cumulative packets received since begin of call
 */
@property (strong, nonatomic, readonly) NSString *receivedPackets;

/**
 *  the interval between current packet recieved to the previous
 */
@property (strong, nonatomic, readonly) NSString *receivedPacketsInterval;

/**
 *  cumulative packet loss since begin of call
 */
@property (strong, nonatomic, readonly) NSString *receivedPacketsLost;

/**
 *  the interval between current packet lost to the previous 
 */
@property (strong, nonatomic, readonly) NSString *receivedPacketsLostInterval;

/**
 *  cumulative amount of bytes (audio)
 */
@property (strong, nonatomic, readonly) NSString *bytesReceived;
/**
 *  Codec name: Opus , PCMA , PCMU
 */
@property (strong, nonatomic, readonly) NSString *codecName;

/**
 * Calculated MOS value;
 */
@property (strong, nonatomic, readonly) NSString *mos;
@end
