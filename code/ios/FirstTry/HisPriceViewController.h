//// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
//  HisPriceViewController.h
//  FirstTry
//
//  Created by Wuyang on 4/26/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BBStockChart.h"
#import "ViewController.h"
#import "SqlData.h"
extern NSString* urladd;

@interface HisPriceViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIScrollView *scrollview;
@property (weak, nonatomic) IBOutlet UILabel *show;
@property (nonatomic) BBChartView* chartView;
@property (nonatomic) NSArray* chartData;
@end
