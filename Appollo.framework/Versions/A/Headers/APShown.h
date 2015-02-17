//
//  APShowed.h
//  Appollo
//
//  Created by Simon Urzua on 09/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModel.h"

@protocol APShown @end

@interface APShown : JSONModel

@property (nonatomic, strong) NSDate *when;

@end
