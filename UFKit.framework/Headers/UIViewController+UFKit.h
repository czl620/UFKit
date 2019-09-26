//
//  UIViewController+UFKit.h
//  Created by Chen Zhangli on 2019/8/1.
//  Copyright © 2019 UFKit. All rights reserved.
//
//          _ _     _ _   _ _ _ _ _   _ _    _ _     _ _   _ _ _ _ _ _ __
//         /  /    /  /  /  _ _ _ /  /  /   ╱  ╱    /__/  /_ _ _   _ _ _/
//        /  /    /  /  /  /        /  /  ╱  ╱     _ _         /  /
//       /  /    /  /  /  /_ _ _   /  / ╱  ╱      /  /        /  /
//      /  /    /  /  /  _ _ _ /  /  / \  \      /  /        /  /
//     /  /_ __/  /  /  /        /  /   \  \    /  /        /  /
//     \ _ _ _ _ /  /__/        /__/     \__\  /__/        /__/

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (UFKit) <UIImagePickerControllerDelegate,UINavigationControllerDelegate>

/**
 选择图片

 @param completion 回调选择的图片
 */
- (void)ufk_pickerImageForResult:(void (^)(UIImage *image))completion __attribute__((deprecated("已过期, 建议使用ufk_pickerImageFromView:forResult:")));
- (void)ufk_pickerImageFromView:(UIView *)sourceView forResult:(void (^)(UIImage *image))completion;

@end

NS_ASSUME_NONNULL_END
