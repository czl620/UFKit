//
//  UFPickerViewRow.h
//  UFKit
//
//  Created by ChenZhangli QQ893419255 on 2019/6/24.
//  Copyright © 2019 UFKit. All rights reserved.
//

#import "UFTextFieldRow.h"

NS_ASSUME_NONNULL_BEGIN

@class UFPickerViewRowMaker;
@interface UFPickerViewRow : UFTextFieldRow

// 选择项
@property (nonatomic, strong) NSArray <__kindof NSString *> *itemArray;

+ (UFPickerViewRow *)makePickerViewRow:(NS_NOESCAPE void(^)(UFPickerViewRowMaker *make))block;

@end

@interface UFPickerViewRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithPickerViewRow:(UFPickerViewRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFPickerViewRow *pickerViewRow;

@property (nonatomic, copy, readonly) UFPickerViewRowMaker *(^itemArray)(NSArray <__kindof NSString *> * _Nullable itemArray);

@end

NS_ASSUME_NONNULL_END
