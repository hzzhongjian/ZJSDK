//
//  ZJ_CJ_NativeAdObject.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJ_CJAdSDK/ZJ_CJ_NativeAdData.h>
#import <ZJ_CJAdSDK/ZJ_CJ_NativeExpressView.h>
#import <ZJ_CJAdSDK/ZJ_CJ_VideoPlayerView.h>

@class ZJ_CJ_AdMetaData;
@class ZJ_CJ_NativeAdObject;
NS_ASSUME_NONNULL_BEGIN

@protocol ZJ_CJ_NativeAdObjectDelegate <NSObject>

/**
 * 广告展示
 * @param adObject  广告数据
 */
- (void)zjcj_NativeAdShow:(ZJ_CJ_NativeAdObject *)adObject;

/**
 * 广告点击
 * @param adObject  广告数据
 */
- (void)zjcj_NativeAdClicked:(ZJ_CJ_NativeAdObject *)adObject;
/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)zjcj_NativeAdClosed:(ZJ_CJ_NativeAdObject *)adObject;

/**
 * 广告关闭
 * @param adObject  广告数据
 */
- (void)zjcj_NativeAdWebPageClosed:(ZJ_CJ_NativeAdObject *)adObject;

@end

@interface ZJ_CJ_NativeAdObject : NSObject

/// 是否是模板广告
@property (nonatomic, assign) BOOL isExpress;

/// 获取广告模板视图
///  非模板广告时，返回空
- (ZJ_CJ_NativeExpressView *)getExpressView;

/// 获取广告的视频播放器
- (ZJ_CJ_VideoPlayerView *)getMediaView;

@property (nonatomic, weak) id <ZJ_CJ_NativeAdObjectDelegate> delegate;

/// 广告的原始数据
@property (nonatomic, strong, readonly) ZJ_CJ_NativeAdData *adData;

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

@end

NS_ASSUME_NONNULL_END
