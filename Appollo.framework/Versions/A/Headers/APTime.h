//
//  APTime.h
//  Appollo
//
//  Created by Simon Urzua on 03/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import "JSONModel.h"

@protocol APTime
@end

typedef NS_ENUM( NSUInteger, APTimeDay )
{
    APTimeDaySunday = 1,
    APTimeDayMonday,
    APTimeDayTuesday,
    APTimeDayWednesday,
    APTimeDayThursday,
    APTimeDayFriday,
    APTimeDaySaturday
    
};

@interface APTime : JSONModel

/**
 * Day to show notification
 */
@property (assign, nonatomic) APTimeDay day;

/**
 * Start Hour in 0-23 range
 */
@property (assign, nonatomic) NSUInteger startHour;

/**
 * Start minute in 0-59 range
 */
@property (assign, nonatomic) NSUInteger startMin;

/**
 * End hour in 0-23 range
 */
@property (assign, nonatomic) NSUInteger endHour;

/**
 * End minute in 0-59 range
 */
@property (assign, nonatomic) NSUInteger endMin;

- (BOOL)inTime;

@end
