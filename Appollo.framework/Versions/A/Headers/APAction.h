//
//  APAction.h
//  Appollo
//
//  Created by Simon Urzua on 03/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import "JSONModel.h"

typedef NS_ENUM( NSUInteger, APActionType )
{
    APActionTypeForeground,
    APActionTypeURL,
    APActionTypeCustom
};

/**
 * Action to fire when notification was received
 */
@interface APAction : JSONModel

/**
 * Type of action
 */
@property (assign, nonatomic) APActionType type;

/**
 * URL to open when notification was received
 */
@property (strong, nonatomic) NSURL<Optional> *url;

/**
 * Payload attached on control panel to notification
 */
@property (strong, nonatomic) id<Optional> data;

- (void)fire;

@end
