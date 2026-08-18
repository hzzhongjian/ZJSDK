# post_install_hook.rb
# 使用 CFPropertyList（xcodeproj 自带，无需额外安装 gem）

QUERIES_SCHEMES_TO_ADD = ['cydia', 
                          'taobao', 
                          'weixin',
                          'alipays',
                          'cainiao',
                          'imeituan',
                          'openapp.jdmobile',
                          'pinduoduo',
                          'kwai',
                          'snssdk1128',
                          'snssdk2329',
                          'sinaweibo',
                          'meituanwaimai',
                          'dianping',
                          'xhsdiscover',
                          'bilibili',
                          'baiduboxapp',
                          'tmall',
                          'fleamarket',
                          'eleme',
                          'onetravel',
                          'quark',
                          'youku',
                          'uppaywallet',
                          'luckycoffee',
                          'orpheus',
                          'lianjiabeike',
                          'openanjuke',
                          'lianjia',
                          'fdd',
                          'soufun',
                          'ziroom']

def inject_queried_url_schemes(installer)
  require 'cfpropertylist'
  require 'xcodeproj'

  project_root = File.dirname(installer.sandbox.root)

  xcodeproj_paths = Dir.glob(File.join(project_root, '*.xcodeproj'))
                         .reject { |p| p.include?('Pods') }

  xcodeproj_paths.each do |proj_path|
    project = Xcodeproj::Project.open(proj_path)
    project_dir = File.dirname(proj_path)

    project.targets.each do |target|
      next unless target.is_a?(Xcodeproj::Project::Object::PBXNativeTarget)

      target.build_configurations.each do |config|
        plist_path = config.build_settings['INFOPLIST_FILE']
        next unless plist_path

        # 展开 $(SRCROOT) 变量
        plist_path = plist_path.gsub('$(SRCROOT)', project_dir)
        full_plist_path = File.expand_path(plist_path, project_dir)
        next unless File.exist?(full_plist_path)

        # 用 CFPropertyList 读取
        cf_plist = CFPropertyList::List.new(file: full_plist_path)
        root = CFPropertyList.native_types(cf_plist.value)
        modified = false

        # ---- 1. 追加 Queried URL Schemes ----
        root['LSApplicationQueriesSchemes'] ||= []
        new_schemes = QUERIES_SCHEMES_TO_ADD - root['LSApplicationQueriesSchemes']
        unless new_schemes.empty?
          root['LSApplicationQueriesSchemes'] += new_schemes
          modified = true
          puts "✅ 已追加 Queried URL Schemes: #{new_schemes.join(', ')}"
        end

        # ---- 2. 删除 NSAllowsArbitraryLoadsInWebContent ----
        ats = root['NSAppTransportSecurity']
        if ats && ats.key?('NSAllowsArbitraryLoadsInWebContent')
          ats.delete('NSAllowsArbitraryLoadsInWebContent')
          modified = true
          puts "🗑️ 已删除 NSAllowsArbitraryLoadsInWebContent"
        end

        # ---- 3. 确保 NSAllowsArbitraryLoads 为 true ----
        root['NSAppTransportSecurity'] ||= {}
        unless root['NSAppTransportSecurity']['NSAllowsArbitraryLoads'] == true
          root['NSAppTransportSecurity']['NSAllowsArbitraryLoads'] = true
          modified = true
          puts "✅ 已设置 NSAllowsArbitraryLoads = true"
        end

        if modified
          # 写回 plist（XML 格式，保持可读性）
          cf_plist.value = CFPropertyList.guess(root)
          cf_plist.save(full_plist_path, CFPropertyList::List::FORMAT_XML)
        end
      end
    end
  end
end
