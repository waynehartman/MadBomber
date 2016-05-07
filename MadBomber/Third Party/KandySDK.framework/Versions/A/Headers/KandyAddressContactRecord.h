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
#import "KandyAddressContactRecordProtocol.h"

/**
 *  Class representing a KandyAddressContactRecord, conforming to KandyAddressContactRecordProtocol.
 Used to set the ReadOnly properties of the protocol.
 */
@interface KandyAddressContactRecord : NSObject<KandyAddressContactRecordProtocol>

/**
 *  Initialization method for KandyAddressContactRecord
 *
 *  @param newServerIdentifier KandyRecord - the server identifier
 *  @param aStreet             the street (optional)
 *  @param aCity               the city (optional)
 *  @param aState              the state (optional)
 *  @param aZip                the zip (optional)
 *  @param aCountry            the country (optional)
 *  @param aCountryCode        the country code (optional)
 *  @param aDataByKey          extra data for the record
 *
 *  @return Initialized KandyAddressContactRecord
 */
-(instancetype)initWithServerIdentifier:(KandyRecord*)newServerIdentifier street:(NSString*)aStreet city:(NSString*)aCity state:(NSString*)aState zip:(NSString*)aZip country:(NSString*)aCountry countryCode:(NSString*)aCountryCode dataByKey:(NSDictionary*)aDataByKey;

@end
