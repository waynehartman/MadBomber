//
//  KandyEventServiceEnums.h
//  KandySDK
//
//  Created by Natan Zalkin on 19.1.2016.
//  Copyright © 2016 genband. All rights reserved.
//

#ifndef KandyEventServiceEnums_h
#define KandyEventServiceEnums_h

static NSString * const KandyEventServiceErrorDomain = @"EventServiceErrorDomain";

/**
 *  The errors that the developer can get while using the event service
 */
typedef NS_ENUM(NSInteger, EKandyEventServiceError) {
    /**
     *  None
     */
    EKandyNotificationServiceError_none = 0,
    /**
     *  For development
     */
    EKandyEventServiceError_count,
};


#endif /* KandyEventServiceEnums_h */
