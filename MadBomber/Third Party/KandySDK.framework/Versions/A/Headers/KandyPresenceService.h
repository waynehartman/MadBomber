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
#import "KandyPresenceServiceEnums.h"
#import "KandyPresenceServiceNotificationDelegate.h"


/**
 * This interface handles:
 *    - Retrieval of presence data for contacts
 */
 
@interface KandyPresenceService : NSObject

/**
 *  Start listening to notification on call service
 *
 *  @param notificationDelegate conforms to protocol KandyPresenceServiceNotificationDelegate
 */
- (void)registerNotifications:(id <KandyPresenceServiceNotificationDelegate> )notificationDelegate;

/**
 *  Stop listening to notification on call service
 *
 *  @param notificationDelegate conforms to protocol KandyPresenceServiceNotificationDelegate
 */
- (void)unregisterNotifications:(id <KandyPresenceServiceNotificationDelegate> )notificationDelegate;

/**
 *  Gets the Laste seen date for the KandyRecords passed as records parameter, and returns it in the response callback as <KandyPresenceProtocol> objects. Also returns requested KandyRecords for which no presence data was found.
 *
 *  @param records            an array of KandyRecords
 *  @param responseCallback   the completion block with preseceObjects containing <KandyPresenceProtocol> objects with the Presence data, or an error if an error has occured. Also returns requested KandyRecords for which no presence data was found.
 */
- (void)getLastSeenForRecords:(NSArray *)records
             responseCallback:(void(^)(NSError* error, NSArray * presenceObjects, NSArray * missingPresenceKandyRecords))responseCallback;
/**
 *  Retrieves the Presence data for the KandyRecords passed as records parameter, and returns it in the response callback as <KandyPresenceProtocol> objects.
 *
 *  @param records          An array of KandyRecords
 *  @param responseCallback The completion block with an error if an error has occured.
 */
-(void)getPresenceStateForRecords:(NSArray *)records
             responseCallback:(void(^)(NSError* error))responseCallback;

/**
 * Updates the user's presence state

 * @param isOnline Is user online or offline
 * @param type The presence activity type (ex: EKandyPresenceType_busy, EKandyPresenceType_outToLunch...)
 * @param responseCallback Block that will be called upon update completion
 */
- (void)updateSelfPresenceState:(BOOL) online
           presenceActivityType:(EKandyPresenceType) type
           responseCallback:(void(^)(NSError* error))responseCallback;

/**
 * This method starts watching contacts, which are given in the list.

 * @param kandyRecords array of KandyRecords to start watching
 * @param responseCallback Block that will be called start watch completion containing error and array of NSString representing the user IDs
 */
- (void)startWatchPresenceForRecords:(NSArray *)kandyRecords
                responseCallback:(void(^)(NSError* error))responseCallback;

/**
 * This method stops watching the given kandyRecords
 * @param kandyRecords array of KandyRecords to start watching
 * @param responseCallback Block that will be called upon stop watch completion containing error and array of NSString representing the user IDs
 */
- (void)stopWatchPresenceForRecords:(NSArray *)kandyRecords
               responseCallback:(void(^)(NSError* error))responseCallback;

/**
 Stop watching all KandyRecords presence

 When your contacts are edited, you may wish to refresh your your presence list, since some contacts refrences might have changed.
 Call this method to clean all previous contacts, and start watch again with the new contacts

 @param responseCallback Block that will be called upon stop watch completion containing error and array of NSString representing the user IDs
 */
-(void)stopWatchAllRecordsWithResponseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  All KandyRecords currently being watched
 *
 *  @return NSArray contains KandyRecords
 */
- (NSArray*)watchedKandyRecords;



@end
