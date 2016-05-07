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
#import "KandyImageItemProtocol.h"

#define kRemoveGroupImage @""
#define kRemoveGroupName @""

@interface KandyGroupParams : NSObject
/**
 *  The group name - can be set to kRemoveGroupName in order to remove the current name
 */
@property (nonatomic, strong) NSString* groupName;
/**
 *  The absolute path to the group image - can be set to kRemoveGroupImage in order to remove the current image
 */
@property (nonatomic, strong) NSString* groupAbsoluteImagePath;
/**
 *  KandyImageItemProtocol representing the group image - will be initiated automatically when updating the groupAbsoluteImagePath
 */
@property (readonly) id<KandyImageItemProtocol> groupImageItem;

@end
