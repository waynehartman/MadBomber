/*
 * Copyright © 2016 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
*/

#import <Foundation/Foundation.h>
#import "KandyCallServiceEnums.h"
#import "KandyCallActivityRecord.h"

@protocol KandyCallActivityDataRetrievalDelegate <NSObject>
/**
 *  Create activity record for the current instance
 *
 *  @return The activityRecord of the current instance
 */
-(KandyCallActivityRecord*) createActivityRecord;
@end
