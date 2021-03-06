//
//  RegisterInfoViewController.m
//  MyMoment
//
//  Created by Edward Liu on 16/4/13.
//  Copyright © 2016年 Edward Liu. All rights reserved.
//

#import "RegisterInfoViewController.h"
#import "AppDelegate.h"
#import "UserCoreData.h"

@interface RegisterInfoViewController ()


@end

@implementation RegisterInfoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
}


-(IBAction)clickSubmitBtn:(id)sender{
    
    
    if ([self.accountTextField.stringValue isEqualToString:@""]&[self.passwordTextField.stringValue isEqualToString:@""]) {
        [self.accountAttentionLabel setHidden:NO];
        [self.passwordAttentionLabel setHidden:NO];
        return;
    }
    else if([self.accountTextField.stringValue isEqualToString:@""]&[self.passwordTextField.stringValue isNotEqualTo:@""]){
        [self.accountAttentionLabel setHidden:NO];
        [self.passwordAttentionLabel setHidden:YES];
        return;
    }
    else if ([self.accountTextField.stringValue isNotEqualTo:@""]&[self.passwordTextField.stringValue isEqualTo:@""]){
        [self.passwordAttentionLabel setHidden:NO];
        [self.accountAttentionLabel setHidden:YES];
        return;
    }
    else if([self.accountTextField.stringValue isNotEqualTo:@""]&[self.passwordTextField.stringValue isNotEqualTo:@""]){
        
        if ([AppDelegate getStaticAccountState]==NO){
        
        AppDelegate *appdelegate=[NSApp delegate];
        appdelegate.mainWindowController.registerViewController.nameLabel.stringValue=self.accountTextField.stringValue;
        [self.view setHidden:YES];
        [appdelegate.mainWindowController.mainView setHidden:NO];
        [appdelegate.mainWindowController.registerViewController.favoriteListBtn setHidden:NO];
        [appdelegate.mainWindowController.registerViewController.historyListBtn setHidden:NO];
        [appdelegate.mainWindowController.registerViewController.accountTextField setHidden:YES];
        [appdelegate.mainWindowController.registerViewController.passwordTextField setHidden:YES];
        [appdelegate.mainWindowController.registerViewController.aboardBtn setHidden:YES];
        [appdelegate.mainWindowController.registerViewController.registerBtn setHidden:YES];
        [appdelegate.mainWindowController.registerViewController.quitBtn setHidden:NO];
            [appdelegate.mainWindowController.registerViewController.attentionLabel setHidden:YES];
        BOOL accountState=YES;
        [AppDelegate setStaticAcccountState:accountState];
        
        User *temperUser=[[User alloc]initWithName:self.accountTextField.stringValue WithAge:self.ageTextField.stringValue WithSex:self.sexMatrix.selectedCell.stringValue WithEmailAdress:self.emailTextField.stringValue WithPhoneNumber:self.phoneTextField.stringValue WithPassword:self.passwordTextField.stringValue WithIntroduction:self.selfIntroductionTextField.stringValue];
        NSMutableArray *temperUserMutableArray=[AppDelegate getStaticUserMutableArray];
        [temperUserMutableArray addObject:temperUser];
        [AppDelegate setstaticUserMutableArray:temperUserMutableArray];
        [AppDelegate setStaticUser:temperUser];
        [AppDelegate setStaticUserRow:([temperUserMutableArray count]-1)];
       [self clearUserCoreData];
        [self saveNewUser];
            NSLog(@"%@",[appdelegate.managedObjectContext executeFetchRequest:[NSFetchRequest fetchRequestWithEntityName:@"UserCoreData"] error:nil]);
        }
        
        else if ([AppDelegate getStaticAccountState]==YES){
            User *temperUser=[[User alloc]initWithName:self.accountTextField.stringValue WithAge:self.ageTextField.stringValue WithSex:self.sexMatrix.selectedCell.stringValue WithEmailAdress:self.emailTextField.stringValue WithPhoneNumber:self.phoneTextField.stringValue WithPassword:self.passwordTextField.stringValue WithIntroduction:self.selfIntroductionTextField.stringValue];
            [AppDelegate setStaticUser:temperUser];
            NSMutableArray *temperUserMutableArray=[AppDelegate getStaticUserMutableArray];
            [temperUserMutableArray setObject:temperUser atIndexedSubscript:[AppDelegate getStaticUserRow]];
            [AppDelegate setstaticUserMutableArray:temperUserMutableArray];
            [self.view setHidden:YES];
            AppDelegate *appdelegate=[NSApp delegate];
            appdelegate.mainWindowController.registerViewController.nameLabel.stringValue=temperUser.userName;
            [appdelegate.mainWindowController.mainView setHidden:NO];
            [self clearUserCoreData];
            [self saveNewUser];
        }
    }
 
}

-(void)saveNewUser{
    AppDelegate *appdelegate=[NSApp delegate];
    NSMutableArray *tempUserMutableArray=[[NSMutableArray alloc]initWithArray:[AppDelegate getStaticUserMutableArray]];
    UserCoreData *userCoreData=[[UserCoreData alloc]initWithEntity:[NSEntityDescription entityForName:@"UserCoreData" inManagedObjectContext:[appdelegate managedObjectContext]] insertIntoManagedObjectContext:appdelegate.managedObjectContext];
    userCoreData.userArrayData=[NSKeyedArchiver archivedDataWithRootObject:tempUserMutableArray];
    NSError *error=nil;
    [appdelegate.managedObjectContext save:&error];
}

-(void)clearUserCoreData{
    AppDelegate *appdelegate=[NSApp delegate];
    NSFetchRequest *request=[NSFetchRequest fetchRequestWithEntityName:@"UserCoreData"];
    NSError *error = nil;
    NSArray *result = [appdelegate.managedObjectContext executeFetchRequest:request error:&error];
    for (NSManagedObject *user in result) {
        [appdelegate.managedObjectContext deleteObject:user];
    }
  
    [appdelegate.managedObjectContext save:&error];
    
   // NSBatchDeleteRequest *delete = [[NSBatchDeleteRequest alloc] initWithFetchRequest:request];
    
    //NSError *error = nil;
    //[appdelegate.persistentStoreCoordinator executeRequest:delete withContext:appdelegate.managedObjectContext error:&error];
}

@end
