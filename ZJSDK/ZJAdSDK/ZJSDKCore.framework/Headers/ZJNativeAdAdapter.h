//
//  ZJNativeAdAdapter.h
//  ZJSDKCore
//
//  Created by Rare on 2021/3/29.
//

//#import "ZJMultipleAdAdapter.h"
#import <ZJSDKCore/ZJMultipleAdAdapter.h>
#import <ZJSDKCore/ZJNativeAdObject.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJNativeAdAdapter;

@protocol ZJNativeAdAdapterDelegate <NSObject>
/**
 广告数据回调

 @param multipleResultObject 广告数据数组
 @param error 错误信息
 */
- (void)zjAdapter_nativeAd:(ZJNativeAdAdapter *)adAdapter didLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;


@end



@interface ZJNativeAdAdapter : ZJMultipleAdAdapter

@property (nonatomic,weak)id <ZJNativeAdAdapterDelegate> delegate;

@property (nonatomic, strong) NSArray<ZJNativeAdObject *> *data;

// required. Image size.
// 穿山甲联盟要求传加载图片尺寸
@property (nonatomic, assign) ZJProposalSize imgSize;

// 部分联盟需要设置的广告尺寸
@property (nonatomic, assign) CGSize adSize;

// 设置是否静音,默认为静音YES，非静音为NO
@property (nonatomic ,assign) BOOL mutedIfCan;

// 一般为当前展示广告控制器
@property (nonatomic, strong) UIViewController *rootViewController;

/** 用户可根据该字段，自己控制视频是否可以点击，
* 如果是YES，就是可以点击，
* 默认为NO，根据SDK内部去判断视频是否可以点击*
*/
@property (nonatomic, assign) BOOL forced_clickable;

/**
 广告数据回调
 */
- (void)nativeAdLoaded:(NSArray<ZJNativeAdObject *> * _Nullable)multipleResultObject error:(NSError * _Nullable)error;



- (void)loadAdWithCount:(NSInteger)adCount;



@end

NS_ASSUME_NONNULL_END
