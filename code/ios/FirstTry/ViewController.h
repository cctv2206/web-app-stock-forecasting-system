//// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
//  ViewController.h
//  FirstTry
//
//  Created by Wuyang on 4/25/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#import <UIKit/UIKit.h>
extern NSString* urladd;
@interface ViewController : UIViewController
@property (weak, nonatomic) IBOutlet UILabel *query;
@property (weak, nonatomic) IBOutlet UIButton *b_history;
@property (weak, nonatomic) IBOutlet UIButton *b_predict;
@property (weak, nonatomic) IBOutlet UITextField *stockQuery;

@end

