//
//  SMFoundation.h
//  SMExtensionExample
//
//  Created by SM Lee on 14/7/16.
//  Copyright (c) 2014年 小码哥. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SMFoundation : NSObject

+ (BOOL)isClassFromFoundation:(Class)c;
+ (BOOL)isFromNSObjectProtocolProperty:(NSString *)propertyName;

@end
