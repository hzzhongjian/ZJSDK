//
//  ZJNewTubePageVC.m
//  ZJSDKDemo
//
//  Created by 麻明康 on 2025/2/18.
//  Copyright © 2025 zj. All rights reserved.
//

#import "ZJNewTubePageVC.h"
#import <ZJSDK/ZJTubePageAd.h>
#import <ZJSDK/ZJContentPageStateDelegate.h>

@interface ZJNewTubePageVC () <ZJContentPageVideoStateDelegate,ZJContentPageStateDelegate, ZJContentPageLoadCallBackDelegate, ZJShortPlayCustomViewDelegate, ZJShortPlayInterfaceDelegate, ZJShortPlayCustomDrawAdViewDelegate, ZJShortPlayDrawVideoViewControllerBannerDelegate, ZJShortPlayAdDelegate, ZJShortPlayPlayerDelegate>

@property (nonatomic, weak) UIViewController *weakTubeVC;

@property (nonatomic, strong) ZJTubePageAd *tubePageAd;

@end
    
@implementation ZJNewTubePageVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self.loadAdView appendAdID:@[AdId_Tube]];
}

- (void)loadAd:(NSString *)adId
{
    ZJTubePageConfig *config = [[ZJTubePageConfig alloc] init];
    // bundleid需要改为com.bytedance.pangrowth，才能跑SDK_Setting_5434885.json
    config.JSONConfigPath = [[NSBundle mainBundle] pathForResource:@"SDK_Setting_5434885" ofType:@"json"];
    config.freeEpisodesCount = 5;
    config.unlockEpisodesCountUsingAD = 5;
    //    用来指定加载ZJ广告，如果不设置，默认加载的穿山甲自带广告，如果要设置需要同时设置下面两个字段的值
    //    config.adType = ZJTubePageADTypeRewardVideo;
    //    config.posId = @"KS90010001";
    config.adType = ZJTubePageADTypeInterstitial;
    config.posId = @"J7311893871";
    config.showCloseButton = YES;
    config.configOrNotCustomViewDelegate = YES;
    config.configOrNotCustomDrawAdViewDelegate = YES;
    config.configOrNotCustomBannerDelegate = YES;
    config.customAdIndex = @[@0, @1];
    self.tubePageAd = [[ZJTubePageAd alloc]initWithPlacementId:adId];
    self.tubePageAd.tubePageConfig = config;
    self.tubePageAd.videoStateDelegate = self;
    self.tubePageAd.stateDelegate = self;
    self.tubePageAd.loadCallBackDelegate = self;
    /// 短剧播放器回调
    self.tubePageAd.playerCallbackDelegate = self;
    /// 广告回调
    self.tubePageAd.adCallbackDelegate = self;
    /// 业务接口回调
//    self.tubePageAd.interfaceCallbackDelegate = self;

    /// 自定义详情页cell试图回调
    self.tubePageAd.customViewCallBackDelegate = self;
    /// 自定义Draw流的subview回调
    self.tubePageAd.customDrawAdViewCallBackDelegate = self;
    /// 滑滑溜底部自定义Banner广告
    self.tubePageAd.drawVideoViewBannerCallbackDelegate = self;
    [self.tubePageAd loadAd];
}

- (void)showAd
{
    self.weakTubeVC = self.tubePageAd.tubePageViewController;
    self.weakTubeVC.modalPresentationStyle = UIModalPresentationFullScreen;
    if(self.weakTubeVC){
        // 快手只能push
        if (self.tubePageAd.currentAdapter.config.platformType == ZJAdPlatform_KS) {
            [self addChildViewController:self.weakTubeVC];
            [self.view addSubview:self.weakTubeVC.view];
        } else {
            // 穿山甲目前用presentViewController的方式
            [self presentViewController:self.weakTubeVC animated:YES completion:^{
                
            }];
        }
    }else{
        NSLog(@"未能创建对应广告位VC，建议从以下原因排查：\n 1，内容包需要手动导入快手模块（pod公共仓库中的SDK不支持内容包）\n 2，确保sdk已注册成功 \n 3，确保广告位正确可用");
    }
}

