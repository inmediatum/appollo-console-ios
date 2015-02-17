//
//  MainTableViewController.m
//  Appollo Console
//
//  Created by Simon Urzua on 05/02/15.
//  Copyright (c) 2015 Inmediatum. All rights reserved.
//

#import "MainTableViewController.h"
#import "NotificationCell.h"

@interface MainTableViewController ()

@property (nonatomic, strong) NSMutableArray *notifications;

@end

@implementation MainTableViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _notifications = [NSMutableArray new];
    [APCore monitor].delegate = self;
}

#pragma mark - APMonitorDelegate

- (void)didReceiveNotification:(APTag *)tag
{
    [_notifications insertObject:tag.message atIndex:0];
    
    NSIndexPath *ip = [NSIndexPath
        indexPathForRow: 0
        inSection: 0
    ];
    
    [self.tableView beginUpdates];
    [self.tableView
        insertRowsAtIndexPaths: @[ip]
        withRowAnimation: UITableViewRowAnimationAutomatic
    ];
    [self.tableView endUpdates];
    
    NSLog(@"Tag notification: %@", tag);
}

- (void)userRejectPermissions
{
    NSLog(@"User reject permissions");
}

- (void)userAcceptPermissions
{
    NSLog(@"User accept permissions");
}

- (void)uncompatibleDevice
{
    NSLog(@"Uncompatible device");
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _notifications.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NotificationCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Notification" forIndexPath:indexPath];
    
    cell.message.text = _notifications[indexPath.row];
    
    return cell;
}

#pragma mark - UIAlertViewDelegate

- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if (buttonIndex == 0)
    {
        UITextField *apiKey = [alertView textFieldAtIndex:0];
        
        [APCore replaceApiKey:apiKey.text];
    }
}

#pragma mark - IBOutlets

- (IBAction)clear:(id)sender
{
    _notifications = [NSMutableArray new];
    
    [self.tableView reloadData];
}

- (IBAction)changeApiKey:(id)sender
{
    UIAlertView *alert = [[UIAlertView alloc]
        initWithTitle: @"API Key"
        message: @"Insert you own valid API Key"
        delegate: self
        cancelButtonTitle:@"Cancel"
        otherButtonTitles:@"Change", nil
    ];
    
    alert.alertViewStyle = UIAlertViewStylePlainTextInput;

    [alert show];
}

@end
