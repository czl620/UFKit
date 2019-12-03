Pod::Spec.new do |s|

#名称
s.name         = 'UFKit'

#版本号
s.version      = '1.1.21'

#许可证
s.license      = { :type => 'MIT' }

#项目主页地址
s.homepage     = 'https://github.com/czl620/UFKit'

#作者
s.authors      = { 'czl620' => '893419255@qq.com' }

#简介
s.summary      = 'A form framework for iOS.'

#项目的地址 （注意这里的tag位置，可以自己写也可以直接用s.version，但是与s.version一定要统一）
s.source       = { :git => 'https://github.com/czl620/UFKit.git', :tag => s.version }

#支持最小系统版本
s.platform     = :ios, '8.0'

#需要包含的源文件
s.source_files = 'UFKit/UFKit.framework/Headers/*.{h}'

#你的SDK路径
s.vendored_frameworks = 'UFKit/UFKit.framework'

#SDK头文件路径
s.public_header_files = 'UFKit/UFKit.framework/Headers/UFKit.h'

#资源文件
s.resources          = "UFKit/UFKit.bundle"

#依赖库
s.frameworks   = 'UIKit','Foundation'

s.dependency  'Masonry', '>= 1.1.0'
s.dependency  'SDWebImage', '>= 5.0.6'
s.dependency  'IQKeyboardManager', '>= 6.3.0'

end
