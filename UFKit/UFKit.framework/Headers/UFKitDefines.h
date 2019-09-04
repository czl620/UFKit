//
//  UFKitDefines.h
//  UFKit
//
//  Created by Chen Zhangli on 2019/9/4.
//  Copyright © 2019 Uniauto. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __cplusplus
#define UFKIT_EXTERN        extern "C" __attribute__((visibility ("default")))
#else
#define UFKIT_EXTERN        extern __attribute__((visibility ("default")))
#endif
