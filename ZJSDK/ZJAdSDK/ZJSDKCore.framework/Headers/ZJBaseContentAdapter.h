//
//  ZJBaseContentAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2023/1/4.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>
#import <ZJSDKCore/ZJTierAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN

// 之前是继承ZJCoreAdAdapter，现改成ZJTierAdAdapter
@interface ZJBaseContentAdapter : ZJTierAdAdapter

@property (nonatomic, strong) UIViewController *viewController;

- (void)reportWithEvent:(ZJEventString)event supplementMsg:(nullable NSString *)supplementMsg;

- (void)loadContentPageWithDeeplink:(NSString *)deepLink;

- (void)loadAd;

@end

NS_ASSUME_NONNULL_END