#pragma mark - ZJShortPlayPlayerDelegate
/*! @abstract 视频切换时的回调 */
- (void)zj_shortplayDrawVideoCurrentVideoChanged:(NSInteger)index adapter:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 加载失败按钮点击重试回调 */
- (void)zj_shortplayDrawVideoDidClickedErrorButtonRetry:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 默认关闭按钮被点击的回调 */
- (void)zj_shortplayDrawVideoCloseButtonClicked:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 数据刷新完成回调 */
- (void)zj_shortplayDrawVideoDataRefreshCompletion:(NSError *)error content:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract tab栏切换控制器的回调*/
- (void)zj_shortplayPageViewControllerSwitchToIndex:(NSInteger)index content:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/**! @abstract 推荐页面底部banner视图**/
- (UIView *)zj_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc content:(id<ZJContentInfo>)content
{
    return nil;
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 200)];
    view.backgroundColor = [UIColor cyanColor];
    return view;
}

#pragma mark - ZJShortPlayAdDelegate

/*! @abstract 发起广告请求 */
- (void)zj_shortplaySendAdRequest:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 广告加载成功 */
- (void)zj_shortplayAdLoadSuccess:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 广告加载失败 */
- (void)zj_shortplayAdLoadFail:(id<ZJContentInfo>)content error:(NSError *)error
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 广告填充失败 */
- (void)zj_shortplayAdFillFail:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 广告曝光 */
- (void)zj_shortplayAdWillShow:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 视频广告开始播放 */
- (void)zj_shortplayVideoAdStartPlay:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 视频广告暂停播放 */
- (void)zj_shortplayVideoAdPause:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 视频广告继续播放 */
- (void)zj_shortplayVideoAdContinue:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 视频广告停止播放 */
- (void)zj_shortplayVideoAdOverPlay:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 点击广告 */
- (void)zj_shortplayClickAdViewEvent:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}
/*! @abstract 广告缓冲 */
- (void)zj_shortplayVideoBufferEvent:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 激励视频广告结束 */
- (void)zj_shortplayVideoRewardFinishEvent:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 激励视频广告跳过 */
- (void)zj_shortplayVideoRewardSkipEvent:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

#pragma mark - ZJShortPlayInterfaceDelegate

/*! @abstract 解锁流程开始 */
- (void)zj_shortplayPlayletDetailUnlockFlowStart:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 解锁流程取消 */
- (void)zj_shortplayPlayletDetailUnlockFlowCancel:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

- (BOOL)zj_shortplayPlayletDetailCustomUnlockView
{
    return NO;
}


/*! @abstract 解锁流程结束，回调解锁结果
 *  - success: 是否解锁成功
 *   - error: 解锁失败错误信息
 */
- (void)zj_shortplayPlayletDetailUnlockFlowEnd:(id<ZJContentInfo>)content
                           success:(BOOL)success
                             error:(NSError * _Nullable)error
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 点击混排中进入跳转播放页的按钮 */
- (void)zj_shortplayClickEnterView:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

/*! @abstract 本剧集观看完毕，切到下一部短剧回调 */
- (void)zj_shortplayNextPlayletWillPlay:(id<ZJContentInfo>)content
{
    NSLog(@"======%s",__FUNCTION__);
}

- (UIView *)zj_shortplayPlayletDetailBottomBanner:(id<ZJContentInfo>)content
{
    return nil;
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 200)];
    view.backgroundColor = [UIColor orangeColor];
    return view;
}

#pragma mark - ZJShortPlayCustomViewDelegate

/// 创建自定义View直接返回，外部不要持有，cell自己持有复用
/// @param cell 短剧的cell
- (UIView *)zj_shortplayPlayletDetailCellCustomView:(UITableViewCell *)cell
{
    return nil;
    // 短剧的cell自定义视图
    UIView *view = [[UIView alloc] initWithFrame:cell.bounds];
    view.backgroundColor = [UIColor greenColor];
    return view;
}

/// 根据数据更新UI
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View，短剧的cell内部会持有
/// @param playletInfo 短剧的数据
- (void)zj_shortplayPlayletDetailCell:(UITableViewCell *)cell updateCustomView:(UIView *)customView withPlayletData:(id)playletInfo
{
    NSLog(@"======%s",__FUNCTION__);
}

