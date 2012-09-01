//
//  cocos2d_x_extensions_demo_iosAppController.h
//  cocos2d-x-extensions-demo-ios
//
//  Created by Liao YuLei on 12-8-31.
//  Copyright __MyCompanyName__ 2012年. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

@end

