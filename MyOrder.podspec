
Pod::Spec.new do |s|
  s.name             = "MyOrder"
  s.version          = "3.1.0"
  s.summary          = "MyOrder Payment library for iOS."
  s.description      = <<-DESC
                       MyOrder Payment library provides an easy way to integrate payments in your
                       iOS apps in The Netherlands.
                       DESC
  s.homepage         = "https://github.com/MyOrder/MyOrder-Payments-iOS-SDK"
  s.license          = { :type => "Copyright", :text => "Copyright (c) 2014 MyOrder B.V." }
  s.authors          = "MyOrder B.V." 
  s.source           = { "http": "https://github.com/MyOrder/MyOrder-Payments-iOS-SDK/blob/master/Versions/3.1.0/MyOrderPaymentSDKv3.1.0.zip" }

  s.platform     = :ios, '6.0'
  s.requires_arc = true

  s.preserve_paths = "MyOrderPaymentSDK.embeddedframework/MyOrder.framework"
  s.public_header_files = "MyOrderPaymentSDK.embeddedframework/MyOrder.framework/**/*.h"
  s.vendored_frameworks = "MyOrderPaymentSDK.embeddedframework/MyOrder.framework"
  s.resources = "MyOrderPaymentSDK.embeddedframework/MyOrder.framework/**/MyOrder.bundle"
  
  s.frameworks = "Security", "AddressBook", "AddressBookUI"

  s.dependencies = [ "TPKeyboardAvoiding" ]

end
