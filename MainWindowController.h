//
//  MainWindowController.h
//  MyMoment
//
//  Created by Edward Liu on 16/3/16.
//  Copyright © 2016年 Edward Liu. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MovieDetailViewController.h"
#import "RigisterViewController.h"

@interface MainWindowController : NSWindowController
@property IBOutlet NSTabView *mainTab;
@property NSView *mainView;
@property NSView *movieView;
@property NSView *musicView;
@property NSView *movieDetailView;
@property(strong)IBOutlet MovieDetailViewController *movieDetailViewController;
@property (strong)IBOutlet RigisterViewController *registerViewController;
@property IBOutlet NSButton *mainBtn;
@property IBOutlet NSButton *movieBtn;
@property IBOutlet NSButton *musicBtn;

@property IBOutlet NSTableView *mainMovieTableView;
@property IBOutlet NSTableView *mainMusicTableView;
@property IBOutlet NSScrollView *mainMovieScrollView;
@property IBOutlet NSButton *mainMovieBtn;
@property IBOutlet NSButton *mainMusicBtn;
@end