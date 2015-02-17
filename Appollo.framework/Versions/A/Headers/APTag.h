//
//  APTag.h
//  Appollo
//
//  Created by Simon Urzua on 03/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import "APTime.h"
#import "APAction.h"
#import "JSONModel.h"
#import "APShown.h"

/**
 * Number of days that a notification can be fired
 */
typedef NS_ENUM( NSUInteger, APTagMultiReception )
{
    APTagMultiReceptionDisabled = 0,
    APTagMultiReceptionOnceTime = 999999
};

/**
 * Transition listener. iOS only support Enter and Exit transitions.
 */
typedef NS_ENUM( NSUInteger, APTagTrigger )
{
    APTagTriggerEnter,
    APTagTriggerExit,
    APTagTriggerStay
};

/**
 * Type of listener. Geotag or iBeacon
 */
typedef NS_ENUM( NSUInteger, APTagType )
{
    APTagTypeGeotag,
    APTagTypeBeacon
};

/**
 * All listeners extends from abstract APTag object. Represent a single listener and single notification.
 */
@interface APTag : JSONModel

/**
 * Unique identifier for notification. Only for internal use. Use "identifier" parameter instead this.
 */
@property (strong, nonatomic) NSString *notificationId;

/**
 * Literal message for notification
 */
@property (strong, nonatomic) NSString *message;

/**
 * Unique identifier defined by developer console.
 */
@property (strong, nonatomic) NSString *identifier;

/**
 * Determines the number of days to show same notification
 */
@property (assign, nonatomic) APTagMultiReception multiReception;

/**
 * Transition that trigger the notification.
 */
@property (assign, nonatomic) APTagTrigger trigger;

/**
 * Not used in iOS
 */
@property (strong, nonatomic) NSNumber<Optional> *dwellingTime;

/**
 * Object that represent the action to do when notification was received
 */
@property (strong, nonatomic) APAction *action;

/**
 * Array that contains the hours when notification can be fired
 */
@property (strong, nonatomic) NSArray<APTime> *time;

/**
 * Listener type. Geotag or iBeacon.
 */
@property (assign, nonatomic) NSNumber<Optional> *type;

@property (strong, nonatomic) NSDate<Optional> *shownDate;

@property (strong, nonatomic) NSArray<APShown, Optional> *shownTimes;

/**
 * Trigger notification in manual way
 */
- (BOOL)showNotification;

@end
