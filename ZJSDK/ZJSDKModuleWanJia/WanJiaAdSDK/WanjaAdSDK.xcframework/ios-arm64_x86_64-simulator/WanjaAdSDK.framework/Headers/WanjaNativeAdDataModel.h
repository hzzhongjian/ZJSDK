//
//  WanjaopusNativeAdDataModel.h
//  WanjaopusAdDemo
//
//  Created by guantou on 2023/11/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class WanjaResponseModel;
@class WanjaSpaceInfoModel;
@class WanjaMediaView;
@class WanjaBlurView;
@class WanjaDisposeResponseModel;

@interface WanjaNativeAdDataModel : NSObject

//  按钮文字
@property (nonatomic, strong, readonly) NSString *wanjaAction;
//  广告标题
@property (nonatomic, strong, readonly) NSString *wanjaHeadline;
//  广告图片素材
@property (nonatomic, strong, readonly) NSArray *wanjaImages;
//  广告文字素材
@property (nonatomic, strong, readonly) NSArray *wanjaTexts;
//  广告视频素材
@property (nonatomic, strong, readonly) NSArray *wanjaVideos;
//  wanjaImages中第一个图片的宽， 当wanjaIsVideo=NO时，才有效
@property (nonatomic, assign, readonly) NSInteger wanjaWidth;
//  wanjaImages中第一个图片的高， 当wanjaIsVideo=NO时，才有效
@property (nonatomic, assign, readonly) NSInteger wanjaHeight;


// 由于广告法规定，必须添加logo，（建议：广告图片放置在广告的左下角，logo放置在广告的右下角）
//  广告图片，当此字符串不为空时，加载adLabelURL的图片。
@property (nonatomic, strong, readonly) NSString *wanjaLabelURL;
//  广告文字，当adLabelURL为空时，使用adLabel的文字
@property (nonatomic, strong, readonly) NSString *wanjaLabel;
//  logo图片，当此字符串不为空时，加载logoURL的图片。
@property (nonatomic, strong, readonly) NSString *wanjaLogoURL;
//  logo文字，当logoURL为空时，使用logoLabel的文字
@property (nonatomic, strong, readonly) NSString *wanjaLogoLabel;
// AppIcon的url
@property (nonatomic, strong, readonly) NSString *appIconUrl;


//摇一摇的UIImageView视图， 调用startAnimating方法，即可开启摇一摇的动画，视图width / height = 1 ：1
@property (nonatomic, strong, readonly) UIImageView *wanjaShakeImageView;
//是否是视频
@property(nonatomic, assign, readonly) BOOL wanjaIsVideo;
//如果wanjaIsVideo=YES，那么会提供视图播放器视图
@property(nonatomic, strong, readonly) WanjaMediaView *wanjaMediaView;
/**
 高斯模糊的图片视图， 自己调整frame的大小就可以，默认显示图片wanjaImages.firstObject, 防止图片变形; 当wanjaIsVideo=true时，blurView=nil
 也可以自定义WanjaBlurView， 来展示图片
 */
@property(nonatomic, strong, readonly) WanjaBlurView *blurView;


// 绑定展示视图和广告点击View（该视图点击可以跳转到落地页）
- (void)bindVieWithContainer:(UIView *)containerView clickableViews:(NSArray *)clickableViews;
// 添加关闭视图（该视图点击，可以关闭广告）
- (void)addADCloseTarget:(UIView*)targetView;
// 添加摇一摇视图， 调用此方法后， sdk内会开启摇一摇的监听, 以及targetView的点击响应
- (void)addShakeTarget:(UIView*)targetView;


/**
 SDK内部方法，无需调用与使用
 */
- (instancetype)initWithData:(WanjaDisposeResponseModel*)disposeModel;

@end

NS_ASSUME_NONNULL_END
