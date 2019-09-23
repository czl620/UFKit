//
//  UFSectionStyle.h
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

#import "UFTextStyle.h"

NS_ASSUME_NONNULL_BEGIN

@class UFSectionStyleMaker;
@interface UFSectionStyle : UFTextStyle

// 分组高度
@property (nonatomic, assign) CGFloat height;
// 文本内容
@property (nonatomic, copy) NSString *text;
// 富文本内容
@property (nonatomic, copy) NSAttributedString *attributedText;
// 行数
@property (nonatomic, assign) NSInteger numberOfLines;

+ (UFSectionStyle *)makeSectionStyle:(NS_NOESCAPE void(^)(UFSectionStyleMaker *make))block;

@end


@interface UFSectionStyleMaker : UFRowTextStyleMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithTextStyle:(UFTextStyle *)titleStyle NS_UNAVAILABLE;
- (instancetype)initWithSectionStyle:(UFSectionStyle *)sectionStyle NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFSectionStyle *sectionStyle;

@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^height)(CGFloat height);
@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^text)(NSString *text);
@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^attributedText)(NSAttributedString *attributedText);
@property (nonatomic, copy, readonly) UFSectionStyleMaker *(^numberOfLines)(NSInteger numberOfLines);

@end

NS_ASSUME_NONNULL_END
