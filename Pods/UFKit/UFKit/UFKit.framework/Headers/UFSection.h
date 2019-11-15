//
//  UFSection.h
//  Created by ChenZhangli QQ893419255 on 2019/6/25.
//  Copyright © 2019 UFKit. All rights reserved.
//
//          _ _     _ _   _ _ _ _ _   _ _    _ _     _ _   _ _ _ _ _ _ __
//         /  /    /  /  /  _ _ _ /  /  /   ╱  ╱    /__/  /_ _ _   _ _ _/
//        /  /    /  /  /  /        /  /  ╱  ╱     _ _         /  /
//       /  /    /  /  /  /_ _ _   /  / ╱  ╱      /  /        /  /
//      /  /    /  /  /  _ _ _ /  /  / \  \      /  /        /  /
//     /  /_ __/  /  /  /        /  /   \  \    /  /        /  /
//     \ _ _ _ _ /  /__/        /__/     \__\  /__/        /__/

#import <Foundation/Foundation.h>
#import "UFSectionStyle.h"
#import "UFRow.h"

NS_ASSUME_NONNULL_BEGIN

@class UFSectionMaker;
@interface UFSection : NSObject

/**
 添加行

 @param row 行
 */
- (__kindof UFRow *)addRow:(__kindof UFRow *)row;
- (void)addRows:(NSArray <__kindof UFRow *> *)rows;
- (__kindof UFRow *)insertRow:(__kindof UFRow *)row atIndex:(NSInteger)index;
- (void)removeRowAtIndex:(NSInteger)index;

- (__kindof UFRow *)addRowWithBlock:(__kindof UFRow *(^)(void))block;

@property (nonatomic, copy, readonly, nullable) NSArray<UFRow *> *rows;

/**
 页眉样式
 */
@property (nonatomic, strong, nullable) UFSectionStyle *headerStyle;

/**
 页脚样式
 */
@property (nonatomic, strong, nullable) UFSectionStyle *footerStyle;

/**
 设置行高
 当UFRow的height不设置时，会统一使用组的行高
 反之使用UFRow的height
 */
@property (nonatomic, assign) CGFloat rowHeight;

/**
 设置标题样式
 当UFRow的titleStyle不设置时，会统一使用组的行高
 反之使用UFRow的titleStyle
 */
@property (nonatomic, strong, nullable) UFRowTitleStyle *titleStyle;

/**
 设置值样式
 当UFRow的valueStyle不设置时，会统一使用组的行高
 反之使用UFRow的valueStyle
 */
@property (nonatomic, strong, nullable) UFTextStyle *valueStyle;


/**
 创建组

 @param block 链式设置组样式
 @return 组
 */
+ (UFSection *)makeSection:(NS_NOESCAPE void(^)(UFSectionMaker *make))block;

@end


@interface UFSectionMaker : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSection:(UFSection *)section NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFSection *section;

@property (nonatomic, copy, readonly) UFSectionMaker *(^headerStyle)(UFSectionStyle *headerStyle);
@property (nonatomic, copy, readonly) UFSectionMaker *(^footerStyle)(UFSectionStyle *footerStyle);

@property (nonatomic, copy, readonly) UFSectionMaker *(^rowHeight)(CGFloat rowHeight);
@property (nonatomic, copy, readonly) UFSectionMaker *(^titleStyle)(UFRowTitleStyle *titleStyle);
@property (nonatomic, copy, readonly) UFSectionMaker *(^valueStyle)(UFTextStyle *valueStyle);

@property (nonatomic, copy, readonly) UFSectionMaker *(^addRow)(__kindof UFRow *row);
@property (nonatomic, copy, readonly) UFSectionMaker *(^addRowWithBlock)(__kindof UFRow *(^)(void));
@property (nonatomic, copy, readonly) UFSectionMaker *(^insertRow)(__kindof UFRow *row, NSInteger index);
@property (nonatomic, copy, readonly) UFSectionMaker *(^removeRowAtIndex)(NSInteger index);

@end


NS_ASSUME_NONNULL_END
