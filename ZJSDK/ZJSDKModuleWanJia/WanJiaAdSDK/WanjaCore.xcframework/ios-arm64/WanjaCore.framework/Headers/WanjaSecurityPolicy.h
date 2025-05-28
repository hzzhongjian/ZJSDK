//
//  WanjaSecurityPolicy.h
//  WanjaCoreSDK
//
//  Created by guantou on 2023/10/10.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>

typedef NS_ENUM(NSUInteger, WanjaSSLPinningMode) {
    WanjaSSLPinningModeNone,
    WanjaSSLPinningModePublicKey,
    WanjaSSLPinningModeCertificate,
};

NS_ASSUME_NONNULL_BEGIN

@interface WanjaSecurityPolicy : NSObject <NSSecureCoding, NSCopying>

@property (readonly, nonatomic, assign) WanjaSSLPinningMode SSLPinningMode;

@property (nonatomic, strong, nullable) NSSet <NSData *> *pinnedCertificates;

@property (nonatomic, assign) BOOL allowInvalidCertificates;

@property (nonatomic, assign) BOOL validatesDomainName;

+ (NSSet <NSData *> *)certificatesInBundle:(NSBundle *)bundle;

+ (instancetype)defaultPolicy;

+ (instancetype)policyWithPinningMode:(WanjaSSLPinningMode)pinningMode;

+ (instancetype)policyWithPinningMode:(WanjaSSLPinningMode)pinningMode withPinnedCertificates:(NSSet <NSData *> *)pinnedCertificates;

- (BOOL)evaluateServerTrust:(SecTrustRef)serverTrust
                  forDomain:(nullable NSString *)domain;

@end

NS_ASSUME_NONNULL_END


