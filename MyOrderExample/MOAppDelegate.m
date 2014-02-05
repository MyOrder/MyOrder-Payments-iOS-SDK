//
//  MOAppDelegate.m
//  MyOrder
//
//  Created by Taras Kalapun on 5/22/13.
//  Copyright (c) 2013 Xaton. All rights reserved.
//

#import "MOAppDelegate.h"
#import <MyOrder/MyOrder.h>
#import "MOExampleViewController.h"


@implementation MOAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    MyOrder *myOrder = [MyOrder shared];
    myOrder.apiKey = @"d712d563-d5ed-4826-8920-1b2c2b743ba9";
    myOrder.apiSecret = @"hH3#1PxxS";
    myOrder.environment = MyOrderEnvironmentSandbox;
        
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    // Override point for customization after application launch.
    MOExampleViewController *viewController = [[MOExampleViewController alloc] init];
    UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:viewController];
    self.window.rootViewController = navController;
    [self.window makeKeyAndVisible];
    
    [[UINavigationBar appearance] setTintColor:[UIColor orangeColor]];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
