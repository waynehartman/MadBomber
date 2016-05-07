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
#import "KandyGroupDownloadPathBuilderProtocol.h"

@interface KandyGroupServiceSettings : NSObject

/**
 *  Maximum size for media upload in kB
 *  Default value is - 20,480
 */
@property (nonatomic, assign) double groupImageMaxUploadSizeInKB;
/**
 *  Protocol that manages the download path - can be replaced with external pathBuilder that
 *  conforms to KandyGroupDownloadPathBuilderProtocol
 */
@property (nonatomic, strong) id<KandyGroupDownloadPathBuilderProtocol> downloadPathBuilder;

@end
