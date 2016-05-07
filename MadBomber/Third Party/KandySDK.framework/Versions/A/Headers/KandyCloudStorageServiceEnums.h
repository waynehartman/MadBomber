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

#ifndef KandySDK_KandyCloudStorageServiceEnums_h
#define KandySDK_KandyCloudStorageServiceEnums_h

static NSString * const KandyCloudServiceErrorDomain = @"CloudServiceErrorDomain";

typedef NS_ENUM(NSInteger, EKandyCloudServiceError)
{
    /**
     *  Thumbnail could not be downloaded
     */
    EKandyCloudServiceError_noThumbnailFound,
    /**
     *  Failed to transfer data cause it is currently transfering
     */
    EKandyCloudServiceError_mediaIsCurrentlyTransfering,
    /**
     *  Message data could not been uploaded
     */
    EKandyCloudServiceError_mediaWasNotUploaded,
    /**
     *  Message data has already been downloaded
     */
    EKandyCloudServiceError_mediaAlreadyDownloaded,
    /**
     * Invalid file name
     */
    EKandyCloudServiceError_invalidFileName,
    /**
     *  the cloud service error count - development use
     */
    EKandyCloudServiceError_count
};

/**
 *  Enum representing the thumbnail size
 */
typedef NS_ENUM(NSInteger, EKandyThumbnailSize)
{
    /**
     *  small sized thumbnail : 50X50
     */
    EKandyThumbnailSize_small,
    /**
     *  medium sized thumbnail : 250X250
     */
    EKandyThumbnailSize_medium,
    /**
     *  large sized thumbnail : 500X500
     */
    EKandyThumbnailSize_large
};

#endif
