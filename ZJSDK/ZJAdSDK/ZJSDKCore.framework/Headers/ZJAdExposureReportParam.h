//
//  ZJAdExposureReportParam.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZJAdExposureFailureCode) {
    ZJAdExposureFailureOther                   = 0,    // 其他
    ZJAdExposureFailureMediaBasePriceFilter    = 1,    // 媒体侧底价过滤
    ZJAdExposureFailureBidFailed               = 2,    // 广告竞价失败
    ZJAdExposureFailureCacheInvalid            = 3,    // 缓存失效
    ZJAdExposureFailureExposurePriorityReduce  = 4,    // 曝光优先级降低
    ZJAdExposureFailureExposureReturnTimeout   = 5,    // 返回超时
    ZJAdExposureFailureExposureMediaBlocking   = 6,    // 媒体屏蔽
};


typedef NS_ENUM(NSUInteger, ZJAdExposureAdnType) {
    ZJAdExposureAdnTypeKuaishou         = 1,    // 输给快手联盟其他广告
    ZJAdExposureAdnTypeOther            = 2,    // 输给其他ADN
    ZJAdExposureAdnTypeSelfSale         = 3,    // 输给自售广告主
};

typedef NS_ENUM(NSUInteger, ZJAdExposureAdnMaterialType) {
    ZJAdExposureAdnMaterialTypeHorizontalImg         = 1,    // 横版图片
    ZJAdExposureAdnMaterialTypeVerticalImg           = 2,    // 竖版图片
    ZJAdExposureAdnMaterialTypeHorizontalVideo       = 3,    // 横版视频
    ZJAdExposureAdnMaterialTypeVerticalVideo         = 4,    // 竖版视频
    ZJAdExposureAdnMaterialTypeThreeImg              = 5,    // 三图
    ZJAdExposureAdnMaterialTypeStreamer              = 6,    // 横幅
    ZJAdExposureAdnMaterialTypeOther                 = 7,    // 其他
};

typedef NS_ENUM(NSUInteger, ZJAdBiddingActionType) {
    ZJAdBiddingActionTypeNone         = 0,    // 未点击&未曝光
    ZJAdBiddingActionTypeSuccess      = 1,    // 点击&曝光
    ZJAdBiddingActionTypeUnkown       = 2,    // 未知
};

typedef NSString* ZJAdADNName;
//平台定义
extern ZJAdADNName const ZJAdADNNameChuanshanjia;
extern ZJAdADNName const ZJAdADNNameGuangdiantong;
extern ZJAdADNName const ZJAdADNNameBaidu;
extern ZJAdADNName const ZJAdADNNameOther;

@interface ZJAdExposureReportParam : NSObject

// 胜出者的ecpm报价
@property (nonatomic, assign) NSUInteger winEcpm;
// 竞胜平台类型
@property (nonatomic, assign) ZJAdExposureAdnType adnType;
// 竞胜平台名称，adnType=KSAdExposureAdnTypeOther时可以设置
@property (nonatomic, copy) ZJAdADNName adnName;

// 竞胜方dsp的广告主名称
@property (nonatomic, copy) NSString *adUserName;
// 竞胜方广告物料类型
@property (nonatomic, assign) ZJAdExposureAdnMaterialType adnMaterialType;
// 竞胜方广告素材url
@property (nonatomic, copy) NSString *adnMaterialUrl;
// 竞胜方的广告主标题
@property (nonatomic, copy) NSString *adTitle;
// 竞胜方dsp本次请求是否展示
@property (nonatomic, assign) ZJAdBiddingActionType isShow;
// 竞胜方dsp本次pv是否被点击
@property (nonatomic, assign) ZJAdBiddingActionType isClick;

@end

NS_ASSUME_NONNULL_END
