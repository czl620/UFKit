//
//  UFForm.h
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

#import <UIKit/UIKit.h>
#import "UFSection.h"
#import "UFActionButton.h"

NS_ASSUME_NONNULL_BEGIN

typedef struct _UFRange {
    NSUInteger secttion;
    NSUInteger row;
} UFRange;


NS_INLINE UFRange UFMakeRange(NSUInteger s, NSUInteger r) {
    UFRange range;
    range.secttion = s;
    range.row = r;
    return range;
}

typedef void(^UFActionsDidClicked)(UIButton *button, NSInteger index);


@class UFFormViewMaker;
@interface UFFormView : UIView

@property (nonatomic, strong) UIColor *separatorColor;
@property (nonatomic, assign) BOOL scrollEnabled;

/**
 添加组
 */
- (__kindof UFSection *)addSection:(__kindof UFSection *)section;
- (void)addSections:(NSArray <__kindof UFSection *> *)sections;
- (__kindof UFSection *)insertSection:(__kindof UFSection *)section atIndex:(NSInteger)index;
- (void)removeSectionAtIndex:(NSInteger)index;

@property (nonatomic, copy, readonly, nullable) NSArray <UFSection *> *sections;
@property (nonatomic, copy, readonly, nullable) NSArray <__kindof UFRow *> *rows;

/**
 刷新表单
 */
- (void)reloadData;

/**
 将表单信息转换为NSDictionary

 @return 表单信息
 */
- (NSDictionary *)toDictionary;

/**
 根据行的名称获取行

 @param name 行名
 @return 行
 */
- (__kindof UFRow *)findRowByName:(NSString *)name;

/**
 根据位置获取行

 @param range 位置（哪一组哪一行）
 @return 行
 */
- (__kindof UFRow *)findRowInRange:(UFRange)range;

/**
 统一设置表单的行高，优先级 row > section > form
 当UFRow的titleStyle不设置
 且UFSection的titleStyle不设置时，
 会统一使用表单的行高
 */
@property (nonatomic, assign) CGFloat rowHeight;

/**
 统一设置表单的标题样式，优先级 row > section > form
 当UFRow的titleStyle不设置
 且UFSection的titleStyle不设置时，
 会统一使用表单的titleStyle样式
 */
@property (nonatomic, strong) UFRowTitleStyle *titleStyle;

/**
 统一设置表单的值样式，优先级 row > section > form
 当UFRow的valueStyle不设置
 且UFSection的valueStyle不设置时，
 会统一使用表单的valueStyle样式
 */
@property (nonatomic, strong) UFTextStyle *valueStyle;


/**
 注册自定义行

@param rowClass 行(UFRow及其子类)
 @param cellClass 单元格(UFRowCell及其子类)
 */
- (void)registerRow:(Class)rowClass byCell:(Class)cellClass;

/**
 创建表单

 @param block 链式设置表单样式
 @return 表单
 */
+ (UFFormView *)makeFormView:(NS_NOESCAPE void(^)(UFFormViewMaker *make))block;


@end


@interface UFFormViewMaker : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFormView:(UFFormView *)formView NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFFormView *formView;

@property (nonatomic, copy, readonly) UFFormViewMaker *(^rowHeight)(CGFloat rowHeight);
@property (nonatomic, copy, readonly) UFFormViewMaker *(^titleStyle)(UFRowTitleStyle *titleStyle);
@property (nonatomic, copy, readonly) UFFormViewMaker *(^valueStyle)(UFTextStyle *valueStyle);

@property (nonatomic, copy, readonly) UFFormViewMaker *(^separatorColor)(UIColor *separatorColor);

@property (nonatomic, copy, readonly) UFFormViewMaker *(^addSection)(__kindof UFSection *section);
@property (nonatomic, copy, readonly) UFFormViewMaker *(^insertSection)(__kindof UFSection *section, NSInteger index);
@property (nonatomic, copy, readonly) UFFormViewMaker *(^removeSectionAtIndex)(NSInteger index);

@property (nonatomic, copy, readonly) UFFormViewMaker *(^addCancelButton)(UFActionButton *cancelButton);
@property (nonatomic, copy, readonly) UFFormViewMaker *(^addSubmitButton)(UFActionButton *submitButton);

@property (nonatomic, copy, readonly) UFFormViewMaker *(^addToSuperView)(UIView *superView);

@property (nonatomic, copy, readonly) UFFormViewMaker *(^scrollEnabled)(BOOL scrollEnabled);

@property (nonatomic, copy, readonly) UFFormViewMaker *(^registerRow)(Class rowClass, Class cellClass);

@end

NS_ASSUME_NONNULL_END
