//
//  UFMobileCodeStyle.h
//  Created by ChenZhangli QQ893419255 on 2019/6/29.
//  Copyright © 2019 UFKit. All rights reserved.
//
//          _ _     _ _   _ _ _ _ _   _ _    _ _     _ _   _ _ _ _ _ _ __
//         /  /    /  /  /  _ _ _ /  /  /   ╱  ╱    /__/  /_ _ _   _ _ _/
//        /  /    /  /  /  /        /  /  ╱  ╱     _ _         /  /
//       /  /    /  /  /  /_ _ _   /  / ╱  ╱      /  /        /  /
//      /  /    /  /  /  _ _ _ /  /  / \  \      /  /        /  /
//     /  /_ __/  /  /  /        /  /   \  \    /  /        /  /
//     \ _ _ _ _ /  /__/        /__/     \__\  /__/        /__/

#import "UFTextStyle.h"

NS_ASSUME_NONNULL_BEGIN

@class UFMobileCodeStyleMaker;
@interface UFMobileCodeStyle : UFTextStyle

// 倒计时按钮背景色
@property (nonatomic, strong) UIColor *backgroundColor;
// 倒计时按钮圆角
@property (nonatomic, assign) CGFloat cornerRadius;
// 倒计时按钮边框
@property (nonatomic, assign) CGFloat borderWidth;
// 倒计时按钮边框颜色
@property (nonatomic, strong) UIColor *borderColor;
// 倒计时按钮尺寸
@property (nonatomic, assign) CGSize size;

// 倒计时按钮与输入框之间分割线的颜色
@property (nonatomic, strong) UIColor *separatorColor;

+ (UFMobileCodeStyle *)makeMobileCodeStyle:(NS_NOESCAPE void(^)(UFMobileCodeStyleMaker *make))block;

@end

@interface UFMobileCodeStyleMaker : UFRowTextStyleMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithTextStyle:(UFTextStyle *)textStyle NS_UNAVAILABLE;
- (instancetype)initWithMobileCodeStyle:(UFMobileCodeStyle *)mobileCodeStyle NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFMobileCodeStyle *mobileCodeStyle;

@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^backgroundColor)(UIColor *backgroundColor);
@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^cornerRadius)(CGFloat cornerRadius);
@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^borderWidth)(CGFloat borderWidth);
@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^borderColor)(UIColor *borderColor);
@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^size)(CGSize size);

@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^separatorColor)(UIColor *separatorColor);

@end

NS_ASSUME_NONNULL_END
