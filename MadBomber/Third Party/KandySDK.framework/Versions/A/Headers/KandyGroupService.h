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
#import "KandyGroupParams.h"
#import "KandyGroup.h"
#import "KandyRecord.h"
#import "KandyGroupServiceSettings.h"
#import "KandyTransferProgress.h"
#import "KandyGroupServiceNotificationDelegate.h"
#import "KandyCloudStorageServiceEnums.h"

@interface KandyGroupService : NSObject

/**
 *  Group service settings
 */
@property (readonly) KandyGroupServiceSettings* settings;

/**
 *  Register to incoming events the client receives from the group service
 *
 *  @param notificationDelegate the delegate
 */
-(void) registerNotifications:(NSObject<KandyGroupServiceNotificationDelegate>*)notificationDelegate;

/**
 *  Stop listening to group notifications
 *
 *  @param notificationDelegate conforms to protocol KandyGroupServiceNotificationDelegate
 */
-(void) unregisterNotifications:(id<KandyGroupServiceNotificationDelegate>)notificationDelegate;

/**
 *  Create a KandyGroup by the received KandyGroupParams
 *
 *  @param groupParams      KandyGroupParams to use for creating the KandyGroup
 *  @param progressCallback callback for updating the progress in case of image uploading
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)createGroup:(KandyGroupParams*)groupParams progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Get group details by group id
 *
 *  @param groupId          the ID of the group to get the details of
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)getGroupDetails:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Get all my groups
 *
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or NSArray containing KandyGroups in case of success
 */
-(void)getMyGroupsWithResponseCallback:(void(^)(NSError* error, NSArray* groups))responseCallBack;
/**
 *  Leave a group
 *
 *  @param groupId          the ID of the group to leave
 *  @param responseCallBack will be called upon completion, will contain error in case of failure
 */
-(void)leaveGroup:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error))responseCallBack;
/**
 *  Destroy group by group ID
 *
 *  @param groupId          the ID of the group to destroy
 *  @param responseCallBack will be called upon completion, will contain error in case of failure
 */
-(void)destroyGroup:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error))responseCallBack;
/**
 *  Update a KandyGroup by the received KandyGroupParams
 *
 *  @param groupParams      KandyGroupParams to use for updating the KandyGroup
 *  @param groupId          the ID of the group to update
 *  @param progressCallback callback for updating the progress in case of image uploading
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)updateGroupParams:(KandyGroupParams*)groupParams groupId:(KandyRecord*)groupId progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Update group name
 *
 *  @param groupName        the new name to use
 *  @param groupId          the ID of the group to update
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)updateGroupName:(NSString*)groupName groupId:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Update group image
 *
 *  @param imageAbsolutePath absolute path to the new image to use
 *  @param groupId           the ID of the group to update
 *  @param progressCallback  callback for updating the upload progress
 *  @param responseCallBack  will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)updateGroupImage:(NSString*)imageAbsolutePath groupId:(KandyRecord*)groupId progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Remove group image
 *
 *  @param groupId          the ID of the group to update
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)removeGroupImage:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Add participants to group
 *
 *  @param participants     NSArray of KandyRecords of participants to add
 *  @param groupId          the ID of the group to update
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)addGroupParticipants:(NSArray*)participants groupId:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Remove participants from group
 *
 *  @param participants     NSArray of KandyRecords of participants to remove
 *  @param groupId          the ID of the group to update
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)removeGroupParticipants:(NSArray*)participants groupId:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Mute group - push notifications from this group will not be received
 *
 *  @param groupId          the ID of the group to mute
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)muteGroup:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Mute group - push notifications from this group will be received
 *
 *  @param groupId          the ID of the group to unmute
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)unMuteGroup:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Mute participants - push notifications from this participants will not be received
 *
 *  @param participants     the participants to mute
 *  @param groupId          the ID of the group
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)muteGroupParticipants:(NSArray*)participants groupId:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Mute participants - push notifications from this participants will be received
 *
 *  @param participants     the participants to unmute
 *  @param groupId          the ID of the group
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or KandyGroup in case of success
 */
-(void)unMuteGroupParticipants:(NSArray*)participants groupId:(KandyRecord*)groupId responseCallback:(void(^)(NSError* error, KandyGroup* group))responseCallBack;
/**
 *  Download the group image thumbnail
 *
 *  @param group            the group to get the thumbnail for
 *  @param thumbnailSize    EKandyThumbnailSize desired thumbnail size
 *  @param progressCallback callback for updating the download progress
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or thumbnail path in case of success
 */
-(void)downloadGroupThumbnail:(KandyGroup*)group thumbnailSize:(EKandyThumbnailSize)thumbnailSize progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, NSString* fileAbsolutePath))responseCallBack;
/**
 *  Download the group image
 *
 *  @param group            the group to get the image for
 *  @param progressCallback callback for updating the download progress
 *  @param responseCallBack will be called upon completion, will contain error in case of failure or file path in case of success
 */
-(void)downloadGroupImage:(KandyGroup*)group progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, NSString *fileAbsolutePath))responseCallback;
/**
 *  Cancel a transfer operation (upload/download)
 *
 *  @param group            the group associated with the operation to cancel
 *  @param responseCallback will be called upon completion, will contain error in case of failure
 */
-(void)cancelOperation:(KandyGroup*)group responseCallback:(void(^)(NSError* error))responseCallback;

@end
