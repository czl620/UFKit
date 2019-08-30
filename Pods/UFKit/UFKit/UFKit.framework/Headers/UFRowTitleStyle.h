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

#import "UFTextStyle.h"

NS_ASSUME_NONNULL_BEGIN

@class UFRowTitleStyleMaker;
@interface UFRowTitleStyle : UFTextStyle

// 标题宽度
@property (nonatomic, assign) CGFloat width;

+ (UFRowTitleStyle *)makeTitleStyle:(NS_NOESCAPE void(^)(UFRowTitleStyleMaker *make))block;

@end


@interface UFRowTitleStyleMaker : UFRowTextStyleMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithTextStyle:(UFTextStyle *)titleStyle NS_UNAVAILABLE;
- (instancetype)initWithTitleStyle:(UFRowTitleStyle *)titleStyle NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFRowTitleStyle *titleStyle;

@property (nonatomic, copy, readonly) UFRowTitleStyleMaker *(^width)(CGFloat width);

@end

NS_ASSUME_NONNULL_END
