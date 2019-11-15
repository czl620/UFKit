//
//  UFTextViewRow.h
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
#import "UFRowInput.h"

NS_ASSUME_NONNULL_BEGIN

@class UFTextViewRowMaker;
@interface UFTextViewRow : UFRow <UFRowInput>

+ (UFRow *)makeRow:(NS_NOESCAPE void(^)(UFRowMaker *make))block NS_UNAVAILABLE;
+ (UFTextViewRow *)makeTextViewRow:(NS_NOESCAPE void(^)(UFTextViewRowMaker *make))block;

@end

@interface UFTextViewRowMaker : UFRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextViewRow:(UFTextViewRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFTextViewRow *textViewRow;

@property (nonatomic, copy, readonly) UFTextViewRowMaker *(^placeholder)(NSString * _Nullable placeholder);

@property (nonatomic, copy, readonly) UFTextViewRowMaker *(^keyboardType)(UIKeyboardType keyboardType);

@property (nonatomic, copy, readonly) UFTextViewRowMaker *(^secureTextEntry)(BOOL secureTextEntry);
@property (nonatomic, copy, readonly) UFTextViewRowMaker *(^editable)(BOOL editable);

@property (nonatomic, copy, readonly) UFTextViewRowMaker *(^maxLength)(NSInteger maxLength);

@property (nonatomic, copy, readonly) UFTextViewRowMaker *(^barTintColor)(UIColor *barTintColor);
@property (nonatomic, copy, readonly) UFTextViewRowMaker *(^keyboardDidDone)(UFKeyboardDidDone keyboardDidDone);

@end

NS_ASSUME_NONNULL_END
