//
//  UFSubtitleRow.h
//  Created by Chen Zhangli on 2019/8/27.
//  Copyright © 2019 UFKit. All rights reserved.
//
//          _ _     _ _   _ _ _ _ _   _ _   _ _      _ _   _ _ _ _ _ _ __
//         /  /    /  /  /  _ _ _ /  /  /  ╱  ╱     /__/  /_ _ _   _ _ _/
//        /  /    /  /  /  /        /  / ╱  ╱      _ _         /  /
//       /  /    /  /  /  /_ _ _   /  /╱  ╱       /  /        /  /
//      /  /    /  /  /  _ _ _ /  /  / \  \      /  /        /  /
//     /  /_ __/  /  /  /        /  /   \  \    /  /        /  /
//     \ _ _ _ _ /  /__/        /__/     \__\  /__/        /__/

#import "UFRow.h"

NS_ASSUME_NONNULL_BEGIN

@class UFSubtitleRowMaker;
@interface UFSubtitleRow : UFRow

// 子标题
@property (nonatomic, copy, nullable) NSString *subtitle;
// 子标题样式
@property (nonatomic, strong, nullable) UFRowTitleStyle *subtitleStyle;

+ (UFRow *)makeRow:(NS_NOESCAPE void(^)(UFRowMaker *make))block NS_UNAVAILABLE;
+ (UFSubtitleRow *)makeSubtitleRow:(NS_NOESCAPE void(^)(UFSubtitleRowMaker *make))block;

@end

@interface UFSubtitleRowMaker : UFRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithSubtitleRow:(UFSubtitleRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFSubtitleRow *subtitleRow;

@property (nonatomic, copy, readonly) UFSubtitleRowMaker *(^subtitle)(NSString * _Nullable subtitle);
@property (nonatomic, copy, readonly) UFSubtitleRowMaker *(^subtitleStyle)(UFRowTitleStyle *subtitleStyle);

@end

NS_ASSUME_NONNULL_END
