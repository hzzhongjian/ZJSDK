//
//  ZJ_YSAdSDKMaterialMeta.h
//  ZJ_YSAdSDK
//
//  Created by yanchao on 2026/3/24.
//
//  纯数据载体：承载信息流广告素材

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_YSAdSDKMaterialMeta : NSObject

/// 广告标题
@property (nonatomic, copy) NSString *title;

/// 广告描述/正文
@property (nonatomic, copy) NSString *desc;

/// 主图 URL 数组（可能多张）
@property (nonatomic, copy) NSArray<NSString *> *imageURLs;

/// 广告主logo
@property (nonatomic, copy) UIImage *icon;

/// CTA 按钮文案（如"立即下载"、"查看详情"）
@property (nonatomic, copy) NSString *callToAction;

/// 是否含视频
@property (nonatomic, assign) BOOL hasVideo;

/// 视频 URL 数组
@property (nonatomic, copy) NSArray<NSString *> *videoURLs;

/// 视频时长（秒）
@property (nonatomic, assign) long videoDuration;

/// 广告点击跳转链接
@property (nonatomic, copy) NSString *redirectUrl;

@end

NS_ASSUME_NONNULL_END
