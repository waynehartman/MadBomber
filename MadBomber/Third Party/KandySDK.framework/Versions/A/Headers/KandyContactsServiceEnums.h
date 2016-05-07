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

#ifndef KandySDK_KandyAddressServiceEnums_h
#define KandySDK_KandyAddressServiceEnums_h

static NSString * const KandyContactsServiceErrorDomain = @"contactsServiceErrorDomain";

typedef NS_ENUM(NSUInteger, EKandyContactsServiceError) {
    /**
     Invalid index
     */
    EKandyContactsServiceError_invalidIndex,
    /**
     Contacts error
     */
    EKandyContactsServiceError_contactsError,
    /**
     *  VCard file corrupted
     */
    EKandyContactsServiceError_vCardFileCorrupted,
    /**
     *  Could not create VCard for contact
     */
    EKandyContactsServiceError_vCardCreationFailed,
    /**
     Total number of values
     */
    EKandyContactsServiceError_count
};

/**
 *  Describes the type of Contacts value in classes conforming to KandyContactRecordProtocol
 */
typedef NS_ENUM(NSUInteger, EKandyContactRecordType)
{
    /**
     *  Value type is phone
     */
    EKandyContactRecordType_phone,
    /**
     *  Value type is email
     */
    EKandyContactRecordType_email,
    /**
     *  Value type is address
     */
    EKandyContactRecordType_address,
    /**
     *  Value type is social profile
     */
    EKandyContactRecordType_socialProfile
};

/**
 *  The type Contact social profile
 */
typedef NS_ENUM(NSUInteger, EKandyContactRecordSocialProfileType)
{
    /**
     *  Social profile unknown
     */
    EKandyContactRecordSocialProfileType_unknown = 0,
    /**
     *  Facebook social profile
     */
    EKandyContactRecordSocialProfileType_facebook = 1,
    /**
     *  Twitter social profile
     */
    EKandyContactRecordSocialProfileType_twitter = 2,
    /**
     *  LinkedIn social profile
     */
    EKandyContactRecordSocialProfileType_linkedIn = 3
};

/**
 *  The type of Contact fields' filter
 */
typedef NS_ENUM(NSUInteger , EKandyDeviceContactFilter)
{
    /**
     *  All Contacts
     */
    EKandyDeviceContactFilter_all          = 1 << 0,
    /**
     *  Only Contacts with emails
     */
    EKandyDeviceContactFilter_email        = 1 << 1,
    /**
     *  Only Contacts with phones
     */
    EKandyDeviceContactFilter_phone        = 1 << 2
};

/**
 *  The fields by which to filter the domain address book.
 */
typedef NS_ENUM(NSUInteger , EKandyDomainContactFilter)
{
    /**
     *  Filter contact's first and last name, userId and phone
     */
    EKandyDomainContactFilter_all,
    /**
     *  Filer contact's first and last name
     */
    EKandyDomainContactFilter_firstAndLastName,
    /**
     *  Filter contact's userId
     */
    EKandyDomainContactFilter_userId,
    /**
     *  Filter contact's phone
     */
    EKandyDomainContactFilter_phone
};


#endif
