#ifndef ZJJSBridgeActions_h
#define ZJJSBridgeActions_h

/**
 * 事件枚举
 */

typedef NS_ENUM(NSInteger, ZJJSBridgeAction) {
    /**
     * 请求失败
     */
    ZJJSBridgeActionOnZjAdError = 1,
    
    /**
     * 请求成功
     */
    ZJJSBridgeActionOnZjAdLoaded = 2,
    
    /**
     * 展示成功
     */
    ZJJSBridgeActionOnZjAdShow = 3,
    
    /**
     * 点击
     */
    ZJJSBridgeActionOnZjAdClick = 4,
    
    /**
     * 播放完成
     */
    ZJJSBridgeActionOnZjAdVideoComplete = 5,
    
    /**
     * 发奖
     */
    ZJJSBridgeActionOnZjAdReward = 6,
    
    /**
     * 关闭
     */
    ZJJSBridgeActionOnZjAdClose = 7,
    
    /**
     * 页面进入
     */
    ZJJSBridgeActionOnPageEnter = 8,
    
    /**
     * 页面离开
     */
    ZJJSBridgeActionOnPageLeave = 9,
    
    /**
     * H5页面回调
     */
    ZJJSBridgeActionOnZjAdEvent = 10,
    
    /**
     * 小说的阅读时长
     */
    ZJJSBridgeActionOnReadTime = 11
};

#endif
