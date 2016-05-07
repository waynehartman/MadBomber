//
//  KandyCallReceiveVideoRTPStatisticsProtocol.h
//  KandySDK
//
//  Created by Yaron Jackoby on 19/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KandyCallReceiveVideoRTPStatisticsProtocol <NSObject>
/**
 *  Cumulative amount of bytes (video)
 */
@property (nonatomic,strong,readonly) NSString *bytesReceived;
/**
 *  resolution dimension height
 */
@property (nonatomic,strong,readonly) NSString *frameHeightReceived;
/**
 *  resolution dimension width
 */
@property (nonatomic,strong,readonly) NSString *frameWidthReceived;

/**
 *  frame rate video received
 */
@property (nonatomic,strong,readonly) NSString *frameRateRecevied;

@end
