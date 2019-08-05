//
//  UIButton+UFKit.h
//  UFKit
//
//  Created by Chen Zhangli on 2019/8/1.
//  Copyright © 2019 Uniauto. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (UFKit)

/**
 倒计时

 @param seconds 总秒数
 */
- (void)ufk_countDown:(NSInteger)seconds;

@end

NS_ASSUME_NONNULL_END
