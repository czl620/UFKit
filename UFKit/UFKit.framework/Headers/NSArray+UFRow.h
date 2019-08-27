//
//  NSArray+UFRow.h
//  UFKit
//
//  Created by ChenZhangli QQ893419255 on 2019/7/4.
//  Copyright © 2019 UFKit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UFRowTitleStyle.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (UFRow)

- (void)setTitleStyle:(nullable UFRowTitleStyle *)titleStyle valueStyle:(nullable UFTextStyle *)valueStyle editable:(BOOL)editable;

@end

NS_ASSUME_NONNULL_END
