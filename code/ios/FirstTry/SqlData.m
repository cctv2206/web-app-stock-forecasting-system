//  SqlData.m
//  FirstTry
//
//  Created by Wuyang on 4/25/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#import "SqlData.h"

@interface SqlData ()
@end

@implementation SqlData
@synthesize stock;

-(id) init{
    self = [super init];
    if(self){
        
    }
    return self;
}
-(id) initWithUrl: (NSString*) att
{
    self = [super init];
    if(self){
        _url = att;
    }
    return self;
}

- (NSArray *)returnHist
{
    
     NSHTTPURLResponse *response = nil;
    
     NSString* http = @"http://localhost/~Wuyang/stock/";
     NSString* stock = self.stock;
     NSString* php = @".php";
     http = [http stringByAppendingString:stock];
     http = [http stringByAppendingString:php];
     
     // NSString *jsonUrlString = [NSString stringWithFormat:@"http://localhost/~Wuyang/stock/getHistoryPrice.php"];
     NSString* jsonUrlString = http;
//     NSString *jsonUrlString = [NSString stringWithFormat:@"http://localhost/~Wuyang/stock/AAPL.php"];

     NSURL *url = [NSURL URLWithString:[jsonUrlString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
     
     //-- Get request and response though URL
     NSURLRequest *request = [[NSURLRequest alloc]initWithURL:url]; NSData *responseData = [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:nil];
     
     //-- JSON Parsing
     
     NSArray *result = [NSJSONSerialization JSONObjectWithData:responseData options:NSJSONReadingMutableContainers error:nil];
//     NSLog(@"Result = %@",result);
//     NSString *showprice;
    /*
     for (int i = 0; i<result.count;i++){
         NSDictionary *price = result[i];
         showprice =price[@"High"];
         NSLog(showprice);
     }
     */
    return result;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
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
