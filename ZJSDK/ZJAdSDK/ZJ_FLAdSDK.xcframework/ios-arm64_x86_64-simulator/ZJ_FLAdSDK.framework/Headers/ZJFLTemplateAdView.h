//
//  ZJFLTemplateAdView.h
//  ZJ_FLAdSDK
//
//  Created by Lurich on 2023/7/24.
//

#import <UIKit/UIKit.h>
#import <ZJ_FLAdSDK/ZJFLFeedAdData.h>
#import <ZJ_FLAdSDK/ZJFLNativeAdRenderProtocol.h>

@interface ZJFLTemplateAdView : UIView <ZJFLNativeAdRenderProtocol>

@property (nonatomic, strong) UIImageView *adImageView;

- (instancetype)initWithFrame:(CGRect)frame Model:(ZJFLFeedAdData *)model Style:(ZJFLTemplateStyleOptions)style LRMargin:(CGFloat)left_right_margin TBMargin:(CGFloat)top_bottom_margin;

@end
