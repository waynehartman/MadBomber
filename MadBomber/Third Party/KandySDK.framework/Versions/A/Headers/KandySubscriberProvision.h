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
#import "KandySignUpServiceEnums.h"
#import "KandyDomain.h"
#import "KandyUserInfo.h"
#import "KandyAreaCode.h"
#import "KandyUserParams.h"
#import "KandyUserProvisionInfo.h"

/**
 * This interface is responsible for the following subscriber provisioning:
 *     - Domain validation
 *     - Request validation code 
 *     - Validate the received code
 *     - Deactivate the user
 *     - User device management
*/
@interface KandySubscriberProvision : NSObject

#pragma mark - Domain validation
/**
 *  Validate domain credentials
 *
 *  @param domainKey        The domain key
 *  @param secret           The domain secret
 *  @param responseCallback Callback that holds the domain name for success and error if occurs
 */
-(void) validateDomain:(NSString*)key domainSecret:(NSString*)secret responseCallback:(void(^)(NSError* error, NSString* domainName))responseCallback;

#pragma mark - User information
/**
 *  Retreive the user's details by its user ID
 *
 *  @param userId           the user identifier
 *  @param responseCallback Callback that holds the user info for success and error if occurs
 */
-(void) getUserDetails:(NSString*)userId responseCallback:(void(^)(NSError* error, KandyUserInfo* userInfo))responseCallback;

#pragma mark - Authenticate user
/**
 *  Request validation code for phone number in order to subscribe it
 *
 *  @param areaCode         KandyAreaCode with the relevant information
 *  @param phoneNumber      the number to register
 *  @param codeRetrivalMethod retrive Code Method @see KandySignUpServiceEnums.h
 *  @param responseCallback holds the destination to validate and error if occurs
 */
-(void) requestCode:(KandyAreaCode*)areaCode phoneNumber:(NSString*)phoneNumber codeRetrivalMethod:(EKandyValidationMethod)codeRetrivalMethod responseCallback:(void(^)(NSError* error, NSString *destinationToValidate))responseCallback;

/**
 *  Request validation code for phone number in order to subscribe it
 *
 *  @param areaCode         KandyAreaCode with the relevant information
 *  @param phoneNumber      the number to register
 *  @param codeRetrivalMethod retrive Code Method @see KandySignUpServiceEnums.h
 *  @param callerPhonePrefix The prefix to be used as a part of phone number of the incoming call that provides the validation code. Currently supported only for call method. Prefix string should contain only decimal numbers. Prefix string length should not be longer then 6 characters. If prefix string length is less then 6 characters it will be padded with '0' character added to the end of the string.
 *  @param responseCallback holds the destination to validate and error if occurs
 */
-(void) requestCode:(KandyAreaCode*)areaCode phoneNumber:(NSString*)phoneNumber codeRetrivalMethod:(EKandyValidationMethod)codeRetrivalMethod callerPhonePrefix:(NSString*)callerPhonePrefix responseCallback:(void(^)(NSError* error, NSString *destinationToValidate))responseCallback;

/**
 *  Validate the code you got
 *
 *  @param OTP              One-time password code (validation code)
 *  @param responseCallback Callback which returns when validation completes
 */
-(void) validateCode:(NSString *)OTP responseCallback:(void(^)(NSError* error))responseCallback;

#pragma mark - Provision user
/**
 *  Validate the code you got. When validation passed, the user will be provisioned in the system
 *
 *  @param OTP              One-time password code (validation code)
 *  @param destination      The number to register
 *  @param areaCode         KandyAreaCode with the relevant information
 *  @param responseCallback Callback that holds KandyUserInfo with the relevant information
 */
-(void) validateAndProvision:(NSString *)OTP destination:(NSString*)destination areaCode:(KandyAreaCode *)areaCode responseCallback:(void(^)(NSError* error, KandyUserInfo* provisionedUserInfo))responseCallback;

/**
 *  Deactivate the current device from the system.
 *
 *  @param responseCallback Callback which returns when disconnect finished. Returns error if falied.
 */
-(void) deactivateWithResponseCallback:(void(^)(NSError* error))responseCallback;

#pragma mark - User's device management
/**
 *  Add device to a provisioned user
 *
 *  @param provisionedUserInfo the provisioned user to add the device to
 *  @param responseCallback    a block of code to run when response returns, on success will return an updated KandyUserInfo object and error will be nil, on failure returns an error
 */
-(void) addUserDevice:(KandyUserInfo*)provisionedUserInfo responseCallback:(void(^)(NSError* error,KandyUserInfo* provisionedUserInfo))responseCallback;

/**
 *  Remove device to a provisioned user
 *
 *  @param provisionedUserInfo the provisioned user to add the device to
 *  @param responseCallback    a block of code to run when response returns,  on success the error will be nil, on failure returns an error
 */

-(void) removeUserDevice:(KandyUserInfo*)provisionedUserInfo responseCallback:(void(^)(NSError* error))responseCallback;

/**
 *  Provision User to the system
 *
 *  @param userInfo         The user to provision.
 *  @param userParams       The user to provision parameters.
 *  @param responseCallback A block of code to run when response returns, on success will return nil error and provisionedUserIno with the generated User,
 *  on failure returns an error and nil provisionedUserInfo
 */
-(void) provisionUser:(KandyUserInfo*)userInfo userParams:(KandyUserParams*)userParams responseCallback:(void(^)(NSError* error, KandyUserInfo * provisionedUserIno))responseCallback;


/**
 * Provision Info
 * @param userId        The userId (phone number, email)
 * @param responseCallback A block of code to run when response returns, on success will return nil error and provisionedUserIno with the generated User,
 *  on failure returns an error and nil provisionedUserInfo
 */
-(void) getUserProvisionInfo:(NSString *)phoneNumber countryCode:(NSString *)countryCode responseCallback:(void (^)(NSError *, KandyUserProvisionInfo *))responseCallback;
@end
