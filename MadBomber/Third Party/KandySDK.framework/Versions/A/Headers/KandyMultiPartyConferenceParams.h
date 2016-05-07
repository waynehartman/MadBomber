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
/**
 *  Kandy multi party conference params contains the settings for a multi party conference
 */
@interface KandyMultiPartyConferenceParams : NSObject

/**
 *  The user name as it will be shown in multi party conference
 */
@property (strong,nonatomic)NSString * nickname;
/**
 *  Establish the call with speaker enabled, default value is YES
 */
@property (assign,nonatomic)BOOL speakerEnabled;
/**
 *  Establish the call with video enabled, default value is YES
 */
@property (assign,nonatomic)BOOL videoEnabled;

/**
 *  Create a new KandyMultiPartyConferenceParams object
 *
 *  @param nickname       The nick name is the user name that will be shown in multi party conference
 *  @param videoEnabled   Set to YES to establish the call with speaker enabled
 *  @param speakerEnabled Set to YES to establish the call with video enabled
 *
 *  @return A new KandyMultiPartyConferenceParams initiated with the given parameters
 */
- (instancetype)initWithNickname:(NSString *)nickname videoEnabled:(BOOL)videoEnabled speakerEnabled:(BOOL)speakerEnabled;
@end
