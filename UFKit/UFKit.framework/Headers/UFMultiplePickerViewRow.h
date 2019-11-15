//
//  UFMutablePickerView.h
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

#import <UFKit/UFKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UFMultiplePickerViewRowMaker;
@interface UFMultiplePickerViewRow : UFTextFieldRow

// 选择项
@property (nonatomic, strong) NSArray <NSString *> *itemArray;

@property (nonatomic, strong) UIColor *checkmarkColor;


+ (UFTextFieldRow *)makeTextFieldRow:(NS_NOESCAPE void(^)(UFTextFieldRowMaker *make))block NS_UNAVAILABLE;
+ (UFMultiplePickerViewRow *)makeMultiplePickerViewRow:(NS_NOESCAPE void (^)(UFMultiplePickerViewRowMaker *make))block;

@end

@interface UFMultiplePickerViewRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithMultiplePickerViewRow:(UFMultiplePickerViewRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFMultiplePickerViewRow *pickerViewRow;

@property (nonatomic, copy, readonly) UFMultiplePickerViewRowMaker *(^itemArray)(NSArray <NSString *> * _Nullable itemArray);

@property (nonatomic, copy, readonly) UFMultiplePickerViewRowMaker *(^checkmarkColor)(UIColor *checkmarkColor);

@end

NS_ASSUME_NONNULL_END
