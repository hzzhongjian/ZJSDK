//
//  ZJSDKInitConfig.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2024/9/10.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJSDKInitConfig : NSObject

+ (instancetype)sharedInstance;

// 个性化推荐
@property (nonatomic, assign) ZJSDKPersionalizedState persionalizedState;

// 程序化推荐开关
@property (nonatomic, assign) ZJSDKProgrammaticRecommend programmaticRecommend;



@end

NS_ASSUME_NONNULL_END
