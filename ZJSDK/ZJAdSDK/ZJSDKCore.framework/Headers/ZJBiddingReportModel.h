//
//  ZJBiddingReportModel.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/4/9.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
#import <ZJSDKCore/ZJBiddingLossRelease.h>
#import <ZJSDKCore/ZJAdExposureReportParam.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJBiddingReportModel : NSObject

@property (nonatomic, assign) NSInteger firstPrice;

@property (nonatomic, assign) NSInteger secondPrice;

/// adn
@property (nonatomic, assign) ZJAdPlatformType firstPlatformType;

/// adn
@property (nonatomic, assign) ZJAdPlatformType secondPlatformType;

/// 竞价时间
@property (nonatomic, strong) NSString *ad_time;

/// 竞胜方dsp的竞价类型，1:分层保价，2:价格标签，3:bidding，4:其他
/// 暂时使用1、3、4
@property (nonatomic, assign) NSInteger first_bid_t;

/// 竞败方dsp的竞价类型，1:分层保价，2:价格标签，3:bidding，4:其他
/// 暂时使用1、3、4
@property (nonatomic, assign) NSInteger second_bid_t;

/// 其他信息
@property (nonatomic, strong, nullable) NSMutableDictionary *extraDic;

///竞败原因，具体值的映射关系见附表4    
@property (nonatomic, assign) ZJBiddingLossReason reason;

/// 竞胜方请求ID
@property (nonatomic, copy) NSString *adRequestId;

// 竞胜平台类型
@property (nonatomic, assign) ZJAdExposureAdnType adnType;

// 竞胜平台名称
@property (nonatomic, copy) ZJAdADNName adnName;

/// 竞胜广告主名称
@property (nonatomic, copy) NSString *adUserName;

/// 竞胜广告标题
@property (nonatomic, copy) NSString *adTitle;

/// 竞胜广告物料类型
@property (nonatomic, assign) ZJAdExposureAdnMaterialType adnMaterialType;

// 竞胜方广告素材url
@property (nonatomic, copy) NSString *adnMaterialUrl;

/// 竞胜方dsp本次请求是否展示
@property (nonatomic, assign) ZJAdBiddingActionType isShow;

/// 竞胜方dsp本次pv是否被点击
@property (nonatomic, assign) ZJAdBiddingActionType isClick;

/// 该字段用来标识这些数据用于传哪里的，如果为YES，代表是上传到暴露给媒体的接口使用
@property (nonatomic, assign) BOOL biddingFailureFlag;

@end

NS_ASSUME_NONNULL_END
