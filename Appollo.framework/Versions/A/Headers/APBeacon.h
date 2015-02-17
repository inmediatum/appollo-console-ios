//
//  APBeacon.h
//  Appollo
//
//  Created by Simon Urzua on 03/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import "APTag.h"
#import "JSONModel.h"

@import CoreLocation;

typedef NS_ENUM( NSUInteger, APBeaconDistance )
{
    APBeaconDistanceNear,
    APBeaconDistanceMid,
    APBeaconDistanceFar
};

@protocol APBeacon @end

/**
 * Location based on iBeacon bluetooth standard
 */
@interface APBeacon : APTag

/**
 * The UUID from the iBeacon
 */
@property (strong, nonatomic) NSString *uuid;

/**
 * Sensible proximity. We recommend manual calibration. Best value depends of terrain.
 */
@property (assign, nonatomic) APBeaconDistance distance;

/**
 * iBeacon major id
 */
@property (strong, nonatomic) NSNumber *majorId;

/**
 * iBeacon minor id
 */
@property (strong, nonatomic) NSNumber<Optional> *minorId;

@property (nonatomic, copy, readonly) CLBeaconRegion<Optional> *region;

@end
