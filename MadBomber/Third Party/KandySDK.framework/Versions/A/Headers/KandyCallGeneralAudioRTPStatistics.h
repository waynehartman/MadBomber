//
//  KandyCallGeneralAudioRTPStatistics.h
//  KandySDK
//
//  Created by Yaron Jackoby on 14/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import "KandyCallGeneralAudioRTPStatisticsProtocol.h"

@interface KandyCallGeneralAudioRTPStatistics : NSObject<KandyCallGeneralAudioRTPStatisticsProtocol>

-(instancetype) initWithValues:(NSDictionary *) values;
-(NSDictionary *)dictionaryData;
@end
