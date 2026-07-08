//
//  WindRewardInfo.h
//  WindSDK
//
//  Created by Codi on 2021/4/7.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSString *WindRewardInfoKey NS_STRING_ENUM;
///  交易id
FOUNDATION_EXPORT const WindRewardInfoKey _Nonnull WindRewardInfoTransIdKey;
/// 奖励类型 0：普通类型 1:服务端奖励
FOUNDATION_EXPORT const WindRewardInfoKey _Nonnull WindRewardInfoRewardTypeKey;
/// 服务器奖励到达状态 0：未到达 1:到达
FOUNDATION_EXPORT const WindRewardInfoKey _Nonnull WindRewardInfoServerRewardStateKey;

@interface WindRewardInfo : NSObject

/// 开发者可以根据激励回调中该参数进行奖励的发放
/// 对应激励回调：- (void)rewardVideoAd:reward:
@property (nonatomic,assign) BOOL isCompeltedView;

///
@property (nonatomic, strong, nullable) NSError *error;


/// 扩展字段
@property (nonatomic, strong, nullable) NSDictionary <WindRewardInfoKey, id> *  option;

@end
