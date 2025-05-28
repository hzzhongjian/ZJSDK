//
//  WanjaDefinitionTools.h
//  WanjaCoreSDK
//
//  Created by guantou on 2019/12/10.
//

#import "UIView+WanjaAddition.h"

#ifndef WanjaDefinitionTools_h
#define WanjaDefinitionTools_h

/**
 切换SDK预编译条件
*/
#define Wanja_SDK_CAN_CUSTOM_SKIPVIEW 0
#define Wanja_SDK_CAN_SWITCH_CHANNEL 0

#define WanjaWithTimeLog(format, ...) NSLog(@"%@", [NSString stringWithFormat:(format), ##__VA_ARGS__])

#define WanjaAdLog(format, ...) printf("class: < %s:(%d行) > method: %s \n%s\n", [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] )

//  比例
#define LJX_Multiple (MIN(kWanjaScreenWidth, kWanjaScreenHeight)<375 ? 1: MIN(kWanjaScreenWidth, kWanjaScreenHeight)/375)
#define Num(_x_) _x_*LJX_Multiple

// 比例：x需要现实的大小，y比例最大值为0时无上限。
#define Wanja_Num(_x_, _y_) \
({CGFloat wanja_screen = MIN(kWanjaScreenWidth, kWanjaScreenHeight);\
CGFloat wanja_multiple = wanja_screen/375;\
if (_y_ <= 1) {\
wanja_multiple = MAX(wanja_multiple, _y_);\
} else {\
wanja_multiple = MIN(wanja_multiple, _y_);\
}\
CGFloat z = _x_*wanja_multiple;\
(z);})

// 判断是否为iPhone X 系列  这样写消除了在Xcode10上的警告。
#define IPHONE_X \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [UIView wanja_lastWindow].safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})

/**
 屏幕宽高
 */
#define kWanjaScreenWidth ({CGFloat width = UIScreen.mainScreen.bounds.size.width;\
UIDeviceOrientation orientation=UIDevice.currentDevice.orientation;\
NSString *deviceType = [UIDevice currentDevice].model;\
BOOL isPad = NO;\
if([deviceType isEqualToString:@"iPad"]) {\
    isPad = YES;\
}\
if(isPad) {\
    if(orientation == UIInterfaceOrientationLandscapeLeft || orientation == UIInterfaceOrientationLandscapeRight) {\
        width = width / 2;\
    }\
    else {\
        UIInterfaceOrientation statusBarOri = UIApplication.sharedApplication.statusBarOrientation;\
        if(statusBarOri==UIDeviceOrientationLandscapeLeft || statusBarOri==UIDeviceOrientationLandscapeRight) {\
            width = width / 2;\
        }\
    }\
}\
(width);\
})

#define kWanjaScreenHeight [[UIScreen mainScreen] bounds].size.height

#define ISIPHONEX ([[UIApplication sharedApplication] statusBarFrame].size.height == 44) || ([UIScreen mainScreen].bounds.size.height == 812 || [UIScreen mainScreen].bounds.size.height == 896) || ([UIScreen mainScreen].bounds.size.width == 812 || [UIScreen mainScreen].bounds.size.width == 896)

/*状态栏高度*/
#define kWanjaStatusBarHeight (CGFloat)(IPHONE_X?(44.0):(20.0))
#define IPHONEX_TABBAR_FIX_HEIGHT 34
#define IPHONEX_TOPBAR_FIX_HEIGHT 44

#define Wanja_SCREEN_WIDTH(_type_) \
({CGFloat width = 0;\
if (_type_ == 2) {\
width = MAX(kWanjaScreenWidth, kWanjaScreenHeight);\
} else {\
width = MIN(kWanjaScreenWidth, kWanjaScreenHeight);\
}\
(width);})

#define Wanja_SCREEN_HEIGHT(_type_) \
({CGFloat height = 0;\
if (_type_ == 2) {\
height = MIN(kWanjaScreenWidth, kWanjaScreenHeight);\
} else {\
height = MAX(kWanjaScreenWidth, kWanjaScreenHeight);\
}\
(height);})

#define Wanja_BASE_SCREEN_WIDTH(_type_) \
({CGFloat width = 0;\
if (_type_ == 2) {\
width = MAX(414, 736);\
} else {\
width = MIN(414, 736);\
}\
(width);})

#define Wanja_BASE_SCREEN_HEIGHT(_type_) \
({CGFloat height = 0;\
if (_type_ == 2) {\
height = MIN(414, 736);\
} else {\
height = MAX(414, 736);\
}\
(height);})


/**
 存储
 */
#define NSUDADDWithValueAndKey(_value_, _key_) [[NSUserDefaults standardUserDefaults]setObject:_value_ forKey:_key_]
#define NSUDWithKey(_key_) [[NSUserDefaults standardUserDefaults] objectForKey:_key_]
#define NSUDRemoveWithKey(_key_) [[NSUserDefaults standardUserDefaults]removeObjectForKey:_key_]
#define NSUDSynchronize  [[NSUserDefaults standardUserDefaults] synchronize]

/**
 工具
 */

#define weakObj(obj) autoreleasepool{} __weak typeof(obj) obj##Weak = obj;
#define strongObj(obj) autoreleasepool{} __strong typeof(obj) obj = obj##Weak;

#define AD_EmptyString(_String_) [WanjaOtherTools isEmptyString:_String_]
#define AD_EmptyData(_Data_) [WanjaOtherTools isEmptyData:_Data_]
#define WanjaCurrentViewController [WanjaScreenTool getCurrentVC]


// 获取广告请求数量。
#define Wanja_adCount(_String_) \
({NSInteger index = 0;\
if (NSUDWithKey(_String_)) {\
    index = [NSUDWithKey(_String_) integerValue];\
}\
index++;\
[[NSUserDefaults standardUserDefaults]setInteger:index forKey:_String_];\
})

//颜色定义
#define WanjaHexColor(color) [UIColor colorWithRed:((color >> 16) & 0xFF) / 255.0 green:((color >> 8) & 0xFF) / 255.0 blue:(color & 0xFF) / 255.0 alpha: 1]
#define WanjaHexColorWithAlpha(color, alphaV) [UIColor colorWithRed:((color >> 16) & 0xFF) / 255.0 green:((color >> 8) & 0xFF) / 255.0 blue:(color & 0xFF) / 255.0 alpha: alphaV]
#endif /* WanjaDefinitionTools_h */
