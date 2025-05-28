//
//  WanjaAdvertisingDelegate.h
//  Pods
//
//  Created by guantou on 2019/12/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaAdvertisingDelegate <NSObject>

@optional

/**
 图片加载完成
 */
- (void)wanja_advertisingDidDownload;

/**
 图片加载失败
 */
- (void)wanja_adResourceDownloadFail;

/**
 广告加载完成
 */
- (void)wanja_advertisingDidFinish;

/**
 广告关闭
 */
- (void)wanja_advertisingDidClose;

/**
 广告加载失败
 */
- (void)wanja_advertisingDidFail;

/**
 广告点击
 */
- (void)wanja_advertisingDidClickType:(NSString * _Nullable)type param:(NSString * _Nullable)param;

/**
 player广告缓冲完成，可以开始播放广告
 */
- (void)wanja_advertisingDidReadyAndStart;

/**
 player广告播放完毕
 */
- (void)wanja_advertisingDidFinishPlay;

/**
 player广告播放失败
 */
- (void)wanja_advertisingDidFailPlay;

/**
 视频广告总时长
 */
- (void)wanja_advertisingPlayerTotalLenght:(CGFloat)time;

@end

NS_ASSUME_NONNULL_END

