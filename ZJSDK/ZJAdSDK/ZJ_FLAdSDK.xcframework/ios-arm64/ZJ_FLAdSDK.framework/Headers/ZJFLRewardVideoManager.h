//
//  ZJFLRewardVideoManager.h
//  ZJ_FLAdSDK
//
//  Created by lurich on 2021/10/19.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_FLAdSDK/ZJFLBaseAdManager.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJFLRewardVideoDelegate <NSObject>

@optional
//回调已全部转为主线程
/**
 * 激励视频广告-视频-加载成功
 */
- (void)rewardedVideoDidLoad;

/**
 * 激励视频广告素材加载失败
 * @param error 错误对象
 */
- (void)rewardedVideoDidFailWithError:(NSError *)error;

/**
 * 激励视频广告成功展示
 */
- (void)rewardedVideoDidVisible;

/**
 * 激励视频广告展示失败
 */
- (void)rewardedVideoFailToVisible:(NSError *)error;

/**
 * 激励视频广告点击
 */
- (void)rewardedVideoDidClick;

/**
 * 激励视频广告播放达到激励条件
 * @param extra 额外参数，即初始化传入的extra
 */
- (void)rewardedVideoDidRewardEffectiveWithExtra:(NSDictionary *)extra;

/**
 * 激励视频广告服务端校验失败
 * @param error 错误原因
 */
- (void)rewardedVideoDidRewardServerDidFail:(NSError *)error;

/**
 * 激励视频广告已经关闭
 */
- (void)rewardedVideoDidClose;

@end

@interface ZJFLRewardVideoManager : ZJFLBaseAdManager

/**
 * 广告回调的代理
 */
@property (nonatomic, weak) id<ZJFLRewardVideoDelegate> delegate;

/**
 * 用户ID可选
 */
@property (nonatomic, copy) NSString *userId;

/**
 * 加载广告数据
 * @param extra 额外参数
 */
- (void)loadAdDataWithExtra:(NSDictionary * _Nullable)extra;

/// 展示激励视频广告
- (void)showRewardVideoAdWithController:(UIViewController *)showAdController;

@end

NS_ASSUME_NONNULL_END
