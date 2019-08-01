//
//  UIViewController+UFKit.h
//  UFKit
//
//  Created by Chen Zhangli on 2019/8/1.
//  Copyright © 2019 Uniauto. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (UFKit) <UIImagePickerControllerDelegate,UINavigationControllerDelegate>

/**
 选择图片

 @param completion 回调选择的图片
 */
- (void)ufk_pickerImageForResult:(void (^)(UIImage *image))completion;

@end

NS_ASSUME_NONNULL_END
