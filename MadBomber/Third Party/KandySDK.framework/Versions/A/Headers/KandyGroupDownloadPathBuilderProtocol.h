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
#import "KandyFileItemProtocol.h"
#import "KandyRecord.h"

@protocol KandyGroupDownloadPathBuilderProtocol <NSObject>

/**
 *  This methods builds and returns the absolute path for downloaded files
 *
 *  @param groupRecord The Kandy record associated with the downloaded file
 *  @param fileItem    The downloaded file item
 *  @param isThumbnail BOOL indicating if the file item downloaded is a thumbnail
 *
 *  @return the absolute path for downloaded files - Default value for iOS is - Documents/Kandy/Media/Groups/UserName/MediaType(/Thumbnail?)
 */
-(NSString*)downloadAbsolutePath:(KandyRecord*)groupRecord fileItem:(id<KandyFileItemProtocol>)fileItem isThumbnail:(BOOL)isThumbnail;
/**
 *  This methods builds and returns the fileName for the downloaded files
 *
 *  @param fileItem    The file item that the name is associated with
 *  @param isThumbnail YES if this is a thumbnail image. If YES, a prefix will be added to the file name
 *
 *  @return the fileName for the downloaded files - Default value for iOS is - (tmb_?)fileItem.fileName if exists, otherwise the (tmb_?)fileItem.contentUUID
 */
-(NSString*)downloadFileName:(id<KandyFileItemProtocol>)fileItem isThumbnail:(BOOL)isThumbnail;

@end