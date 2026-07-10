#
# Be sure to run `pod lib lint ZJSDK_Pods.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZJSDK'
  s.version          = '2.6.2.7'
  s.summary          = 'ZJSDK广告'
# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/hzzhongjian/ZJSDK.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'hzzhongjian' => 'opentwo@hzzhongjian.cn' }
  s.source           = { :git => 'https://github.com/hzzhongjian/ZJSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  s.ios.deployment_target = '11.0'
  s.platform     = :ios, "11.0"
  #依赖的系统frameworks
  s.frameworks = ['UIKit','Foundation','StoreKit','MobileCoreServices','WebKit','MediaPlayer','CoreML','CoreMedia','CoreLocation','AVFoundation','CoreTelephony','SystemConfiguration','AdSupport','CoreMotion','Accelerate','QuartzCore','Security','ImageIO','CFNetwork','CoreGraphics','SafariServices','AVKit','DeviceCheck','CoreImage','MapKit','JavaScriptCore','CoreText','AddressBook','CoreData','MessageUI','QuickLook','AudioToolBox','Photos','LocalAuthentication','AssetsLibrary','CoreFoundation','CoreVideo','NetworkExtension']
  s.weak_frameworks = ['AppTrackingTransparency','CoreHaptics']
  #依赖的系统静态库
  #z表示libz.tdb,后缀不需要,lib开头的省略lib
  s.libraries = ['resolv.9','c++','z','sqlite3','bz2','xml2','c++abi','sqlite3.0','iconv']
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64', 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386,arm64' }
  s.xcconfig = { 'ENABLE_BITCODE' => 'NO', 'OTHER_LDFLAGS' =>'-ObjC'}
#  valid_archs = ['armv7', 'i386', 'x86_64', 'arm64']
#  s.pod_target_xcconfig = {
#    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
#  }
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.default_subspecs = ['ZJSDKModuleGDT','ZJSDKModuleCSJ','ZJSDKModuleDSP','ZJSDKModuleSIG','ZJSDKModuleBD','ZJSDKModuleBeiZi','ZJSDKModuleKS','ZJSDKModuleTaKu','ZJSDKModuleQiYun','ZJSDKModuleWanJia']
  
    ### ZJ默认集成基础包
    s.subspec 'ZJAdSDK' do |ss|
        ss.vendored_frameworks = ['ZJSDK/ZJAdSDK/*.framework','ZJSDK/ZJAdSDK/*.xcframework']
        ss.preserve_paths = ['ZJSDK/ZJAdSDK/*.framework','ZJSDK/ZJAdSDK/*.xcframework']
        ss.resource = ['ZJSDK/ZJAdSDK/*.bundle']
        ss.dependency 'Masonry'
        ss.dependency 'ReactiveObjC'
        ss.dependency 'lottie-ios', '2.5.3'
    end
    
    ### GDT适配器兼容版
    s.subspec 'ZJSDKModuleGDTCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGDT/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end
  
    ### GDT适配器
    s.subspec 'ZJSDKModuleGDT' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGDT/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'GDTMobSDK'
    end
  
    ### 穿山甲适配器兼容版
    s.subspec 'ZJSDKModuleCSJCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleCSJ/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end
  
    ### 穿山甲适配器
    s.subspec 'ZJSDKModuleCSJ' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleCSJ/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'Ads-CN/BUAdSDK'
        ss.dependency 'Ads-CN/CSJMediation'
    end

    ### 穿山甲短剧SDK依赖
    ### source 'https://github.com/CocoaPods/Specs.git'
    ### source 'https://github.com/volcengine/volcengine-specs.git'
    s.subspec 'ZJSDKModuleCSJPlayletSDK' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleCSJ/playlet/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
