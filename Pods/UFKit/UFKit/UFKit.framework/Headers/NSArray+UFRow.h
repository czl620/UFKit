//
//  NSArray+UFRow.h
//  Created by ChenZhangli QQ893419255 on 2019/7/4.
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
#import "UFRowTitleStyle.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (UFRow)

- (void)setTitleStyle:(nullable UFRowTitleStyle *)titleStyle valueStyle:(nullable UFTextStyle *)valueStyle editable:(BOOL)editable;

@end

NS_ASSUME_NONNULL_END
