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

- (instancetype)initWithInnerDrawVideoAdRelatedView:(JLInnerDrawVideoAdRelatedView *) innerDrawVideoAdRelatedView;

@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, weak, nullable) id<JLDrawVideoAdRelatedViewDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType;

// ⚠️ 当 Draw 广告视图要显示到页面上时，如在 TableView 的 cellForRowAtIndexPath 函数中，把 cell.contentView 作为此 containerView 参数传递来，
// 然后我们把 Draw 广告视图添加到这个 cell.contentView 上，由此就把 Draw 广告视图显示到屏幕上了。
- (void)registerContainer:(UIView *)containerView;
// ⚠️ unregisterView 则是把我们的 Draw 广告视图从其父视图移除，如在 cell 的 prepareForReuse 执行，cell 被复用时，调用此 unregisterView 函数。
- (void)unregisterView;

// ⚠️ 竞胜/竞败 时上报相关的函数。
- (NSInteger)eCPM;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
