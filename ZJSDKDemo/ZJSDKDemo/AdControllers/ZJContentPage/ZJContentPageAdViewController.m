//
//  ZJContentPageAdViewController.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2025/1/20.
//  Copyright © 2025 zj. All rights reserved.
//

#import "ZJContentPageAdViewController.h"
#import <ZJSDK/ZJContentPageAd.h>

@interface ZJContentPageAdViewController () <ZJContentPageVideoStateDelegate, ZJContentPageStateDelegate, ZJContentPageLoadCallBackDelegate>

@property (nonatomic, strong) ZJContentPageAd *contentPageAd;

@property (nonatomic, strong) UIViewController *contentPageVC;

@end

@implementation ZJContentPageAdViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.loadAdView appendAdID:@[AdId_ContentPage]];
    self.loadAdView.showButton.backgroundColor = kMainColor;
}

- (void)loadAd:(NSString *)adId
{
    [super loadAd:adId];
    self.contentPageAd = [[ZJContentPageAd alloc]initWithPlacementId:adId];
    self.contentPageAd.videoStateDelegate = self;
    self.contentPageAd.stateDelegate = self;
    self.contentPageAd.loadCallBackDelegate = self;
    [self.contentPageAd loadAd];
}

- (void)showAd
{
    self.contentPageVC = self.contentPageAd.contentPageViewController;
    if(self.contentPageVC){
        [self addChildViewController:self.contentPageVC];
        [self.view addSubview:self.contentPageVC.view];
        CGFloat contentY = [UIApplication sharedApplication].statusBarFrame.size.height+self.navigationController.navigationBar.frame.size.height;
        [self.contentPageVC.view setFrame:CGRectMake(0, contentY, self.view.frame.size.width, self.view.frame.size.height - contentY)];
    }else{
        NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
    }
}

@end
