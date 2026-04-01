//
//  BidReason.h
//  ZJ_SSFWAdSDK
//
//  Created by yongjiu on 2025/1/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    /// 比普通常规广告低
    BidLossCodeNormal = 1001,
    /// 比竞价广告低
    BidLossCodeHB = 1002,
    /// 竞价超时 如长时间无竞价结果通知mp sdk
    BidLossCodeTimeout = 1003,
    /// 广告换成过期
    BidLossCodeExpire = 1004,
    /// 其他
    BidLossCodeOther = 1005,
} ZJ_SSFWBidLossCode;

typedef enum : NSInteger {
    ZJ_SSFWADNIDCSJ = 101,        // 穿山甲
    ZJ_SSFWADNIDYLH = 102,        // 优量汇
    ZJ_SSFWADNIDBD = 103,         // 百度
    ZJ_SSFWADNIDKS = 104,         // 快手
    ZJ_SSFWADNIDADMOB = 108,      // AdMob
    ZJ_SSFWADNIDMINTEGRAL = 109,  // Mintegral
    ZJ_SSFWADNIDSIGMOB = 110,     // Sigmob
    ZJ_SSFWADNIDOTHER = -1        // 其他
} ZJ_SSFWADNID;

@interface ZJ_SSFWBidReason : NSObject

/* ==========竞价失败时使用============ */
/// 竞价失败code
@property(nonatomic,assign)ZJ_SSFWBidLossCode lossCode;
/// 当lossCode == BidLossCodeOther时 可以传递自定义的竞价失败原因
@property(nonatomic,copy)NSString *lossOtherReason;
/// 竞胜方价格
@property(nonatomic,assign)double winPrice;
/// 竞胜方渠道id
@property(nonatomic,assign)ZJ_SSFWADNID winAdnId;
/// 额外字段 用于媒体自定义 key value 均为NSString 类型
@property(nonatomic,strong)NSDictionary<NSString *,NSString *> *extra;


@property(nonatomic,strong,readonly)NSDictionary<NSString *,NSString *> *lossParams;


@end

NS_ASSUME_NONNULL_END
