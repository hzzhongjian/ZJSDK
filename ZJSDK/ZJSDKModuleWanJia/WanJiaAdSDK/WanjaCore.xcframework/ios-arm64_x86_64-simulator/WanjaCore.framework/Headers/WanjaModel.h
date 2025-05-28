//
//  WanjaModel.h
//  WanjaCoreSDK
//
//  Created by guantou on 2020/1/6.
//

#import <Foundation/Foundation.h>

#if __has_include(<WanjaModel/WanjaModel.h>)
FOUNDATION_EXPORT double WanjaModelVersionNumber;
FOUNDATION_EXPORT const unsigned char WanjaModelVersionString[];
#import <WanjaModel/NSObject+WanjaModel.h>
#import <WanjaModel/WanjaClassIvarInfo.h>
#else
#import "NSObject+WanjaModel.h"
#import "WanjaClassInfo.h"
#endif
