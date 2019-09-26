//
//  UFRowInput.h
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

#import <UIKit/UIKit.h>
#import "UFKitDefines.h"
#import "UFRow.h"

NS_ASSUME_NONNULL_BEGIN

UFKIT_EXTERN NSString * const UFKeyboardDidDoneNotification;

/**
 限制输入样式

 - UFInputLimitTypeNone: 无限制
 - UFInputLimitTypeMobile: 手机号码
 - UFInputLimitTypeEmail: 邮箱
 - UFInputLimitTypeIdCard: 身份证号
 - UFInputLimitTypeNumbers: 数字
 - UFInputLimitTypeLetters: 字母
 - UFInputLimitTypeCapitalLetters: 大写字母
 - UFInputLimitTypeAlphanumeric: 字母和数字
 - UFInputLimitTypeFloat: 浮点数
 - UFInputLimitTypeMoney: 金额（2位小数）
 */
typedef NS_ENUM(NSUInteger, UFInputLimitType) {
    UFInputLimitTypeNone = 0,
    UFInputLimitTypeMobile,
    UFInputLimitTypeEmail,
    UFInputLimitTypeIdCard,
    UFInputLimitTypeNumbers,
    UFInputLimitTypeLetters,
    UFInputLimitTypeCapitalLetters,
    UFInputLimitTypeAlphanumeric,
    UFInputLimitTypeFloat,
    UFInputLimitTypeMoney,
};

@class UFRow;
@protocol UFRowInput;
typedef void(^UFKeyboardDidDone)(__kindof UFRow <UFRowInput> *row, NSString *text);

@protocol UFRowInput <NSObject>

// 占位符
@property (nonatomic, copy, nullable) NSString *placeholder;
// 键盘样式
@property (nonatomic, assign) UIKeyboardType keyboardType;
// 安全输入
@property (nonatomic, assign) BOOL secureTextEntry;
// 是否可编辑
@property (nonatomic, assign) BOOL editable;
// 最大限制输入长度
@property (nonatomic, assign) NSInteger maxLength;
// 工具条按钮颜色
@property (nonatomic, strong) UIColor *barTintColor;
// 工具条完成按钮点击时回调
@property (nonatomic, copy) UFKeyboardDidDone keyboardDidDone;
// 是否允许复制粘贴选择等
@property (nonatomic, assign) BOOL canPerformAction;

@end


NS_ASSUME_NONNULL_END
