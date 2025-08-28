//
//  ZJNativeAdHTMLTableViewCell.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2025/8/25.
//  Copyright © 2025 zj. All rights reserved.
//

#import "ZJNativeAdHTMLTableViewCell.h"

@implementation ZJNativeAdHTMLTableViewCell

- (void)setupWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject delegate:(id<ZJNativeAdViewDelegate>)delegate vc:(UIViewController *)vc{

    self.fillView.viewController = vc;
    self.fillView.delegate = delegate;
//    [self.fillView registerDataObject:dataObject clickableViews:@[self.fillView.appIconImageView, self.fillView.imageView,self.fillView.descLabel,self.fillView.titleLabel,self.fillView.clickButton]];
    [self.fillView registerDataObject:dataObject clickableViews:@[self.fillView,self.fillView.clickButton]];
    self.fillView.htmlView.frame = CGRectMake(0, ZJNativeTopHeight, self.frame.size.width, 150);
//    self.fillView.videoOrImageFrame = self.fillView.videoAdView.frame;
    [self.fillView resizeIfNeed];
    [self.contentView addSubview:self.fillView];
//    self.fillView.logoView.hidden = YES;

}


+ (CGFloat)cellHeightWithUnifiedNativeAdDataObject:(ZJNativeAdObject *)dataObject
{
    CGFloat baseHeigth = [super cellHeightWithUnifiedNativeAdDataObject:dataObject];
     //视频cell
     CGFloat videoHeight = 150;
     //图片高度+顶部固定高度+底部间隙
     return videoHeight+baseHeigth+8;
}


@end