/// 当cell执行到layoutSubviews时会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)zj_shortplayPlayletDetailCell:(UITableViewCell *)cell layoutSubviews:(UIView *)customView
{
    NSLog(@"======%s",__FUNCTION__);
}

/// 当cell执行到layoutSubviews后会回调此协议方法
/// @param cell 短剧的cell
/// @param customView `djx_playletDetailCellCustomView:`返回的自定义View
- (void)zj_shortplayPlayletDetailCell:(UITableViewCell *)cell afterLayoutSubviews:(UIView *)customView
{
    NSLog(@"======%s",__FUNCTION__);
}

#pragma mark - ZJShortPlayCustomDrawAdViewDelegate
- (UIView *)zj_shortplayDetailCellCreateAdView:(UITableViewCell *)cell adInputIndex:(NSUInteger)adIndex
{
    return nil;
//    自定义draw的广告页面
    UIView *view = [[UIView alloc] initWithFrame:cell.bounds];
    view.backgroundColor = [UIColor yellowColor];
    return view;
}

- (void)zj_shortplayDetailCell:(UITableViewCell *)cell bindDataToDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex
{
    NSLog(@"======%s",__FUNCTION__);
}


- (void)zj_shortplayDetailCell:(UITableViewCell *)cell layoutSubview:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex
{
    NSLog(@"======%s",__FUNCTION__);
}

- (void)zj_shortplayDetailCell:(UITableViewCell *)cell willDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex
{
    NSLog(@"======%s",__FUNCTION__);
}

- (void)zj_shortplayDetailCell:(UITableViewCell *)cell didEndDisplayDrawAdView:(UIView *)drawAdView adInputIndex:(NSUInteger)adIndex
{
    NSLog(@"======%s",__FUNCTION__);
}


#pragma mark - 推荐的底部banner
- (UIView *)zj_shortplayDrawVideoVCBottomBannerView:(UIViewController *)vc
{
    return nil;
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 300)];
    view.backgroundColor = [UIColor redColor];
    return view;
    
//    return nil;
}

#pragma mark - ZJContentPageLoadCallBackDelegate

- (void)zj_contentPageLoadSuccess
{
    NSLog(@"短剧内容可以加载了");
    self.loadAdView.showButton.backgroundColor = kMainColor;
}

- (void)zj_contentPageLoadFailure:(NSError *)error
{
    NSLog(@"短剧内容加载失败了");
}

#pragma mark ZJContentPageVideoStateDelegate
/**
 * 视频开始播放
 * @param videoContent 内容模型
 */
- (void)zj_videoDidStartPlay:(id<ZJContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频暂停播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidPause:(id<ZJContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频恢复播放
* @param videoContent 内容模型
*/
- (void)zj_videoDidResume:(id<ZJContentInfo>)videoContent{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频停止播放
* @param videoContent 内容模型
* @param finished     是否播放完成
*/
- (void)zj_videoDidEndPlay:(id<ZJContentInfo>)videoContent isFinished:(BOOL)finished{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 视频播放失败
* @param videoContent 内容模型
* @param error        失败原因
*/
- (void)zj_videoDidFailedToPlay:(id<ZJContentInfo>)videoContent withError:(NSError *)error{
    NSLog(@"%s，%@",__FUNCTION__,error);
}

#pragma mark ZJContentPageStateDelegate

/**
* 内容展示
* @param content 内容模型
*/
- (void)zj_contentDidFullDisplay:(id<ZJContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容隐藏
* @param content 内容模型
*/
- (void)zj_contentDidEndDisplay:(id<ZJContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容暂停显示，ViewController disappear或者Application resign active
* @param content 内容模型
*/
- (void)zj_contentDidPause:(id<ZJContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
/**
* 内容恢复显示，ViewController appear或者Application become active
* @param content 内容模型
*/
- (void)zj_contentDidResume:(id<ZJContentInfo>)content{
    NSLog(@"======%s",__FUNCTION__);
}
@end
