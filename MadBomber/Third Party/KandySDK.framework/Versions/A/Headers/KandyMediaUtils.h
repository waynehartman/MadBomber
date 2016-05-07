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
#import <UIKit/UIKit.h>

/**
 *  Utility methods for media
 */
@interface KandyMediaUtils : NSObject

/**
 *  Creates and returns an image thumbnail for the image at the received path
 *
 *  @param imageAbsolutePath absolute path to the original image from which to create thumbnail
 *  @param size              height and width of the newly-created thumbnail - size will keep the original image proportions, so received size is the max width/height of the thumbnail
 *  @param responseCallback  will be called on completion with the thumbnail, or an error if occured
 */
+(void)getImageThumbnail:(NSString*)imageAbsolutePath thumbnailSize:(int)size responseCallback:(void(^)(NSError* error, UIImage *thumbnailImage))responseCallback;

/**
 *  Creates and returns an image thumbnail for the video at the received path
 *
 *  @param imageAbsolutePath absolute path to the original video from which to create thumbnail
 *  @param size              height and width of the newly created thumbnail - size will keep the original video proportions, so received size is the max width/height of the thumbnail
 *  @param responseCallback  will be called on completion with the thumbnail, or an error if occured
 */
+(void)getVideoThumbnail:(NSString*)videoAbsolutePath thumbnailSize:(int)size responseCallback:(void(^)(NSError* error, UIImage *thumbnailImage))responseCallback;

/**
 *  Create a compresses image from the received image
 *
 *  @param imageAbsolutePath           original image absolute path
 *  @param compressedImageAbsolutePath path to save the compressed image
 *  @param compressedFileName          name of the compressed image - without extension
 *  @param maxDimensions               max dimension for the compressed image - you can pass CGSizeZero to prevent dimensions change. Changing the dimesions will take the width/height ratio into consideration
 *  @param compressionQuality          value from 0.0 to 1.0. The value 0.0 represents the maximum compression (or lowest quality), while the value 1.0 represents the least compression (or best quality)
 *  @param responseCallback            will be called upon completion and pass the complete path to the compressed image (jpg representation), or error if occurred
 */
+(void)getCompressedImage:(NSString*)imageAbsolutePath compressedImagePath:(NSString*)compressedImageAbsolutePath compressFileName:(NSString*)compressedFileName maxDimensions:(CGSize)maxDimensions compressionQuality:(float)compressionQuality responseCallback:(void(^)(NSError* error, NSString *compressedAbsolutePath))responseCallback;


@end
