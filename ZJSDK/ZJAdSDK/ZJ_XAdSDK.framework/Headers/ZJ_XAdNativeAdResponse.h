//
//  ZJ_XAdNativeAdResponse.h
//  PublicFilePackage
//
//  Created by 周泽浩 on 2018/9/5.
//  Copyright © 2018年 YD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

typedef NS_ENUM(NSInteger, NativeAdType) {
    NORMAL_NativeAD, // 一般图文或图片广告
    VIDEO_NativeAD, // 视频广告
    HTML_NativeAD, // html模版广告
};

@interface ZJ_XAdNativeAdResponse : NSObject
/// 容器视图
@property (nonatomic,strong) UIView *adContainerView;
/// 视频视图
@property (nonatomic,strong) UIView *adVideoView;
/// HTML视图
@property (nonatomic,strong) UIView *adHTMLView;
// 素材id/创意id
@property (nonatomic,copy) NSString *crid;
/// 标题
@property (nonatomic,copy) NSString *adTitle;
/// 简介
@property (nonatomic,copy) NSString *adDescribe;
/// logo图片url
@property (nonatomic,copy) NSString *logoUrl;
/// icon图片url
@property (nonatomic,copy) NSString *iconURL;
/// 广告图片URL
@property (nonatomic,strong) NSArray *imagesURL;
// 视频URL
@property (nonatomic,copy) NSString *videoUrl;
/// 物料类型
@property (nonatomic,assign) NativeAdType adType;

@property (nonatomic,assign) NSInteger eCPM;

///获取广告容器   [自定义frame]
- (UIView *)buildContainer;

///获取视频播放视图   [自定义frame]
- (UIView *)buildVideoView;

///获取HTML视图   [自定义frame]
- (UIView *)buildHTMLView;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)getECPM;
@end
