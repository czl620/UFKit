//
//  UFDatePickerRow.h
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

#import "UFTextFieldRow.h"

NS_ASSUME_NONNULL_BEGIN

@class UFDatePickerRowMaker;
@interface UFDatePickerRow : UFTextFieldRow

// 日期样式
@property (nonatomic, assign) UIDatePickerMode datePickerMode;
// 日期格式（如:yyyy-MM-dd）
@property (nonatomic, copy) NSString *dateFormat;

@property (nonatomic, strong) NSDate *minimumDate;
@property (nonatomic, strong) NSDate *maximumDate;

+ (UFTextFieldRow *)makeTextFieldRow:(NS_NOESCAPE void(^)(UFTextFieldRowMaker *make))block NS_UNAVAILABLE;
+ (UFDatePickerRow *)makeDatePickerRow:(NS_NOESCAPE void(^)(UFDatePickerRowMaker *make))block;

@end

@interface UFDatePickerRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithDatePickerRow:(UFDatePickerRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFDatePickerRow *datePickerRow;

@property (nonatomic, copy, readonly) UFDatePickerRowMaker *(^datePickerMode)(UIDatePickerMode datePickerMode);
@property (nonatomic, copy, readonly) UFDatePickerRowMaker *(^dateFormat)(NSString * _Nullable dateFormat);
@property (nonatomic, copy, readonly) UFDatePickerRowMaker *(^minimumDate)(NSDate * _Nullable minimumDate);
@property (nonatomic, copy, readonly) UFDatePickerRowMaker *(^maximumDate)(NSDate * _Nullable maximumDate);

@end

NS_ASSUME_NONNULL_END
