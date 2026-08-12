//
//  JYNativeAd.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import "JYNativeAdDataObject.h"
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYNativeAd;
@protocol JYNativeAdDelegate <NSObject>

- (void)jy_nativeAdDidLoad:(NSArray<JYNativeAdDataObject *> * _Nullable)nativeAdDataObjects error:(NSError * _Nullable)error;

@end

@interface JYNativeAd : NSObject <JYAdProtocol>
@property (nonatomic, weak, nullable) id<JYNativeAdDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType  __attribute__(( deprecated ( "使用JYNativeAdDataObject中unionType代替" )));

-(instancetype) initWithSlotId:(NSString *) slotId;
- (void)loadAdWithCount:(NSInteger) count;

- (NSInteger)eCPM __attribute__(( deprecated ( "使用JYNativeAdDataObject中-eCPM代替" )));
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo __attribute__(( deprecated ( "使用JYNativeAdDataObject中-sendWinNotificationWithInfo:代替" )));
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo __attribute__(( deprecated ( "使用JYNativeAdDataObject中-sendLossNotificationWithInfo:代替" )));
@end

NS_ASSUME_NONNULL_END
