//
//  ZJ_MJKSelfRenderFeedAd.h
//  ZJ_MJKAdSDK
//
//  Created by Harry Jiang on 2026/3/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdError.h>
#import <ZJ_MJKAdSDK/ZJ_MJKAdDelegate.h>
#import <ZJ_MJKAdSDK/ZJ_MJKSelfRenderFeedData.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJ_MJKSelfRenderFeedAd;

@protocol ZJ_MJKSelfRenderFeedAdDelegate <NSObject>
@optional
//广告加载完成
-(void)onMgcSelfRenderFeedAdLoaded:(ZJ_MJKSelfRenderFeedAd *)feedAd data:(ZJ_MJKSelfRenderFeedData *)data;

//广告加载失败
-(void)onMgcSelfRenderFeedAdError:(ZJ_MJKSelfRenderFeedAd *)feedAd error:(ZJ_MJKAdError *)err;

@end

@interface ZJ_MJKSelfRenderFeedAd : NSObject

@property (nonatomic, assign)BOOL disableCache;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKSelfRenderFeedAdDelegate> _Nullable)delegate;

/**
 初始化
 **/
- (instancetype)initWithAdId:(NSString*)tagId size:(CGSize)size extra:(NSDictionary<NSString *,NSString *> *)extra controller:(UIViewController * _Nullable)controller delegate:(id<ZJ_MJKSelfRenderFeedAdDelegate> _Nullable)delegate;

/**
 加载广告
 */
- (void)loadAd;

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
 重设ViewController
 */
- (void)resetViewController:(UIViewController *)controller;

/**
 销毁
 */
- (void)destroy;

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
