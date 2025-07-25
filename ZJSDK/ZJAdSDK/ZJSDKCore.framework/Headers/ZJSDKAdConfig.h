//
//  ZJSDKAdConfig.h
//  ZJSDKCore
//
//  Created by Rare on 2022/2/23.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
#import <ZJSDKCore/ZJAdsModel.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZJSDKAdConfig : NSObject

+ (instancetype)shared;

@property (nonatomic, copy) NSString *appId;

@property (nonatomic, copy) NSArray <NSDictionary *>*platforms;

@property (nonatomic, copy) NSArray <ZJAdPositionModel *>*adArray;

@property (nonatomic, copy) NSString *secretStr;

@property (nonatomic, assign) ZJAdSDKLogLevel level;

//是否可以获取ecpm
@property (nonatomic, assign) BOOL can_read_ecpm;

// 开屏广告兜底控制，如果用户调用开屏广告展示方法，默认在0.5秒前没有曝光的方法回调，就会触发关闭事件
@property (nonatomic, assign) BOOL is_splash_fallback_control;

@end

NS_ASSUME_NONNULL_END
