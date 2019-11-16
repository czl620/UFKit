
platform :ios, '8.0'
inhibit_all_warnings!

target 'UFKitDemo' do
    #use_frameworks!
    pod 'UFKit', '~> 1.1.17'

end


post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      if config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'].to_f < 8.0
        config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '8.0'
      end
    end
  end
end
