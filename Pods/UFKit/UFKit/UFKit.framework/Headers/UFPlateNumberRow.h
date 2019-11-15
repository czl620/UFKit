//
//  UFPlateNumberRow.h
//  Created by ChenZhangli QQ893419255 on 2019/6/28.
//  Copyright © 2019 UFKit. All rights reserved.
//
//          _ _     _ _   _ _ _ _ _   _ _    _ _     _ _   _ _ _ _ _ _ __
//         /  /    /  /  /  _ _ _ /  /  /   ╱  ╱    /__/  /_ _ _   _ _ _/
//        /  /    /  /  /  /        /  /  ╱  ╱     _ _         /  /
//       /  /    /  /  /  /_ _ _   /  / ╱  ╱      /  /        /  /
//      /  /    /  /  /  _ _ _ /  /  / \  \      /  /        /  /
//     /  /_ __/  /  /  /        /  /   \  \    /  /        /  /
//     \ _ _ _ _ /  /__/        /__/     \__\  /__/        /__/

#import <UFKit/UFKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UFPlateNumberRowMaker;
@interface UFPlateNumberRow : UFTextFieldRow

// 省份简写的字体颜色
@property (nonatomic, strong) UIColor *color;

@property (nonatomic, assign) CGFloat inputWidth;

+ (UFTextFieldRow *)makeTextFieldRow:(NS_NOESCAPE void(^)(UFTextFieldRowMaker *make))block NS_UNAVAILABLE;
+ (UFPlateNumberRow *)makePlateNumberRow:(NS_NOESCAPE void(^)(UFPlateNumberRowMaker *make))block;

@end

@interface UFPlateNumberRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithPlateNumberRow:(UFPlateNumberRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFPlateNumberRow *plateNumberRow;

@property (nonatomic, copy, readonly) UFPlateNumberRowMaker *(^color)(UIColor *color);
@property (nonatomic, copy, readonly) UFPlateNumberRowMaker *(^inputWidth)(CGFloat inputWidth);

@end

NS_ASSUME_NONNULL_END
