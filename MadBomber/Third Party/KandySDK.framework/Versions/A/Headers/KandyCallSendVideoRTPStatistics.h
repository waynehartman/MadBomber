//
//  KandyCallSendVideoRTPStatistics.h
//  KandySDK
//
//  Created by Yaron Jackoby on 14/01/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KandyCallSendVideoRTPStatisticsProtocol.h"

@interface KandyCallSendVideoRTPStatistics : NSObject<KandyCallSendVideoRTPStatisticsProtocol>

-(instancetype) initWithValues:(NSDictionary *) values;
-(NSDictionary *)dictionaryData;
@end
