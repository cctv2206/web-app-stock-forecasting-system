//
//  SqlData.h
//  FirstTry
//
//  Created by Wuyang on 4/25/15.
//  Copyright (c) 2015 Wuyang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SqlData : UIViewController
@property NSString* stock;
@property NSString* url;
-(NSArray*)returnHist;

@end
