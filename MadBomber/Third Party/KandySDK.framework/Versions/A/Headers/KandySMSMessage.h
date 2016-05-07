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
#import "KandyMessageProtocol.h"

@interface KandySMSMessage : NSObject<KandyMessageProtocol>

/**
 *  The display name that will be used when showing the SMS on the recipient side
 */
@property (nonatomic,strong) NSString* displayName;

/**
 *  Initializing method for KandySMSMessage
 *
 *  @param aText                      the text message data
 *  @param aInternationalPhoneNumber  the phone number to send the SMS (e164 format)
 *  @param aDisplayName               Optional, sender address must only contain alphanumeric characters and restrictions may apply depending on the destination network. If not provided, the user ID will be sent as the source
 *
 *  @return initialized KandySMSMessage
 */
-(id)initWithText:(NSString*)aText recipient:(NSString*)aInternationalPhoneNumber displayName:(NSString*)aDisplayName;

@end
