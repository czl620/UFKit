//
//  UFActionButton.h
//  Created by ChenZhangli QQ893419255 on 2019/6/27.
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

NS_ASSUME_NONNULL_BEGIN

@class UFActionButton;
typedef void(^UFActionButtonClick)(UFActionButton *button);

@class UFActionButtonMaker;
@interface UFActionButton : UIButton

@property (nonatomic, copy) UFActionButtonClick actionButtonClick;

+(UFActionButton *)makeActionButtonWithType:(UIButtonType)buttonType
                             block:(NS_NOESCAPE void(^)(UFActionButtonMaker *make))block;

+(UFActionButton *)makeActionButton:(void(^)(UFActionButtonMaker *make))block;

@end

@interface UFActionButtonMaker : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithActionButton:(UFActionButton *)button NS_DESIGNATED_INITIALIZER;


@property (nonatomic, strong, readonly) UFActionButton *actionButton;


@property (nonatomic, copy, readonly) UFActionButtonMaker *(^titleForState)(NSString * title, UIControlState state);
@property (nonatomic, copy, readonly) UFActionButtonMaker *(^titleColorForState)(UIColor * titleColor, UIControlState state);
@property (nonatomic, copy, readonly) UFActionButtonMaker *(^imageForState)(UIImage * image, UIControlState state);
@property (nonatomic, copy, readonly) UFActionButtonMaker *(^backgroundImageForState)(UIImage * backgroundImage, UIControlState state);
@property (nonatomic, copy, readonly) UFActionButtonMaker *(^backgroundColor)(UIColor *backgroundColor);

@property (nonatomic, copy, readonly) UFActionButtonMaker *(^cornerRadius)(CGFloat cornerRadius);
@property (nonatomic, copy, readonly) UFActionButtonMaker *(^borderWidth)(CGFloat borderWidth);
@property (nonatomic, copy, readonly) UFActionButtonMaker *(^borderColor)(UIColor *borderColor);

@property (nonatomic, copy, readonly) UFActionButtonMaker *(^actionButtonClick)(UFActionButtonClick actionButtonClick);

@end

NS_ASSUME_NONNULL_END
