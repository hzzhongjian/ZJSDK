//
//  KSAdExposureReportParam.h
//  KSUModel
//
//  Created by xuzaihu on 2021/7/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, KSAdExposureFailureCode) {
    KSAdExposureFailureOther                   = 0,    // 其他
    KSAdExposureFailureMediaBasePriceFilter    = 1,    // 媒体侧底价过滤
    KSAdExposureFailureBidFailed               = 2,    // 广告竞价失败
    KSAdExposureFailureCacheInvalid            = 3,    // 缓存失效
    KSAdExposureFailureExposurePriorityReduce  = 4,    // 曝光优先级降低
    KSAdExposureFailureExposureReturnTimeout   = 5,    // 返回超时
    KSAdExposureFailureExposureMediaBlocking   = 6,    // 媒体屏蔽
};

typedef NS_ENUM(NSUInteger, KSAdExposureAdnType) {
    KSAdExposureAdnTypeKuaishou         = 1,    // 输给快手联盟其他广告
    KSAdExposureAdnTypeOther            = 2,    // 输给其他ADN
    KSAdExposureAdnTypeSelfSale         = 3,    // 输给自售广告主
};

typedef NS_ENUM(NSUInteger, KSAdExposureAdnMaterialType) {
    KSAdExposureAdnMaterialTypeHorizontalImg         = 1,    // 横版图片
    KSAdExposureAdnMaterialTypeVerticalImg           = 2,    // 竖版图片
    KSAdExposureAdnMaterialTypeHorizontalVideo       = 3,    // 横版视频
    KSAdExposureAdnMaterialTypeVerticalVideo         = 4,    // 竖版视频
    KSAdExposureAdnMaterialTypeThreeImg              = 5,    // 三图
    KSAdExposureAdnMaterialTypeStreamer              = 6,    // 横幅
    KSAdExposureAdnMaterialTypeOther                 = 7,    // 其他
};

typedef NS_ENUM(NSUInteger, KSAdBiddingActionType) {
    KSAdBiddingActionTypeNone         = 0,    // 未点击&未曝光
    KSAdBiddingActionTypeSuccess      = 1,    // 点击&曝光
    KSAdBiddingActionTypeUnkown       = 2,    // 未知
};

typedef NSString* KSAdADNName;
//平台定义
extern KSAdADNName const KSAdADNNameChuanshanjia;
extern KSAdADNName const KSAdADNNameGuangdiantong;
extern KSAdADNName const KSAdADNNameBaidu;
extern KSAdADNName const KSAdADNNameOther;
extern int const KSAdCompetitiveFailureDefaultValue;

@interface KSAdExposureReportParam : NSObject

// 胜出者的ecpm报价
@property (nonatomic, assign) NSUInteger winEcpm;
// 竞胜平台类型
@property (nonatomic, assign) KSAdExposureAdnType adnType;
// 竞胜平台名称，adnType=KSAdExposureAdnTypeOther时可以设置
@property (nonatomic, copy) KSAdADNName adnName;

// 竞胜方dsp的广告主名称
@property (nonatomic, copy) NSString *adUserName;
// 竞胜方广告物料类型
@property (nonatomic, assign) KSAdExposureAdnMaterialType adnMaterialType;
// 竞胜方广告素材url
@property (nonatomic, copy) NSString *adnMaterialUrl;
// 竞胜方的广告主标题
@property (nonatomic, copy) NSString *adTitle;
// 媒体侧的请求id
@property (nonatomic, copy) NSString *adRequestId;
// 竞胜方dsp本次请求是否展示
@property (nonatomic, assign) KSAdBiddingActionType isShow;
// 竞胜方dsp本次pv是否被点击
@property (nonatomic, assign) KSAdBiddingActionType isClick;


@end

NS_ASSUME_NONNULL_END
