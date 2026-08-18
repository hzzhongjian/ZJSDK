//
//  ZJ_CJNativeAdObject.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_CJAdSDK/ZJ_CJNativeAdData.h>
#import <ZJ_CJAdSDK/ZJ_CJNativeExpressView.h>
#import <ZJ_CJAdSDK/ZJ_CJ_VideoPlayerView.h>

@class ZJ_CJAdMetaData;
@class ZJ_CJNativeAdObject;
NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_CJNativeAdObjectDelegate <NSObject>

/**
 * 广告展示
 * @param adObject  广告数据
 */
- (void)zj_cj_NativeAdShow:(ZJ_CJNativeAdObject *)adObject;

/**
 * 广告点击
 * @param adObject  广告数据
 */
- (void)zj_cj_NativeAdClicked:(ZJ_CJNativeAdObject *)adObject;
/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)zj_cj_NativeAdClosed:(ZJ_CJNativeAdObject *)adObject;

/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)zj_cj_NativeAdWebPageClosed:(ZJ_CJNativeAdObject *)adObject;

@end

@interface ZJ_CJNativeAdObject : NSObject

/// 是否是模板广告
@property (nonatomic, assign) BOOL isExpress;

/// 获取广告模板视图
///  非模板广告时，返回空
- (ZJ_CJNativeExpressView *)getExpressView;

/// 获取广告的视频播放器
- (ZJ_CJVideoPlayerView *)getMediaView;

@property (nonatomic, weak) id <ZJ_CJNativeAdObjectDelegate> delegate;

/// 广告的原始数据
@property (nonatomic, strong, readonly) ZJ_CJNativeAdData *adData;

/**
 * 获取广告出价
 * 广告加载成功之后，才会有值
 *  单位：分
 */
- (NSInteger)getBidPrice;

/**
 * 聚合竞价结果回传
 */
- (void)sendBidResultNotificationWithInfo:(NSDictionary *)infoDic andResut:(BOOL)isSucc;

/**
 * 获取图片素材地址
 */
- (NSArray<NSString *> *)getImageFileUrls;

/**
 * 获取视频素材地址
 */
- (NSArray<NSString *> *)getVideoFileUrls;

/**
 * 获取落地页地址
 */
- (NSString *)getLandpageUrl;

@end

NS_ASSUME_NONNULL_END
