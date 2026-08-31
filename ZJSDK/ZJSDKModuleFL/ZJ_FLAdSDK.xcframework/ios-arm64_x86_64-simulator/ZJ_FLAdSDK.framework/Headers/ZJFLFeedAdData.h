//
//  ZJFLFeedAdData.h
//  LunchAd
//
//  Created by shuai on 2018/10/15.
//  Copyright © 2018年 YX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, ZJFLTemplateStyleOptions) {
    /* 默认样式-图文混合 */
    ZJFLTemplateStyleDefault  = 0,
    /* 文字浮层 */
    ZJFLTemplateStyleNest     = 1,
    /* 上文下图 */
    ZJFLTemplateStyleTTBI     = 2,
    /* 上图下文 */
    ZJFLTemplateStyleTIBT     = 3,
    /* 左文右图 */
    ZJFLTemplateStyleLTRI     = 4,
    /* 左图右文 */
    ZJFLTemplateStyleLIRT     = 5,
    /* 纯图片 */
    ZJFLTemplateStyleImage    = 6,
};


@interface ZJFLFeedAdData : NSObject

/**
 * 是否由SDK渲染图片，默认为NO，如想让SDK渲染，注册点击事件之前赋值更改为YES，
 */
@property (nonatomic) BOOL isRenderImage;

/**
 * 大图Url，可能为空，不能以次区分视频和照片素材，视频可能也会有封面素材图，使用 isVideoAd 区分是否是视频素材
 */
@property (nonatomic, copy, nullable) NSString *imageUrl;

/**
 * 缓存的大图Image，注册之后异步有值
 */
@property (nonatomic, strong, nullable) UIImage *bgImage;

/**
 * 大图广告的宽
 */
@property (nonatomic) double imageWidth DEPRECATED_MSG_ATTRIBUTE("已弃用");

/**
 * 大图广告的高
 */
@property (nonatomic) double imageHeight DEPRECATED_MSG_ATTRIBUTE("已弃用");

/**
 * >1：横图
 * <1：竖图
 */
@property (nonatomic) double imageRatio DEPRECATED_MSG_ATTRIBUTE("已弃用");

/**
 * 多图广告的Url集合
 */
@property (nonatomic, copy, nullable) NSArray *mediaUrlList;

/**
 * 广告图标url
 */
@property (nonatomic, copy, nullable) NSString *iconUrl;

/**
 * 广告图标图片
 */
@property (nonatomic, strong, nullable) UIImage *icon;

/**
 * 广告平台logo标识url
 */
@property (nonatomic, copy, nullable) NSString *logoUrl;

/**
 * 广告平台logo图片
 */
@property (nonatomic, strong, nullable) UIImage *logo;

/**
 * 标题
 */
@property (nonatomic, copy, nullable) NSString *adTitle;

/**
 * 描述
 */
@property (nonatomic, copy, nullable) NSString *adContent;

/**
 * 广告ID
 */
@property (nonatomic, assign) NSUInteger adID;

/**
 * 广告按钮显示文字
 */
@property (nonatomic, copy, nullable) NSString *buttonText;

/**
 * 广告主类型
 */
@property (nonatomic, assign) NSInteger adType;

/**
 * 广告角标，必须渲染
 */
@property (nonatomic, strong, nullable) UIImage *adLogo DEPRECATED_MSG_ATTRIBUTE("已弃用，使用 adLogoIcon 替代");

/**
 * 新版广告角标
 */
@property (nonatomic, strong, nullable) UIImage *adLogoIcon;

/**
 * 广告主名称
 */
@property (nonatomic, copy, nullable) NSString *adOriginName;

/**
 * 是否自定义视频播放器，注册点击事件之前赋值，默认由SDK去渲染视频广告
 */
@property (nonatomic) BOOL isCustomRender;

/**
 * 是否为视频广告
 */
@property (nonatomic) BOOL isVideoAd;

/**
 * 视频广告Url，可能为空
 */
@property (nonatomic, copy, nullable) NSString *videoUrl;

/**
 * 视频广告时长
 */
@property (nonatomic) double videoDuration;

/**
 * 视频广告的宽(非必传，可能为空)
 */
@property (nonatomic) double videoWidth;

/**
 * 视频广告的高(非必传，可能为空)
 */
@property (nonatomic) double videoHeight;

/**
 * 广告元数据
 */
@property (nonatomic, strong, nullable) id data;

/**
 * 广告主元数据
 */
@property (nonatomic, strong, nullable) id manager;

/**
 * 在混合信息流中，当为模板广告时，此属性有值
 */
@property (nonatomic, weak, nullable) UIView *adView;

/**
 * 是否添加
 */
@property (nonatomic) BOOL isAdd;

/**
 * 是否自定义交互界面  默认为NO，由SDK自身渲染。如需自己渲染，注册点击事件之前赋值更改为YES，
 * （摇一摇等、仅限自有预算 自渲染广告使用，不适用于联盟广告、模版广告）
 */
@property (nonatomic, assign) BOOL isRenderShakeView;

/**
 * 自渲染  渲染好的视频视图
 * 当isCustomRender = NO时，sdk会默认在注册接口(registerAdForView)传入的view上渲染视频，不需额外操作，这时不需要再使用mediaView。
 * 当isCustomRender = YES时，可选择使用mediaView，也可通过videoUrl自行渲染视频
 *
 * 可通过该字段控制视频样式：[ZJFLAdSDKManager defaultManager].contentMode
 * UIViewContentModeScaleAspectFill 充满背景
 * UIViewContentModeScaleAspectFit 宽高适应展示(默认)
 */
@property (nonatomic, strong, nullable) UIView *mediaView;

@end
