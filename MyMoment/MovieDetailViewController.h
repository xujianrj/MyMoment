//
//  MovieDetailViewController.h
//  MyMoment
//
//  Created by Edward Liu on 16/4/8.
//  Copyright © 2016年 Edward Liu. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface MovieDetailViewController : NSViewController<NSTableViewDelegate,NSTableViewDataSource>
{ int score;
}

@property IBOutlet NSButton *oneScoreBtn;
@property IBOutlet NSButton *twoScoreBtn;
@property IBOutlet NSButton *threeScoreBtn;
@property IBOutlet NSButton *fourScoreBtn;
@property IBOutlet NSButton *fiveScoreBtn;
@property IBOutlet NSTextField *scoreTextField;
@property NSMutableArray *messageArray;
@property IBOutlet NSButton *submitMessageBtn;
@property IBOutlet NSTextField *messageTextField;
@property IBOutlet NSTableView *messageTableView;
@property NSString *message;


@property IBOutlet NSTextField *nameLabel;
@property IBOutlet NSTextField *styleLabel;
@property IBOutlet NSTextField *introductionLabel;
@property IBOutlet NSImageView *imageView;
@property IBOutlet NSTextField *authorLabel;
@property IBOutlet NSImageView *resultStarImageView;
@property IBOutlet NSTextField *resultScoreLabel;
@end