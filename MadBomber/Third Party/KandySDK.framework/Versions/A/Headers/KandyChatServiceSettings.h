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
#import "KandyCloudStorageServiceEnums.h"
#import "KandyChatDownloadPathBuilderProtocol.h"

@interface KandyChatServiceSettings : NSObject

/**
 *  Maximum size for media upload in kB
 *  Default value is - 20,480
 */
@property (nonatomic, assign) double mediaMaxUploadSizeInKB;

/**
 *  Protocol that manages the download path - can be replaced with external pathBuilder that
 *  conforms to KandyChatDownloadPathBuilderProtocol
 */
@property (nonatomic, strong) id<KandyChatDownloadPathBuilderProtocol> downloadPathBuilder;
/**
 *  Size of the auto downloaded thumbnails for media items
 *  Default value is EKandyThumbnailSize_medium
 */
@property (nonatomic, assign) EKandyThumbnailSize autoDownload_thumbnailSize;

/**
 *  Should auto download thumbnail if exists, on incoming messages
 *  Default value is YES
 */
@property (nonatomic, assign) BOOL autoDownload_thumbnail;

/**
 *  Auto download media only when using this connection type
 *  Default value is EKandyMediaAutoDownloadConnectionType_cellularData (all connection types)
 */
@property (nonatomic, assign) EKandyMediaAutoDownloadConnectionType autoDownload_media_connectionType;

/**
 *  Should auto download media for events pulled from history. Default is "NO". This flag takes onto account value of "autoDownload_media_connectionType" property when deciding should SDK download the media.
 */
@property (nonatomic, assign) BOOL autoDownload_media_fromHistory;

/**
 *  Max size auto download media on incoming messages in kB
 *  Default value is 20,480
 */
@property (nonatomic, assign) double autoDownload_media_maxSizeKB;

@end
