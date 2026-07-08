//
//  SigmobAdProtocol.h
//  WindSDK
//
//  Created by Codi on 2021/4/7.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol WindBiddingProtocol <NSObject>

///设置广告的底价，单位：分（仅支持bidding模式）
-(void)setBidFloor:(NSUInteger)bidFloor;

///参与竞价的结算模式(CNY:人民币；USD:美元) 默认：CNY
- (void)setCurrency:(NSString *)currency;

///返回广告对应的ecpm（该接口需要在广告加载成功之后会返回对应的ecpm），
///当非竞价广告时或者没有权限访问该部分会返回nil 单位：分
- (NSString *)getEcpm;

/// 返回广告对应的结算模式
/// 当非竞价广告时或者没有权限访问该部分会返回nil
- (NSString *)getCurrency;

/// invoke this method to set this actual auction price 调用此方法设置当前实际结算价
/// @param ecpm auction price 实际结算价格 单位分
- (void)setBidEcpm:(NSInteger)ecpm;

/**
 *  竞胜之后调用, 需要在调用广告 show 之前调用
 *
 *  @param winInfo 字典类型，必填。支持的key有
 *  AUCTION_PRICE：竞胜价格 (单位: 分)，值类型为NSNumber
 *  HIGHEST_LOSS_PRICE：最高失败出价，值类型为NSNumber
 *  CURRENCY：币种，默认CNY，美元：USD, 值类型为NSString
 *
 */
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;

/**
 *  竞败之后或未参竞调用
 *
 *  @pararm lossInfo 竞败信息，字典类型，必填，支持的key有
 *  AUCTION_PRICE ：竞胜价格 (单位: 分)，选填。值类型为NSNumber
 *  CURRENCY：币种，默认CNY，美元：USD, 值类型为NSString
 *  LOSS_REASON ：广告竞败原因，必填。竞败原因参考枚举WindAdBiddingLossReason中的定义，值类型为NSNumber
 *  ADN_ID ：竞胜方渠道ID，必填。值类型为NSNumber *
 *         1 ：sigmob；2：穿山甲；3: 腾讯广告；4:快手；5:百度；
 *         6:mtg；7:vungle；8:facebook；10001 ：其他
 */
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end



