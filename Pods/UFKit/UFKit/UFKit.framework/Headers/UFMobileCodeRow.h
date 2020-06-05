//
//  UFMobileCodeRow.h
//  Created by ChenZhangli QQ893419255 on 2019/6/26.
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
#import "UFMobileCodeStyle.h"

NS_ASSUME_NONNULL_BEGIN

@class UFMobileCodeRow;
typedef void(^UFCodeDidClicked)(__kindof UFMobileCodeRow *row, UIButton *button);

@class UFCodeRowMaker;
@interface UFMobileCodeRow : UFTextFieldRow

@property (nonatomic, copy) NSString *codeTitle;
// 验证码按钮样式
@property (nonatomic, strong, nullable) UFMobileCodeStyle *codeStyle;
// 点击获取验证码时回调
@property (nonatomic, copy) UFCodeDidClicked codeDidClicked;

+ (UFTextFieldRow *)makeTextFieldRow:(NS_NOESCAPE void(^)(UFTextFieldRowMaker *make))block NS_UNAVAILABLE;
+ (UFMobileCodeRow *)makeCodeRow:(NS_NOESCAPE void(^)(UFCodeRowMaker *make))block;

@end

@interface UFCodeRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithCodeRow:(UFMobileCodeRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFMobileCodeRow *codeRow;

@property (nonatomic, copy, readonly) UFCodeRowMaker *(^codeTitle)(NSString *codeTitle);
@property (nonatomic, copy, readonly) UFCodeRowMaker *(^codeStyle)(UFMobileCodeStyle *codeStyle);
@property (nonatomic, copy, readonly) UFCodeRowMaker *(^codeDidClicked)(UFCodeDidClicked codeDidClicked);


@end

NS_ASSUME_NONNULL_END
