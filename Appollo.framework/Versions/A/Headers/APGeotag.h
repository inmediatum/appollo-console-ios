//
//  APGeotag.h
//  Appollo
//
//  Created by Simon Urzua on 03/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import "APTag.h"
#import "JSONModel.h"

@import CoreLocation;

@protocol APGeotag @end

/**
 * Location in the map
 */
@interface APGeotag : APTag

// Specific

/**
 * Map latitude
 */
@property (assign, nonatomic) double latitude;

/**
 * Map longitude
 */
@property (assign, nonatomic) double longitude;

/**
 * Range in meters form the central point.
 */
@property (assign, nonatomic) NSUInteger radius;

@property (nonatomic, copy, readonly) CLCircularRegion<Optional> *region;

@end
