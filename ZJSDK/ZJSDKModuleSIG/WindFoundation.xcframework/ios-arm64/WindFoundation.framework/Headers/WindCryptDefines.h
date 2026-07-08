//
//  WindCryptDefines.h
//  WindSDK
//
//  Created by Codi on 2021/8/2.
//  Copyright © 2021 Codi. All rights reserved.
//

typedef NS_ENUM(uint32_t,WindAlgorithm)
{
    WindAlgorithm_AES128 = 0,
    WindAlgorithm_AES256 = 0,
    WindAlgorithm_DES,
    WindAlgorithm_3DES,
    WindAlgorithm_CAST,
    WindAlgorithm_RC4,
    WindAlgorithm_RC2,
    WindAlgorithm_Blowfish,
};

//algorithm block size bytes,iv size == block size
typedef NS_ENUM(uint16_t,WindBlockSize)
{
    /*AES*/
    WindBlockSize_AES128 = 16,
    WindBlockSize_AES256 = 16,
    
    /*DES*/
    WindBlockSize_DES = 8,
    
    /*3DES*/
    WindBlockSize_3DES = 8,
    
    //流式加密，没有固定长度
    /*CAST*/
    WindBlockSize_CAST = 8,
    WindBlockSize_RC2 = 8,
    WindBlockSize_Blowfish = 8,
    WindBlockSize_RC4 = 1
};
//RC4一个字节一个字节加解密

//encrypt key size bytes
typedef NS_ENUM(uint16_t,WindKeySize)
{
    /*DES*/
    WindKeySize_DES = 8,
    
    /*3DES*/
    WindKeySize_3DES_EDE2 = 16,
    WindKeySize_3DES_EDE3 = 24,
    
    /*AES*/
    WindKeySize_AES128 = 16,
    WindKeySize_AES256_24 = 24,
    WindKeySize_AES256_32 = 32,
    
    /*CAST*/
    WindKeySize_CAST_5 = 5,
    WindKeySize_CAST_16 = 16,
    WindKeySize_RC2 = 8,
    WindKeySize_RC4 = 512,
    WindKeySize_Blowfish = 8
};


//encrypt operation
typedef NS_ENUM(uint8_t,WindOperaton)
{
    WindOperaton_Encrypt = 0,
    WindOperaton_Decrypt = 1
};

//encrypt padding type
typedef NS_ENUM(NSInteger,WindPaddingMode)
{
    WindPaddingMode_NONE,
    WindPaddingMode_PKCS7,
    WindPaddingMode_PKCS5,
    WindPaddingMode_Zero,
    WindPaddingMode_0x80,
    WindPaddingMode_ANSIX923,
    WindPaddingMode_ISO10126
};

//encrypt option mode
typedef NS_ENUM(NSInteger, WindOptionMode)
{
    WindOptionMode_ECB,
    WindOptionMode_CBC,
    WindOptionMode_PCBC,
    WindOptionMode_CFB,
    WindOptionMode_OFB,
    WindOptionMode_CTR
};
