//// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
//  ViewController.m
//  FirstTry
//
//  Created by Wuyang on 4/25/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#import "ViewController.h"
@interface ViewController ()
@end
NSString* urladd;

@implementation ViewController
- (IBAction)action_TranValue:(id)sender {
    urladd = _stockQuery.text;
    
}
- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
//    [self.view setBackgroundColor:[UIColor colorWithPatternImage:[UIImage imageNamed:@"es.jpg"]]];
    UIImage *backgroundImage = [UIImage imageNamed:@"es2.jpg"];
    UIImageView *backgroundImageView=[[UIImageView alloc]initWithFrame:self.view.frame];
    backgroundImageView.image=backgroundImage;
    [self.view insertSubview:backgroundImageView atIndex:0];
//    [_b_history.layer setMasksToBounds:YES];
//    [_b_predict.layer setMasksToBounds:YES];
//    [_b_history.layer setCornerRadius:10.0];
//    [_b_predict.layer setCornerRadius:10.0];
//    [_b_history.layer setBorderWidth:2.0];
//    [_b_predict.layer setBorderWidth:2.0];
//    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
//    CGColorRef colorref = CGColorCreate(colorSpace, (CGFloat[]){1,0,0,1});
//    [_b_history.layer setBorderColor:colorref];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
