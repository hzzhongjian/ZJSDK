//
//  ZJContextProvider.h
//
//  Created by Rare on 2021/7/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJContextProvider : NSObject


+ (NSString *)IDFA;

+ (NSString *)UUID;

+ (NSString *)IDFV;

+ (NSString *)renderTier;

+ (NSString *)adSlot;

+ (NSString *)envVer;

+ (NSString *)model;

+ (NSString *)getChannelId;

/// 用来标识唯一设备ID的, 使用场景是，一次请求，追踪用户操作流程，再次请求就会生成新的uuid
+ (NSString *)uniqueUUID;

+ (NSString *)linkQuality;

@end

NS_ASSUME_NONNULL_END
