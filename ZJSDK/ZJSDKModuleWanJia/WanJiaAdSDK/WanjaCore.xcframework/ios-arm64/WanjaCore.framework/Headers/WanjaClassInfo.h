//
//  WanjaClassInfo.h
//  TestView
//
//  Created by guantou on 2020/1/6.
//  Copyright © 2020 北京市吕俊学. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, WanjaEncodingType) {
    WanjaEncodingTypeMask       = 0xFF, ///< mask of type value
    WanjaEncodingTypeUnknown    = 0, ///< unknown
    WanjaEncodingTypeVoid       = 1, ///< void
    WanjaEncodingTypeBool       = 2, ///< bool
    WanjaEncodingTypeInt8       = 3, ///< char / BOOL
    WanjaEncodingTypeUInt8      = 4, ///< unsigned char
    WanjaEncodingTypeInt16      = 5, ///< short
    WanjaEncodingTypeUInt16     = 6, ///< unsigned short
    WanjaEncodingTypeInt32      = 7, ///< int
    WanjaEncodingTypeUInt32     = 8, ///< unsigned int
    WanjaEncodingTypeInt64      = 9, ///< long long
    WanjaEncodingTypeUInt64     = 10, ///< unsigned long long
    WanjaEncodingTypeFloat      = 11, ///< float
    WanjaEncodingTypeDouble     = 12, ///< double
    WanjaEncodingTypeLongDouble = 13, ///< long double
    WanjaEncodingTypeObject     = 14, ///< id
    WanjaEncodingTypeClass      = 15, ///< Class
    WanjaEncodingTypeSEL        = 16, ///< SEL
    WanjaEncodingTypeBlock      = 17, ///< block
    WanjaEncodingTypePointer    = 18, ///< void*
    WanjaEncodingTypeStruct     = 19, ///< struct
    WanjaEncodingTypeUnion      = 20, ///< union
    WanjaEncodingTypeCString    = 21, ///< char*
    WanjaEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    WanjaEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    WanjaEncodingTypeQualifierConst  = 1 << 8,  ///< const
    WanjaEncodingTypeQualifierIn     = 1 << 9,  ///< in
    WanjaEncodingTypeQualifierInout  = 1 << 10, ///< inout
    WanjaEncodingTypeQualifierOut    = 1 << 11, ///< out
    WanjaEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    WanjaEncodingTypeQualifierByref  = 1 << 13, ///< byref
    WanjaEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    WanjaEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    WanjaEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    WanjaEncodingTypePropertyCopy         = 1 << 17, ///< copy
    WanjaEncodingTypePropertyRetain       = 1 << 18, ///< retain
    WanjaEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    WanjaEncodingTypePropertyWeak         = 1 << 20, ///< weak
    WanjaEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    WanjaEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    WanjaEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

WanjaEncodingType WanjaEncodingGetType(const char *typeEncoding);

@interface WanjaClassIvarInfo : NSObject

@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) WanjaEncodingType type;    ///< Ivar's type

- (instancetype)initWithIvar:(Ivar)ivar;

@end

@interface WanjaClassMethodInfo : NSObject

@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type

- (instancetype)initWithMethod:(Method)method;

@end

@interface WanjaClassPropertyInfo : NSObject

@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) WanjaEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

- (instancetype)initWithProperty:(objc_property_t)property;

@end

@interface WanjaClassInfo : NSObject

@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) WanjaClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, WanjaClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, WanjaClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, WanjaClassPropertyInfo *> *propertyInfos; ///< properties

- (void)setNeedUpdate;

- (BOOL)needUpdate;

+ (nullable instancetype)classInfoWithClass:(Class)cls;

+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END

