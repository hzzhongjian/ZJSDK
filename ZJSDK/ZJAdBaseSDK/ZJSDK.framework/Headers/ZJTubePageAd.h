//
//  ZJTubePageAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/8.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import <ZJSDKCore/ZJContentInfo.h>
#import "ZJContentPageStateDelegate.h"
#import <ZJSDKCore/ZJTubePageAdapter.h>
#import <ZJSDKCore/ZJTubePageConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJTubePageAd : ZJTierAd

@property (nonatomic, strong,nullable) ZJTubePageAdapter *currentAdapter;

///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;

///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;

/// 短剧内容加载结果代理
@property (nonatomic, weak) id <ZJContentPageLoadCallBackDelegate> loadCallBackDelegate;

/// 短剧播放器回调
@property (nonatomic, weak) id <ZJShortPlayPlayerDelegate> playerCallbackDelegate;

/// 广告回调
@property (nonatomic, weak) id <ZJShortPlayAdDelegate> adCallbackDelegate;

/// 业务接口回调
@property (nonatomic, weak) id <ZJShortPlayInterfaceDelegate> interfaceCallbackDelegate;

/// 自定义详情页cell试图回调
@property (nonatomic, weak) id <ZJShortPlayCustomViewDelegate> customViewCallBackDelegate;

/// 自定义Draw流的subview回调
@property (nonatomic, weak) id <ZJShortPlayCustomDrawAdViewDelegate> customDrawAdViewCallBackDelegate;

/// 滑滑溜底部自定义Banner广告
@property (nonatomic, weak) id <ZJShortPlayDrawVideoViewControllerBannerDelegate> drawVideoViewBannerCallbackDelegate;


/// 短剧相关配置
@property (nonatomic, strong) ZJTubePageConfig *tubePageConfig;

/// 短剧内容的控制器，媒体可以直接获取并展示
- (UIViewController *)tubePageViewController;


@end

NS_ASSUME_NONNULL_END
