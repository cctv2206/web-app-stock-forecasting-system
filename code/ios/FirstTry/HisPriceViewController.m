//// Writtern by Wuyang Zhang
//Debugged by Wuyang Zhang
//Test by Wuyang Zhang
//  HisPriceViewController.m
//  FirstTry
//
//  Created by Wuyang on 4/26/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#import "HisPriceViewController.h"
#define Float(a) (((NSNumber*)a).floatValue)

@interface HisPriceViewController ()

@end

@implementation HisPriceViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    //init stock graph
    _chartView = [[BBChartView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.height, self.view.frame.size.width)];
    [self.view addSubview:_chartView];
    [self loadData];
    //ChartView add area, area add series
    Area* areaup = [[Area alloc] init];
    //set delegate for axis's data provider
    areaup.bottomAxis.labelProvider = self;
    Area* areadown = [[Area alloc] init];
    areadown.bottomAxis.labelProvider = self;
    BarSeries* bar = [[BarSeries alloc] init];
    StockSeries* stock = [[StockSeries alloc] init];
    [areaup addSeries:stock];
    [areadown addSeries:bar];
    
//    init points in graph
    
    
     float stockPrice [90][4];
     int i = 0;
     //open close low high
     for (NSArray* arr in _chartData){
         NSDictionary *price = arr;
         stockPrice[i][1] = [price[@"Close"] floatValue];
         stockPrice[i][3]= [price[@"High"] floatValue];
         stockPrice[i][0]= [price[@"Open"] floatValue];
         stockPrice[i][2] = [price[@"Low"] floatValue];
         i++;
         
     }
    for (int i = 0; i< 90; i++){
        [stock addPointOpen:stockPrice[i][0] close:stockPrice[i][1] low:stockPrice[i][2] high:stockPrice[i][3]];
    }
    
    
 /*
    for (NSArray* arr in _chartData) {
        
        //        下面的点
//         [bar addPoint:Float(arr[1])];
        //        open，close,low, high
        [stock addPointOpen:Float(arr[2]) close:Float(arr[5]) low:Float(arr[4]) high:Float(arr[3])];
    }
*/
    
    
    
    //    加入表格
    [self.chartView addArea:areaup];
//    [self.chartView addArea:areadown];
    // two area's height ratio
//    [self.chartView setHeighRatio:0.3 forArea:areadown];
    
    // set any color you like
    [BBTheme theme].barBorderColor = [UIColor clearColor];
    [BBTheme theme].xAxisFontSize = 11;
    
    // begin to show the view animated
    [self.chartView drawAnimated:YES];

    
    // Do any additional setup after loading the view.
}

- (void)loadData{
    //    传递jasondata
    // based on keyword input in textfield, query history price
    SqlData* sql = [[SqlData alloc]init];
    sql.stock = urladd;
    _chartData = [sql returnHist];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - AxisDataProvider
- (NSString *)textForIdx:(NSUInteger)idx{
    NSString* ret = nil;
    
    // Too much labels would make them overlapping
    //    传递过去90天的时间数据
    if (idx % 15 == 0) {
        NSDate* curDate = [NSDate date];
        NSDate* date = nil;
        NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
        NSDateComponents* dateComponents = [[NSDateComponents alloc] init];
        NSCalendar *calendar = [NSCalendar currentCalendar];
        // idx - 90, is meaningless for your data.
        [dateComponents setDay:idx-90];
        formatter.dateFormat =  @"MM/dd HH:00";;
        date = [calendar dateByAddingComponents:dateComponents toDate:curDate options:0];
        ret = [formatter stringFromDate:date];
    }
    
    return ret;
    
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
