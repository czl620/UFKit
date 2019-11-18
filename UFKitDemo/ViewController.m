//
//  ViewController.m
//  UFKitDemo
//
//  Created by ChenZhangli QQ893419255 on 2019/6/27.
//  Copyright © 2019 UFKIT. All rights reserved.
//

#import "ViewController.h"
#import <UFKit/UFKit.h>
#import "Masonry.h"
#import "MyRow.h"
#import "MyRowCell.h"

@interface ViewController () <UFCustomPickerViewRowDelegate>

@property (nonatomic, copy) NSArray *customArray;
@property (nonatomic, copy) NSDictionary *currentDict;
@property (nonatomic, copy) NSString *currentStr;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    NSLog(@"版本：%@",UFKIT_VERSION);

    _customArray = @[@{@"title":@"A",
                       @"children":@[@"a1",
                                     @"a2",
                                     @"a3"]
                       },
                     @{@"title":@"B",
                       @"children":@[@"b1",
                                     @"b2",
                                     @"b3"]
                       },
                     @{@"title":@"C",
                       @"children":@[@"c1",
                                     @"c2",
                                     @"c3"]
                       },
                     ];
    _currentDict = _customArray[0];
    _currentStr = _currentDict[@"children"][0];


    __weak typeof(self) weakSelf = self;
    __block UFFormView *formView = [UFFormView makeFormView:^(UFFormViewMaker * _Nonnull make) {
        make
        .registerRow([MyRow class], [MyRowCell class])
        .rowHeight(50)
        .addSection([UFSection makeSection:^(UFSectionMaker * _Nonnull make) {
            make

            // 标题样式设置
            .titleStyle([UFRowTitleStyle makeTitleStyle:^(UFRowTitleStyleMaker * _Nonnull make) {
                make
                .width(100)
                .font([UIFont systemFontOfSize:15])
                .textAlignment(NSTextAlignmentLeft);
            }])

            // 值样式设置
            .valueStyle([UFTextStyle makeTextStyle:^(UFRowTextStyleMaker * _Nonnull make) {
                make
                .font([UIFont systemFontOfSize:15])
                .color([UIColor darkTextColor])
                .textAlignment(NSTextAlignmentRight);
            }])

            // 使用block形式添加自定义行
            .addRowWithBlock(^__kindof UFRow * _Nonnull{
                // 自定义ROW,使用自定义字段
                MyRow *myRow = [[MyRow alloc] init];
                myRow.title = @"我的自定义1";
                myRow.name = @"my1";
                myRow.accessoryType = UFRowAccessorySpace;
                myRow.myCustom = @"我是自定义Row";
                return myRow;
            })

            // 添加自定义行
            .addRow([MyRow makeRow:^(UFRowMaker * _Nonnull make) {
                // 自定义ROW，使用ext属性
                make
                .title(@"我的自定义2")
                .name(@"name1")
                .accessoryType(UFRowAccessorySpace)
                .ext(@"我是自定义Row");
            }])

            // 添加头像
            .addRow([UFAvatarRow makeAvatarRow:^(UFAvatarRowMaker * _Nonnull make) {
                make
                .cornerRadius(30)
                .avatarImage([UIImage imageNamed:@"touxiang"])
                .avatarDidSelected(^(__kindof UFAvatarRow * _Nonnull row, UIImageView * _Nonnull avatarView) {
                    NSLog(@"你点击了头像");
                    [weakSelf ufk_pickerImageFromView:weakSelf.view forResult:^(UIImage * _Nonnull image) {
                        if (image) {
                            row.avatarImage = image;
                            row.value = nil;
                            avatarView.image = image;
                        }
                    }];
                })
                .title(@"头像")
                .value(@"http://img0.imgtn.bdimg.com/it/u=2572957358,1108684168&fm=26&gp=0.jpg")
                .name(@"avatar")
                .accessoryType(UFRowAccessorySpace);
            }])

            // 添加姓名
            .addRow([UFTextFieldRow makeTextFieldRow:^(UFTextFieldRowMaker * _Nonnull make) {
                make
                .maxLength(4)
                .title(@"姓名")
                .value(@"")
                .name(@"name")
                .accessoryType(UFRowAccessorySpace);
            }])

            // 添加性别
            .addRow([UFRadioGroupRow makeRadioGroupRow:^(UFRadioGroupRowMaker * _Nonnull make) {
                make
                .itemArray(@[@"男",@"女"])
                .title(@"性别")
                .value(@"男")
                .name(@"gender")
                .accessoryType(UFRowAccessorySpace);
            }])

            // 添加联系方式
            .addRow([UFTextFieldRow makeTextFieldRow:^(UFTextFieldRowMaker * _Nonnull make) {
                make
                .limitType(UFInputLimitTypeMobile)
                .isRequired(YES)
                .title(@"联系方式")
                .name(@"mobile")
                .accessoryType(UFRowAccessorySpace);
            }])

            // 添加手机验证码
            .addRow([UFMobileCodeRow makeCodeRow:^(UFCodeRowMaker * _Nonnull make) {
                make
                .codeStyle([UFMobileCodeStyle makeMobileCodeStyle:^(UFMobileCodeStyleMaker * _Nonnull make) {

                }])
                .codeDidClicked(^(__kindof UFMobileCodeRow * _Nonnull row, UIButton * _Nonnull button) {
                    NSLog(@"点了了获取验证码");
                    [button ufk_countDown:60];
                })
                .maxLength(4)
                .limitType(UFInputLimitTypeNumbers)
                .title(@"验证码")
                .name(@"code")
                .accessoryType(UFRowAccessorySpace);
            }])

            // 添加单选技能
            .addRow([UFPickerViewRow makePickerViewRow:^(UFPickerViewRowMaker * _Nonnull make) {
                make
                .itemArray(@[@"iOS",@"macOS",@"swift",@"iPhone",@"iPad",@"iPod"])
                .title(@"技能")
                .value(@"swift")
                .name(@"skills")
                .accessoryType(UFRowAccessoryDisclosureIndicator);
            }])

            // 添加多选爱好
            .addRow([UFMultiplePickerViewRow makeMultiplePickerViewRow:^(UFMultiplePickerViewRowMaker * _Nonnull make) {
                make
                .itemArray(@[@"看电影",@"旅游",@"看书",@"打游戏",@"篮球",@"足球",@"其他"])
                .title(@"爱好")
                .value(@"打游戏,其他")
                .name(@"hobby")
                .accessoryType(UFRowAccessoryDisclosureIndicator);
            }])

            // 添加生日
            .addRow([UFDatePickerRow makeDatePickerRow:^(UFDatePickerRowMaker * _Nonnull make) {
                make
                .datePickerMode(UIDatePickerModeDate)
                .dateFormat(@"yyyy-MM-dd")
                .title(@"生日")
                .name(@"birthday")
                .value(@"")
                .accessoryType(UFRowAccessoryDisclosureIndicator)
                .valueDidChanged(^(__kindof UFRow * _Nonnull row, NSString * _Nonnull value) {
                    
                });
            }])

            // 添加三级地址选择
            .addRow([UFAreaPickerRow makeAreaPickerRow:^(UFAreaPickerRowMaker * _Nonnull make) {
                make
                .areaSeparator(@",")
                .title(@"地址")
                .name(@"address")
                .accessoryType(UFRowAccessoryDisclosureIndicator);
            }])

            // 添加免打扰开关
            .addRow([UFSwitchRow makeSwitchRow:^(UFSwitchRowMaker * _Nonnull make) {
                make
                .tintColor([UIColor redColor])
                .title(@"免打扰")
                .value(SWITCH_ON)
                .name(@"allow")
                .accessoryType(UFRowAccessorySpace)
                .valueDidChanged(^(__kindof UFRow * _Nonnull row, __kindof NSString * _Nonnull value) {
                    if ([row.value boolValue]) {
                        NSLog(@"开");
                    } else {
                        NSLog(@"关");
                    }
                });
            }])

            // 添加机动车车牌
            .addRow([UFPlateNumberRow makePlateNumberRow:^(UFPlateNumberRowMaker * _Nonnull make) {
                make
                .title(@"车牌号")
                .value(@"鲁A12345")
                .titleStyle([UFRowTitleStyle makeTitleStyle:^(UFRowTitleStyleMaker * _Nonnull make) {
                    make
                    .width([UIScreen mainScreen].bounds.size.width - 175)
                    .textAlignment(NSTextAlignmentLeft);
                }])
                .name(@"plate")
                .accessoryType(UFRowAccessorySpace);
            }])

            // 添加自定义选择器
            .addRow([UFCustomPickerViewRow makeCustomPickerViewRow:^(UFCustomPickerViewRowMaker * _Nonnull make) {
                make.
                delegate(weakSelf)
                .valueDidSelected(^(__kindof UFCustomPickerViewRow * _Nonnull row, UITextField * _Nonnull textField) {
                    NSString *value = [NSString stringWithFormat:@"%@%@",weakSelf.currentDict[@"title"],weakSelf.currentStr];
                    row.value = value;
                    textField.text = value;
                })
                .title(@"自定义选择器")
                .name(@"custom")
                .accessoryType(UFRowAccessoryDisclosureIndicator);;
            }])

            // 添加带有子标题的支付
            .addRow([UFSubtitleRow makeSubtitleRow:^(UFSubtitleRowMaker * _Nonnull make) {
                make
                .subtitle(@"推荐支付宝用户使用")
                .subtitleStyle([UFRowTitleStyle makeTitleStyle:^(UFRowTitleStyleMaker * _Nonnull make) {
                    make
                    .width(140)
                    .font([UIFont systemFontOfSize:12])
                    .color([UIColor lightGrayColor]);
                }])
                .accessoryImage([UIImage imageNamed:@"checked"])
                .height(80)
                .title(@"支付宝")
                .image([UIImage imageNamed:@"alipay"]);
            }])

            // 添加多行个人简介
            .addRow([UFTextViewRow makeTextViewRow:^(UFTextViewRowMaker * _Nonnull make) {
                make
                .maxLength(0)
                .title(@"个人简介")
                .value(@"苹果公司是美国一家高科技公司。由史蒂夫·乔布斯、斯蒂夫·沃兹尼亚克和罗·韦恩等人于1976年4月1日创立，总部位于加利福尼亚州的库比蒂诺")
                .name(@"introduction")
                .accessoryType(UFRowAccessorySpace);
            }]);
        }])

        // 添加提交按钮
        .addSubmitButton([UFActionButton makeActionButton:^(UFActionButtonMaker * _Nonnull make) {
            make
            .titleForState(@"提交", UIControlStateNormal)
            .titleColorForState([UIColor whiteColor], UIControlStateNormal)
            .cornerRadius(17)
            .backgroundColor([UIColor redColor])
            .actionButtonClick(^(UFActionButton * _Nonnull button) {
                NSLog(@"提交的信息：\n%@",[formView toDictionary]);
            });
        }])
        .addToSuperView(self.view);
    }];

    [formView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.mas_equalTo(self.view);
    }];

    
    formView.subviews[0].backgroundColor = [UIColor blueColor];

    // 查找某一行
//    UFRow *row_range = [formView findRowInRange:UFMakeRange(0, 9)];
//    UFRow *row_name = [formView findRowByName:@"name"];


}

- (NSInteger)numberOfComponentsInPickerViewRow:(nonnull UFCustomPickerViewRow *)pickerViewRow {
    return 2;
}

- (NSInteger)pickerViewRow:(nonnull UFCustomPickerViewRow *)pickerViewRow numberOfRowsInComponent:(NSInteger)component {
    if (component == 0) {
        return [_customArray count];
    }
    return ((NSArray *)(_currentDict[@"children"])).count;
}

- (nonnull NSString *)pickerViewRow:(nonnull UFCustomPickerViewRow *)pickerViewRow titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    if (component == 0) {
        return _customArray[row][@"title"];
    }
    return ((NSArray *)(_currentDict[@"children"]))[row];
}

- (void)pickerViewRow:(nonnull UFCustomPickerViewRow *)pickerViewRow didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    if (component == 0) {
        _currentDict = _customArray[row];
        _currentStr = _currentDict[@"children"][0];
    } else {
        _currentStr = _currentDict[@"children"][row];
    }
}


@end
