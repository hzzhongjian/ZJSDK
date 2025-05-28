//
//  WanjaConfigureModel.h
//  WanjaCore
//
//  Created by ZY on 2020/1/6.
//

#import "WanjaBaseModel.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaConfiguratorModel;
@class WanjaManagerModel;
@class WanjaInitModel;
@class WanjaAdSlotsModel;
@class WanjaFilterModel;
@class WanjaBuyerModel;
@class WanjaBidModel;
@class WanjaMessageModel;
@class WanjaEventsModel;
@class WanjaComponent;
@class WanjaBidComponent;
@class WanjaComponentRule;
@class WanjaFullScreenClick;
@class WanjaRenderView;
@class WanjaShakeView;
@class WanjaSwipeViewModel;
@class WanjaCallBackStrategy;
@class WanjaRenderPolicy;
@class WanjaPosition;
@class WanjaPassPolicy;
@class WanjaRegionalClick;

/**
 配置文件Model
*/
@interface WanjaConfigureModel : WanjaBaseModel

//  请求结果code
@property (nonatomic, assign) NSInteger code;
//  请求结果信息
@property (nonatomic, copy) NSString *msg;
//  请求结果内容
@property (nonatomic, copy) NSString *data;

@end

/**
 data解密后Model
*/
@interface WanjaDataModel : WanjaBaseModel

// 版本号
@property (nonatomic, copy) NSString *configVersion;

// 更新时间
@property (nonatomic, assign) uint64_t lastUpdateTime;

// 有效期
@property (nonatomic, assign) NSInteger expireTime;

// 是否加密
@property (nonatomic, assign) BOOL encrypt;

// 配置更新
@property (nonatomic, strong) WanjaConfiguratorModel *configurator;

// 广告方案
@property (nonatomic, strong) WanjaManagerModel *manager;

// 上报事件
@property (nonatomic, strong) WanjaMessageModel *messenger;

@end

/**
 配置文件检测
*/
@interface WanjaConfiguratorModel : WanjaBaseModel

//  配置id
@property (nonatomic, copy) NSString *uid;
//  工作内容
@property (nonatomic, copy) NSString *job;
//  动态配置版本号
@property (nonatomic, copy) NSString *version;
//  配置版本号
@property (nonatomic, copy) NSString *configVersion;
//  检查间隔
@property (nonatomic, assign) NSInteger checkInterval;
//  请求地址
@property (nonatomic, copy) NSString *configUrl;

@end

/**
 广告控制与worker控制
*/
@interface WanjaManagerModel : WanjaBaseModel

//  广告配置版本号
@property (nonatomic, copy) NSString *configVersion;
//  注册worker内容
//@property (nonatomic, strong) WanjaInitModel *cookieInit;
@property (nonatomic, assign) NSInteger personalRecommend;
//  广告相关配置
@property (nonatomic, strong) NSArray<WanjaAdSlotsModel *> *adSlots;

@end

/**
 worker控制
*/
@interface WanjaInitModel : WanjaBaseModel

//  注册worker数组
@property (nonatomic, strong) NSArray *workers;

@end

/**
 广告控制adSlots
*/
@interface WanjaAdSlotsModel : WanjaBaseModel

@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *slotId;
//  广告类型
@property (nonatomic, copy) NSString *adType;
@property (nonatomic, copy) NSString *adTypeId;
@property (nonatomic, copy) NSString *componentSsid;
//  广告筛选配置
@property (nonatomic, strong) WanjaFilterModel *filter;
//  广告买方配置
@property (nonatomic, strong) NSArray<WanjaBuyerModel *> *buyer;
//  广告设置
@property (nonatomic, strong) WanjaBidModel *bid;
@property (nonatomic, strong) WanjaBidComponent *bidComponent;
@property (nonatomic, strong) WanjaComponent *component;

@end

/**
 广告筛选，总体控制
*/
@interface WanjaFilterModel : WanjaBaseModel

//  最小请求时间
@property (nonatomic, assign) NSInteger minAdLoadTime;
//  需要权限
@property (nonatomic, strong) NSArray *privilege;
//  安卓设备长度
@property (nonatomic, strong) NSArray *imeiLength;
//  idfa限制
@property (nonatomic, assign) BOOL getIdfa;

@end

/**
 广告买方
*/
@interface WanjaBuyerModel : WanjaBaseModel

