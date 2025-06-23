//
//  ZjBannerViewController.m
//  ZJSDKDemo
//
//  Created by Robin on 2021/1/31.
//  Copyright © 2021 zj. All rights reserved.
//

#import "ZJBannerViewController.h"
#import <ZJSDK/ZJBannerAd.h>

#define ZJBannerHeight 200
@interface ZJBannerViewController ()<ZJBannerAdDelegate>

@property (nonatomic, strong) ZJBannerAd *bannerAd;

@end

@implementation ZJBannerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.loadAdView appendAdID:@[AdId_Banner]];
    self.loadAdView.showButton.hidden = NO;
}

-(void)loadAd:(NSString*) adId{
    [super loadAd:adId];
    CGFloat width = self.view.frame.size.width;
    self.bannerAd = [[ZJBannerAd alloc] initWithPlacementId:adId rootViewController:self adSize:CGSizeMake(width, ZJBannerHeight)];
    self.bannerAd.delegate = self;
    [self.bannerAd loadAd];
    
}

- (void)showAd
{
    [self.bannerAd showAd];
    UIView *bannerView = [self.bannerAd bannerView];
    CGFloat y = self.view.frame.size.height - bannerView.frame.size.height -kSafeBottomMargin-50;
    CGRect frame = CGRectMake(0, y, bannerView.frame.size.width, bannerView.frame.size.height);
    bannerView.frame = frame;
    [self.view addSubview:bannerView];
}

#pragma mark - ZJBannerAdDelegate
/**
 banner广告加载成功
 */
- (void)zj_bannerAdDidLoad:(ZJBannerAd *)bannerAd
{
    self.loadAdView.showButton.backgroundColor = kMainColor;
    [self logMessage:[NSString stringWithFormat:@"zj_bannerAdDidLoad"]];
    [self logMessage:[bannerAd valueForKey:@"logString"]];
}

/**
 banner广告加载失败
 */
- (void)zj_bannerAd:(ZJBannerAd *)bannerAd didLoadFailWithError:(NSError * _Nullable)error
{
    [self logMessage:[NSString stringWithFormat:@"bannerAdViewError:%@",error]];
}

/**
 bannerAdView曝光回调
 */
- (void)zj_bannerAdWillBecomVisible:(ZJBannerAd *)bannerAd
{
    [self logMessage:[NSString stringWithFormat:@"zj_bannerAdWillBecomVisible"]];
}

/**
 关闭banner广告回调
 */
- (void)zj_bannerAdDislike:(ZJBannerAd *)bannerAd
{
    [self logMessage:[NSString stringWithFormat:@"zj_bannerAdDislike"]];
}

/**
 点击banner广告回调
 */
- (void)zj_bannerAdDidClick:(ZJBannerAd *)bannerAd
{
    [self logMessage:[NSString stringWithFormat:@"zj_bannerAdDidClick"]];
}

/**
 关闭banner广告详情页回调
 */
- (void)zj_bannerAdDidCloseOtherController:(ZJBannerAd *)bannerAd
{
    [self logMessage:[NSString stringWithFormat:@"zj_bannerAdDidCloseOtherController"]];
}


@end
