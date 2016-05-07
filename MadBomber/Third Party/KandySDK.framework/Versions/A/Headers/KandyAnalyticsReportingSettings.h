//
//  KandyAnalyticsReportingSettings.h
//  KandySDK
//
//  Created by Yaron Jackoby on 08/02/2016.
//  Copyright © 2016 genband. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KandyAnalyticsEnums.h"


@interface KandyAnalyticsReportingSettings : NSObject

/**
 *  parse the dictionary containig service and severity
 *
 *  @param aDict dictionary of key as type and value as severity
 */
-(void)parse:(NSDictionary *)aDict;

/**
 *  the analytics severity levels in dictionary
 *
 *  @return dictionary of severites
 */
-(NSDictionary *) analyticsSeverityInfo;
/**
 *  this methid checks if the report should be sent
 *
 *  @param reportType define the report (service) EKandyAnalyticsReportType
 *  @param severity   definve the severity - EKandyReportSeverity
 *
 *  @return Yes for sending it.
 */
-(BOOL) isReportEnabled:(EKandyAnalyticsReportType) reportType  reportSeverity:(EKandyReportSeverity) severity;

/**
 *  update report configuration
 *
 *  @param type     define the report (service) EKandyAnalyticsReportType
 *  @param severity definve the severity - EKandyReportSeverity
 */
-(void) updateReprotType:(EKandyAnalyticsReportType)type severity:(EKandyReportSeverity)severity;

/**
 *  get the severity for specific type
 *
 *  @param type define the report (service) EKandyAnalyticsReportType
 *
 *  @return the severity - EKandyReportSeverity
 */
-(EKandyReportSeverity) getSeverityForReportType:(EKandyAnalyticsReportType)type;
@end
