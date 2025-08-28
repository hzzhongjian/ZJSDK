//
//  ZJ_XAdWMNativeAdData.h
//  ZJ_AdWangMaiSDK
//
//  Created by xiang shi on 2024/9/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, WMNativeAdType) {
    SINGLE_IMAGE, // 单图
    GROUP_IMAGE, // 多图
    VIDEO, // 视频广告
};

typedef NS_ENUM(NSInteger, WMAdInteractionType) {
    ACTION_TYPE_LANDING_PAGE, // 打开落地页、deep_link
    ACTION_TYPE_SMALL_PROGRAM, // 微信小程序
};

NS_ASSUME_NONNULL_BEGIN

@interface ZJ_XAdWMNativeAdData : NSObject
// 物料类型
@property (nonatomic,assign) WMNativeAdType adType;
// 交互类型
@property (nonatomic,assign) WMAdInteractionType interaction_type;
// 素材id/创意id
@property (nonatomic,nullable,copy) NSString *crid;
// 标题
@property (nonatomic,nullable,copy) NSString *adTitle;
// 描述
@property (nonatomic,nullable,copy) NSString *adDescribe;
// 品牌方名称
@property (nonatomic,nullable,copy) NSString *brandName;
// logo
@property (nonatomic,nullable,copy) NSString *logoUrl;
// icon
@property (nonatomic,nullable,copy) NSString *iconUrl;
// 广告单图
@property (nonatomic,nullable,copy) NSString *imageUrl;
// 广告组图
@property (nonatomic,nullable,strong) NSArray *imageUrlList;
// 视频URL
@property (nonatomic,nullable,copy) NSString *videoUrl;
// 视频时长
@property (nonatomic,assign) NSInteger duration;
// 素材宽度
@property (nonatomic,assign) NSInteger materialWidth;
// 素材高度
@property (nonatomic,assign) NSInteger materialHeight;
// 落地页
@property (nonatomic,nullable,copy) NSString *target_url;
// deep_link
@property (nonatomic,nullable,copy) NSString *deep_link;

// 广告素材为视频时，静音监控链接
@property (nonatomic,nullable,strong) NSArray *v_mute_tracking_event;
// 广告素材为视频时，取消静音监控链接
@property (nonatomic,nullable,strong) NSArray *v_unmute_tracking_event;
// 广告素材为视频时，视频暂停监控链接
@property (nonatomic,nullable,strong) NSArray *v_pause_tracking_event;
// 广告素材为视频时，视频取消暂停监控链接
@property (nonatomic,nullable,strong) NSArray *v_resume_tracking_event;
// 广告素材为视频时，视频全屏监控链接
@property (nonatomic,nullable,strong) NSArray *v_fullscreen_tracking_event;
// 广告素材为视频时，视频退出全屏监控链接
@property (nonatomic,nullable,strong) NSArray *v_exitfullscreen_tracking_event;
// 广告素材为视频时，跳过视频播放监控链接
@property (nonatomic,nullable,strong) NSArray *v_skip_tracking_event;
// 广告素材为视频时，对视频播放阶段的上报
//示例： @[@{@"url":@[@""],@"millisec":@(1000)]  millisec单位毫秒
@property (nonatomic,nullable,strong) NSArray *v_progress_tracking_event;
// 广告素材为视频时，视频关闭监控链接
@property (nonatomic,nullable,strong) NSArray *v_close_tracking_event;
// 广告素材为视频时，视频继续播放监控链接
@property (nonatomic,nullable,strong) NSArray *v_continue_tracking_event;

// 视频前贴片内容
@property (nonatomic,nullable,copy) NSString *preimgUrl;
// 视频后贴片内容
@property (nonatomic,nullable,copy) NSString *endimgUrl;
// 后贴icon图标
@property (nonatomic,nullable,copy) NSString *endiconUrl;
// 后贴描述
@property (nonatomic,nullable,copy) NSString *enddesc;
// 后贴标题
@property (nonatomic,nullable,copy) NSString *endtitle;
// 评论数
@property (nonatomic,assign) NSInteger endcomments;
// 按钮文案
@property (nonatomic,nullable,copy) NSString *endbutton;
// 评分
@property (nonatomic,assign) NSInteger endrating;
/// 广告的eCPM，单位：分
@property (nonatomic,assign) NSInteger eCPM;

@end

NS_ASSUME_NONNULL_END
