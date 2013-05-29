//
//  ADTransitionController.h
//  Transition
//
//  Created by Patrick Nollet on 21/02/11.
//  Copyright 2011 Applidium. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ADTransition.h"

// Our container view must be backed by a CATransformLayer
@interface ADTransitionView : UIView {    
}
@end

@protocol ADTransitionControllerDelegate;

@interface ADTransitionController : UIViewController <ADTransitionDelegate, UINavigationBarDelegate> {
    NSMutableArray *  _viewControllers;
    NSMutableArray *  _transitions; // Transition stack, paired with the view controller stack
    BOOL              _isContainerViewTransitioning;
    BOOL              _isNavigationBarTransitioning;
    UINavigationBar * _navigationBar;
    UIView *          _containerView;
}

@property (nonatomic, copy) NSMutableArray * viewControllers;
@property (nonatomic, readonly, retain) UIViewController * topViewController;
@property (nonatomic, readonly, retain) UIViewController * visibleViewController;
@property (nonatomic, assign) id<ADTransitionControllerDelegate> delegate;
@property(nonatomic, getter = isNavigationBarHidden, setter = setNavigationBarHidden:) BOOL navigationBarHidden;
- (void)setNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated;

- (id)initWithRootViewController:(UIViewController *)rootViewController;
- (void)pushViewController:(UIViewController *)viewController withTransition:(ADTransition *)animation;
- (UIViewController *)popViewController;
- (UIViewController *)popViewControllerWithTransition:(ADTransition *)animation;

@end

@protocol ADTransitionControllerDelegate <NSObject>
- (void)transitionController:(ADTransitionController *)transitionController willShowViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)transitionController:(ADTransitionController *)transitionController didShowViewController:(UIViewController *)viewController animated:(BOOL)animated;
@end