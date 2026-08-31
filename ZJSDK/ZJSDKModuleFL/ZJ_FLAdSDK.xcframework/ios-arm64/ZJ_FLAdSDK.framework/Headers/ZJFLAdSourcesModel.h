//
//  ZJFLAdSourcesModel.h
//  ZJ_FLAdSDK
//
//  Created by lurich on 2022/2/23.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJFLAdSourcesModel : NSObject

/// MARK: 以下参数为广告相关信息
/// 广告源在平台的id
@property (nonatomic, assign)   NSInteger adv_id;
/// 广告主应用ID
@property (nonatomic, copy)     NSString *app_id;
/// 广告源广告位id
@property (nonatomic, copy)     NSString *tagid;
/// 广告版位Id
@property (nonatomic, copy)     NSString *slot_id;
/// 广告主key值
@property (nonatomic, copy)     NSString *app_key;
/// 广告的eCPM
@property (nonatomic, assign)   double bidfloor;
/// 自定义参数，json格式
@property (nonatomic, copy)     NSString *ext;
/// 插屏样式  0= 半插屏，1=插全屏
@property (nonatomic, assign)   NSInteger is_full_screen;
/// 请求的广告唯一Id
@property (nonatomic, copy)     NSString *uniqueID;
/// 1、开屏、2、 插屏、3、 信息流（31：原生；32：模板）、4、 激励视频、5、 横幅、6、 全屏视频、7、 Draw 信息流
@property (nonatomic, assign)   NSInteger adv_place_type;

/// MARK: 以下参数为block回调
/// 1：素材加载成功  2：素材加载失败  3：点击  4：从落地页返回  5：广告关闭 6：素材成功展示 7：激励视频获得奖励回调  8：素材渲染成功   9：视频播放状态改变  11：素材渲染失败  12：展示失败（暂仅对开屏生效）
@property (nonatomic, assign)   NSInteger type;
/// 视频状态（具体查看ZJFLMediaPlayerStatus枚举）
@property (nonatomic, assign)   NSInteger status;
/// 对应的广告主
@property (nonatomic, strong, nullable) id adObjc;
/// 请求广告的错误信息
@property (nonatomic, copy)     NSError *error;
/// 对应的广告主数据，Feed：原始数据数组   Template:模板view数组
@property (nonatomic, copy, nullable) NSArray *views;
/// 模板view
@property (nonatomic, weak)     UIView *showView;

@end

NS_ASSUME_NONNULL_END
