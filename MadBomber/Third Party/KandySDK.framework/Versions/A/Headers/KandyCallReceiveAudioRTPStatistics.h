//
//  KandyCallReceiveAudioRTPStatistics.h
//  KandySDK
//
//  Created by Yaron Jackoby on 14/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import "KandyCallReceiveAudioRTPStatisticsProtocol.h"
@interface KandyCallReceiveAudioRTPStatistics : NSObject<KandyCallReceiveAudioRTPStatisticsProtocol>

-(instancetype) initWithValues:(NSDictionary *) values prevStatistics:(KandyCallReceiveAudioRTPStatistics *)prevReceiveAudioRTPStatistics;

-(NSDictionary *)dictionaryData;

@end
