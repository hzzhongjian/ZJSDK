//
//  WindHCDataCacheItem.h
//  WindHTTPCache
//
//  Created by Single on 2017/8/13.
//  Copyright © 2017年 Single. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WindHCDataCacheItemZone;

@interface WindHCDataCacheItem : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, copy, readonly) NSURL *URL;
@property (nonatomic, copy, readonly) NSArray<WindHCDataCacheItemZone *> *zones;
@property (nonatomic, readonly) long long totalLength;
@property (nonatomic, readonly) long long cacheLength;
@property (nonatomic, readonly) long long vaildLength;
/// 最后一次更新时间(单位：s)
@property (nonatomic, assign, readonly) NSTimeInterval updatedTime;
/// 创建时间(单位：s)
@property (nonatomic, assign, readonly) NSTimeInterval createdTime;
/// 修文件的更新时间为当前时间
- (void)updateModificationDate;

@end
