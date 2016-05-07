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
#import "KandyContactsServiceEnums.h"
#import "KandyContactsServiceNotificationDelegate.h"
#import "KandyContactProtocol.h"
#import "KandyContactParams.h"

/**
 *  Register/Unregister the incoming messages for the Contacts service
 *  Return the device contacts in the response callback
 */
@interface KandyContactsService : NSObject

/**
 *  Register the incoming messages the client receives from the Contacts service
 *
 *  @param chatServiceResponseDelegate the delegate
 */
-(void) registerNotifications:(NSObject<KandyContactsServiceNotificationDelegate>*)notificationDelegate;

/**
 *  Stop listening to Contacts notifications
 *
 *  @param notificationDelegate conforms to protocol KandyProvisionNotificationDelegate
 */
-(void) unregisterNotifications:(id<KandyContactsServiceNotificationDelegate>)notificationDelegate;

#pragma mark - Device Address Book
/**
 *  Returns the device contacts as <KandyContactProtocol> objects in an array in the response callback. If operation failed, return an error.
 *
 */
-(void)getDeviceContactsWithResponseCallback:(void(^)(NSError* error, NSArray* kandyContacts))responseCallback;

/**
 *  Returns the device contacts as <KandyContactProtocol> objects in an array in the response callback. If operation failed, return an error. Filters contact according kandyContactFilter and text in textSearch (filtering the displayName). If textSearch is empty or nil, does not filter by text.
 *
 *  @param kandyContactFilter EKandyContactFilter specifying whether to display all contacts, contacts with emails and/or contacts with phone.
 *  @param textSearch         Filtering done on the displayName
 *  @param responseCallback   A callback with <KandyContactProtocol> objects in an array if operation succeeded or error if operation failed.
 */
-(void)getDeviceContactsWithFilter:(EKandyDeviceContactFilter)kandyContactFilter textSearch:(NSString*)textSearch responseCallback:(void(^)(NSError* error, NSArray* kandyContacts))responseCallback;

#pragma mark - Domain Directory Address Book
/**
 *  Returns the domain contacts as <KandyContactProtocol> objects in an array in the response callback. If operation failed, return an error.
 *
 *  @param responseCallback a callback with <KandyContactProtocol> objects in an array if operation succeeded or error if operation failed.
 */
-(void)getDomainDirectoryContactsWithResponseCallback:(void(^)(NSError* error, NSArray* kandyContacts))responseCallback;

/**
 *  Returns the domain contacts as <KandyContactProtocol> objects in an array in the response callback. If operation failed, return an error. Filters contact according to filterType and text in textSearch.
 *
 *  @param textSearch       the text to search in the fields indicated by filterType.
 *  @param filterType       the fields in which to search for the text.
 *  @param caseSensitive    Boolean value indicating whether or not the search is case sensitive.
 *  @param responseCallback A callback with <KandyContactProtocol> objects in an array if operation succeeded, or error if operation failed.
 */
-(void)getFilteredDomainDirectoryContactsWithTextSearch:(NSString*)textSearch filterType:(EKandyDomainContactFilter)filterType caseSensitive:(BOOL)caseSensitive responseCallback:(void(^)(NSError* error, NSArray* kandyContacts))responseCallback;

#pragma mark - Personal Address Book
/**
 *  Returns the personal contacts as <KandyContactProtocol> objects in an array in the response callback. If operation failed, return an error.
 *
 *  @param responseCallback a callback with <KandyContactProtocol> objects in an array if operation succeeded or error if operation failed.
 */
-(void)getPersonalAddressBookWithResponseCallback:(void(^)(NSError* error, NSArray* kandyContacts))responseCallback;

/**
 *  Add a contact to the personal addressbook
 *
 *  @param params           KandyContactParams used to create the KandyContact
 *  @param responseCallback a callback with the created <KandyContactProtocol> object if operation succeeded or error if operation failed.
 */
-(void)addPersonalConatct:(KandyContactParams*)params responseCallback:(void(^)(NSError* error, id<KandyContactProtocol>kandyContact))responseCallback;

/**
 *  Update a contact from the personal addressbook
 *
 *  @param params           KandyContactParams used to update the KandyContact - must contain a valid contactID
 *  @param contactID        the contactID of the contact to update
 *  @param responseCallback a callback with the updated <KandyContactProtocol> object if operation succeeded or error if operation failed.
 */
-(void)updatePersonalContact:(KandyContactParams*)params contactID:(NSString*)contactID responseCallback:(void(^)(NSError* error, id<KandyContactProtocol>kandyContact))responseCallback;

/**
 *  Delete a contact from the personal addressbook
 *
 *  @param contactID        the contactID of the contact to delete
 *  @param responseCallback completion block that returns an error incase of failure, otherwise nil
 */
-(void)deletePersonalContact:(NSString*)contactID responseCallback:(void(^)(NSError* error))responseCallback;

#pragma mark - VCard
/**
 *  Create VCard by contact. If the contact has nativeRecordId, used in order to take the full contact data from the native addressBook.
 *
 *  @param kandyContact    the KandyContact we are using to create VCard data
 *  @param completionBlock completion block that gives us the VCard data if succeeded, otherwise nil
 
 */
-(void) createVCardDataByContact:(id<KandyContactProtocol>)kandyContact completionBlock:(void (^)(NSError* error, NSData* vCardData))completionBlock;

/**
 *  Create KandyContact using VCard data
 *
 *  @param vCardData the VCard from which to take the contact data
 *  @param error     out param, to be filled with error in case the cotnact creation failed
 *
 *  @return KandyContact if succeeded, otherwise nil
 */
-(id<KandyContactProtocol>) createContactByVCard:(NSData*)vCardData error:(NSError**)error;

@end
