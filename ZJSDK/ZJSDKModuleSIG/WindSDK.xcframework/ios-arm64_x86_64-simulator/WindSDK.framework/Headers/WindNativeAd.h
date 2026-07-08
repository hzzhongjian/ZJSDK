//
//  WindNativeAd.h
//  WindSDK
//
//  Created by Codi on 2021/11/2.
//

#import <Foundation/Foundation.h>
#import "WindAdMetaData.h"
#import "WindAdImageData.h"

typedef NS_ENUM(NSInteger, WindFeedADMode) {
    WindFeedADModeSmallImage = 2,
    WindFeedADModeLargeImage = 3,
    WindFeedADModeNativeExpress = 4,
    WindFeedADModeVideo = 14,
    WindFeedADModeVideoPortrait = 15,
    WindFeedADModeVideoLandSpace = 16,
};

typedef NS_ENUM(NSUInteger, WindNativeAdInteractionType) {
    WindNativeAdInteractionTypeUnknown = 0,
    WindNativeAdInteractionTypeDownload,
    WindNativeAdInteractionTypeWeb,
};

@interface WindNativeAd : NSObject


/// Typed access to the ad title.
@property (nonatomic, copy, readonly, nullable) NSString *title;

/// Typed access to the body text, usually a longer description of the ad.
@property (nonatomic, copy, readonly, nullable) NSString *desc;

/// Typed access to the ad icon.
@property (nonatomic, copy, readonly, nullable) NSString *iconUrl;

/// Typed access to the call to action phrase of the ad.
@property (nonatomic, copy, readonly, nullable) NSString *callToAction;

/// Typed access to the ad image URL List.
@property (nonatomic, strong, readonly, nullable) NSArray *imageUrlList;

/// Typed access to the ad star rating.
@property (nonatomic, assign, readonly) double rating;

@property (nonatomic, assign, readonly) WindFeedADMode feedADMode;

/// 图片尺寸集合 @["{width,height}"]
@property (nonatomic, strong, readonly, nullable) NSArray *imageSizeList;

/// 视频宽
@property (nonatomic, assign, readonly) CGFloat videoWidth;

/// 视频高
@property (nonatomic, assign, readonly) CGFloat videoHeight;

/// 广告交互类型
@property (nonatomic, assign, readonly) WindNativeAdInteractionType interactionType;

/// 广告元数据
@property (nonatomic, strong, readonly, nullable) WindAdMetaData *metaData;

/// 图片集合
@property (nonatomic, strong, readonly, nullable) NSArray<WindAdImageData *> *imageDataList;

@end
