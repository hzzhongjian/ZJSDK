//
//  TXAdRewardManager.h
//  TanxSDK
//
//  Created by tongyuecheng on 2023/5/26.
//  Copyright © 2023 tanx.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TXAdRewardVideoRewardInfo.h"
#import "TXAdModel.h"
#import "TXAdManagerDelegate.h"
#import "TXAdRewardVideoSlotModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TXAdRewardAdsDelegate <NSObject,TXAdManagerDelegate>
@optional

/**
 *  视频下载成功回调（仅激励视频回调）
 *  @param model 数据model
 */
- (void)onAdDidDownLoadSuccessWithModel:(TXAdModel *)model;

/**
 *  视频下载失败回调（仅激励视频回调）
 *  @param model 数据model
 */
- (void)onAdDidDownLoadFailWithModel:(TXAdModel *)model;

/**
 * 广告跳过回调
 * @param model 数据model
 */
- (void)onAdDidSkipWithModel:(TXAdModel *)model;

/**
 * 激励视频播放完成或者出错，废弃中
 * @param error nil代表播放成功
 * @param model 数据model
 */
- (void)onAdDidFinishPlayingError:(nullable NSError *)error
                        withModel:(TXAdModel *)model NS_UNAVAILABLE;

/**
 * 激励视频播放完成
 * @param model 数据model
 */
- (void)onAdDidPlayFinish:(TXAdModel *)model;

/**
 * 激励视频播放错误
 * @param model 数据model
 * @param error 播放错误
 */
- (void)onAdDidPlayFailed:(TXAdModel *)model
                    error:(nullable NSError *)error;

/**
 * 发奖回调（激励视频、激励浏览回调，仅回调一次）
 * @param rewardInfo 发奖信息（优先使用rewardInfo.rewardInfoDict的数据，
 *                          如rewardInfoDict为nil，使用model确定是哪个广告）
 * @param model 数据model
 */
- (void)onAdDidReceiveRewardInfo:(TXAdRewardVideoRewardInfo *)rewardInfo
                       withModel:(nullable TXAdModel *)model;

/**
 * 发奖回调（激励唤端回调，仅回调一次）
 *
 * @param list 发奖信息（会包含多个发奖信息 TXAdRewardVideoRewardInfo）
 */
- (void)onAdDidReceiveRewardInfoList:(NSArray *)list;

/**
 *  查询发奖接口请求完成回调（代表当次查询发奖完成）废弃中
 */
- (void)onAdQueryRewardPrizeInfoComplete NS_UNAVAILABLE;

@end

@interface TXAdRewardManager : NSObject

/**
 * 回调代理
 */
@property(nonatomic, weak) id<TXAdRewardAdsDelegate> delegate;

/**
 * 初始化方法
 *
 * @param pid 广告pid
 */
- (instancetype)initWithPid:(NSString *)pid NS_DESIGNATED_INITIALIZER;

/**
 *  初始化方法
 *
 *  @param  slotModel 广告配置参数model，存放pid等参数
 *  @return instancetype
 */
- (instancetype)initWithSlotModel:(TXAdRewardVideoSlotModel *)slotModel NS_DESIGNATED_INITIALIZER;

/**
 * 获取激励广告
 *
 * @param adsDataBlock  广告数据block
 */
- (void)getRewardAdsWithAdsDataBlock:(TXGetAdDatasBlock)adsDataBlock;

/**
 * 上报竞价结果
 *
 * @param  model 数据model(请求数据的回调里拿到的model)
 * @param  result 竞价结果yes/no
 */
- (void)uploadBidding:(TXAdModel *)model result:(BOOL)result;

/**
 * 展示激励广告
 *      0、广告数据类型是视频， onAdDidDownLoadSuccessWithModel: 回调过后调用
 *      1、广告数据是换端类型，会进行换端；失败，则展示普通激励广告
 *
 * @param viewController  不能为nil，当前所在VC
 * @param adModel                  不能为nil，广告数据model
 * @param openType                不能为nil，如果传入Vc没有navigationController，则使用present方式打开
 * @return NSError                   校验admoel、vc，如错误返回错误信息
 */
- (nullable NSError *)showAdFromRootViewController:(UIViewController *)viewController
                                         withModel:(TXAdModel *)adModel
                                          openType:(TXAdViewOpenType)openType;

/**
 *  查询发奖接口：
 *      0、通过delegate方法 onAdDidReceiveRewardInfo:withModel:返回当前用户所有发奖结果
 *      1、如无发奖信息，delegate方法不会回调
 *
 *  @param mediaUid   接入方用户id，查询发奖使用；必传
 *  @param pidsList   广告pid数组；必传
 */
- (void)queryRewardPrizeInfoWithMediaUid:(NSString *)mediaUid
                                pidsList:(NSArray *)pidsList;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

