//
//  UIColor+MOAppearance.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>


/** This category allows third party developers to customize colors inside the MyOrder library */
@interface UIColor (MOAppearance)


/**
 @name Customizable colors setters
 */

/**
 Changes the background color of the library
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setBackgroundColor:(UIColor *)color;

/**
 Changes the section border color (textfields and groups)
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setSectionBorderColor:(UIColor *)color;

/**
 Changes the text color of textfield titles
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setTextFieldTitleColor:(UIColor *)color;

/**
 Changes the color of switch enabled state
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setSwitchOnColor:(UIColor *)color;

/**
 Changes the text color of labels on top of a background view
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setTextColor:(UIColor *)color;

/**
 Changes the text color of the buttons
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setButtonTextColor:(UIColor *)color;

/**
 Changes the text color of the links to external services
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setLinkTextColor:(UIColor *)color;

/**
 Changes the background color of the header in order details when fail
 @param color Color to set. Nil for returning to default
 */
+ (void)MO_setOrderErrorColor:(UIColor *)color;


// Getters
+ (UIColor *)MO_backgroundColor;
+ (UIColor *)MO_sectionBorderColor;
+ (UIColor *)MO_textFieldTitleColor;
+ (UIColor *)MO_switchOnColor;
+ (UIColor *)MO_textColor;
+ (UIColor *)MO_buttonTextColor;
+ (UIColor *)MO_linkTextColor;
+ (UIColor *)MO_orderErrorColor;

@end
