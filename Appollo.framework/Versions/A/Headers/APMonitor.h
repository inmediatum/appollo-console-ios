//
//  APMonitor.h
//  Appollo
//
//  Created by Simon Urzua on 03/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import "JSONModel.h"
#import "APBeacon.h"
#import "APGeotag.h"

@import CoreLocation;

#pragma mark - Property Protocols

/**
 * Protocol for notificate when user accept required permissions and notificate when
 * notification did receive a notification
 */
@protocol APMonitorDelegate <NSObject>

@required

/**
 * Fired when notification was received
 */
- (void)didReceiveNotification:(APTag *)tag;

/**
 * Fired when user reject explicitly location permissions
 */
- (void)userRejectPermissions;

/**
 * Fired when user accept explicitly permissions
 */
- (void)userAcceptPermissions;

/**
 * Fired when the fisical device it's uncompatible with location or the user lock
 * the functionality, for example parent control
 */
- (void)uncompatibleDevice;

@end

@interface APMonitor : JSONModel <CLLocationManagerDelegate>

/**
 * APMonitorDelegate delegate
 */
@property (nonatomic) id<APMonitorDelegate> delegate;

- (void)requestAutorizationIfNeeded;
- (void)startMonitoringAll;
- (void)startMonitoringGeotags;
- (void)startRangingBeacons;
- (void)stopMonitoringGeotags;
- (void)stopRangingBeacons;
- (void)stopMonitoringAll;

- (void)restartMonitor;

@end
