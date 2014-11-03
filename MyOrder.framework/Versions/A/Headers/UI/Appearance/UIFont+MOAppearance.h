//
//  UIFont+MOAppearance.h
//  MyOrder
//
//  Created by Angel Garcia on 5/27/13.
//
//

#import <UIKit/UIKit.h>

/** This category allows third party developers to customize fonts inside the MyOrder library */
@interface UIFont (MOAppearance)


/**
*  Set a custom font to use by the library on regular labels. Font size can also be changed
*
*  @param font Font to use in the SDK for regular labels
*/
+ (void)MO_setFont:(UIFont *)font;

/**
 *  Set a custom font to use by the library on bold labels. Font size can also be changed
 *
 *  @param font Font to use in the SDK for bold labels
 */
+ (void)MO_setBoldFont:(UIFont *)font;


/**
 *  Set a custom font to use by the library on medium labels. Font size can also be changed
 *
 *  @param font Font to use in the SDK for medium labels
 */
+ (void)MO_setMediumFont:(UIFont *)font;


//Getters
+ (UIFont *)MO_fontOfSize:(CGFloat)size;
+ (UIFont *)MO_boldFontOfSize:(CGFloat)size;
+ (UIFont *)MO_mediumFontOfSize:(CGFloat)size;

@end


@interface UIFont (MODeprecated)

/**
 Changes the main font used by regular labels in the library
 @param fontName Font to use on regular labels. Nil for returning to default
 @warning Deprecated, will be removed in next major release. Use  +(void)MO_setFont:
 */
+ (void)MO_setFontName:(NSString *)fontName __attribute__((deprecated));

/**
 Changes the main font used by bold labels in the library
 @param fontName Font to use on bold labels. Nil for returning to default
 @warning Deprecated, will be removed in next major release. Use  +(void)MO_setBoldFont:
 */
+ (void)MO_setBoldFontName:(NSString *)fontName __attribute__((deprecated));

/**
 Changes the main font used by semi-bold labels in the library
 @param fontName Font to use on semi-bold labels. Nil for returning to default
 @warning Deprecated, will be removed in next major release. Use  +(void)MO_setMediumFont:
 */
+ (void)MO_setMediumFontName:(NSString *)fontName __attribute__((deprecated));


@end