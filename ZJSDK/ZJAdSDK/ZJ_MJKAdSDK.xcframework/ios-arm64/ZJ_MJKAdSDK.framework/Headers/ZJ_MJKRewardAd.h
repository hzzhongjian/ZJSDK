//
//  ZJ_MJKRewardAd.h
//  ZJ_MJKAdOS
//
//  Created by Harry Jiang on 7/5/25.
//

#import <Foundation/Foundation.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdError.h>
#import <UIKit/UIKit.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_MJKRewardAd;

@protocol ZJ_MJKRewardAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcRewardAdLoaded:(ZJ_MJKRewardAd *)rewardAd;

//广告加载失败
-(void)onMgcRewardAdError:(ZJ_MJKRewardAd *)rewardAd error:(ZJ_MJKAdError *)err;

//广告点击后回调
-(void)onMgcRewardAdClick:(ZJ_MJKRewardAd *)rewardAd;

//广告点击关闭后回调
-(void)onMgcRewardAdClose:(ZJ_MJKRewardAd *)rewardAd;

//广告展示展示回调
-(void)onMgcRewardAdShow:(ZJ_MJKRewardAd *)rewardAd;

//广告展示曝光回调
-(void)onMgcRewardAdDidExposure:(ZJ_MJKRewardAd *)rewardAd;

//广告隐藏回调
-(void)onMgcRewardAdHidden:(ZJ_MJKRewardAd *)rewardAd;

//广告播放完成
-(void)onMgcRewardAdDidFinish:(ZJ_MJKRewardAd *)rewardAd;

//广告数据回调
-(void)onMgcRewardAdData:(ZJ_MJKRewardAd *)rewardAd data:(NSDictionary *)data;

//视频广告播放开始
-(void)onMgcRewardAdVideoStart:(ZJ_MJKRewardAd *)rewardAd;

//视频广告播放结束
-(void)onMgcRewardAdVideoEnd:(ZJ_MJKRewardAd *)rewardAd;

//视频广告播放报错
-(void)onMgcRewardAdVideoError:(ZJ_MJKRewardAd *)rewardAd code:(NSString *)code msg:(NSString *)msg;

//广告内跳落地页打开回调
-(void)onMgcRewardAdLandingPageStart:(ZJ_MJKRewardAd *)rewardAd;

//广告内跳落地页关闭回调
-(void)onMgcRewardAdLandingPageClose:(ZJ_MJKRewardAd *)rewardAd;
@end

@interface ZJ_MJKRewardAd : NSObject

@property (nonatomic, assign)BOOL disableCache;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKRewardAdDelegate> _Nullable)delegate;

/**
 初始化
 extra 设置激励广告的激励值，广告成功回调后将返回
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKRewardAdDelegate> _Nullable)delegate;

/**
 加载广告
 */
- (void)loadAd;

/**
 当前控制器添加展示
 */
- (void)show;

/**
 preset new Controller展示
 */
- (void)presentShow;

/**
 当前控制器添加展示
 */
- (void)show:(UIViewController *)controller;

/**
 preset new Controller展示
 */
- (void)presentShow:(UIViewController *)controller;

/**
 重设ViewController
 */
- (void)resetViewController:(UIViewController *)controller;

/**
 重设代理
 */
- (void)resetDelegate:(id<ZJ_MJKRewardAdDelegate> _Nullable)delegate;

/**
 获取广告视图
 */
- (UIView *)getView;

/**
 销毁广告
 */
- (void)destroy;

/**
 获取真实宽高
 */
- (CGSize)getADRealSize;

/**
 获取extra信息
 */
- (NSDictionary *)getExtraData;

/**
 获取tagId
 */
- (NSString *)getTagId;

/**
 获取竞价数据
 */
- (NSInteger)getBidPrice;

/**
 广告是否超时
 */
- (BOOL) isDataTimeout;

/**
 有效缓存条数
 */
- (NSInteger) hasCache;

/**
 增加缓存
 广告缓存加载，可设置1-4条，如果设置数和缓存总数之和超过4，那么新缓存的数量为4减去已缓存的数量
 */
- (void) loadCache:(NSInteger)count delegate:(id<ZJ_MJKAdLoadDelegate> _Nullable)delegate;

/**
 竞价失败回调
 winPrice 整数分
 reason
      * 101：出价低
      * 102：超时
      * 103：广告主被屏蔽
      * 104：文案被屏蔽
      * 105：素材被屏蔽
      * 106：媒体的其他原因
      * 107：内部问题或报错
 */
- (void) lossTracker:(NSInteger) winPrice reason:(NSString *)reason;

@end

NS_ASSUME_NONNULL_END
