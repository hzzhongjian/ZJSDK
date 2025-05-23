//
//  ZJTierAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2022/11/11.
//  Copyright © 2022 zj. All rights reserved.
//

#import <ZJSDK/ZJAd.h>
#import <ZJSDKCore/ZJTierAdAdapter.h>
#import <ZJSDKCore/ZJAdCountdown.h>
#import <ZJSDKCore/ZJAdPreferenceManager.h>
#import <ZJSDKCore/ZJStrategyManager.h>
#import "ZJTierAdLoader.h"


NS_ASSUME_NONNULL_BEGIN

@protocol ZJBiddingProtocol <NSObject>

@required
/// 广告数据和联盟素材加载处理成功，但是没有加载
- (void)dealSuccessResult;

/// 广告数据和联盟素材加载失败
- (void)dealFailResultWithError:(NSError *)error;

/// 创建Tier的加载器，处理ad适配器
- (ZJTierAdLoader *)createTierLoader:(NSArray <ZJAdUnitModel *> *)tiers showPriority:(ZJAdShowPriority)showPriority;

@optional
- (NSInteger)getCountDownInterval;

@end


//ZJTierAd为刚开始重构时思路不清晰，命名有误，特此标注。应理解为ZJSingleAd，与ZJMultipleAd对应
@interface ZJTierAd : ZJAd <ZJBiddingProtocol> {
    BOOL _needDelayLoadAd;
    BOOL _takeFastReturnAd;
    NSInteger eCPM1;
    NSInteger eCPM2;
}

@property (nonatomic, assign) BOOL hasLoadResult;

//倒计时器
//@property (nonatomic,strong)ZJAdCountdown *countdown;
//数据管理
@property (nonatomic, strong) ZJAdPreferenceManager *adManager;

//错误信息数组
@property (nonatomic, strong) NSMutableArray <NSError *>*adFailArray;

@property (nonatomic, strong) NSMutableString *logString;

//pd广告请求成功数组
@property (nonatomic, strong) NSMutableArray <ZJTierAdAdapter *> *successAdaptersPD;

//bd广告请求成功数组
@property (nonatomic, strong) NSMutableArray <ZJTierAdAdapter *> *successAdaptersBD;


@property (nonatomic, strong) ZJTierAdAdapter *ecpm1Adapter;

@property (nonatomic, strong, nullable)ZJTierAdAdapter *currentAdapter;

- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
