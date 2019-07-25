//
//  UFAvatarRow.h
//  UFKit
//
//  Created by ChenZhangli QQ893419255 on 2019/6/25.
//  Copyright © 2019 UFKit. All rights reserved.
//

#import "UFRow.h"

NS_ASSUME_NONNULL_BEGIN

@class UFAvatarRow;
typedef void(^UFAvatarDidSelected)(__kindof UFAvatarRow *row, UIImageView *avatarView);

@class UFAvatarRowMaker;
@interface UFAvatarRow : UFRow

// 头像圆角
@property (nonatomic, assign) CGFloat cornerRadius;

@property (nonatomic, strong) UIImage *avatarImage;

// 点击头像时回调
@property (nonatomic, copy) UFAvatarDidSelected avatarDidSelected;

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
