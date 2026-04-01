//
//  JTAdSlot.h
//  JTAdSDK
//
//  Created by Frank on 2025/6/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 广告位模型
@interface JTAdSlot : NSObject

/// 广告位唯一ID
@property (nonatomic, copy) NSString * slotId;

/// 期望广告视图（View）的大小，单位：pt
@property (nonatomic, assign) CGSize adSize;

/// 期望素材中图片View的大小，单位：pt
@property (nonatomic, assign) CGSize imgSize;

@end

NS_ASSUME_NONNULL_END
