//
//  UFPlateNumberRow.h
//  UFKit
//
//  Created by ChenZhangli QQ893419255 on 2019/6/28.
//  Copyright © 2019 UFKit. All rights reserved.
//

#import <UFKit/UFKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UFPlateNumberRowMaker;
@interface UFPlateNumberRow : UFTextFieldRow

@property (nonatomic, strong) UIColor *color;

+ (UFPlateNumberRow *)makePlateNumberRow:(NS_NOESCAPE void(^)(UFPlateNumberRowMaker *make))block;

@end

@interface UFPlateNumberRowMaker : UFTextFieldRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithTextFieldRow:(UFTextFieldRow *)row NS_UNAVAILABLE;
- (instancetype)initWithPlateNumberRow:(UFPlateNumberRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFPlateNumberRow *plateNumberRow;

@property (nonatomic, copy, readonly) UFPlateNumberRowMaker *(^color)(UIColor *color);

@end

NS_ASSUME_NONNULL_END
