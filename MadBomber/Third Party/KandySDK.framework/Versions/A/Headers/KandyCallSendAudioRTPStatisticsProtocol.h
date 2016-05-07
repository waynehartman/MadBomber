//
//  KandyCallSendAudioRTPStatisticsProtocol.h
//  KandySDK
//
//  Created by Yaron Jackoby on 19/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KandyCallSendAudioRTPStatisticsProtocol <NSObject>
/**
 *  cumulative amount of bytes (audio)
 */
@property (nonatomic,strong,readonly) NSString *bytesSent;
/**
 *   cumulative amount of packets (audio)
 */
@property (nonatomic,strong,readonly) NSString *packetsSent;
/**
 *  codec name Opus , PCMA , PCMU
 */
@property (nonatomic,strong,readonly) NSString *codecName;

@end
