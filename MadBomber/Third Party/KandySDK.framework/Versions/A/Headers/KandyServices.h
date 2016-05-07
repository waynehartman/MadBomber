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
#import "KandyLocationService.h"
#import "KandyPresenceService.h"
#import "KandyChatService.h"
#import "KandyCallService.h"
#import "KandyPushNotificationService.h"
#import "KandyContactsService.h"
#import "KandyGroupService.h"
#import "KandyProfileService.h"
#import "KandyBillingService.h"
#import "KandyCloudStorageService.h"
#import "KandyMultiPartyConferenceService.h"
#import "KandyEventService.h"

/**
 * This interface handles all the SDK services: Location, Presence, Chat, Call, Address Book, and Push Notifications
 */
@interface KandyServices : NSObject

/**
 *  Location service - serves all location related process
 */
@property (nonatomic, readonly) KandyLocationService* location;

/**
 *  Presence service - serves all presence process
 */
@property (nonatomic, readonly) KandyPresenceService* presence;

/**
 *  Chat service - serves all messaging process
 */
@property (nonatomic, readonly) KandyChatService* chat;

/**
 *  Call service - serves all calling process
 */
@property (nonatomic, readonly) KandyCallService* call;

/**
 *  Events service - serves events related process
 */
@property (nonatomic, readonly) KandyEventService* events;
/**
 *  PushNotification service - serves all remote notifications related process
 */
@property (nonatomic, readonly) KandyPushNotificationService* push;

/**
 *  Contacts service - serves all contacts related process
 */
@property (nonatomic, readonly) KandyContactsService* contacts;

/**
 *  GroupService - serves all group related process
 */
@property (nonatomic, readonly) KandyGroupService* group;

/**
 *  ProfileService - serves all profile related process
 */
@property (nonatomic, readonly) KandyProfileService* profile;

/**
 *  BillingService - serves all billing related process
 */
@property (nonatomic, readonly) KandyBillingService* billing;

/**
 *  CloudStorageService - serves all media transfer related process
 */
@property (nonatomic, readonly) KandyCloudStorageService* cloudStorage;
/**
 *  MultiPartyConferenceService - serves multi party conference related process
 */
@property (nonatomic, readonly) KandyMultiPartyConferenceService* multiPartyConference;

@end
