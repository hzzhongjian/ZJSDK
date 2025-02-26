//
//  ZJAdInfo.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2025/2/11.
//

#import <Foundation/Foundation.h>
#import <ZJSDKCore/ZJSDKAdEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJAdInfo : NSObject

// 平台ID
@property (nonatomic, copy) NSString *platformID;

// 平台名字
@property (nonatomic, copy) NSString *platformName;

// 平台类型
@property (nonatomic, assign) ZJAdPlatformType platformType;

@end

NS_ASSUME_NONNULL_END
