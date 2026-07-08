//
//  ZJHorizontalFeedPageAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/20.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import "ZJContentPageStateDelegate.h"
#import <ZJSDKCore/ZJContentInfo.h>
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJHorizontalFeedAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJHorizontalFeedPageAd : ZJTierAd

///视频状态代理
@property (nonatomic, weak) id <ZJContentPageVideoStateDelegate> videoStateDelegate;
///页面状态代理
@property (nonatomic, weak) id <ZJContentPageStateDelegate> stateDelegate;

/// 处理视频内容加载成功和失败的代理方法
@property (nonatomic, weak) id <ZJContentPageLoadCallBackDelegate> loadCallBackDelegate;

@property (nonatomic, strong) ZJHorizontalFeedAdapter *currentAdapter;

- (UIViewController *)horizontalFeedPageViewController;

@end

NS_ASSUME_NONNULL_END
