//
//  ZJInvoker.h
//  ZJSDKCore
//
//  Created by 麻明康 on 2022/9/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZJInvoker : NSObject

+ (id)safePerformAction:(SEL)action 
                 target:(NSObject *)target
             withObject:(nullable id)object,...NS_REQUIRES_NIL_TERMINATION;

+ (NSArray *)getInstanceMethodList:(NSString *)className;

+ (NSArray *)getClassMethodList:(NSString *)className;

+ (NSArray *)getMethodList:(NSString *)className;

// 判断类是否有实例方法
+ (BOOL)className:(NSString *)className instanceMethodName:(NSString *)instanceMethodName;

// 判断类是否有类方法
+ (BOOL)className:(NSString *)className classMethodName:(NSString *)classMethodName;

// 判断类是否拥有某个属性
+ (BOOL)className:(NSString *)className propertyName:(NSString *)propertyName;

@end

NS_ASSUME_NONNULL_END
