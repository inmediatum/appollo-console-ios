//
//  APSync.h
//  Appollo
//
//  Created by Simon Urzua on 03/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import "JSONModel.h"
#import "APGeotag.h"
#import "APBeacon.h"

typedef void (^APTagsSync)(BOOL success);

/**
 * Group of APTags.
 */
@interface APTags : JSONModel

@property (assign, nonatomic) float version;
@property (strong, nonatomic) NSArray<APBeacon> *beacons;
@property (strong, nonatomic) NSArray<APGeotag> *geotags;

/**
 * Trigger syncronization with Appollo Server.
 */
+ (void)sync;

/**
 * Trigger syncronization with Appollo Server. Excecute a block when ready
 */
+ (void)syncWithComplete:(APTagsSync)onComplete;

/**
 * All now available APGeotag and APBeacon
 */
+ (APTags *)tags;

/**
 * All now available APBeacon
 */
+ (NSArray *)beacons;

/**
 * All now available APGeotag
 */
+ (NSArray *)geotags;

+ (void)saveTags;

+ (APGeotag *)findGeotagWithRegion:(CLRegion *)region;
+ (APBeacon *)findBeaconWithRegion:(CLRegion *)region;

/**
 * Returns a APTag with identifier.
 */
+ (APTag *)findTagWithIdentifier:(NSString *)identifier;

@end