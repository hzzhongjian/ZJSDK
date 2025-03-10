//
//  ZJNativeExpressFeedAdManager.h
//  ZJSDK
//
//  Created by Rare on 2021/1/8.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJAd.h"
#import <ZJSDKCore/ZJNativeExpressFeedAd.h>
#import "ZJMultipleAd.h"

// 信息流广告
NS_ASSUME_NONNULL_BEGIN

@class ZJNativeExpressFeedAdManager ,ZJNativeExpressFeedAd;

@protocol ZJNativeExpressFeedAdManagerDelegate <NSObject>

@optional
///加载成功
- (void)ZJ_nativeExpressFeedAdManagerSuccessToLoad:(ZJNativeExpressFeedAdManager *)adsManager nativeAds:(NSArray<ZJNativeExpressFeedAd *> *_Nullable)multipleResultObject;

///加载失败
- (void)ZJ_nativeExpressFeedAdManager:(ZJNativeExpressFeedAdManager *)adsManager didFailWithError:(NSError *_Nullable)error;

@end


@interface ZJNativeExpressFeedAdManager : ZJMultipleAd

@property (nonatomic, weak) id <ZJNativeExpressFeedAdManagerDelegate> delegate;


@property (nonatomic) CGSize adSize;

///视频静音， 默认：NO
@property (nonatomic) BOOL mutedIfCan;

/*
 *required.[必选]
 * root view controller for handling ad actions.
 * 详解：开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 */
@property (nonatomic, weak) UIViewController *rootViewController;


@property (nonatomic, strong ,readonly) NSArray <ZJNativeExpressFeedAd *> *data;

// 部分联盟需要设置size [必选]
- (instancetype)initWithPlacementId:(NSString *)placementId size:(CGSize)size;

/**
 * 加载广告，建议最大个数不超过5个
 */
- (void)loadAdDataWithCount:(NSInteger)count;

@end




NS_ASSUME_NONNULL_END
