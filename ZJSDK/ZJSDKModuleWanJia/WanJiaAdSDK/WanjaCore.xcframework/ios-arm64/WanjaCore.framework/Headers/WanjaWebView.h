//
//  WanjaWebView.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/9.
//

#import <UIKit/UIKit.h>
#import "WanjaAdvertisingDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 webView广告
*/
@class WanjaSpaceInfoModel;

@interface WanjaWebView : UIView

@property (nonatomic, weak) id<WanjaAdvertisingDelegate> delegate;

/**
 点击位置，相对于广告
*/
@property (nonatomic, assign, readonly) CGPoint adClickPoint;
/**
 点击位置，相对于屏幕
*/
@property (nonatomic, assign, readonly) CGPoint srClickPoint;

- (instancetype)initWithFrame:(CGRect)frame;

/**
 渲染广告
 @param spaceInfo 广告数据模型
 @param index 加载第几个广告
*/
- (void)loadWebViewWithWanjaSpaceInfo:(WanjaSpaceInfoModel *)spaceInfo index:(NSInteger)index;
- (void)loadWebViewWithWanjaSpaceInfo:(WanjaSpaceInfoModel *)spaceInfo index:(NSInteger)index isNative:(BOOL)isNative;
- (void)loadLocalHtmlImage:(NSString*)htmlImage;

/**
 移除本身，在NSObject中无法释放
 */
- (void)closeSelf;

@end

NS_ASSUME_NONNULL_END