#        ss.dependency 'Ads-CN/CSJMediation-Only'
#        ss.dependency 'Ads-CN/BUAdLive'
#        ss.dependency 'TTSDKFramework/Player-SR', '1.46.2.7-premium'
#        ss.dependency 'TTSDKFramework/LivePull', '1.46.2.7-premium'
#        ss.dependency 'PangrowthX/shortplay', '2.9.0.5'
    end    
  
    ### 快手适配器兼容版
    s.subspec 'ZJSDKModuleKSCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleKS/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end
  
    ### 快手适配器
    s.subspec 'ZJSDKModuleKS' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleKS/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ##    ss.dependency 'KSAdSDK', '3.3.69'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleKS/KSAdSDK/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleKS/KSAdSDK/*.xcframework'
    end

    ### DSP适配器
    s.subspec 'ZJSDKModuleDSP' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleDSP/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'DSPSDK'
    end
 
    ### SIG适配器兼容版
    s.subspec 'ZJSDKModuleSIGCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleSIG/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ### SIG适配器
    s.subspec 'ZJSDKModuleSIG' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleSIG/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        # ss.dependency 'SigmobAd-iOS', '~> 4.20.0'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleSIG/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleSIG/*.xcframework'
    end
 
    ### 百度适配器兼容版   
    s.subspec 'ZJSDKModuleBDCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBD/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ### 百度适配器   
    s.subspec 'ZJSDKModuleBD' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBD/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'BaiduMobAdSDK', '~> 5.37'
    end


    ### 倍孜适配器兼容版
    s.subspec 'ZJSDKModuleBeiZiCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBeiZi/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ### 倍孜适配器
    s.subspec 'ZJSDKModuleBeiZi' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBeiZi/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'BeiZiSDK-iOS/BeiZiSDK-iOS', '~> 4.90'
    end
 
#   s.subspec 'ZJSDKModuleWM' do |ss|
#     ss.vendored_libraries = 'ZJSDK/ZJSDKModuleWM/*.a'
#     ss.dependency 'ZJSDK/ZJAdSDK'
#     ss.dependency 'ToBid-iOS', '2.6.0'
#     ss.dependency 'BaiduMobAdSDK', '5.11'
   
