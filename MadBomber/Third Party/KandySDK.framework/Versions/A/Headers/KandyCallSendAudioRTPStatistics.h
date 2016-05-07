//
//  KandyCallSendAudioRTPStatistics.h
//  KandySDK
//
//  Created by Yaron Jackoby on 14/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KandyCallSendAudioRTPStatisticsProtocol.h"

@interface KandyCallSendAudioRTPStatistics : NSObject<KandyCallSendAudioRTPStatisticsProtocol>

-(instancetype) initWithValues:(NSDictionary *) values;
-(NSDictionary *)dictionaryData;
@end
