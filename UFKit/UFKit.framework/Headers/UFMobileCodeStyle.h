//
//  UFMobileCodeStyle.h
//  UFKit
//
//  Created by ChenZhangli on 2019/6/29.
//  Copyright © 2019 UFKIT. All rights reserved.
//

#import "UFTextStyle.h"

NS_ASSUME_NONNULL_BEGIN

@class UFMobileCodeStyleMaker;
@interface UFMobileCodeStyle : UFTextStyle

@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, assign) CGFloat cornerRadius;

@property (nonatomic, strong) UIColor *separatorColor;

+ (UFMobileCodeStyle *)makeMobileCodeStyle:(NS_NOESCAPE void(^)(UFMobileCodeStyleMaker *make))block;

@end

@interface UFMobileCodeStyleMaker : UFRowTextStyleMaker

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithTextStyle:(UFTextStyle *)textStyle NS_UNAVAILABLE;
- (instancetype)initWithMobileCodeStyle:(UFMobileCodeStyle *)mobileCodeStyle NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFMobileCodeStyle *mobileCodeStyle;

@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^backgroundColor)(UIColor *backgroundColor);
@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^cornerRadius)(CGFloat cornerRadius);

@property (nonatomic, copy, readonly) UFMobileCodeStyleMaker *(^separatorColor)(UIColor *separatorColor);

@end

NS_ASSUME_NONNULL_END
