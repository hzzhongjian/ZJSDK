//
//  ZJAd.h
//  ZJSDK
//
//  Created by Rare on 2022/2/25.
//  Copyright © 2022 zj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZJSDKCore/ZJAdDebugLog.h>
#import <ZJSDKCore/NSError+ZJAd.h>


NS_ASSUME_NONNULL_BEGIN

@interface ZJAd : NSObject

// 广告位ID
@property(nonatomic,copy,readonly) NSString *placementId;
/**
*  构造方法
*  详解：placementId - 广告位 ID
*/
- (instancetype)initWithPlacementId:(NSString *)placementId;


// 获取错误信息
- (NSArray *)getFillFailureMessages;

/**
 * 返回广告的eCPM，广告加载成功后调用有效，单位：分
 * @return 成功返回一个大于等于0的值，
 */
- (NSInteger)eCPM;

// 展示广告来源，枚举类型
- (ZJAdPlatformType)platformType;



@end

NS_ASSUME_NONNULL_END
