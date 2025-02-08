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

NS_ASSUME_NONNULL_BEGIN

@interface ZJTubePageAd : ZJTierAd

@property (nonatomic, strong,nullable) ZJTubePageAdapter *currentAdapter;

///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;

///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;

/// 短剧内容加载结果代理
@property (nonatomic, weak) id <ZJContentPageLoadCallBackDelegate> loadCallBackDelegate;

/// 短剧内容的控制器，媒体可以直接获取并展示
- (UIViewController *)tubePageViewController;

@end

NS_ASSUME_NONNULL_END
