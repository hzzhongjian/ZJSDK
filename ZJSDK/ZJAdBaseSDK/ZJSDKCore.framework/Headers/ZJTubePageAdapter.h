//
//  ZJTubePageAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/6/12.
//

#import <ZJSDKCore/ZJBaseTubeAdapter.h>
#import <ZJSDKCore/ZJContentInfo.h>
#import <ZJSDKCore/ZJContentAdapterStateDelegate.h>
#import <ZJSDKCore/ZJContentAdapterStateProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJTubePageAdapter : ZJBaseTubeAdapter<
ZJContentAdapterStateProtocol,
ZJAdapterContentAdapterVideoStateProtocol,
ZJContentAdapterLoadCallBackProtocol,
ZJShortPlayPlayerCallBackProtocol,
ZJShortPlayAdCallBackProtocol,
ZJShortPlayInterfaceCallBackProtocol,
ZJShortPlayCustomViewCallBackProtocol,
ZJShortPlayCustomDrawAdViewCallBackProtocol,
ZJShortPlayDrawVideoViewControllerBannerCallBackProtocol
>
/// 任务完成回调
- (void)zjAdapter_contentTaskComplete:(id<ZJContentInfo>)content;

///  视频状态代理
@property (nonatomic, weak) id <ZJAdapterContentAdapterVideoStateDelegate> zjAdapter_videoStateDelegate;
///  页面状态代理
@property (nonatomic, weak) id <ZJContentAdapterStateDelegate> zjAdapter_stateDelegate;
/// 加载状态回调
@property (nonatomic, weak) id <ZJContentAdapterLoadCallBackDelegate> zjAdapter_loadCallbackDelegate;

// 以下为新增回调
/// 短剧播放器回调
@property (nonatomic, weak) id <ZJShortPlayPlayerCallBackDelegate> zjAdapter_playerCallbackDelegate;

/// 广告回调
@property (nonatomic, weak) id <ZJShortPlayAdCallBackDelegate> zjAdapter_adCallbackDelegate;

/// 业务接口回调
@property (nonatomic, weak) id <ZJShortPlayInterfaceCallBackDelegate> zjAdapter_interfaceCallbackDelgate;

/// 自定义详情页cell试图回调
@property (nonatomic, weak) id <ZJShortPlayCustomViewCallBackDelegate> zjAdapter_customViewCallBackDelegate;

/// 自定义Draw流的subview回调
@property (nonatomic, weak) id <ZJShortPlayCustomDrawAdViewCallBackDelegate> zjAdapter_customDrawAdViewCallBackDelegate;

/// 滑滑溜底部自定义Banner广告
@property (nonatomic, weak) id <ZJShortPlayDrawVideoViewControllerBannerCallBackDelegate> zjAdapter_drawVideoViewBannerCallbackDelegate;

@end

NS_ASSUME_NONNULL_END
