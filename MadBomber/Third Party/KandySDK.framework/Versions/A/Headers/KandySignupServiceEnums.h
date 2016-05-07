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

#ifndef Fring_KandySignUpServiceEnums_h
#define Fring_KandySignUpServiceEnums_h

/**
 The Kandy signup service error domain name
 */
static NSString * const KandySignupServiceErrorDomain = @"SignupServiceErrorDomain";

typedef NS_ENUM(NSUInteger, EKandyValidationMethod)
{
    EKandyValidationMethod_sms, /** request incoming SMS deliver to validation code*/
    EKandyValidationMethod_call, /** request incoming voice call to deliver to validation code*/
    EKandyValidationMethod_email, /** request email to deliver to validation code*/
    EKandyValidationMethod_chat, /** request chat to deliver to validation code*/
    EKandyValidationMethod_unkonwn
};

typedef NS_ENUM(NSUInteger, EKandySignupServiceError) 
{
    EKandySignupServiceError_unknown = 0,
    
    
    EKandySignupServiceError_userValidationFailed = 1001, /** user validation failed*/
//    EKandySignupServiceError_MissingMandatoryRequestParameter,
//    EKandySignupServiceError_BadRequest,
//    EKandySignupServiceError_userNotFound = 1004,
    EKandySignupServiceError_failedSendingValidationCode = 1005, /** unable to send validation code*/
    EKandySignupServiceError_inconsistentDeviceIDInRegistrationAndValidation, /** device ID in registration and validation do not match*/
    EKandySignupServiceError_countryLookupFailed, /** unable to recognize country*/
    EKandySignupServiceError_noRegistrationForValidationRequest, /** could not find registration attempt for this validation request*/
    EKandySignupServiceError_registrationRequestLimitReached, /** registration attempts exeeded*/
    EKandySignupServiceError_validationCodeExpired, /** validation code expired*/
    EKandySignupServiceError_tooManyValidationTries, /** validation attempts exeeded*/
    
    EKandySignupServiceError_oneTimePasswordNotFound = 1013, /** validation code was not found*/
    EKandySignupServiceError_wrongValidationMethod  = 1017, /** invalid validation method*/
    
    EKandySignupServiceError_phoneNumberNormalizationFailed = 1018, /** phone number normalization failed*/
    EKandySignupServiceError_anotherRegistrationForTheUserIsInProgress = 1022, /** another registration for this user is already in progress*/
    EKandySignupServiceError_unconfirmedUser = 1023, /** user is not confirmed*/
    EKandySignupServiceError_countryNotAllowed = 1025, /** user country is not allowed for registration*/
    
    EKandySignupServiceError_numberOfRegisteredUsersExcceeded = 1026, /** number of registered users excceeded*/
    EKandySignupServiceError_numberOfRegisteredDevicesExcceeded = 1027, /** number of registered devices excceeded*/
    
    EKandySignupServiceError_provisionedUserNotFound, /** could not find provisioned user*/
    EKandySignupServiceError_numberNotAllowed
//    EKandySignupServiceError_userAlreadyExists, //new
//    EKandySignupServiceError_invalidUserId, //new
//    EKandySignupServiceError_invalidUserPassword, //new
};


#endif
