//
//  APCore.h
//  Appollo
//
//  Created by Simon Urzua on 03/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APMonitor.h"
@import UIKit;

typedef void (^APCoreSync)(UIBackgroundFetchResult result);

/**
 * Main Appollo class
 */
@interface APCore : NSObject

/**
 * Initialize the Appollo Api
 */
+ (void)appolloWithApiKey:(NSString *)apiKey useBackgroundRefresh:(BOOL)backgroundRefresh;

/**
 * Returns actual Api Key
 */
+ (NSString *)retrieveApiKey;

/**
 * Replace the actual Api Key
 */
+ (void)replaceApiKey:(NSString *)apiKey;

/**
 * Returns actual APMonitor
 */
+ (APMonitor *)monitor;

/**
 * Synchronize listeners with Appollo Api when a change in control panel was made.
 */
+ (void)fetchUpdateInBackground:(APCoreSync)callback;

/**
 * Subscribe to control panel updates.
 */
+ (void)suscribeToChangesNotifications:(NSData *)deviceToken;

/**
 * Translate a local notification to APTag
 */
+ (APTag *)didReceiveLocalNotification:(UILocalNotification *)notification;


@end