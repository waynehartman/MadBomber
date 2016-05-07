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
#import <CoreLocation/CoreLocation.h>
#import "KandyTextItemProtocol.h"
#import "KandyImageItemProtocol.h"
#import "KandyVideoItemProtocol.h"
#import "KandyAudioItemProtocol.h"
#import "KandyContactItemProtocol.h"
#import "KandyLocationItemProtocol.h"
#import "KandyCustomItemProtocol.h"

@interface KandyMessageBuilder : NSObject

/**
 *  Creates and returns an object conforms to protocol KandyTextItemProtocol
 *
 *  @param text       the text
 *
 *  @return an object conforms to protocol KandyTextItemProtocol
 */
+(id<KandyTextItemProtocol>)createTextItem:(NSString*)text;
/**
 *  Creates and returns an object conforms to protocol KandyImageItemProtocol
 *
 *  @param imagePath     absolute path to the image
 *  @param text          the text (optional)
 *
 *  @return an object conforms to protocol KandyTextItemProtocol
 */
+(id<KandyImageItemProtocol>)createImageItem:(NSString*)imagePath text:(NSString*)text;
/**
 *  Creates and returns an object conforms to protocol KandyVideoItemProtocol
 *
 *  @param imagePath     absolute path to the video
 *  @param text          the text (optional)
 *
 *  @return an object conforms to protocol KandyVideoItemProtocol
 */
+(id<KandyVideoItemProtocol>)createVideoItem:(NSString*)videoPath text:(NSString*)text;
/**
 *  Creates and returns an object conforms to protocol KandyAudioItemProtocol
 *
 *  @param imagePath     absolute path to the audio
 *  @param text          the text (optional)
 *
 *  @return an object conforms to protocol KandyAudioItemProtocol
 */
+(id<KandyAudioItemProtocol>)createAudioItem:(NSString*)audioPath text:(NSString*)text;
/**
 *  Creates and returns an object conforms to protocol KandyContactItemProtocol
 *
 *  @param imagePath     absolute path to the contact VCard
 *  @param text          the text (optional)
 *
 *  @return an object conforms to protocol KandyContactItemProtocol
 */
+(id<KandyContactItemProtocol>)createContactItem:(NSString*)contactVCardPath text:(NSString*)text;
/**
 *  Creates and returns an object conforms to protocol KandyLocationItemProtocol
 *
 *  @param location CLLocation    the location
 *  @param text                   the text (optional)
 *
 *  @return an object conforms to protocol KandyLocationItemProtocol
 */
+(id<KandyLocationItemProtocol>)createLocationItem:(CLLocation*)location text:(NSString*)text;
/**
 *  Creates and returns an object conforms to protocol KandyFileItemProtocol
 *
 *  @param filePath     absolute path to the file (can be of any type that's not listed above)
 *  @param text          the text (optional)
 *
 *  @return an object conforms to protocol KandyFileItemProtocol - Thumbnail will not be supported
 */
+(id<KandyFileItemProtocol>)createFileItem:(NSString*)filePath text:(NSString*)text;
/**
 *  Creates and returns an object conforms to protocol KandyCustomItemProtocol
 *
 *  @param customDataDictionary   NSDictionary             dictionary containing the message's custom data
 *  @param pushMessageTitle       the push message title (optional)
 *  @param mimeType               the media item's mimeType
 *
 *  @return an object conforms to protocol KandyLocationItemProtocol
 */
+(id<KandyCustomItemProtocol>)createCustomItem:(NSDictionary*)customDataDictionary pushMessageTitle:(NSString*)pushMessageTitle mimeType:(NSString *)mimeType;

@end
