//
//  ZJSDKInitConfig.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/9/10.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>
#import <ZJSDKCore/ZJSDKInitModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZJSDKInitConfig : NSObject


+ (instancetype)sharedInstance;

@property (nonatomic, strong) ZJSDKInitModel *sdkInitModel;

// 个性化推荐
@property (nonatomic, assign) ZJSDKPersionalizedState persionalizedState;

// 程序化推荐开关
@property (nonatomic, assign) ZJSDKProgrammaticRecommend programmaticRecommend;



@end

NS_ASSUME_NONNULL_END
