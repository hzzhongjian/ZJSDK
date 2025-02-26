//
//  ZJKSAdExposureReportParam.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/2/11.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ZJKSAdBiddingActionType) {
    ZJKSAdBiddingActionTypeNone         = 0,    // 未点击&未曝光
    ZJKSAdBiddingActionTypeSuccess      = 1,    // 点击&曝光
    ZJKSAdBiddingActionTypeUnkown       = 2,    // 未知
};

typedef NS_ENUM(NSUInteger, ZJKSAdExposureAdnType) {
    ZJKSAdExposureAdnTypeKuaishou         = 1,    // 输给快手联盟其他广告
    ZJKSAdExposureAdnTypeOther            = 2,    // 输给其他ADN
    ZJKSAdExposureAdnTypeSelfSale         = 3,    // 输给自售广告主
};

typedef NS_ENUM(NSUInteger, ZJKSAdExposureAdnMaterialType) {
    ZJKSAdExposureAdnMaterialTypeHorizontalImg         = 1,    // 横版图片
    ZJKSAdExposureAdnMaterialTypeVerticalImg           = 2,    // 竖版图片
    ZJKSAdExposureAdnMaterialTypeHorizontalVideo       = 3,    // 横版视频
    ZJKSAdExposureAdnMaterialTypeVerticalVideo         = 4,    // 竖版视频
    ZJKSAdExposureAdnMaterialTypeThreeImg              = 5,    // 三图
    ZJKSAdExposureAdnMaterialTypeStreamer              = 6,    // 横幅
    ZJKSAdExposureAdnMaterialTypeOther                 = 7,    // 其他
};

@interface ZJKSAdExposureReportParam : NSObject

// 胜出者的ecpm报价
@property (nonatomic, assign) NSUInteger winEcpm;
// 竞胜平台类型
@property (nonatomic, assign) ZJKSAdExposureAdnType adnType;
// 竞胜平台名称，adnType=KSAdExposureAdnTypeOther时可以设置
// Chuanshanjia/Guangdiantong/Baidu/Other
@property (nonatomic, copy) NSString *adnName;

// 竞胜方dsp的广告主名称
@property (nonatomic, copy) NSString *adUserName;
// 竞胜方广告物料类型
@property (nonatomic, assign) ZJKSAdExposureAdnMaterialType adnMaterialType;
// 竞胜方广告素材url
@property (nonatomic, copy) NSString *adnMaterialUrl;
// 竞胜方的广告主标题
@property (nonatomic, copy) NSString *adTitle;
// 媒体侧的请求id
@property (nonatomic, copy) NSString *adRequestId;
// 竞胜方dsp本次请求是否展示
@property (nonatomic, assign) ZJKSAdBiddingActionType isShow;
// 竞胜方dsp本次pv是否被点击
@property (nonatomic, assign) ZJKSAdBiddingActionType isClick;

// 广告类型
@property (nonatomic, assign) ZJAdType adType;

@end

NS_ASSUME_NONNULL_END
