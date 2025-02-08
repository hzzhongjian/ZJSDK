//
//  ZJNewsTierLoader.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/7.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import <ZJSDKCore/ZJNewsAdAdapter.h>
#import <ZJSDKCore/ZJNewsAdProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJNewsTierLoader;

@protocol ZJNewsTierLoaderDelegate <NSObject>

/**
 newsAd曝光回调
 */
- (void)zj_newsAdLoaderDidShow:(ZJNewsTierLoader *)newsAdLoader;

/**
 news广告奖励触发回调
 */
- (void)zj_newsAdLoaderRewardEffective:(ZJNewsTierLoader *)newsAdLoader;

/**
 点击news广告回调
 */
- (void)zj_newsAdLoaderDidClick:(ZJNewsTierLoader *)newsAd;

/**
 canGoBack状态监听
 */
- (void)zj_newsAdLoader:(ZJNewsTierLoader *)newsAd canGoBackStateChange:(BOOL)canGoBack;

@end

@interface ZJNewsTierLoader : ZJTierAdLoader <ZJNewsAdAdapterDelegate>

@property (nonatomic, weak) id <ZJNewsTierLoaderDelegate> delegate;

@property (nonatomic, copy) NSString *userId;

@property (nonatomic, assign) CGRect adFrame;

@end

NS_ASSUME_NONNULL_END
