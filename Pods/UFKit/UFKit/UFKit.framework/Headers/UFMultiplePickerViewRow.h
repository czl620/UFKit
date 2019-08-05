//
//  UFMutablePickerView.h
//  UFKit
//
//  Created by ChenZhangli on 2019/6/29.
//  Copyright © 2019 UFKIT. All rights reserved.
//

#import <UFKit/UFKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UFMultiplePickerViewRowMaker;
@interface UFMultiplePickerViewRow : UFTextFieldRow

// 选择项
@property (nonatomic, strong) NSArray <__kindof NSString *> *itemArray;

@property (nonatomic, strong) UIColor *checkmarkColor;

+ (UFMultiplePickerViewRow *)makeMultiplePickerViewRow:(NS_NOESCAPE void (^)(UFMultiplePickerViewRowMaker *make))block;

@end

@interface UFMultiplePickerViewRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithMultiplePickerViewRow:(UFMultiplePickerViewRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFMultiplePickerViewRow *pickerViewRow;

@property (nonatomic, copy, readonly) UFMultiplePickerViewRowMaker *(^itemArray)(NSArray <__kindof NSString *> * _Nullable itemArray);

@property (nonatomic, copy, readonly) UFMultiplePickerViewRowMaker *(^checkmarkColor)(UIColor *checkmarkColor);

@end


NS_ASSUME_NONNULL_END
