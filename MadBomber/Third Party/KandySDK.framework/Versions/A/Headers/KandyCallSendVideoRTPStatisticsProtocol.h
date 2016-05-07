//
//  KandyCallSendVideoRTPStatisticsProtocol.h
//  KandySDK
//
//  Created by Yaron Jackoby on 19/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KandyCallSendVideoRTPStatisticsProtocol <NSObject>
/**
 *  bytes sent
 */
@property (nonatomic,strong,readonly) NSString *bytesSent;
/**
 *  codec name: VP8
 */
@property (nonatomic,strong,readonly) NSString *codecName; //
/**
 *  resolution dimension height
 */
@property (nonatomic,strong,readonly) NSString *frameHeightSent;
/**
 *   resolution dimension width
 */
@property (nonatomic,strong,readonly) NSString *frameWidthSent;
/**
 *  frame rate
 */
@property (nonatomic,strong,readonly) NSString *frameRateSent;
@end
