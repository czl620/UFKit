//
//  UFRowImageStyle.h
//  UFKit
//
//  Created by Chen Zhangli on 2019/9/26.
//  Copyright © 2019 Uniauto. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class UFImageStyleMaker;
@interface UFImageStyle : NSObject

@property (nonatomic, strong, nullable) UIImage *placeholderImage;
@property (nonatomic, assign) CGSize imageSize;
@property (nonatomic, assign) CGFloat cornerRadius;

+ (UFImageStyle *)makeImageStyle:(NS_NOESCAPE void(^)(UFImageStyleMaker *make))block;

@end


@interface UFImageStyleMaker : NSObject

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithImageStyle:(UFImageStyle *)imageStyle NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) UFImageStyle *imageStyle;

@property (nonatomic, copy, readonly) UFImageStyleMaker *(^placeholderImage)(UIImage *placeholderImage);
@property (nonatomic, copy, readonly) UFImageStyleMaker *(^imageSize)(CGSize imageSize);
@property (nonatomic, copy, readonly) UFImageStyleMaker *(^cornerRadius)(CGFloat cornerRadius);

@end

NS_ASSUME_NONNULL_END
