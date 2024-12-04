//
//  JLDrawVideoAdRelatedView.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLDrawVideoAdRelatedView;

@protocol JLDrawVideoAdRelatedViewDelegate <NSObject>
@optional
- (void)jl_drawVideoAdRelatedViewDidExpose:(JLDrawVideoAdRelatedView *)drawVideoAdRelatedView;
- (void)jl_drawVideoAdRelatedViewDidClick:(JLDrawVideoAdRelatedView *)drawVideoAdRelatedView;
- (void)jl_drawVideoAdRelatedViewDidCloseOtherController:(JLDrawVideoAdRelatedView *)drawVideoAdRelatedView;
- (void)jl_drawVideoAdRelatedViewDidPlayFinish:(JLDrawVideoAdRelatedView *)drawVideoAdRelatedView;
@end

@class JLInnerDrawVideoAdRelatedView;

@interface JLDrawVideoAdRelatedView : NSObject <JLAdProtocol>
{
    @package
    JLInnerDrawVideoAdRelatedView * _innerDrawVideoAdRelatedView;
}
-(instancetype) initWithInnerDrawVideoAdRelatedView:(JLInnerDrawVideoAdRelatedView *) innerDrawVideoAdRelatedView;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, weak, nullable) id<JLDrawVideoAdRelatedViewDelegate> delegate;

- (void)registerContainer:(UIView *)containerView;
- (void)unregisterView;

@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;
- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;
@end

NS_ASSUME_NONNULL_END
