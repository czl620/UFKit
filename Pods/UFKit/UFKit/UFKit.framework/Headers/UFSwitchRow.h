//
//  UFSwitchRow.h
//  Created by ChenZhangli QQ893419255 on 2019/6/24.
//  Copyright © 2019 UFKit. All rights reserved.
//
//          _ _     _ _   _ _ _ _ _   _ _    _ _     _ _   _ _ _ _ _ _ __
//         /  /    /  /  /  _ _ _ /  /  /   ╱  ╱    /__/  /_ _ _   _ _ _/
//        /  /    /  /  /  /        /  /  ╱  ╱     _ _         /  /
//       /  /    /  /  /  /_ _ _   /  / ╱  ╱      /  /        /  /
//      /  /    /  /  /  _ _ _ /  /  / \  \      /  /        /  /
//     /  /_ __/  /  /  /        /  /   \  \    /  /        /  /
//     \ _ _ _ _ /  /__/        /__/     \__\  /__/        /__/

#import "UFRow.h"
#import "UFKitDefines.h"

NS_ASSUME_NONNULL_BEGIN

UFKIT_EXTERN NSString * const SWITCH_ON;
UFKIT_EXTERN NSString * const SWITCH_OFF;

@class UFSwitchRowMaker;
@interface UFSwitchRow : UFRow

// 开关颜色
@property (nonatomic, strong) UIColor *tintColor;

+ (UFRow *)makeRow:(NS_NOESCAPE void(^)(UFRowMaker *make))block NS_UNAVAILABLE;
+ (UFSwitchRow *)makeSwitchRow:(NS_NOESCAPE void(^)(UFSwitchRowMaker *make))block;

@end

@interface UFSwitchRowMaker : UFRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithSwitchRow:(UFSwitchRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFSwitchRow *switchRow;

@property (nonatomic, copy, readonly) UFSwitchRowMaker *(^tintColor)(UIColor *tintColor);

@end

NS_ASSUME_NONNULL_END
