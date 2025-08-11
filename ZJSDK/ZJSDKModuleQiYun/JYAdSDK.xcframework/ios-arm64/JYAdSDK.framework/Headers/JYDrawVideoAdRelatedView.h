//
//  JYDrawVideoAdRelatedView.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYDrawVideoAdRelatedView;

@protocol JYDrawVideoAdRelatedViewDelegate <NSObject>

@optional
- (void)jy_drawVideoAdRelatedViewDidExpose:(JYDrawVideoAdRelatedView *)drawVideoAdRelatedView;
- (void)jy_drawVideoAdRelatedViewDidClick:(JYDrawVideoAdRelatedView *)drawVideoAdRelatedView;
- (void)jy_drawVideoAdRelatedViewDidCloseOtherController:(JYDrawVideoAdRelatedView *)drawVideoAdRelatedView;
- (void)jy_drawVideoAdRelatedViewDidPlayFinish:(JYDrawVideoAdRelatedView *)drawVideoAdRelatedView;

@end

@class JYInnerDrawVideoAdRelatedView;

@interface JYDrawVideoAdRelatedView : NSObject <JYAdProtocol>
{
    @package
    JYInnerDrawVideoAdRelatedView * _innerDrawVideoAdRelatedView;
}

- (instancetype)initWithInnerDrawVideoAdRelatedView:(JYInnerDrawVideoAdRelatedView *) innerDrawVideoAdRelatedView;

@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, weak, nullable) id<JYDrawVideoAdRelatedViewDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;

// ⚠️ 当 Draw 广告视图要显示到页面上时，如在 TableView 的 cellForRowAtIndexPath 函数中，把 cell.contentView 作为此 containerView 参数传递来，
// 然后我们把 Draw 广告视图添加到这个 cell.contentView 上，由此就把 Draw 广告视图显示到屏幕上了。
- (void)registerContainer:(UIView *)containerView;
// ⚠️ unregisterView 则是把我们的 Draw 广告视图从其父视图移除，如在 cell 的 prepareForReuse 执行，cell 被复用时，调用此 unregisterView 函数。
- (void)unregisterView;

// ⚠️ 竞胜/竞败 时上报相关的函数。
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

@end

NS_ASSUME_NONNULL_END
