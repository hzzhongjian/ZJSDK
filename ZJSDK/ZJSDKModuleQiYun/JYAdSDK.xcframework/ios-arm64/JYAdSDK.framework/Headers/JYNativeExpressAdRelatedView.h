//
//  JYNativeExpressAdRelatedView.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/5/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYNativeExpressAdRelatedView;

@protocol JYNativeExpressAdRelatedViewDelegate <NSObject>

@optional

- (void)jy_nativeExpressAdRelatedViewDidRenderSuccess:(JYNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jy_nativeExpressAdRelatedViewDidRenderFail:(JYNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jy_nativeExpressAdRelatedViewDidExpose:(JYNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jy_nativeExpressAdRelatedViewDidClick:(JYNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jy_nativeExpressAdRelatedViewDidCloseOtherController:(JYNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jy_nativeExpressAdRelatedViewDidPresentFullScreenModal:(JYNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jy_nativeExpressAdRelatedViewDislike:(JYNativeExpressAdRelatedView *)nativeExpressAdRelatedView;

@end

@class JYInnerNativeExpressAdRelatedView;

@interface JYNativeExpressAdRelatedView : NSObject <JYAdProtocol>
{
    @package
    JYInnerNativeExpressAdRelatedView * _innerNativeExpressAdRelatedView;
}
-(instancetype) initWithInnerNativeExpressAdRelatedView:(JYInnerNativeExpressAdRelatedView *) innerNativeExpressAdRelatedView;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, weak, nullable) id<JYNativeExpressAdRelatedViewDelegate> delegate;

- (void)render;
- (UIView *)getAdView;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;
@end

NS_ASSUME_NONNULL_END
