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
 *  The Contact fields keys to the dataByType dictionary in <KandyContactProtocol>
 */
/**
 *  Contact first name
 *  The value will be NSString
 */
#define kKandyContactFirstNameKey @"first_name"
/**
 *  Contact middle name
 *  The value will be NSString
 */
#define kKandyContactMiddleNameKey @"middle_name"
/**
 *  Contact last name
 *  The value will be NSString
 */
#define kKandyContactLastNameKey @"last_name"
/**
 *  Contact company
 *  The value will be NSString
 */
#define kKandyContactCompanyKey @"company"
/**
 *  Contact photo
 *  The value will be UIImage
 */
#define kKandyContactPhotoKey @"photo"
/**
 *  Contact thumbnail
 *  The value will be UIImage
 */
#define kKandyContactThumbnailKey @"thumbnail"
/**
 *  ID of record in iOS address book
 *  The value will be NSNumber
 */
#define kKandyContactRecordIDKey @"record_id"
/**
 *  Contact creation date
 *  The value will be NSDate
 */
#define kKandyContactCreationDateKey @"creation_date"
/**
 *  Contact modification date
 *  The value will be NSDate
 */
#define kKandyContactModificationDateKey @"modification_date"
/**
 *  Contact note
 *  The value will be NSString
 */
#define kKandyContactNoteKey @"note"
/**
 *  Contact associated DID
 *  The value will be NSString
 */
#define kKandyContactAssociatedDID @"associated_did"

@class KandyRecord;

/**
 * This protocol handles the contact protocol
 */
@protocol KandyContactProtocol <NSObject>

/**
 *  The contact ID as defined in the server
 */
@property (nonatomic, readonly) NSString* contactID;

/**
 *  Represents an identifier that is recognized by the server. For example: for making calls.
 */
@property (nonatomic, readonly) KandyRecord * serverIdentifier;

/**
 *  Kandy contact display name
 */
@property (nonatomic, readonly) NSString* displayName;

/**
 *  Array of phones. Objects in array of <KandyPhoneContactRecordProtocol>.
 */
@property (nonatomic, readonly) NSArray* phones;

/**
 *  Array of emails. Objects in array of <KandyEmailContactRecordProtocol>.
 */
@property (nonatomic, readonly) NSArray* emails;

/**
 *  Array of addresses. Objects in array of <KandyAddressContactRecordProtocol>.
 */
@property (nonatomic, readonly) NSArray* addresses;

/**
 *  Array of social profiles. Objects in array of <KandySocialProfileContactRecordProtocol>.
 */
@property (nonatomic, readonly) NSArray* socialProfiles;

/**
 *  Dictionary that contains additional data - User can add additional data to KandyContact by adding it to dataByType.
 */
@property (nonatomic, readonly) NSDictionary* dataByType;

@end
