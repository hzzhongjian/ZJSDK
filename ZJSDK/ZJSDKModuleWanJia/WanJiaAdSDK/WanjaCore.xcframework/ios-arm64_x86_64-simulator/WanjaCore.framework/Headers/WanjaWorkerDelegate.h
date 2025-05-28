//
//  WanjaWorkerDelegate.h
//  Pods
//
//  Created by guantou on 2020/2/20.
//

#import <Foundation/Foundation.h>
#import "WanjaAdRequestError.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WanjaWorkerDelegate <NSObject>

@optional

/**
 图片加载完成
 */
- (void)wanja_workerDidDownload;

/**
 图片加载失败
 */
- (void)wanja_workerResourceDownloadFail;

/**
 广告加载完成
 */
- (void)wanja_workerDidFinish;

/**
 广告关闭
 */
- (void)wanja_workerDidClose;

/**
 广告加载失败
 */
- (void)wanja_workerDidFailWithError:(WanjaAdRequestError *)error;

/**
 广告点击
 */
- (void)wanja_workerDidClickType:(NSString * _Nullable)type param:(NSString * _Nullable)param;

/**
 player广告缓冲完成，可以开始播放广告
 */
- (void)wanja_workerDidReadyAndStart;

/**
 player广告播放完毕
 */
- (void)wanja_workerDidFinishPlay;

/**
 player广告播放失败
 */
- (void)wanja_workerDidFailPlay;

/**
 视频广告总时长
 */
- (void)wanja_workerPlayerTotalLenght:(CGFloat)time;

/**
 开屏剩余时长
 */
- (void)wanja_workerAdLifeTime:(NSUInteger)time;

/**
 h5页面完成按钮回调
 */
- (void)wanja_normalDoneClick;

@end

NS_ASSUME_NONNULL_END
