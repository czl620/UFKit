//
//  UFRowTitleStyle.h
//  Created by ChenZhangli QQ893419255 on 2019/6/21.
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

@class UFRowTextStyleMaker;
@interface UFTextStyle : NSObject

// 文本颜色
@property (nonatomic, strong) UIColor *color;
// 文本字体
@property (nonatomic, strong) UIFont *font;
// 文本对齐方式
@property (nonatomic, assign) NSTextAlignment textAlignment;

+ (UFTextStyle *)makeTextStyle:(NS_NOESCAPE void(^)(UFRowTextStyleMaker *make))block;

@end

@interface UFRowTextStyleMaker : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithTextStyle:(UFTextStyle *)textStyle NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFTextStyle *textStyle;

@property (nonatomic, copy, readonly) UFRowTextStyleMaker *(^color)(UIColor *color);
@property (nonatomic, copy, readonly) UFRowTextStyleMaker *(^font)(UIFont *font);
@property (nonatomic, copy, readonly) UFRowTextStyleMaker *(^textAlignment)(NSTextAlignment textAlignment);

@end


NS_ASSUME_NONNULL_END
