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
#import "KandyChatServiceEnums.h"

/**
 * Handles the media item
 */
@protocol KandyMediaItemProtocol <NSObject>

/**
 *  Media type (EKandyFileType)
 */
@property (readonly) EKandyFileType mediaType;
/**
 *  Text associated with the MediaItem
 */
@property (readonly) NSString* text;
/**
 *  Optional. Additional info stored with the message.
 */
@property (readonly) NSDictionary* additionalData;
/**
 *   Optional. User can store any generic object types (NSSting, NSNumber, NSData etc.) within the dicitionary
 *
 *  @param info user specified custom data
 */
-(void)updateAddtitionalData:(NSDictionary*)additionalData;
/**
 *  Absolute path to the thumbnail file
 *  Absolute path may change for some reason e.g., after application version update
 */
@property (readonly) NSString* thumbnailAbsolutePath;
/**
 *  Relative path to the thumbnail file - does not include the application directory path prefix
 *  Relative path is important since it does not change under any circumstance
 */
@property (readonly) NSString* thumbnailRelativePath;
/**
 *  Update the thumbnail path, e.g. after it was downloaded successfully
 *
 *  @param aThumbnailPath the updated thumbnail path
 */
-(void)updateThumbnailPath:(NSString*)aThumbnailPath;
/**
 *  Check if it is needed to download media
 *
 *  @return YES if there is media to download
 */
-(BOOL)shouldDownloadMedia;

@end


