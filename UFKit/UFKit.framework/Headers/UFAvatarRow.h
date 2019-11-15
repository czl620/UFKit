//
//  UFAvatarRow.h
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

#import "UFRow.h"

NS_ASSUME_NONNULL_BEGIN

@class UFAvatarRow;
typedef void(^UFAvatarDidSelected)(__kindof UFAvatarRow *row, UIImageView *avatarView);

@class UFAvatarRowMaker;
@interface UFAvatarRow : UFRow

// 头像圆角
@property (nonatomic, assign) CGFloat cornerRadius;

/*
 *  头像，当网络图片作为头像时，加载失败情况下可以作为占位头像
 *  如果不使用网络图片仅使用UIImage作为头像，需将value设为nil
 */
@property (nonatomic, strong) UIImage *avatarImage;

// 点击头像时回调
@property (nonatomic, copy) UFAvatarDidSelected avatarDidSelected;

+ (UFRow *)makeRow:(NS_NOESCAPE void(^)(UFRowMaker *make))block NS_UNAVAILABLE;
+ (UFAvatarRow *)makeAvatarRow:(NS_NOESCAPE void(^)(UFAvatarRowMaker *make))block;

@end

@interface UFAvatarRowMaker : UFRowMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithRow:(UFRow *)row NS_UNAVAILABLE;
- (instancetype)initWithAvatarRow:(UFAvatarRow *)row NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFAvatarRow *avatarRow;

@property (nonatomic, copy, readonly) UFAvatarRowMaker *(^cornerRadius)(CGFloat cornerRadius);
@property (nonatomic, copy, readonly) UFAvatarRowMaker *(^avatarImage)(UIImage *avatarImage);
@property (nonatomic, copy, readonly) UFAvatarRowMaker *(^avatarDidSelected)(UFAvatarDidSelected avatarDidSelected);

@end

NS_ASSUME_NONNULL_END
