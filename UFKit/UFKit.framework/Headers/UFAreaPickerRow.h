//
//  UFAreaPickerRow.h
//  Created by Chen Zhangli on 2019/7/30.
//  Copyright © 2019 UFKit. All rights reserved.
//
//          _ _     _ _   _ _ _ _ _   _ _    _ _     _ _   _ _ _ _ _ _ __
//         /  /    /  /  /  _ _ _ /  /  /   ╱  ╱    /__/  /_ _ _   _ _ _/
//        /  /    /  /  /  /        /  /  ╱  ╱     _ _         /  /
//       /  /    /  /  /  /_ _ _   /  / ╱  ╱      /  /        /  /
//      /  /    /  /  /  _ _ _ /  /  / \  \      /  /        /  /
//     /  /_ __/  /  /  /        /  /   \  \    /  /        /  /
//     \ _ _ _ _ /  /__/        /__/     \__\  /__/        /__/

#import "UFTextFieldRow.h"

NS_ASSUME_NONNULL_BEGIN

@class UFAreaPickerRowMaker;
@interface UFAreaPickerRow : UFTextFieldRow

// 地址分割符（如：@“ ” @“，” @“-”）
@property (nonatomic, copy) NSString *areaSeparator;

+ (UFTextFieldRow *)makeTextFieldRow:(NS_NOESCAPE void(^)(UFTextFieldRowMaker *make))block NS_UNAVAILABLE;
+ (UFAreaPickerRow *)makeAreaPickerRow:(NS_NOESCAPE void(^)(UFAreaPickerRowMaker *make))block;

@end

@interface UFAreaPickerRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithAreaPickerRow:(UFAreaPickerRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFAreaPickerRow *areaPickerRow;

@property (nonatomic, copy, readonly) UFAreaPickerRowMaker *(^areaSeparator)(NSString * _Nullable areaSeparator);

@end

NS_ASSUME_NONNULL_END
