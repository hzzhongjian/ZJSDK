//
//  ZJFLBannerView.h
//  ZJ_FLAdSDKAdapter
//
//  Created by Lurich on 2023/3/28.
//

#import <UIKit/UIKit.h>

@class ZJFLFeedAdData,ZJFLAdSourcesModel;

NS_ASSUME_NONNULL_BEGIN

@interface ZJFLBannerView : UIView

@property (nonatomic, strong) UIImageView *logoImgView;
@property (nonatomic, strong, nullable) ZJFLFeedAdData *model;

@end

NS_ASSUME_NONNULL_END
