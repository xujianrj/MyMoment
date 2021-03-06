//
//  AppDelegate.h
//  MyMoment
//
//  Created by Edward Liu on 16/3/16.
//  Copyright © 2016年 Edward Liu. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MainWindowController.h"
#import "Movie.h"
#import "Music.h"
#import "User.h"
#import "Message.h"
#import "UserCoreData.h"



static BOOL staticAccountState;
static NSMutableArray *staticCommentMutableArray;
static NSMutableArray *staticMovieMutableArray;
static NSMutableArray *staticMusicMutableArray;
static NSMutableArray *staticMovieScoreRankingMutableArray;
static Movie *staticMovie;
static Music *staticMusic;
static Movie *staticScoreRankingMovie;
static User *staticUser;
static NSInteger staticUserRow;
static NSMutableArray *staticUserMutableArray;
static NSMutableArray *staticFavoriteListMutableArray;
static NSMutableArray *staticMusicFavoriteListMutableArray;
static NSMutableArray *staticHistoryListMutableArray;
static NSMutableArray *staticMusicHistoryListMutableArray;
static NSInteger staticMovieRow;
static NSInteger staticMusicRow;


@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong) IBOutlet MainWindowController *mainWindowController;

+(BOOL)getStaticAccountState;
+(BOOL)setStaticAcccountState:(BOOL)newAccountState;

//+(NSMutableArray *)getStaticCommentMutableArray;
//+(NSMutableArray *)setStaticCommentMutableArray:(NSMutableArray *)newCommentMutableArray;

+(NSMutableArray *)getStaticMovieMutableArray;
+(NSMutableArray *)setStaticMovieMutableArray:(NSMutableArray *)newMovieMutableArray;

+(NSMutableArray *)getStaticMovieScoreRankingMutableArray;
+(NSMutableArray *)setStaticMovieScoreRankingMutableArray:(NSMutableArray *)newMovieMutableArray;

+(NSMutableArray *)getStaticMusicMutableArray;
+(NSMutableArray *)setStaticMusicMutableArray:(NSMutableArray *)newMusicMutableArray;

+(Movie *)getStaticMovie;
+(Movie *)setStaticMovie:(Movie *)newMovie;

+(Music *)getStaticMusic;
+(Music *)setStaticMusic:(Music *)newMusic;

+(Movie *)getStaticScoreRankingMovie;
+(Movie *)setStaticScoreRankingMovie:(Movie *)newMovie;

+(User *)getStaticUser;
+(User *)setStaticUser:(User *)newUser;

+(NSInteger)getStaticUserRow;
+(NSInteger)setStaticUserRow:(NSInteger)row;

+(NSMutableArray *)getStaticUserMutableArray;
+(NSMutableArray *)setstaticUserMutableArray:(NSMutableArray *)newUserMutableArray;

+(NSMutableArray *)getStaticFavoriteListMutableArray;
+(NSMutableArray *)setstaticFavoriteListMutableArray:(NSMutableArray *)newFavoriteMutableArray;

+(NSMutableArray *)getStaticMusicFavoriteListMutableArray;
+(NSMutableArray *)setstaticMusicFavoriteListMutableArray:(NSMutableArray *)newMusicFavoriteMutableArray;

+(NSMutableArray *)getStaticHistoryListMutableArray;
+(NSMutableArray *)setstaticHistoryListMutableArray:(NSMutableArray *)newHistoryListMutableArray;

+(NSMutableArray *)getStaticMusicHistoryListMutableArray;
+(NSMutableArray *)setstaticMusicHistoryListMutableArray:(NSMutableArray *)newMusicHistoryListMutableArray;

+(NSInteger)getStaticMovieRow;
+(NSInteger)setStaticMovieRow:(NSInteger)row;

+(NSInteger)getStaticMusicRow;
+(NSInteger)setStaticMusicRow:(NSInteger)row;

@end

