//
//  KandyCallGeneralAudioRTPStatisticsProtocol.h
//  KandySDK
//
//  Created by Yaron Jackoby on 19/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KandyCallGeneralAudioRTPStatisticsProtocol <NSObject>
/**
 *  // host/stun/relay candidates
 */
@property (nonatomic,strong,readonly) NSString *localCandidateType;
/**
 *  // host/stun/relay candidates
 */
@property (nonatomic,strong,readonly) NSString *remoteCandidateType;
/**
 *  local address incoming media IP
 */
@property (nonatomic,strong,readonly) NSString *localAddress;
/**
 *  remote address remote media IP
 */
@property (nonatomic,strong,readonly) NSString *remoteAddress;
/**
 *  packets sent
 */
@property (nonatomic,strong,readonly) NSString *packetsSent;
/**
 *   cumulative amount of bytes (audio + video)
 */
@property (nonatomic,strong,readonly) NSString *bytesReceived;
/**
 *   cumulative amount of bytes (audio + video)
 */
@property (nonatomic,strong,readonly) NSString *bytesSent;

@end
