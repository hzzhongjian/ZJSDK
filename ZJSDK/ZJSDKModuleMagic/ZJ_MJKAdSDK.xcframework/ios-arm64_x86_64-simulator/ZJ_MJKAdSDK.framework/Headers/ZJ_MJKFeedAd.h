//
//  ZJ_MJKFeedAd.h
//  ZJ_MJKAdOS
//
//  Created by Harry Jiang on 15/5/25.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdError.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_MJKFeedAd;

@protocol ZJ_MJKFeedAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcFeedAdLoaded:(ZJ_MJKFeedAd *)feedAd;

//广告加载失败
-(void)onMgcFeedAdError:(ZJ_MJKFeedAd *)feedAd error:(ZJ_MJKAdError *)err;

//广告点击后回调
-(void)onMgcFeedAdClick:(ZJ_MJKFeedAd *)feedAd;

//广告按钮点击关闭后回调
-(void)onMgcFeedAdClose:(ZJ_MJKFeedAd *)feedAd;

//广告展示回调
-(void)onMgcFeedAdShow:(ZJ_MJKFeedAd *)feedAd;

//广告展示曝光回调
-(void)onMgcFeedAdDidExposure:(ZJ_MJKFeedAd *)feedAd;

//广告隐藏回调
-(void)onMgcFeedAdHidden:(ZJ_MJKFeedAd *)feedAd;

//广告数据回调
-(void)onMgcFeedAdData:(ZJ_MJKFeedAd *)feedAd data:(NSDictionary *)data;

//广告内跳落地页打开回调
-(void)onMgcFeedAdLandingPageStart:(ZJ_MJKFeedAd *)feedAd;

//广告内跳落地页关闭回调
-(void)onMgcFeedAdLandingPageClose:(ZJ_MJKFeedAd *)feedAd;
@end

@interface ZJ_MJKFeedAd : NSObject

@property (nonatomic, assign)BOOL disableCache;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKFeedAdDelegate> _Nullable)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKFeedAdDelegate> _Nullable)delegate;

/**
 加载广告
 */
- (void)loadAd;

/**
 获取广告视图
 */
- (UIView *)getView;


/**
 是否是视频广告
 */
- (BOOL)isVideo;

/**
 重设ViewController
 */
- (void)resetViewController:(UIViewController *)controller;

/**
 重设代理
 */
- (void)resetDelegate:(id<ZJ_MJKFeedAdDelegate> _Nullable)delegate;

/**
 视频是否正在播放
 */
- (BOOL)isPlaying;

/**
 暂停视频
 */
- (void)pauseVideo;

/**
 播放视频
 */
- (void)playVideo;

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
