//
//  ZJBaseTubeAdapter.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/6/11.
//

#import <ZJSDKCore/ZJCoreAdAdapter.h>
#import <ZJSDKCore/ZJTierAdAdapter.h>

NS_ASSUME_NONNULL_BEGIN
//ZJCoreAdAdapter是继承ZJCoreAdAdapter 改成 ZJTierAdAdapter
@interface ZJBaseTubeAdapter : ZJTierAdAdapter
@property (nonatomic, strong) UIViewController *viewController;
-(void)reportWithEvent:(ZJEventString)event supplementMsg:(nullable NSString *)supplementMsg;

- (void)loadContentPageWithDeeplink:(NSString *)deepLink;

-(void)loadAd;
@end

NS_ASSUME_NONNULL_END
