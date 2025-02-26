//
//  ZJTubePage.h
//  ZJSDK
//
//  Created by 麻明康 on 2024/6/12.
//  Copyright © 2024 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import "ZJContentPageStateDelegate.h"
#import <ZJSDKCore/ZJContentInfo.h>
#import <ZJSDKCore/ZJTubePageConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJTubePage : ZJAd <ZJContentInfo>

@property (nonatomic, readonly) UIViewController *viewController;

///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;

///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;

// 新增类方法,必须在调用初始化方法之前使用，此方法必须调用
+ (void)setConfig:(ZJTubePageConfig *)config;

/// 短剧播放器回调
@property (nonatomic, weak) id <ZJShortPlayPlayerDelegate> playerCallbackDelegate;

/// 广告回调
@property (nonatomic, weak) id <ZJShortPlayAdDelegate> adCallbackDelegate;

/// 业务接口回调
@property (nonatomic, weak) id <ZJShortPlayInterfaceDelegate> interfaceCallbackDelegate;

/// 自定义详情页cell视图回调
@property (nonatomic, weak) id <ZJShortPlayCustomViewDelegate> customViewCallBackDelegate;

/// 自定义Draw流的subview回调
@property (nonatomic, weak) id <ZJShortPlayCustomDrawAdViewDelegate> customDrawAdViewCallBackDelegate;

/// 滑滑溜底部自定义Banner广告
@property (nonatomic, weak) id <ZJShortPlayDrawVideoViewControllerBannerDelegate> drawVideoViewBannerCallbackDelegate;

@end

NS_ASSUME_NONNULL_END
