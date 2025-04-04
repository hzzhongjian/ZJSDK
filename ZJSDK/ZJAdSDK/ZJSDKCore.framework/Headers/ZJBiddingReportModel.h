//
//  ZJBiddingReportModel.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/4/9.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
#import <ZJSDKCore/ZJBiddingLossRelease.h>
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

/// 竞胜广告主名称
@property (nonatomic, copy) NSString *adUserName;

/// 竞胜广告标题
@property (nonatomic, copy) NSString *adTitle;

/// 竞胜广告物料类型
@property (nonatomic, copy) NSString *adnMaterialType;



@end

NS_ASSUME_NONNULL_END
