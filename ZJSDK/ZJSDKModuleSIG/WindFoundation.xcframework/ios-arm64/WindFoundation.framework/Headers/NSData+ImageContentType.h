/*
 * This file is part of the SDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Fabrice Aneche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 You can use switch case like normal enum. It's also recommended to add a default case. You should not assume anything about the raw value.
 For custom coder plugin, it can also extern the enum for supported format. See `SigmobSDImageCoder` for more detailed information.
 */
typedef NSInteger SigmobSDImageFormat NS_TYPED_EXTENSIBLE_ENUM;
static const SigmobSDImageFormat SigmobSDImageFormatUndefined = -1;
static const SigmobSDImageFormat SigmobSDImageFormatJPEG      = 0;
static const SigmobSDImageFormat SigmobSDImageFormatPNG       = 1;
static const SigmobSDImageFormat SigmobSDImageFormatGIF       = 2;
static const SigmobSDImageFormat SigmobSDImageFormatTIFF      = 3;
static const SigmobSDImageFormat SigmobSDImageFormatWebP      = 4;
static const SigmobSDImageFormat SigmobSDImageFormatHEIC      = 5;
static const SigmobSDImageFormat SigmobSDImageFormatHEIF      = 6;
static const SigmobSDImageFormat SigmobSDImageFormatPDF       = 7;
static const SigmobSDImageFormat SigmobSDImageFormatSVG       = 8;
static const SigmobSDImageFormat SigmobSDImageFormatBMP       = 9;
static const SigmobSDImageFormat SigmobSDImageFormatRAW       = 10;

/**
 NSData category about the image content type and UTI.
 */
@interface NSData (ImageContentType)

/**
 *  Return image format
 *
 *  @param data the input image data
 *
 *  @return the image format as `SDImageFormat` (enum)
 */
+ (SigmobSDImageFormat)sigmobsd_imageFormatForImageData:(nullable NSData *)data;

/**
 *  Convert SigmobSDImageFormat to UTType
 *
 *  @param format Format as SigmobSDImageFormat
 *  @return The UTType as CFStringRef
 *  @note For unknown format, `kSDUTTypeImage` abstract type will return
 */
+ (nonnull CFStringRef)sigmobsd_UTTypeFromImageFormat:(SigmobSDImageFormat)format CF_RETURNS_NOT_RETAINED NS_SWIFT_NAME(sd_UTType(from:));

/**
 *  Convert UTType to SigmobSDImageFormat
 *
 *  @param uttype The UTType as CFStringRef
 *  @return The Format as SigmobSDImageFormat
 *  @note For unknown type, `SDImageFormatUndefined` will return
 */
+ (SigmobSDImageFormat)sigmobsd_imageFormatFromUTType:(nonnull CFStringRef)uttype;

@end