//  买方名称
@property (nonatomic, copy) NSString *uid;
//  类型，是否等待，是否先回，是否价高等
@property (nonatomic, copy) NSString *zone;
@property (nonatomic, copy) NSString *sdkId;
@property (nonatomic, copy) NSString *slotId;
@property (nonatomic, copy) NSString *baseId;
@property (nonatomic, copy) NSString *bidType;
@property (nonatomic, copy) NSString *buyerSlotUuid;
@property (nonatomic, copy) NSString *click_url;
@property (nonatomic, strong) NSArray *dspIds;
@property (nonatomic, copy) NSString *fail_url;
@property (nonatomic, copy) NSString *fixedType;
@property (nonatomic, copy) NSString *image_url;
@property (nonatomic, copy) NSString *filterPrice;
@property (nonatomic, copy) NSString *mediaFixedPrice;
@property (nonatomic, strong) NSDictionary *priceDict;
@property (nonatomic, copy) NSString *profitRatio;      // 利润率
@property (nonatomic, copy) NSString *renderViewSsid;
@property (nonatomic, copy) NSString *request_url;
@property (nonatomic, copy) NSString *response_url;
@property (nonatomic, copy) NSString *win_url;

//  价格
@property (nonatomic, assign) CGFloat avgPrice;
@property (nonatomic, assign) CGFloat channelPrice;
@property (nonatomic, assign) BOOL cache;
@property (nonatomic, assign) NSInteger weight;
//  worker
@property (nonatomic, copy) NSString *adWorker;
//  广告筛选
@property (nonatomic, strong) WanjaFilterModel *filter;
//  是否进行过比价
@property (nonatomic, assign) BOOL isSuccess;

@property (nonatomic, strong) WanjaFullScreenClick *fullScreenClick;
@property (nonatomic, strong) NSArray<WanjaRenderView *> *renderView;
@property (nonatomic, strong) WanjaShakeView *shakeView;
@property (nonatomic, strong) WanjaRegionalClick *regionalClickView;
@property (nonatomic, strong) WanjaSwipeViewModel *scrollClick;
@property (nonatomic, strong) WanjaRenderPolicy *renderPolicy;
@property (nonatomic, strong) NSArray<WanjaCallBackStrategy *> *callBackStrategy;

@end

@interface WanjaRegionalClick : WanjaBaseModel

@property (nonatomic, copy) NSString *backgroundColor;
@property (nonatomic, copy) NSString *titleColor;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *regionalClickUuid;
@property (nonatomic, assign) CGFloat backgroundAlpha;
@property (nonatomic, assign) CGFloat titleSize;
@property (nonatomic, strong) WanjaPosition *position;

@end

@interface WanjaSwipeViewModel : WanjaBaseModel

@property (nonatomic, strong) WanjaPosition *position;
@property (nonatomic, copy) NSString *scrollClickUuid;
@property (nonatomic, copy) NSString *scrollDirection;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *details;
@property (nonatomic, assign) CGFloat titleFont;
@property (nonatomic, assign) CGFloat scrollDistance;
@property (nonatomic, assign) CGFloat detailsFont;
@property (nonatomic, assign) CGFloat randomClickTime;
@property (nonatomic, assign) CGFloat randomClickNum;

@end

@interface WanjaFullScreenClick : WanjaBaseModel

@property (nonatomic, copy) NSString *fullScreenClickUuid;
@property (nonatomic, assign) NSInteger randomClickNum;

@end

@interface WanjaRenderView : WanjaBaseModel

@property (nonatomic, copy) NSString *countDownColor;
@property (nonatomic, copy) NSString *skipText;
@property (nonatomic, copy) NSString *textColor;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *fullScreenClickUuid;  // SKIPVIEW=跳过按钮，MATERIALVIEW=素材图层,AREAOPTIMIZE=优化广告可点击区域
@property (nonatomic, strong) WanjaPosition *layerPosition;   // 按钮位置和大小
@property (nonatomic, strong) WanjaPosition *tapPosition;     // 点击区域
@property (nonatomic, strong) NSArray<WanjaPassPolicy *> *passPolicy;// 透传策略

@property (nonatomic, assign) NSInteger delayDisplaySkipButton;// 延时显示跳过按钮时长
@property (nonatomic, assign) NSInteger level;          // 图层的层级等级，值越小层级越靠上
@property (nonatomic, assign) NSInteger paddingHeight;  // 距离顶部距离
@property (nonatomic, assign) NSInteger showBorder;     // 边框
@property (nonatomic, assign) NSInteger skipViewTotalTime;      // 跳过按钮最长显示时间
@property (nonatomic, assign) NSInteger skipUnavailableTime;    // 跳过按钮不可点击时长
@property (nonatomic, assign) NSInteger showCountDown;          // 是否显示倒计时

