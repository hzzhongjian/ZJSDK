//
//  ZJInterstitialAdProtocol.h
//  ZJSDKCore
//
//  Created by Robin on 2021/1/14.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ZJInterstitialAdProtocol <NSObject>

///视频静音， 支持部分广播  默认：YES,静音，NO为非静音
@property (nonatomic) BOOL mutedIfCan;
///广告size， 支持部分广播
@property (nonatomic, assign) CGSize adSize;

///--------------下面四个属性是为了兼容激励切换插屏适配添加的---------------------
///交易ID 需开启服务端校验才能获取交易ID
@property (nonatomic, copy, readonly) NSString *trade_id;
///验证dic
@property (nonatomic, copy, readonly) NSDictionary *validationDictionary;
///交易ID
@property (nonatomic, copy, readonly) NSString *trans_id;

/// ///视频静音， 支持部分广播  默认：YES,静音，NO为非静音
@property (nonatomic) BOOL videoMuted;

- (void)loadAd;

- (void)presentAdFromRootViewController:(UIViewController*)viewController;

// 新加的展示方法,为了适配激励转插屏
- (void)showAdInViewController:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
