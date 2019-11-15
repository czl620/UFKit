//
//  UFCustomPickerViewRow.h
//  Created by Chen Zhangli on 2019/8/1.
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

@class UFCustomPickerViewRow;
@protocol UFCustomPickerViewRowDelegate <NSObject>

@required
- (NSInteger)numberOfComponentsInPickerViewRow:(UFCustomPickerViewRow *)pickerViewRow;
- (NSInteger)pickerViewRow:(UFCustomPickerViewRow *)pickerViewRow numberOfRowsInComponent:(NSInteger)component;
- (NSString *)pickerViewRow:(UFCustomPickerViewRow *)pickerViewRow titleForRow:(NSInteger)row forComponent:(NSInteger)component;
- (void)pickerViewRow:(UFCustomPickerViewRow *)pickerViewRow didSelectRow:(NSInteger)row inComponent:(NSInteger)component;

@end

typedef void(^UFCustomPickerSelectDidFinished)(__kindof UFCustomPickerViewRow *row, UITextField *textField);

@class UFCustomPickerViewRowMaker;
@interface UFCustomPickerViewRow : UFTextFieldRow

@property (nonatomic, weak) id <UFCustomPickerViewRowDelegate> delegate;

// 选择完成后点击确定按钮时回调
@property (nonatomic, copy) UFCustomPickerSelectDidFinished valueDidSelected;

+ (UFTextFieldRow *)makeTextFieldRow:(NS_NOESCAPE void(^)(UFTextFieldRowMaker *make))block NS_UNAVAILABLE;
+ (UFCustomPickerViewRow *)makeCustomPickerViewRow:(NS_NOESCAPE void(^)(UFCustomPickerViewRowMaker *make))block;

@end


@interface UFCustomPickerViewRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithCustomPickerViewRow:(UFCustomPickerViewRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFCustomPickerViewRow *pickerViewRow;

@property (nonatomic, copy, readonly) UFCustomPickerViewRowMaker *(^delegate)(id <UFCustomPickerViewRowDelegate> _Nullable delegate);

@property (nonatomic, copy, readonly) UFCustomPickerViewRowMaker *(^valueDidSelected)(UFCustomPickerSelectDidFinished valueDidSelected);

@end

NS_ASSUME_NONNULL_END