#     ss.dependency 'MintegralAdSDK', '7.2.9'
#     ss.dependency 'MintegralAdSDK/RewardVideoAd'
#     ss.dependency 'MintegralAdSDK/BannerAd'
#     ss.dependency 'MintegralAdSDK/SplashAd'
#     ss.dependency 'MintegralAdSDK/InterstitialAd'
#     ss.dependency 'MintegralAdSDK/NativeAdvancedAd'
#     ss.dependency 'KSAdSDK', '3.3.64.8'
#     ss.dependency 'Google-Mobile-Ads-SDK' , '10.0.0'
#     ss.dependency 'GDTMobSDK', '4.14.10'
#     ss.dependency 'Ads-CN', '5.0.0.5'
#  end

    ###Tanx适配器兼容版  
    s.subspec 'ZJSDKModuleTanXCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTanX/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ### Tanx适配器
    s.subspec 'ZJSDKModuleTanX' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTanX/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        # 可以把TanX的依赖更换为pod管理
        #    ss.dependency 'TanxSDK', '~> 3.5.3'
        ss.vendored_frameworks  = ['ZJSDK/ZJSDKModuleTanX/*.framework','ZJSDK/ZJSDKModuleTanX/*.xcframework']
        ss.resource             = 'ZJSDK/ZJSDKModuleTanX/*.bundle'
        ss.preserve_paths       = ['ZJSDK/ZJSDKModuleTanX/*.framework','ZJSDK/ZJSDKModuleTanX/*.xcframework']
    end

    ###趣盟适配器兼容版
    s.subspec 'ZJSDKModuleQMCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleQM/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ###趣盟适配器
    s.subspec 'ZJSDKModuleQM' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleQM/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.vendored_frameworks = 'ZJSDK/ZJSDKModuleQM/QMAdSDK/*.xcframework'
        ss.preserve_paths      = 'ZJSDK/ZJSDKModuleQM/QMAdSDK/*.xcframework'
        ss.dependency 'AFNetworking'
        ss.dependency 'YYWebImage'
        ss.dependency 'YYImage/WebP'
    end

    ###章鱼适配器兼容版
    s.subspec 'ZJSDKModuleOCTOPUSCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleOCTOPUS/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end
  
    ###章鱼适配器
    s.subspec 'ZJSDKModuleOCTOPUS' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleOCTOPUS/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'OctopusSDK'
    end

    ###章鱼定制包适配器
    s.subspec 'ZJSDKModuleWanJia' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleWanJia/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleWanJia/WanJiaAdSDK/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleWanJia/WanJiaAdSDK/*.xcframework'
        ss.resource             = 'ZJSDK/ZJSDKModuleWanJia/WanJiaAdSDK/Assets/*.bundle'
    end

    ###奇运新适配器兼容版
    s.subspec 'ZJSDKModuleQiYunCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleQiYun/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ###奇运新适配器
    s.subspec 'ZJSDKModuleQiYun' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleQiYun/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleQiYun/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleQiYun/*.xcframework'
    end

    ###TaKu适配器兼容版
    s.subspec 'ZJSDKModuleTaKuCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTaKu/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ###TaKu适配器
    s.subspec 'ZJSDKModuleTaKu' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTaKu/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'AnyThinkiOS', '6.5.47'
        ss.dependency 'AnyThinkMediationAdxSmartdigimktCNAdapter','6.5.66.0'
    end

    ###美数适配器兼容版
    s.subspec 'ZJSDKModuleMeiShuCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleMeiShu/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ###美数适配器
    s.subspec 'ZJSDKModuleMeiShu' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleMeiShu/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'MSMobAdSDKv3/MS', '~> 3.0.3.0'
    end

    ###飞梭适配器-支持最低版本是iOS12.0
    s.subspec 'ZJSDKModuleFS' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleFS/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        # ss.dependency 'FSUnionAdSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleFS/FSUnionAdSDK/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleFS/FSUnionAdSDK/*.xcframework'
        ss.resource             = 'ZJSDK/ZJSDKModuleFS/FSUnionAdSDK/*.bundle'
    end

    ###飞梭适配器兼容版
    s.subspec 'ZJSDKModuleFSCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleFS/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ###聚推适配器
    s.subspec 'ZJSDKModuleJuTui' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleJuTui/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleJuTui/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleJuTui/*.xcframework'
    end

########################################################################################
    ### ZJ分模块集成基础包
    s.subspec 'ZJAdBaseSDK' do |ss|
        ss.vendored_frameworks = ['ZJSDK/ZJAdBaseSDK/*.framework']
        ss.preserve_paths = ['ZJSDK/ZJAdBaseSDK/*.framework']
        ss.resource = ['ZJSDK/ZJAdBaseSDK/*.bundle']
    end

    ###布鲁肯适配器兼容版
    s.subspec 'ZJSDKBaseModuleBLKCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBLK/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###布鲁肯适配器
    s.subspec 'ZJSDKBaseModuleBLK' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBLK/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleBLK/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleBLK/*.xcframework'
    end

    ###泛为适配器兼容版
    s.subspec 'ZJSDKBaseModuleFWCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleFW/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###泛为适配器
    s.subspec 'ZJSDKBaseModuleFW' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleFW/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleFW/*.framework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleFW/*.framework'
        ss.resource             = 'ZJSDK/ZJSDKModuleFW/*.bundle'
    end

    ###旺脉适配器兼容版
    s.subspec 'ZJSDKBaseModuleXWMCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleXWM/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###旺脉适配器
    s.subspec 'ZJSDKBaseModuleXWM' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleXWM/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleXWM/*.framework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleXWM/*.framework'
        ss.resource             = 'ZJSDK/ZJSDKModuleXWM/*.bundle'
    end

    ###萤石适配器兼容版
    s.subspec 'ZJSDKBaseModuleYSCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleYS/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###旺脉适配器
    s.subspec 'ZJSDKBaseModuleYS' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleYS/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleYS/*.framework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleYS/*.framework'
        ss.resource             = 'ZJSDK/ZJSDKModuleYS/*.bundle'
        ss.dependency 'Masonry'
        ss.dependency 'ReactiveObjC'
        ss.dependency 'lottie-ios', '2.5.3'
    end

    ### GDT适配器兼容版
    s.subspec 'ZJSDKBaseModuleGDTCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGDT/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end
  
    ### GDT适配器
    s.subspec 'ZJSDKBaseModuleGDT' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGDT/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.dependency 'GDTMobSDK'
    end
  
    ### 穿山甲适配器兼容版
    s.subspec 'ZJSDKBaseModuleCSJCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleCSJ/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end
  
    ### 穿山甲适配器
    s.subspec 'ZJSDKBaseModuleCSJ' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleCSJ/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.dependency 'Ads-CN/BUAdSDK'
        ss.dependency 'Ads-CN/CSJMediation'
    end

    ### 穿山甲短剧SDK依赖
    ### source 'https://github.com/CocoaPods/Specs.git'
    ### source 'https://github.com/volcengine/volcengine-specs.git'
    s.subspec 'ZJSDKBaseModuleCSJPlayletSDK' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleCSJ/playlet/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
#        ss.dependency 'Ads-CN/CSJMediation-Only'
#        ss.dependency 'Ads-CN/BUAdLive'
#        ss.dependency 'TTSDKFramework/Player-SR', '1.46.2.7-premium'
#        ss.dependency 'TTSDKFramework/LivePull', '1.46.2.7-premium'
#        ss.dependency 'PangrowthX/shortplay', '2.9.0.5'
    end    
  
    ### 快手适配器兼容版
    s.subspec 'ZJSDKBaseModuleKSCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleKS/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end
  
    ### 快手适配器
    s.subspec 'ZJSDKBaseModuleKS' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleKS/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleKS/KSAdSDK/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleKS/KSAdSDK/*.xcframework'
    end

    ### DSP适配器
    s.subspec 'ZJSDKBaseModuleDSP' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleDSP/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.dependency 'DSPSDK'
    end
 
    ### SIG适配器兼容版
    s.subspec 'ZJSDKBaseModuleSIGCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleSIG/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ### SIG适配器
    s.subspec 'ZJSDKBaseModuleSIG' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleSIG/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        # ss.dependency 'SigmobAd-iOS', '~> 4.20.0'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleSIG/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleSIG/*.xcframework'
    end
 
    ### 百度适配器兼容版   
    s.subspec 'ZJSDKBaseModuleBDCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBD/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ### 百度适配器   
    s.subspec 'ZJSDKBaseModuleBD' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBD/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.dependency 'BaiduMobAdSDK', '~> 5.37'
    end


    ### 倍孜适配器兼容版
    s.subspec 'ZJSDKBaseModuleBeiZiCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBeiZi/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ### 倍孜适配器
    s.subspec 'ZJSDKBaseModuleBeiZi' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBeiZi/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.dependency 'BeiZiSDK-iOS/BeiZiSDK-iOS', '~> 4.90'
    end

    ###Tanx适配器兼容版  
    s.subspec 'ZJSDKBaseModuleTanXCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTanX/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ### Tanx适配器
    s.subspec 'ZJSDKBaseModuleTanX' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTanX/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        # 可以把TanX的依赖更换为pod管理
        #    ss.dependency 'TanxSDK', '~> 3.5.3'
        ss.vendored_frameworks  = ['ZJSDK/ZJSDKModuleTanX/*.framework','ZJSDK/ZJSDKModuleTanX/*.xcframework']
        ss.resource             = 'ZJSDK/ZJSDKModuleTanX/*.bundle'
        ss.preserve_paths       = ['ZJSDK/ZJSDKModuleTanX/*.framework','ZJSDK/ZJSDKModuleTanX/*.xcframework']
    end

    ###趣盟适配器兼容版
    s.subspec 'ZJSDKBaseModuleQMCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleQM/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###趣盟适配器
    s.subspec 'ZJSDKBaseModuleQM' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleQM/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks = 'ZJSDK/ZJSDKModuleQM/QMAdSDK/*.xcframework'
        ss.preserve_paths      = 'ZJSDK/ZJSDKModuleQM/QMAdSDK/*.xcframework'
        ss.dependency 'AFNetworking'
        ss.dependency 'YYWebImage'
        ss.dependency 'YYImage/WebP'
    end

    ###章鱼适配器兼容版
    s.subspec 'ZJSDKBaseModuleOCTOPUSCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleOCTOPUS/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end
  
    ###章鱼适配器
    s.subspec 'ZJSDKBaseModuleOCTOPUS' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleOCTOPUS/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.dependency 'OctopusSDK'
    end

    ###章鱼定制包适配器
    s.subspec 'ZJSDKBaseModuleWanJia' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleWanJia/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleWanJia/WanJiaAdSDK/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleWanJia/WanJiaAdSDK/*.xcframework'
        ss.resource             = 'ZJSDK/ZJSDKModuleWanJia/WanJiaAdSDK/Assets/*.bundle'
    end

    ###奇运新适配器兼容版
    s.subspec 'ZJSDKBaseModuleQiYunCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleQiYun/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###奇运新适配器
    s.subspec 'ZJSDKBaseModuleQiYun' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleQiYun/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleQiYun/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleQiYun/*.xcframework'
    end

    ###TaKu适配器兼容版
    s.subspec 'ZJSDKBaseModuleTaKuCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTaKu/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###TaKu适配器
    s.subspec 'ZJSDKBaseModuleTaKu' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTaKu/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.dependency 'AnyThinkiOS', '6.5.47'
        ss.dependency 'AnyThinkMediationAdxSmartdigimktCNAdapter','6.5.66.0'
    end

    ###美数适配器兼容版
    s.subspec 'ZJSDKBaseModuleMeiShuCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleMeiShu/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###美数适配器
    s.subspec 'ZJSDKBaseModuleMeiShu' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleMeiShu/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.dependency 'MSMobAdSDKv3/MS', '~> 3.0.3.0'
    end

    ###飞梭适配器-支持最低版本是iOS12.0
    s.subspec 'ZJSDKBaseModuleFS' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleFS/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        # ss.dependency 'FSUnionAdSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleFS/FSUnionAdSDK/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleFS/FSUnionAdSDK/*.xcframework'
        ss.resource             = 'ZJSDK/ZJSDKModuleFS/FSUnionAdSDK/*.bundle'
    end

    ###飞梭适配器兼容版
    s.subspec 'ZJSDKBaseModuleFSCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleFS/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
    end

    ###聚推适配器
    s.subspec 'ZJSDKBaseModuleJuTui' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleJuTui/*.a'
        ss.dependency 'ZJSDK/ZJAdBaseSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleJuTui/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleJuTui/*.xcframework'
    end

    ### 谷歌适配器
    s.subspec 'ZJSDKModuleGoogle' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGoogle/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'Google-Mobile-Ads-SDK'
    end
    
    ### 穿山甲海外适配器
    s.subspec 'ZJSDKModulePangle' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModulePangle/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'Ads-Global'
    end
    
    ### MTG适配器
    s.subspec 'ZJSDKModuleMTG' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleMTG/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'MintegralAdSDK'
        ss.dependency 'MintegralAdSDK/RewardVideoAd'
        ss.dependency 'MintegralAdSDK/BannerAd'
        ss.dependency 'MintegralAdSDK/SplashAd'
        ss.dependency 'MintegralAdSDK/InterstitialAd'
        ss.dependency 'MintegralAdSDK/NativeAdvancedAd'
    end
 
end
