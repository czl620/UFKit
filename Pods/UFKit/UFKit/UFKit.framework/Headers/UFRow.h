//
//  UFRow.h
//  Created by ChenZhangli QQ893419255 on 2019/6/21.
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
#import "UFRowValue.h"
#import "UFRowTitleStyle.h"
#import "UFImageStyle.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UFRowAccessoryType) {
    UFRowAccessoryNone = UITableViewCellAccessoryNone,
    UFRowAccessoryDisclosureIndicator = UITableViewCellAccessoryDisclosureIndicator,
    UFRowAccessoryDetailDisclosureButton = UITableViewCellAccessoryDetailDisclosureButton,
    UFRowAccessoryUITableViewCellAccessoryCheckmark = UITableViewCellAccessoryCheckmark,
    UFRowAccessoryDetailButton = UITableViewCellAccessoryDetailButton,
    UFRowAccessorySpace
};


@class UFRow;
typedef void(^UFValueDidChanged)(__kindof UFRow *row, NSString *value);
typedef void(^UFRowDidSelected)(__kindof UFRow *row);
typedef void(^UFRowAccessoryDidSelected)(__kindof UFRow *row, UIView *accessoryView);


@class UFRowMaker;
@interface UFRow : NSObject

// 行名称 (同一表单保证其唯一性)
@property (nonatomic, copy, nullable) NSString *name;

// 图标
@property (nonatomic, strong, nullable) id image;
@property (nonatomic, strong, nullable) UIImage *placeholderImage __attribute__((deprecated("已过期, 建议使用UFImageStyle")));
@property (nonatomic, assign) CGSize imageSize __attribute__((deprecated("已过期, 建议使用UFImageStyle")));

@property (nonatomic, strong, nullable) UFImageStyle *imageStyle;

// 标题
@property (nonatomic, copy, nullable) NSString *title;
// 标题样式
@property (nonatomic, strong, nullable) UFRowTitleStyle *titleStyle;
// 富文本标题
@property (nonatomic, copy, nullable) NSAttributedString *attributedTitle;

// 值
@property (nonatomic, copy, nullable) NSString *value;
// 值样式
@property (nonatomic, strong, nullable) UFTextStyle *valueStyle;

// 行高
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, strong) UIColor *seperatorColor;

@property (nonatomic, assign) UFRowAccessoryType accessoryType;
@property (nonatomic, strong) UIImage *accessoryImage;

// 必填项，标题前加红色*，你也可以使用attributedTitle自定义
@property (nonatomic, assign) BOOL isRequired;

// 扩展字段
@property (nonatomic, strong) id ext;

// 值发生改变时回调
@property (nonatomic, copy) UFValueDidChanged valueDidChanged;
// 行点击时回调
@property (nonatomic, copy) UFRowDidSelected rowDidSelected;

@property (nonatomic, copy) UFRowAccessoryDidSelected accessoryDidSelected;


+ (__kindof UFRow *)makeRow:(NS_NOESCAPE void(^)(UFRowMaker *make))block;

@end


@interface UFRowMaker : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFRow *row;

@property (nonatomic, copy, readonly) UFRowMaker *(^image)(id image);
@property (nonatomic, copy, readonly) UFRowMaker *(^placeholderImage)(UIImage *placeholderImage) __attribute__((deprecated("已过期, 建议使用UFImageStyle")));
@property (nonatomic, copy, readonly) UFRowMaker *(^imageSize)(CGSize imageSize) __attribute__((deprecated("已过期, 建议使用UFImageStyle")));

@property (nonatomic, copy, readonly) UFRowMaker *(^imageStyle)(UFImageStyle *imageStyle);

@property (nonatomic, copy, readonly) UFRowMaker *(^name)(NSString *name);

@property (nonatomic, copy, readonly) UFRowMaker *(^title)(NSString * _Nullable title);
@property (nonatomic, copy, readonly) UFRowMaker *(^titleStyle)(UFRowTitleStyle *titleStyle);
@property (nonatomic, copy, readonly) UFRowMaker *(^attributedTitle)(NSAttributedString * _Nullable attributedTitle);

@property (nonatomic, copy, readonly) UFRowMaker *(^value)(NSString * _Nullable value);
@property (nonatomic, copy, readonly) UFRowMaker *(^valueStyle)(UFTextStyle *valueStyle);

@property (nonatomic, copy, readonly) UFRowMaker *(^height)(CGFloat height);
@property (nonatomic, copy, readonly) UFRowMaker *(^seperatorColor)(UIColor *seperatorColor);

@property (nonatomic, copy, readonly) UFRowMaker *(^accessoryType)(UFRowAccessoryType accessoryType);
@property (nonatomic, copy, readonly) UFRowMaker *(^accessoryImage)(UIImage *accessoryImage);

@property (nonatomic, copy, readonly) UFRowMaker *(^isRequired)(BOOL isRequired);

@property (nonatomic, copy, readonly) UFRowMaker *(^ext)(id ext);

@property (nonatomic, copy, readonly) UFRowMaker *(^valueDidChanged)(UFValueDidChanged valueDidChanged);
@property (nonatomic, copy, readonly) UFRowMaker *(^rowDidSelected)(UFRowDidSelected rowDidSelected);
@property (nonatomic, copy, readonly) UFRowMaker *(^accessoryDidSelected)(UFRowAccessoryDidSelected accessoryDidSelected);

@end

NS_ASSUME_NONNULL_END
