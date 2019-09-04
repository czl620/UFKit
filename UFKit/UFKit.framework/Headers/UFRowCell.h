//
//  UFRowCell.h
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
#import "UFRow.h"

NS_ASSUME_NONNULL_BEGIN

@interface UFRowCell : UITableViewCell

// 标题
@property (nonatomic, strong) UILabel *titleLabel;
// 图标
@property (nonatomic, strong) UIImageView *iconView;
// 分割线
@property (nonatomic, strong) UIView *seperatorView;

// 行，子类可能需要重写set方法，以便添加row的属性值对应到单元格的每个UI组件中
@property (nonatomic, strong) __kindof UFRow *row;

// 添加/修改约束条件,你也可以在初始化方法中添加自定义的约束条件
- (void)setupConstraints;

@end

NS_ASSUME_NONNULL_END
