//
//  ZJ_MJKSplashAd.h
//  ZJ_MJKAdOS
//
//  Created by Harry Jiang on 28/4/25.
//

#import <Foundation/Foundation.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdError.h>
#import <UIKit/UIKit.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_MJKSplashAd;

@protocol ZJ_MJKSplashAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcSplashAdLoaded:(ZJ_MJKSplashAd *)splashAd;

//广告加载失败
-(void)onMgcSplashAdError:(ZJ_MJKSplashAd *)splashAd error:(ZJ_MJKAdError *)err;

//广告点击后回调
-(void)onMgcSplashAdClick:(ZJ_MJKSplashAd *)splashAd;

//广告点击跳过后回调
-(void)onMgcSplashAdSkip:(ZJ_MJKSplashAd *)splashAd;

//广告展示回调
-(void)onMgcSplashAdShow:(ZJ_MJKSplashAd *)splashAd;

//广告真实曝光回调
-(void)onMgcSplashAdDidExposure:(ZJ_MJKSplashAd *)splashAd;

//广告隐藏回调
-(void)onMgcSplashAdHidden:(ZJ_MJKSplashAd *)splashAd;

//广告请求超时
-(void)onMgcSplashAdTimeOut:(ZJ_MJKSplashAd *)splashAd;

//广告播放完成
-(void)onMgcSplashAdDidFinish:(ZJ_MJKSplashAd *)splashAd;

//广告数据回调
-(void)onMgcSplashAdData:(ZJ_MJKSplashAd *)splashAd data:(NSDictionary *)data;

//广告内跳落地页打开回调
-(void)onMgcSplashAdLandingPageStart:(ZJ_MJKSplashAd *)splashAd;

//广告内跳落地页关闭回调
-(void)onMgcSplashAdLandingPageClose:(ZJ_MJKSplashAd *)splashAd;
@end

@interface ZJ_MJKSplashAd : NSObject

@property (nonatomic, assign)BOOL disableCache;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKSplashAdDelegate> _Nullable)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKSplashAdDelegate> _Nullable)delegate;

/**
 初始化（底部自定义视图）
 屏幕尺寸由SDK内部获取，广告请求高度 = 屏幕高度 - bottomView高度；
 展示时广告顶部对齐，bottomView直接添加在广告视图底部，总高度 = 广告返回高度 + bottomView高度
 bottomView可为nil，为nil时等同于满屏请求
 **/
- (instancetype)initWithAdId:(NSString*)tagId bottomView:(UIView * _Nullable)bottomView controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKSplashAdDelegate> _Nullable)delegate;

/**
 初始化（底部自定义视图，带extra）
 屏幕尺寸由SDK内部获取，广告请求高度 = 屏幕高度 - bottomView高度；
 展示时广告顶部对齐，bottomView直接添加在广告视图底部，总高度 = 广告返回高度 + bottomView高度
 bottomView可为nil，为nil时等同于满屏请求
 **/
- (instancetype)initWithAdId:(NSString*)tagId bottomView:(UIView * _Nullable)bottomView extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKSplashAdDelegate> _Nullable)delegate;

/**
 加载广告
 */
- (void)loadAd;

/**
 展示
 */
- (void)show;

/**
 展示
 */
- (void)show:(UIViewController *)controller;

/**
 展示（添加到window上）
 window为nil时优先取controller所在的window，其次取keyWindow
 */
- (void)showWindow:(UIWindow * _Nullable)window;

/**
 重设ViewController
 */
- (void)resetViewController:(UIViewController *)controller;

/**
 重设代理
 */
- (void)resetDelegate:(id<ZJ_MJKSplashAdDelegate> _Nullable)delegate;

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
