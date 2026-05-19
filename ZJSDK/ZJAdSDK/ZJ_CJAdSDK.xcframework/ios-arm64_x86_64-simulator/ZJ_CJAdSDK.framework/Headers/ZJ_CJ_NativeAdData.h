//
//  ZJ_CJ_NativeAdData.h
//  ZJ_CJAdSDK
//
//  Created by coderqi on 2025/12/10.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface ZJ_CJ_ImageInfo : NSObject

@property (nonatomic, strong) NSString *url;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

- (instancetype)initWithUrl:(NSString *)url andWidth:(NSInteger)width andHeight:(NSInteger)height;

@end

@interface ZJ_CJ_VideoInfo : NSObject

@property (nonatomic, strong) NSString *url;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) double duration;

- (instancetype)initWithUrl:(NSString *)url andWidth:(NSInteger)width andHeight:(NSInteger)height;

@end

@interface ZJ_CJ_NativeAdData : NSObject

/// AppIcon
@property (nonatomic, copy, readonly) NSString *appIconUrl;

/// 广告标题
@property (nonatomic, copy, readonly) NSString *title;

/// 广告描述
@property (nonatomic, copy, readonly) NSString *desc;

/// 广告来源
@property (nonatomic, copy, readonly) NSString *source;

/// 广告角标,  宽高比为100:21
@property (nonatomic, strong, readonly) UIImage *adLogoImage;

/// 广告角标URL地址,  宽高比为1:1
@property (nonatomic, strong, readonly) NSString *adLogoUrl;

/// 按钮文案
@property (nonatomic, copy, readonly) NSString *callToAction;

/// 广告图片素材地址
@property (nonatomic, strong, readonly) NSArray <NSString *>*imageUrls;

/// 广告图片对象集合
@property (nonatomic, strong, readonly) NSArray <ZJ_CJ_ImageInfo *>*images;

/// 是否是视频类广告
@property (nonatomic, assign, readonly) BOOL isVideoAd;

/// 视频类素材描述
@property (nonatomic, strong, readonly) ZJ_CJ_VideoInfo *videoAdInfo;

/// 是否下载类广告
@property (nonatomic, assign, readonly) BOOL isDownloadAd;

// 更新数据
- (void)updateData;

@end

NS_ASSUME_NONNULL_END
