//
//  JLNativeAd.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/4/20.
//

#import <Foundation/Foundation.h>
#import "JLNativeAdDataObject.h"
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLNativeAd;
@protocol JLNativeAdDelegate <NSObject>

- (void)jl_nativeAdDidLoad:(NSArray<JLNativeAdDataObject *> * _Nullable)nativeAdDataObjects error:(NSError * _Nullable)error;

@end

@interface JLNativeAd : NSObject <JLAdProtocol>
@property (nonatomic, weak, nullable) id<JLNativeAdDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType  __attribute__(( deprecated ( "使用JLNativeAdDataObject中unionType代替" )));

-(instancetype) initWithSlotId:(NSString *) slotId;
- (void)loadAdWithCount:(NSInteger) count;

- (NSInteger)eCPM __attribute__(( deprecated ( "使用JLNativeAdDataObject中-eCPM代替" )));
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo __attribute__(( deprecated ( "使用JLNativeAdDataObject中-sendWinNotificationWithInfo:代替" )));
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo __attribute__(( deprecated ( "使用JLNativeAdDataObject中-sendLossNotificationWithInfo:代替" )));
@end

NS_ASSUME_NONNULL_END
