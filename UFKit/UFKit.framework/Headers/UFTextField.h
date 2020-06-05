//
//  UFTextField.h
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

#import <UIKit/UIKit.h>
#import "UFRowInput.h"

NS_ASSUME_NONNULL_BEGIN

@class UFTextField;
@protocol UFTextFieldDelegate <NSObject>

@optional
- (void)ufk_textFieldTextDidChange:(UFTextField *)textField;

- (BOOL)ufk_textFieldShouldBeginEditing:(UFTextField *)textField;
- (void)ufk_textFieldDidBeginEditing:(UFTextField *)textField;
- (BOOL)ufk_textFieldShouldEndEditing:(UFTextField *)textField;
- (void)ufk_textFieldDidEndEditing:(UFTextField *)textField;
- (void)ufk_textFieldDidEndEditing:(UFTextField *)textField reason:(UITextFieldDidEndEditingReason)reason NS_AVAILABLE_IOS(10_0);

- (BOOL)ufk_textField:(UFTextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;;

- (BOOL)ufk_textFieldShouldClear:(UFTextField *)textField;
- (BOOL)ufk_textFieldShouldReturn:(UFTextField *)textField;

@end

@interface UFTextField : UITextField

@property (nonatomic, assign) BOOL canPerformAction;

@property(nonatomic, assign) UIEdgeInsets textEdgeInsets;

// 最大限制输入长度
@property (nonatomic, assign) NSInteger maxInputLength;
// 限制输入的类型
@property (nonatomic, assign) UFInputLimitType limitType;

@property (nonatomic, strong) UIColor *ufk_placeholderColor;

@property (nonatomic, weak) id<UFTextFieldDelegate> UFKDelegate;

@end

NS_ASSUME_NONNULL_END
