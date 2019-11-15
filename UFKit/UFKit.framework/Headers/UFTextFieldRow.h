//
//  UFTextFieldRow.h
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

#import "UFRow.h"
#import "UFRowInput.h"

NS_ASSUME_NONNULL_BEGIN

@class UFTextFieldRowMaker;
@interface UFTextFieldRow : UFRow <UFRowInput>

// 限制输入的正则表达式
@property (nonatomic, copy) NSString *regex;

// 限制输入的类型
@property (nonatomic, assign) UFInputLimitType limitType;

+ (UFRow *)makeRow:(NS_NOESCAPE void(^)(UFRowMaker *make))block NS_UNAVAILABLE;
+ (UFTextFieldRow *)makeTextFieldRow:(NS_NOESCAPE void(^)(UFTextFieldRowMaker *make))block;

@end


@interface UFTextFieldRowMaker : UFRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFTextFieldRow *textFieldRow;

@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^placeholder)(NSString * _Nullable placeholder);

@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^keyboardType)(UIKeyboardType keyboardType);

@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^secureTextEntry)(BOOL secureTextEntry);
@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^editable)(BOOL editable);

@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^maxLength)(NSInteger maxLength);
@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^regex)(NSString *regex);
@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^limitType)(UFInputLimitType limitType);

@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^canPerformAction)(BOOL canPerformAction);

@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^barTintColor)(UIColor *barTintColor);
@property (nonatomic, copy, readonly) UFTextFieldRowMaker *(^keyboardDidDone)(UFKeyboardDidDone keyboardDidDone);

@end

NS_ASSUME_NONNULL_END
