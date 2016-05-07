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
#import "KandyRecord.h"
#import "KandyImageItemProtocol.h"

@interface KandyGroup : NSObject

/**
 *  Initialization method for KandyGroup
 *
 *  @param groupID   KandyRecord representing the group ID
 *
 *  @return initialized KandyGroup
 */
-(instancetype)initWithGroupID:(KandyRecord*)groupID;

/**
 *  Initialization method for KandyGroup
 *
 *  @param groupID     KandyRecord representing the group ID
 *  @param groupName   the group name
 *
 *  @return initialized KandyGroup
 */
-(instancetype)initWithGroupID:(KandyRecord*)groupID groupName:(NSString*)groupName;

/**
 *  Kandy record representing the group identifier
 */
@property (nonatomic, strong) KandyRecord* groupId;
/**
 *  The group name
 */
@property (nonatomic, strong) NSString* name;
/**
 *  KandyImageItemProtocol representing the image
 */
@property (nonatomic, strong) id<KandyImageItemProtocol> image;
/**
 *  The group creation date - will be initialized upon calling createGroup
 */
@property (nonatomic, strong) NSDate* creationDate;
/**
 *  Max participants allowed for the group - will be initialized upon calling createGroup
 */
@property (nonatomic, assign) NSUInteger maxParticipants;
/**
 *  The group participants - array of KandyGroupParticipants
 */
@property (nonatomic, strong) NSMutableArray* participants;
/**
 *  Yes if the group notifications are muted - will be updated upon calling Mute/unMute group
 */
@property (nonatomic, assign) BOOL isMuted;

@end