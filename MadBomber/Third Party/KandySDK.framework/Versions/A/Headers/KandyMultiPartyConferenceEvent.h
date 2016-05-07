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
#import "KandyEventProtocol.h"

@class KandyRecord;

/**
 *  A multi party conference base event
 */
@interface KandyMultiPartyConferenceEvent : NSObject <KandyEventProtocol>

/**
 *  The KandyRecord of the sender
 */
@property (readonly)KandyRecord * sender;
/**
 *  KandyRecord representing the destination
 */
@property (readonly)KandyRecord * destination;
/**
 *  The multi party conference ID
 */
@property (readonly)NSString * conferenceID;

/**
 *  Initialization method for KandyMultiPartyConferenceInvite
 *
 *  @param uuid                  event UUID
 *  @param timestamp             event timestamp
 *  @param sender                the sender
 *  @param destination           the destination
 *  @param conferenceID          the conference ID
 *
 *  @return Initialized instance of KandyMultiPartyConferenceInvite object
 */
- (instancetype)initWithUUID:(NSString *)uuid
                   timestamp:(NSDate *)timestamp
                      sender:(KandyRecord *)sender
                 destination:(KandyRecord *)destination
                conferenceID:(NSString *)conferenceID
              isHistoryEvent:(BOOL)isHistoryEvent;
@end
