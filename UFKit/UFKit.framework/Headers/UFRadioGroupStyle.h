//
//  UFRowRadioGroupStyle.h
//  Created by ChenZhangli QQ893419255 on 2019/6/25.
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

@class UFRowRadioGroupStyleMaker;
@interface UFRadioGroupStyle : NSObject

// 未选中图片
@property (nonatomic, strong, nullable) UIImage *image;
// 选中图片
@property (nonatomic, strong, nullable) UIImage *selectedImage;

+ (UFRadioGroupStyle *)makeRadioGroupStyle:(NS_NOESCAPE void(^)(UFRowRadioGroupStyleMaker *make))block;

@end

@interface UFRowRadioGroupStyleMaker : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRadioGroupStyle:(UFRadioGroupStyle *)radioGroupStyle NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFRadioGroupStyle *radioGroupStyle;
;

@property (nonatomic, copy, readonly) UFRowRadioGroupStyleMaker *(^image)(UIImage *image);
@property (nonatomic, copy, readonly) UFRowRadioGroupStyleMaker *(^selectedImage)(UIImage *selectedImage);

@end

NS_ASSUME_NONNULL_END
