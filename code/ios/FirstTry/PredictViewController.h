//// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
//  PredictViewController.h
//  FirstTry
//
//  Created by Wuyang on 4/28/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SqlData.h"
//#import "ViewController.h"
extern NSString* urladd;
@interface PredictViewController : UIViewController
@property (weak, nonatomic) IBOutlet UILabel *stocktitle;
@property (nonatomic) NSArray* chartData;
@property (weak, nonatomic) IBOutlet UILabel *open;
@property (weak, nonatomic) IBOutlet UILabel *close;
@property (weak, nonatomic) IBOutlet UILabel *high;
@property (weak, nonatomic) IBOutlet UILabel *low;
@property (weak, nonatomic) IBOutlet UILabel *vol;
@property (weak, nonatomic) IBOutlet UILabel *predict;
@end
