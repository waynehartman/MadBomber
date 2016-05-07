//
//  KandyCallGeneralVideoRTPStatisticsProtocol.h
//  KandySDK
//
//  Created by Yaron Jackoby on 19/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol KandyCallGeneralVideoRTPStatisticsProtocol <NSObject>
/**
 *  current actual bitrate sent by encoder
 */
@property (nonatomic,strong,readonly) NSString *targetEncBitrate;
/**
 *  current configured target bit rate for encoder
 */
@property (nonatomic,strong,readonly) NSString *actualEncBitrate;

@end
