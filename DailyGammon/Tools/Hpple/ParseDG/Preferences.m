//
//  Preferences.m
//  DailyGammon
//
//  Created by Peter on 10.12.18.
//  Copyright © 2018 Peter Schneider. All rights reserved.
//

#import "Preferences.h"
#import "TFHpple.h"

@implementation Preferences

- (NSMutableArray *)readPreferences
{
    NSURL *url = [NSURL URLWithString:@"http://dailygammon.com/bg/profile"];
    NSData *htmlData = [NSData dataWithContentsOfURL:url];
    
    NSMutableArray *preferencesArray = [[NSMutableArray alloc]init];
    // Create parser
    TFHpple *xpathParser = [[TFHpple alloc] initWithHTMLData:htmlData];
    
    //Get all the cells of the 2nd row of the 3rd table
    //        NSArray *elements  = [xpathParser searchWithXPathQuery:@"//table[3]/tr[2]/td"];
    NSArray *elements  = [xpathParser searchWithXPathQuery:@"//form[3]/table[1]/tr"];
    
    for(TFHppleElement *element in elements)
    {
        TFHppleElement *child = [element firstChild];
        for (TFHppleElement *grandChild in child.children)
        {
            NSDictionary *dict = [grandChild attributes];
            if([[dict objectForKey:@"type"] isEqualToString:@"checkbox"])
            {
                [preferencesArray addObject:dict];
            }
        }
    }
    
    return preferencesArray;
}

- (int)readNextMatchOrdering
{
    int order = 0;
    NSURL *url = [NSURL URLWithString:@"http://dailygammon.com/bg/profile"];
    NSData *htmlData = [NSData dataWithContentsOfURL:url];
    
    TFHpple *xpathParser = [[TFHpple alloc] initWithHTMLData:htmlData];
    
    NSArray *elements  = [xpathParser searchWithXPathQuery:@"//form[3]/table[2]/tr"];
    
    for(TFHppleElement *element in elements)
    {
        TFHppleElement *child = [element firstChild];
        for (TFHppleElement *grandChild in child.children)
        {
            NSDictionary *dict = [grandChild attributes];
     //       XLog(@"%@",dict);
            if([[dict objectForKey:@"checked"] isEqualToString:@"checked"])
               return order;
        }
        order++;
    }
    
    return order;
}

- (bool)isMiniBoard
{
    NSURL *url = [NSURL URLWithString:@"http://dailygammon.com/bg/profile"];
    NSData *htmlData = [NSData dataWithContentsOfURL:url];
    
    TFHpple *xpathParser = [[TFHpple alloc] initWithHTMLData:htmlData];
    
    NSArray *elements  = [xpathParser searchWithXPathQuery:@"//form[3]/table[4]/tr"];
    
    for(TFHppleElement *element in elements)
    {
        TFHppleElement *child = [element firstChild];
        for (TFHppleElement *grandChild in child.children)
        {
            NSDictionary *dict = [grandChild attributes];
            //       XLog(@"%@",dict);
            if([[element content] isEqualToString:@"Mini"])
                if([[dict objectForKey:@"checked"] isEqualToString:@"checked"])
                    return TRUE;
        }
    }
    return FALSE;
}
@end