@end

@interface WanjaPassPolicy : WanjaBaseModel

@property (nonatomic, copy) NSString *passType;
@property (nonatomic, assign) NSInteger passPercent;

@end

@interface WanjaShakeView : WanjaBaseModel

@property (nonatomic, strong) WanjaPosition *position;
@property (nonatomic, assign) NSInteger rotatAmplitude;
@property (nonatomic, assign) float accelerometerValue; //加速度
@property (nonatomic, assign) NSInteger rotatCount;
@property (nonatomic, assign) NSInteger shakeCount;
@property (nonatomic, assign) CGFloat shakeEndAmplitude;
@property (nonatomic, assign) CGFloat shakeStartAmplitude;
@property (nonatomic, copy) NSString *shakeViewUuid;
@property (nonatomic, copy) NSString *shakeTitleText;
@property(nonatomic, assign) BOOL showShakeLogo; //是否显示摇一摇logo
//百度网盘专用
@property(nonatomic, assign) NSInteger shakeTimes;//摇动次数

@end

@interface WanjaRenderPolicy : WanjaBaseModel

@property (nonatomic, assign) NSInteger frequency;
@property (nonatomic, assign) CGFloat stay_time;
@property (nonatomic, assign) CGFloat percent;

@end

@interface WanjaCallBackStrategy : WanjaBaseModel

@property (nonatomic, copy) NSString *eventCode;
@property (nonatomic, copy) NSString *rate;

@end

@interface WanjaPosition : WanjaBaseModel

@property (nonatomic, copy) NSString *top;
@property (nonatomic, copy) NSString *centerX;
@property (nonatomic, copy) NSString *centerY;
@property (nonatomic, copy) NSString *height;
@property (nonatomic, copy) NSString *width;

@end

/**
 广告设置
*/
@interface WanjaBidModel : WanjaBaseModel

//  比价时间
@property (nonatomic, assign) NSInteger reserveFRWTime;
//  结束时间
@property (nonatomic, assign) NSInteger reserveTime;
@property (nonatomic, assign) NSInteger bidTime;

@end

/**
 广告设置
*/
@interface WanjaMessageModel : WanjaBaseModel

//  上报配置版本号
@property (nonatomic, copy) NSString *configVersion;
//  热更新版本号
@property (nonatomic, copy) NSString *version;
//  最大文件设定
@property (nonatomic, copy) NSString *fileMaxSize;
//  检查时间
@property (nonatomic, assign) uint64_t checkInterval;
//  有效期
@property (nonatomic, assign) uint64_t expireTime;
//  上报事件
@property (nonatomic, strong) NSArray<WanjaEventsModel *> *events;

@end

/**
 上报事件
*/
@interface WanjaEventsModel : WanjaBaseModel

//  广告相关配置
@property (nonatomic, strong) NSArray *codes;
//  NO离线上报，YES时时上报
@property (nonatomic, assign) BOOL isOnline;
//  上报地址
@property (nonatomic, copy) NSString *uploadUrl;

@end


@interface WanjaBidComponent : WanjaBaseModel

@property (nonatomic, strong) NSArray<WanjaComponent *> *bidList;

@end


@interface WanjaComponent : WanjaBaseModel

@property (nonatomic, copy) NSString *baseId;
@property (nonatomic, copy) NSString *buyerId;
@property (nonatomic, copy) NSString *buyerSlotUuid;
@property (nonatomic, copy) NSString *forwardId;
@property (nonatomic, copy) NSString *level;
@property (nonatomic, copy) NSString *parentForwardId;
@property (nonatomic, assign) NSInteger sleepTime;
@property (nonatomic, strong) NSArray<WanjaComponentRule *> *rules;

@property (nonatomic, copy) NSString *content;
@property (nonatomic, strong) NSArray<WanjaComponent *> *forward;

@end

@interface WanjaComponentRule : WanjaBaseModel

@property (nonatomic, copy) NSString *baseId;
@property (nonatomic, copy) NSString *formula;
@property (nonatomic, strong) NSArray *results;

@end

NS_ASSUME_NONNULL_END
