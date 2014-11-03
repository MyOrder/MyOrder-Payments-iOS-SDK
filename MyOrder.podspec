
Pod::Spec.new do |s|
  s.name             = "MyOrder"
  s.version          = "2.1.0"
  s.summary          = "MyOrder Payment library for iOS."
  s.description      = <<-DESC
                       MyOrder Payment library provides an easy way to integrate payments in your
                       iOS apps in The Netherlands.
                       DESC
  s.homepage         = "http://myorder.nl/sdk"
  s.license          = { :type => "Copyright", :text => "Copyright (c) 2014 MyOrder B.V." }
  s.authors          = "MyOrder B.V." 
  s.source           = { :git => "https://github.com/MyOrder/MyOrder-Payments-iOS-SDK.git", :tag => s.version.to_s }

  s.platform     = :ios, '6.0'
  s.requires_arc = true

  s.preserve_paths = "MyOrder.framework"
  s.public_header_files = "MyOrder.framework/**/*.h"
  s.vendored_frameworks = "MyOrder.framework"
  s.resources = "MyOrder.framework/**/MyOrder.bundle"
  
  s.frameworks = "Security", "AddressBook", "AddressBookUI"

  s.dependencies = [ "TPKeyboardAvoiding" ]

end
