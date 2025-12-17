//
//  ZJSDKDefines.h
//  ZJOptimizeProject
//
//  Created by Rare on 2021/7/29.
//
#import <UIKit/UIKit.h>

#ifndef ZJSDKDefines_h
#define ZJSDKDefines_h

#define ZJ_ScreenHeight [UIScreen mainScreen].bounds.size.height

#define ZJ_ScreenWidth [UIScreen mainScreen].bounds.size.width

#define ZJ_BANNED_TIME @"BANNED_TIME"

#define ZJ_IPHONEXSeries zj_is_iphoneXSeries_screen()

#define ZJ_SafeAreaInsetsBottom \
({CGFloat bottom = 0; \
if (@available(iOS 11.0, *))  { \
bottom = zj_visibleWindow().safeAreaInsets.bottom; \
} \
(bottom);})

#define ZJ_SafeAreaInsetsTop \
({CGFloat top = 0; \
if (@available(iOS 11.0, *)) { \
top = zj_visibleWindow().safeAreaInsets.top; \
} \
(top);})


/**---------------------------------------------------*/
//强弱引用转换，用于解决代码块（block）与强引用对象之间的循环引用问题
//弱引用
#define zj_weakify(object)  __weak typeof(object) weak##object = object;
//强引用
#define zj_strongify(object)  __strong typeof(object) object = weak##object;
/**---------------------------------------------------*/


FOUNDATION_EXPORT UIWindow * zj_visibleWindow(void);

FOUNDATION_EXPORT BOOL zj_is_iphoneXSeries_screen(void);

FOUNDATION_EXPORT UIViewController * zj_getCurrentVC(void);
FOUNDATION_EXPORT UIViewController * zj_getCurrentVCFrom(UIViewController *vc);

FOUNDATION_EXPORT NSString * const ZJSDKVersion;

FOUNDATION_EXPORT NSNumber * getZJSDKPlugVer (void);


// 判断某个类是否存在
#define ZJ_RUNTIME_HAS_CLASS(classname) (NSClassFromString(@#classname) != nil)

// 运行时检查协议是否存在
#define ZJ_RUNTIME_HAS_PROTOCOL(protocolname) (objc_getProtocol(#protocolname) != nil)

// 运行时检查某个类实现了某个协议，会检查整个继承链，包括父类实现的协议
#define ZJ_CLASS_CONFORMS_TO_PROTOCOL(classname, protocolname) \
    ([NSClassFromString(@#classname) conformsToProtocol:@protocol(protocolname)])

// 运行时检查方法是否存在
#define ZJ_RUNTIME_HAS_METHOD(classname, sel) ([NSClassFromString(@#classname) instancesRespondToSelector:@selector(sel)])


#endif /* ZJSDKDefines_h */
