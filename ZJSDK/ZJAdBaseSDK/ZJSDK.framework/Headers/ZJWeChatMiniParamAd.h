//
//  ZJWeChatMiniParamAd.h
//  ZJSDK
//
//  Created by 麻明康 on 2025/1/19.
//  Copyright © 2025 zj. All rights reserved.
//

#import <ZJSDK/ZJSDK.h>
#import <ZJSDKCore/ZJMiniParamAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

@class ZJWeChatMiniParamAd;

@protocol ZJWeChatMiniParamAdDelegate <NSObject>

@optional
/**
 *  小程序唤起成功
 */
- (void)zj_wechatMiniParamAdDidAwake:(ZJWeChatMiniParamAd *)miniParamAd;


/**
 *  小程序唤起失败
 */
- (void)zj_wechatMiniParamAdAwakeFail:(ZJWeChatMiniParamAd *)miniParamAd error:(NSError *)error;


@end


@interface ZJWeChatMiniParamAd : ZJTierAd

@property (nonatomic, weak) id <ZJWeChatMiniParamAdDelegate> delegate;

@property (nonatomic, strong,nullable) ZJMiniParamAdAdapter *currentAdapter;

@end

NS_ASSUME_NONNULL_END
