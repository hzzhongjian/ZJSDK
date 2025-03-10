//
//  JLNativeExpressAdRelatedView.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/5/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLNativeExpressAdRelatedView;

@protocol JLNativeExpressAdRelatedViewDelegate <NSObject>

@optional

- (void)jl_nativeExpressAdRelatedViewDidRenderSuccess:(JLNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jl_nativeExpressAdRelatedViewDidRenderFail:(JLNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jl_nativeExpressAdRelatedViewDidExpose:(JLNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jl_nativeExpressAdRelatedViewDidClick:(JLNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jl_nativeExpressAdRelatedViewDidCloseOtherController:(JLNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jl_nativeExpressAdRelatedViewDidPresentFullScreenModal:(JLNativeExpressAdRelatedView *)nativeExpressAdRelatedView;
- (void)jl_nativeExpressAdRelatedViewDislike:(JLNativeExpressAdRelatedView *)nativeExpressAdRelatedView;

@end

@class JLInnerNativeExpressAdRelatedView;

@interface JLNativeExpressAdRelatedView : NSObject <JLAdProtocol>
{
    @package
    JLInnerNativeExpressAdRelatedView * _innerNativeExpressAdRelatedView;
}
-(instancetype) initWithInnerNativeExpressAdRelatedView:(JLInnerNativeExpressAdRelatedView *) innerNativeExpressAdRelatedView;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, weak, nullable) id<JLNativeExpressAdRelatedViewDelegate> delegate;

- (void)render;
- (UIView *)getAdView;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;
- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;
@end

NS_ASSUME_NONNULL_END
