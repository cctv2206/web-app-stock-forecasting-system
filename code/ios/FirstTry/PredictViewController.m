//// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
//  PredictViewController.m
//  FirstTry
//
//  Created by Wuyang on 4/28/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#import "PredictViewController.h"

@interface PredictViewController ()

@end
@implementation PredictViewController
- (void)viewDidLoad {
    [super viewDidLoad];
    UIImage *backgroundImage = [UIImage imageNamed:@"es2.jpg"];
    UIImageView *backgroundImageView=[[UIImageView alloc]initWithFrame:self.view.frame];
    backgroundImageView.image=backgroundImage;
    [self.view insertSubview:backgroundImageView atIndex:0];
    // Do any additional setup after loading the view.
    
    SqlData* sql = [[SqlData alloc]init];
    sql.stock = urladd;
//    sql.stock = @"getHistoryPrice";
    _chartData = [sql returnHist];
    
    NSDictionary *price = _chartData[0];
    _close.text = price[@"Close"];
    _open.text = price[@"Open"];
    _high.text = price[@"High"];
    _low.text = price[@"Low"];
    _vol.text = price[@"Volume"];
    _stocktitle.text = urladd;
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
