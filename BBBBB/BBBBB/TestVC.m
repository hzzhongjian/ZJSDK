//
//  TestVC.m
//  BBBBB
//
//  Created by 麻明康 on 2024/11/14.
//

#import "TestVC.h"

@interface TestVC ()

@property (nonatomic, readwrite) NSString *name;

@end

@implementation TestVC

//@synthesize name = _name;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    self.name = @"1000";
}

- (UIModalPresentationStyle)modalPresentationStyle
{
    return UIModalPresentationFullScreen;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
