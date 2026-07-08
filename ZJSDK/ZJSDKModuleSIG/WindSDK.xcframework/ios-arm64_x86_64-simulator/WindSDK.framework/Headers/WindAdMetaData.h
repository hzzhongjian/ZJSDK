//
//  WindAdMetaData.h
//  WindSDK
//
//  Created by duyuwei on 2025/5/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface WindAdMetaData : NSObject

/// 广告id、广告唯一标识
@property (nonatomic, copy, readonly, nullable) NSString *adId;

/// saasADX信息
@property (nonatomic, copy, readonly, nullable) NSDictionary<NSString *, NSString *> *saasOptions;


@end

NS_ASSUME_NONNULL_END
