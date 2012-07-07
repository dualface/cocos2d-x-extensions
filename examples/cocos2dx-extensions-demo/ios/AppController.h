//
//  cocos2dx_extensions_demoAppController.h
//  cocos2dx-extensions-demo
//
//  Created by YuLei Liao on 12-7-7.
//  Copyright __MyCompanyName__ 2012年. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController	*viewController;
}

@end

