//
//  JLDrawVideoAd.h
//  JLAdSDK
//
//  Created by jlad110 on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import "JLDrawVideoAdRelatedView.h"
#import <JLAdSDK/JLAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JLDrawVideoAd;
@protocol JLDrawVideoAdDelegate <NSObject>

- (void)jl_drawVideoAdDidLoad:(NSArray<JLDrawVideoAdRelatedView *> * _Nullable)drawVideoAdRelatedViews error:(NSError * _Nullable) error;

@end

@interface JLDrawVideoAd : NSObject <JLAdProtocol>

@property (nonatomic, weak, nullable) id<JLDrawVideoAdDelegate> delegate;
@property (nonatomic, assign, readonly) JLAdSdkUnionType unionType __attribute__(( deprecated ( "使用JLDrawVideoAdRelatedView中unionType代替" )));
@property (nonatomic, assign) BOOL videoMuted;

- (instancetype) initWithSlotId:(NSString *)slotId adSize:(CGSize)adSize;
- (void)loadAdWithCount:(NSInteger)count;

- (NSInteger)eCPM __attribute__(( deprecated ( "使用JLDrawVideoAdRelatedView中-eCPM代替" )));
- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo __attribute__(( deprecated ( "使用JLDrawVideoAdRelatedView中-sendWinNotificationWithInfo:代替" )));
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo __attribute__(( deprecated ( "使用JLDrawVideoAdRelatedView中-sendLossNotificationWithInfo:代替" )));

@end

NS_ASSUME_NONNULL_END
