//
//  NSData+WindCrypt.h
//  WindSDK
//
//  Created by Codi on 2021/8/2.
//  Copyright © 2021 Codi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WindFoundation/NSData+WindPadding.h>
#import <WindFoundation/WindCryptDefines.h>



extern NSString * const WindCryptErrorDomain;




@interface NSData (WindCrypt)

/**
 encrypt interface

 @param op encryt or decrypt
 @param alg encryt algorithm
 @param om ECB、CBC、CFB、OFB
 @param padding padding type
 @param key key
 @param iv init vector
 @param error return err info
 @return  result,fail if return nil
 */
- (NSData*)WindCryptWithOp:(WindOperaton)op
                algorithm:(WindAlgorithm)alg
               optionMode:(WindOptionMode)om
                  padding:(WindPaddingMode)padding
                      key:(id)key
                       iv:(id)iv
                    error:(NSError**)error;



@end








