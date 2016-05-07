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
#import "KandyFileItemProtocol.h"
#import "KandyTransferProgress.h"
#import "KandyCloudStorageServiceEnums.h"

@interface KandyCloudStorageService : NSObject

/**
 *  Upload media to the cloud
 *
 *  @param fileItem         the data to upload
 *  @param progressCallback block to handle the progress
 *  @param responseCallback block to handle the completion/failure
 */
-(void)uploadMedia:(id<KandyFileItemProtocol>)fileItem progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  Download thumbnail of the media from the cloud
 *
 *  @param fileItem         the fileItem to download the thumbnail for
 *  @param thumbnailName    thumbnail name
 *  @param downloadPath     download path
 *  @param thumbnailSize    the desired thumbnail size
 *  @param progressCallback callback that will be called upon upload progress change
 *  @param responseCallback callback that will be called upon upload completion / failure
 */
-(void)downloadThumbnail:(id<KandyFileItemProtocol>)fileItem thumbnailName:(NSString*)thumbnailName downloadPath:(NSString*)downloadPath thumbnailSize:(EKandyThumbnailSize)thumbnailSize progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, NSString* filePath))responseCallback;
    
/**
 *  Download media from the cloud
 *
 *  @param fileItem         the fileItem to download
 *  @param fileName         file name for the downloaded file
 *  @param downloadPath     path for the download
 *  @param progressCallback callback that will be called upon upload progress change
 *  @param responseCallback callback that will be called upon upload completion / failure
 */
-(void)downloadMedia:(id<KandyFileItemProtocol>)fileItem fileName:(NSString*)fileName downloadPath:(NSString*)downloadPath progressCallback:(void(^)(KandyTransferProgress* transferProgress))progressCallback responseCallback:(void(^)(NSError* error, NSString* filePath))responseCallback;

/**
 *  Cancel the Upload/Download process of the media
 *
 *  @param fileItem      the fileItem to cancel download or upload request for
 *  @param responseCallback callback that will be called upon request success / failure
 */
-(void)cancelMediaTransfer:(id<KandyFileItemProtocol>)fileItem responseCallback:(void(^)(NSError* error))responseCallback;

@end
