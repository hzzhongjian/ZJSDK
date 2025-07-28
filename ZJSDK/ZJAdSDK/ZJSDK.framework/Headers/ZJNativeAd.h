//
//  ZJNativeAd.h
//  ZJSDK
//
//  Created by Rare on 2021/3/29.
//  Copyright © 2021 zj. All rights reserved.
//

//#import "ZJAd.h"
#import <ZJSDKCore/ZJNativeAdObject.h>
#import <ZJSDKCore/ZJNativeAdView.h>
#import "ZJMultipleAd.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ZJNativeAdDelegate <NSObject>

@optional
/**自渲染广告加载回调*/
- (void)zj_nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;

@end

@interface ZJNativeAd : ZJMultipleAd

@property (nonatomic, weak) id <ZJNativeAdDelegate> delegate;

// required. Image size.
// 穿山甲联盟要求传加载图片尺寸
@property (nonatomic, assign) ZJProposalSize imgSize;

// 部分联盟需要传的广告尺寸
@property (nonatomic, assign) CGSize adSize;

/**
 是否设置静音模式，默认是true
*/
@property (nonatomic ,assign) BOOL mutedIfCan;

// 一般为当前展示广告控制器
@property (nonatomic, strong) UIViewController *rootViewController;

@end

NS_ASSUME_NONNULL_END
