//
//  UFRowInput.h
//  UFKit
//
//  Created by ChenZhangli QQ893419255 on 2019/6/24.
//  Copyright © 2019 UFKit. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UFRow.h"

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString * const UFKeyboardDidDoneNotification;

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
