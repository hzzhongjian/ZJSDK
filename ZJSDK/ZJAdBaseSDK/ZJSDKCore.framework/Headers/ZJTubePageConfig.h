//
//  ZJTubePageConfig.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/2/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZJTubePageVideoProgressBarStyle) {//进度条样式
    ZJTubePageVideoProgressBarStyleLightContent     = 0,  // 浅色系
    ZJTubePageVideoProgressBarStyleDarkContent      = 1   // 深色系
};

// 需要展示的tab，默认全部展示
typedef NS_ENUM(NSInteger, ZJTubePageDrawVideoVCTabOptions) {
    ZJTubePageDrawVideoVCTabOptions_playlet       = 1 << 0, // 详情页Tab
    ZJTubePageDrawVideoVCTabOptions_playlet_feed  = 1 << 1, // 推荐Tab
    ZJTubePageDrawVideoVCTabOptions_theater       = 1 << 2, // 剧场Tab
};

// 广告类型
typedef NS_ENUM(NSInteger, ZJTubePageADType) {
    ZJTubePageADTypeInterstitial = 0,
    ZJTubePageADTypeRewardVideo = 1,
};

@interface ZJTubePageConfig : NSObject

/// 用户在穿山甲平台注册的应用，填写包名之后，下载的SDK参数配置的json文件，放在包中的路径
/// 申请流程：穿山甲管理平台->接入管理->内容输出->找到自己添加的应用->包名录入->下载SDK参数配置，添加到项目里，申请流程会有所变化
/// [[NSBundle mainBundle] pathForResource:@"SDK_Setting_5434885" ofType:@"json"]; 传这个路径
@property (nonatomic, copy) NSString *JSONConfigPath;

/*! @abstract 是否需要展示左上角的关闭按钮。 默认不展示 */
@property (nonatomic, assign) BOOL showCloseButton;

/*! @abstract 是否需要隐藏首次安装出现的引导手势图。 默认展示 */
@property (nonatomic, assign) BOOL hiddenGuideGeste;

/*! @abstract 展示VC的大小。 默认屏幕大小 */
@property (nonatomic, assign) CGSize viewSize;

/*! @abstract 外流进度条距离最低部的距离 */
@property (nonatomic, assign) CGFloat out_bottomOffset;
/*! @abstract 短剧内流进度条距离最低部的距离 */
@property (nonatomic, assign) CGFloat inner_playPlet_bottomOffset;
/*! @abstract 进度条的样式。 默认浅色系 */
@property (nonatomic, assign) ZJTubePageVideoProgressBarStyle progressBarStyle;
/// 隐藏底部跳转区域
@property (nonatomic, assign) BOOL hiddenPlayletEnterView;
/// 进入详情页方式 强制使用push 默认使用present
@property (nonatomic, assign) BOOL enterPlayPageUsePush;
//免费观看的集数n
@property (nonatomic, assign) NSInteger freeEpisodesCount;
//观看一次激励视频解锁的集数m
@property (nonatomic, assign) NSInteger unlockEpisodesCountUsingAD;
/// 隐藏点赞
@property (nonatomic) BOOL hideLikeIcon;
/// 隐藏收藏
@property (nonatomic) BOOL hideCollectIcon;
/// 短剧混排流中的免费短剧集数，默认为1集混排
@property (nonatomic, assign) NSInteger playletFreeCount;
/// 禁用双击点赞
@property (nonatomic) BOOL disableDoubleClickLike;
/// 禁用长按倍速
@property (nonatomic) BOOL disableLongPressSpeed;
/// 短剧播放详情页，表示在第几集后面插入自定义Draw广告, 如果没有设置短剧播放详情页，不需要设置
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *customAdIndex;
/// 需要展示的tab，默认全部展示
@property (nonatomic, assign) ZJTubePageDrawVideoVCTabOptions drawVCTabOptions;
/// 是否隐藏频道tab，仅有一个tab时这个开关才生效
@property (nonatomic, assign) BOOL shouldHideTabBarView;

// ---------------是否配置代理，如果需要配置代理就要设置True，否则默认代理设置不生效-------------
/// 是否配置自定义详情页cell视图回调
@property (nonatomic, assign) BOOL configOrNotCustomViewDelegate;
/// 是否配置自定义详情页Draw广告
@property (nonatomic, assign) BOOL configOrNotCustomDrawAdViewDelegate;
/// 是否配置滑滑溜底部自定义Banner广告
@property (nonatomic, assign) BOOL configOrNotCustomBannerDelegate;

// ---------------自定义广告，--------------------------
/// 指定广告类型，目前支持自定义广告，插屏和激励视频两种
@property (nonatomic, assign) ZJTubePageADType adType;
/// 指定广告位ID
@property (nonatomic, copy) NSString *posId;

@end

NS_ASSUME_NONNULL_END
