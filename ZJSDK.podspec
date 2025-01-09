#
# Be sure to run `pod lib lint ZJSDK_Pods.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZJSDK'
  s.version          = '2.5.9.7'
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
  s.frameworks = 'UIKit','Foundation','StoreKit','MobileCoreServices','WebKit','MediaPlayer','CoreML','CoreMedia','CoreLocation','AVFoundation','CoreTelephony','SystemConfiguration','AdSupport','CoreMotion','Accelerate','QuartzCore','Security','ImageIO','CFNetwork','CoreGraphics','SafariServices','AVKit','DeviceCheck','CoreImage','MapKit','JavaScriptCore','CoreText','AddressBook','CoreData','MessageUI','QuickLook','AudioToolBox','Photos'
  s.weak_frameworks = 'AppTrackingTransparency'
  #依赖的系统静态库
  #z表示libz.tdb,后缀不需要,lib开头的省略lib
  s.libraries = 'resolv.9','c++','z','sqlite3','bz2','xml2','c++abi','sqlite3.0','iconv'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64', 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386,arm64' }
  s.xcconfig = { 'ENABLE_BITCODE' => 'NO', 'OTHER_LDFLAGS' =>'-ObjC'}
#  valid_archs = ['armv7', 'i386', 'x86_64', 'arm64']
#  s.pod_target_xcconfig = {
#    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
#  }
#  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.default_subspecs = 'ZJSDKModuleGDT','ZJSDKModuleCSJ','ZJSDKModuleDSP','ZJSDKModuleSIG','ZJSDKModuleBD','ZJSDKModuleBeiZi','ZJSDKModuleTanX','ZJSDKModuleKS','ZJSDKModuleOCTOPUS'
  
    s.subspec 'ZJAdSDK' do |ss|
        ss.vendored_frameworks = 'ZJSDK/ZJAdSDK/*.framework'
        ss.preserve_paths = 'ZJSDK/ZJAdSDK/*.framework'
        ss.resource = 'ZJSDK/ZJAdSDK/*.bundle'
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
        ss.dependency 'GDTMobSDK', '~> 4.14.62'
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
        ss.dependency 'Ads-CN-Beta'
        ss.dependency 'Ads-CN-Beta/CSJMediation'
        ss.dependency 'Ads-CN-Beta/BUAdSDK'
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

    ### MTG适配器兼容版
    s.subspec 'ZJSDKModuleMTGCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleMTG/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ### MTG适配器
    s.subspec 'ZJSDKModuleMTG' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleMTG/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'MintegralAdSDK', '~> 7.0'
        ss.dependency 'MintegralAdSDK/RewardVideoAd'
        ss.dependency 'MintegralAdSDK/BannerAd'
        ss.dependency 'MintegralAdSDK/SplashAd'
        ss.dependency 'MintegralAdSDK/InterstitialAd'
        ss.dependency 'MintegralAdSDK/NativeAdvancedAd'
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
        ss.dependency 'SigmobAd-iOS', '~> 4.7'
    end

    ### 谷歌适配器
    s.subspec 'ZJSDKModuleGoogle' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleGoogle/*.a'
        ss.source_files       = 'ZJSDK/ZJSDKModuleGoogle/*.h'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'Google-Mobile-Ads-SDK'
    end
 
    ### 百度适配器兼容版   
    s.subspec 'ZJSDKModuleBDCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBD/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.resource           = 'ZJSDK/ZJSDKModuleBD/*.bundle'
    end

    ### 百度适配器   
    s.subspec 'ZJSDKModuleBD' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleBD/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'BaiduMobAdSDK', '~> 5.36'
        ss.resource           = 'ZJSDK/ZJSDKModuleBD/*.bundle'
    end
 
    ### 穿山甲海外适配器
    s.subspec 'ZJSDKModulePangle' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModulePangle/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.dependency 'Ads-Global'
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
        ss.source_files         = 'ZJSDK/ZJSDKModuleTanX/*.h'
    end

    ### Tanx适配器
    s.subspec 'ZJSDKModuleTanX' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleTanX/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        # 可以把TanX的依赖更换为pod管理
        #    ss.dependency 'TanxSDK', '~> 3.5.3'
        ss.source_files         = 'ZJSDK/ZJSDKModuleTanX/*.h'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleTanX/*.framework'
        ss.resource             = 'ZJSDK/ZJSDKModuleTanX/*.bundle'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleTanX/*.framework'
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

    ###移卡适配器兼容版
    s.subspec 'ZJSDKModuleYKCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleYK/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ###移卡适配器
    s.subspec 'ZJSDKModuleYK' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleYK/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleYK/*.framework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleYK/*.framework'
    end
    
    ###奇运适配器兼容版
    s.subspec 'ZJSDKModuleJiaJiCompatible' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleJiaJi/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
    end

    ###奇运适配器
    s.subspec 'ZJSDKModuleJiaJi' do |ss|
        ss.vendored_libraries = 'ZJSDK/ZJSDKModuleJiaJi/*.a'
        ss.dependency 'ZJSDK/ZJAdSDK'
        ss.vendored_frameworks  = 'ZJSDK/ZJSDKModuleJiaJi/*.xcframework'
        ss.preserve_paths       = 'ZJSDK/ZJSDKModuleJiaJi/*.xcframework'
    end
 
end
