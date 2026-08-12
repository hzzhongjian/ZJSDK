//
//  JYEntryElement.h
//  JYAdSDK
//
//  Created by jyad110 on 2021/6/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JYContentPage.h"
#import <JYAdSDK/JYAdSDKConfig.h>

NS_ASSUME_NONNULL_BEGIN

@class JYEntryElement;

@protocol JYEntryElementDelegate <NSObject>

@optional

- (void)jy_entryElementAdDidLoad:(JYEntryElement *)entryElement;
- (void)jy_entryElementAdDidFailToLoad:(JYEntryElement *)entryElement error:(NSError *)error;
- (void)jy_entryElementAdDidExpose:(JYEntryElement *)entryElement;
- (void)jy_entryElementAdDidClick:(JYEntryElement *)entryElement contentPage:(JYContentPage *) contentPage;

@end

@interface JYEntryElement : NSObject
@property (nonatomic, weak, nullable) id<JYEntryElementDelegate> delegate;
@property (nonatomic, assign, readonly) JYAdSdkUnionType unionType;
@property (nonatomic, copy, readonly) UIView *entryView;
@property (nonatomic, readonly) CGSize entryExpectedSize;

@property (nonatomic, assign) CGFloat expectedWidth;
- (instancetype)initWithSlotId:(NSString *) slotId;
- (void)loadAd;
- (NSInteger)eCPM;
- (NSDictionary * _Nullable)extraInfo;
@end

NS_ASSUME_NONNULL_END
