//
//  MyRowCell.m
//  UFKitDemo
//
//  Created by Chen Zhangli on 2019/9/23.
//  Copyright © 2019 Uniauto. All rights reserved.
//

#import "MyRowCell.h"
#import "MyRow.h"

@interface MyRowCell ()

@property (nonatomic, strong) MyRow *myRow;

@end

@implementation MyRowCell


- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {

        // 自定义UI
        _myLabel = [[UILabel alloc] initWithFrame:CGRectMake(100, 0, 100, 40)];
        _myLabel.backgroundColor = [UIColor redColor];
        [self.contentView addSubview:_myLabel];
    }
    return self;
}

- (void)setRow:(__kindof UFRow *)row {
    _myRow = (MyRow *)row;
    [super setRow:row];

    self.myLabel.text = _myRow.myCustom;
}

- (void)setupConstraints {
    [super setupConstraints];
    // 添加你的自定义约束
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

@end
