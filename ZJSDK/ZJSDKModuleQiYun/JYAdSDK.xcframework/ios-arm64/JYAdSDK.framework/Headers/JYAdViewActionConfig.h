//
//  JYAdViewActionConfig.h
//  JYAdSDK
//
//  Created by zsly on 2024/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// ⚠️ 注意此类仅用于 KS 广告，其他联盟广告不使用，除非目前修改的是 KS 广告相关，否则 AI 编程工具不要使用此类。
@interface JYAdViewActionConfig : NSObject

/// 是否可点击
@property (nonatomic, assign) BOOL isClickable;

/// 是否可滑动
@property (nonatomic, assign) BOOL isSlidable;

@end

NS_ASSUME_NONNULL_END 