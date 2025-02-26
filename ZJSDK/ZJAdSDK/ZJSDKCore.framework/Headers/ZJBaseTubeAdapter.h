//
//  ZJBaseTubeAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/6/11.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>
#import <ZJSDKCore/ZJTierAdAdapter.h>
#import <ZJSDKCore/ZJTubePageConfig.h>

NS_ASSUME_NONNULL_BEGIN
//ZJCoreAdAdapter是继承ZJCoreAdAdapter 改成 ZJTierAdAdapter

@interface ZJBaseTubeAdapter : ZJTierAdAdapter

@property (nonatomic, strong) UIViewController *viewController;

@property (nonatomic, strong) ZJTubePageConfig *tubePageConfig;

- (void)reportWithEvent:(ZJEventString)event supplementMsg:(nullable NSString *)supplementMsg;

- (void)loadContentPageWithDeeplink:(NSString *)deepLink;

- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
