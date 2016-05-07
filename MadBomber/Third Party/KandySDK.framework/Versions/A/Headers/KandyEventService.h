//
//  KandyEventService.h
//  KandySDK
//
//  Created by Natan Zalkin on 4.11.2015.
//  Copyright © 2015 genband. All rights reserved.
//

#import "KandyRecord.h"
#import "KandyEventProtocol.h"

@interface KandyEventService : NSObject

/**
 *  Marks events as received
 *
 *  @param kandyEvents      a list of events to Ack
 *  @param responseCallback a callback containing a possible error
 */
-(void) markEventsAsReceived:(NSArray<id<KandyEventProtocol>>* _Nonnull)events responseCallback:(void(^ _Nullable)(NSError * _Nullable error))responseCallback;

/**
 *  Pull pending events from server
 *
 *  @param responseCallback in case of error, get error in the response callback, otherwise get the chat events
 */
-(void) pullPendingEventsWithResponseCallback:(void(^ _Nullable)(NSError * _Nullable error))responseCallback;

/**
 *  Get all conversations for current provisioned user
 *
 *  @warning This feature is considered experemental and could only be partially supported by the backend
 *
 *  @param responseCallback A callback that returns all destinations with which current provisioned user had communicates, or error if request was failed
 */
-(void) getAllConversationsWithResponseCallback:(void (^ _Nullable)(NSError * _Nullable error, NSSet<KandyRecord*> * _Nullable destinations))responseCallback;

/**
 *  Pull history events from the server for specific destination
 *
 *  @warning This feature is considered experemental and could only be partially supported by the backend
 *
 *  @param destination      The destination to pull history events for
 *  @param timestamp        The starting date to pull earlier or future events from
 *  @param moveForward      The pulling direction. Forward direction means pull future events from timestamp date specified. If set to NO will pull earlier events starting from timestamp date specified.
 *  @param maxCount         The maximum number of events to be pulled. If number of events on server is less than this number, all the events available will be pulled.
     If maxCount value provided is zero, all the events from the specified timestamp will be pulled
 *  @param responseCallback A callback that returns number of events pulled and flag indicating that more messages is awailabe to pull on success, or error if request was failed
 */
-(void) pullHistoryEventsForDestination:(KandyRecord * _Nonnull)destination timestamp:(NSDate * _Nonnull)timestamp moveForward:(BOOL)moveForward maxCount:(NSInteger)maxCount responseCallback:(void (^ _Nullable)(NSError * _Nullable error, NSInteger numberOfEventsReceived, BOOL hasMoreEventsToPull))responseCallback;

/**
 *  Pull all history events for all destinations user was communicating in the past
 *
 *  @warning This feature is considered experemental and could only be partially supported by the backend
 *
 *  @param timestamp        The starting date to pull earlier or future events from
 *  @param moveForward      The pulling direction. Forward direction means pull future events from timestamp date specified. If set to NO will pull earlier events starting from timestamp date specified.
 *  @param maxCount         The maximum number of events to be pulled. If number of events on server is less than this number, all the events available will be pulled.
     If maxCount value provided is zero, all the events from the specified timestamp will be pulled
 *  @param responseCallback A callback that returns number of events pulled and flag indicating that more messages is awailabe to pull on success, or error if request was failed
 */
-(void) pullHistoryEventsWithTimestamp:(NSDate * _Nonnull)timestamp moveForward:(BOOL)moveForward maxCount:(NSInteger)maxCount responseCallback:(void (^ _Nullable)(NSError * _Nullable error, NSSet<KandyRecord*> * _Nullable destinations, NSInteger numberOfEventsReceived, BOOL hasMoreEventsToPull))responseCallback;

/**
 *  Delete all conversations form history for current provisioning user
 *
 *  @param responseCallback A callback that returns error if request was failed, returns nil on success
 */
-(void) deleteAllConversationsWithResponseCallback:(void (^ _Nullable)(NSError * _Nullable error))responseCallback;

/**
 *  Delete all events from history for specified destinations
 *
 *  @param destinations     List of destinations
 *  @param responseCallback A callback that returns error if request was failed, returns nil on success
 */
-(void) deleteConversations:(NSArray<KandyRecord*>* _Nonnull)destinations responseCallback:(void (^ _Nullable)(NSError * _Nullable error))responseCallback;

/**
 *  Delete specific events from history for specified destination
 *
 *  @param events           List of UUIDs for events that will be deleted
 *  @param destination      A destination
 *  @param responseCallback A callback that returns error if request was failed, returns nil on success
 */
-(void) deleteHistoryEvents:(NSArray<NSString*>* _Nonnull)eventUUIDs destination:(KandyRecord* _Nonnull)destination responseCallback:(void (^ _Nullable)(NSError * _Nullable error))responseCallback;

@end
