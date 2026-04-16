//
//  ZJ_CJ_RewardVideoSlot.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/9.
//

#import <ZJ_CJAdSDK/ZJ_CJAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_CJ_RewardVideoSlot : ZJ_CJ_Slot

/// userId 媒体用户id，用于发奖使用
@property (nonatomic,   copy) NSString *userId;

/// 任务完成之后，是否需要后端检查验证任务有效性，默认NO
@property (nonatomic, assign) BOOL needSevrCheck;

@end

NS_ASSUME_NONNULL_END
