//
//  WindPointer.h
//  WindSDK
//
//  Created by Codi on 2022/11/8.
//

#import <Foundation/Foundation.h>
#import <sys/_types/_socklen_t.h>

@interface WindPointer : NSObject

int p_pgsn(int a, struct sockaddr * __restrict b, socklen_t * __restrict c);

void p_init(void);

@end
