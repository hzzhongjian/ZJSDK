//
//  WindHCDataResponse.h
//  WindHTTPCache
//
//  Created by Single on 2017/8/24.
//  Copyright © 2017年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/WindHCRange.h>

@interface WindHCDataResponse : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, copy, readonly) NSURL *URL;
@property (nonatomic, copy, readonly) NSDictionary *headers;
@property (nonatomic, copy, readonly) NSString *contentType;
@property (nonatomic, copy, readonly) NSString *contentRangeString;
@property (nonatomic, readonly) WindHCRange contentRange;
@property (nonatomic, readonly) long long contentLength;
@property (nonatomic, readonly) long long totalLength;

@end
