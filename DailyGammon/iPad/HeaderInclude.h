//
//  HeaderTest.h
//  DailyGammon
//
//  Created by Peter on 30.11.18.
//  Copyright © 2018 Peter Schneider. All rights reserved.
//

#ifndef HeaderTest_h
#define HeaderTest_h


-(UIView *)makeHeader
{
    design = [[Design alloc] init];
    tools = [[Tools alloc] init];

    int maxBreite = [UIScreen mainScreen].bounds.size.width;
    UIView *headerView = [[UIView alloc] initWithFrame:CGRectMake(20, 20, maxBreite - 40, 50)];
    
    int x = 0;
    int y = 5;
    int diceBreite = 40;
    int luecke = 10;
    
    AppDelegate *app = (AppDelegate *)[[UIApplication sharedApplication] delegate];

    int countDB = [app.dbConnect countRating];
    if([[[NSUserDefaults standardUserDefaults] valueForKey:@"iCloud"]boolValue])
        countDB = 99;

    int minDB = 5;
//    int anzahlButtons = 6;
//    if(countDB > minDB)
//        anzahlButtons = 7;
    int anzahlButtons = 8;
    if(countDB > minDB)
        anzahlButtons += 1;
    int headerBreite = headerView.frame.size.width;

    int buttonBreite = (headerBreite - diceBreite - (anzahlButtons * luecke) ) / anzahlButtons;
    
    int buttonHoehe = 35;
        
    int boardSchema = [[[NSUserDefaults standardUserDefaults] valueForKey:@"BoardSchema"]intValue];
    if(boardSchema < 1)
        boardSchema = 4;
    NSString *imageName = @"dice_rot.png";
    switch(boardSchema)
    {
        case 1:
        case 2:
            imageName = @"dice_gruen.png";
            break;
        case 3:
            imageName = @"dice_blau.png";
            break;
        case 4:
            imageName = @"dice_rot.png";
        break;
            
    }
    UIImageView *diceView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:imageName]];
    diceView.frame = CGRectMake(0, 5, diceBreite, diceBreite);
    
    x +=  diceBreite + luecke;
    
//    UIButton *button1 = [UIButton buttonWithType:UIButtonTypeSystem];
    self.topPageButton = [UIButton buttonWithType:UIButtonTypeSystem];
    self.topPageButton = [design makeNiceButton:self.topPageButton];
    [self.topPageButton setTitle:[NSString stringWithFormat:@"%d Top Page", [tools matchCount]] forState: UIControlStateNormal];
    self.topPageButton.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    self.topPageButton.tag = 1;
    [self.topPageButton addTarget:self action:@selector(topPageVC) forControlEvents:UIControlEventTouchUpInside];
    
    x += buttonBreite + luecke;
    
    UIButton *button2 = [UIButton buttonWithType:UIButtonTypeSystem];
    button2 = [design makeNiceButton:button2];
    [button2 setTitle:@"Game Lounge" forState: UIControlStateNormal];
    button2.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    button2.tag = 2;
    [button2 addTarget:self action:@selector(GameLoungeVC) forControlEvents:UIControlEventTouchUpInside];

    x += buttonBreite + luecke;
    
    UIButton *button3 = [UIButton buttonWithType:UIButtonTypeSystem];
    button3 = [design makeNiceButton:button3];
    [button3 setTitle:@"Help" forState: UIControlStateNormal];
    button3.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    button3.tag = 3;
    [button3 addTarget:self action:@selector(help) forControlEvents:UIControlEventTouchUpInside];

    x += buttonBreite + luecke;
    
    UIButton *button4 = [UIButton buttonWithType:UIButtonTypeSystem];
    button4 = [design makeNiceButton:button4];
    [button4 setTitle:@"Settings" forState: UIControlStateNormal];
    button4.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    button4.tag = 4;
    [button4 addTarget:self action:@selector(popoverSetUp:) forControlEvents:UIControlEventTouchUpInside];

    x += buttonBreite + luecke;
 
    UIButton *button5 = [UIButton buttonWithType:UIButtonTypeSystem];
    button5 = [design makeNiceButton:button5];
    [button5 setTitle:@"Log Out" forState: UIControlStateNormal];
    button5.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    button5.tag = 5;
    [button5 addTarget:self action:@selector(logout) forControlEvents:UIControlEventTouchUpInside];

    x += buttonBreite + luecke;

    UIButton *button6 = [UIButton buttonWithType:UIButtonTypeSystem];
    button6 = [design makeNiceButton:button6];
    [button6 setTitle:@"About" forState: UIControlStateNormal];
    button6.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    button6.tag = 6;
    [button6 addTarget:self action:@selector(showPopOverAbout:) forControlEvents:UIControlEventTouchUpInside];

    x += buttonBreite + luecke;
    
    UIButton *button7 = [UIButton buttonWithType:UIButtonTypeSystem];
    button7 = [design makeNiceButton:button7];
    [button7 setTitle:@"Rating" forState: UIControlStateNormal];
    button7.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    button7.tag = 7;
    [button7 addTarget:self action:@selector(ratingVC) forControlEvents:UIControlEventTouchUpInside];
    
    if(countDB > minDB)
        x += buttonBreite + luecke;

    UIButton *button8 = [UIButton buttonWithType:UIButtonTypeSystem];
    button8 = [design makeNiceButton:button8];
    [button8 setTitle:@"Players" forState: UIControlStateNormal];
    button8.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    button8.tag = 8;
    [button8 addTarget:self action:@selector(playerVC) forControlEvents:UIControlEventTouchUpInside];
    
    x += buttonBreite + luecke;

    UIButton *button9 = [UIButton buttonWithType:UIButtonTypeSystem];
    button9 = [design makeNiceButton:button9];
    [button9 setTitle:@"Feedback" forState: UIControlStateNormal];
    button9.frame = CGRectMake(x, y, buttonBreite - 10, buttonHoehe);
    button9.tag = 8;
    [button9 addTarget:self action:@selector(feedback) forControlEvents:UIControlEventTouchUpInside];

    [headerView addSubview:diceView];
    
    [headerView addSubview:self.topPageButton];
    [headerView addSubview:button2];
    [headerView addSubview:button3];
    [headerView addSubview:button4];
    [headerView addSubview:button5];
    [headerView addSubview:button6];
    if(countDB > minDB)
        [headerView addSubview:button7];
    [headerView addSubview:button8];
    [headerView addSubview:button9];

    return headerView;
}
-(void) ratingVC
{
    AppDelegate *app = (AppDelegate *)[[UIApplication sharedApplication] delegate];

    RatingVC *vc = [app.activeStoryBoard instantiateViewControllerWithIdentifier:@"RatingVC"];
    
    [self.navigationController pushViewController:vc animated:NO];
}

-(void) topPageVC
{
    AppDelegate *app = (AppDelegate *)[[UIApplication sharedApplication] delegate];

    TopPageVC *vc = [app.activeStoryBoard instantiateViewControllerWithIdentifier:@"TopPageVC"];
    
    [self.navigationController pushViewController:vc animated:NO];
}

-(void) GameLoungeVC
{
    AppDelegate *app = (AppDelegate *)[[UIApplication sharedApplication] delegate];

    GameLounge *vc = [app.activeStoryBoard instantiateViewControllerWithIdentifier:@"GameLoungeVC"];
    
    [self.navigationController pushViewController:vc animated:NO];
}

- (IBAction)popoverSetUp:(id)sender
{
    AppDelegate *app = (AppDelegate *)[[UIApplication sharedApplication] delegate];

    UIViewController *controller = [app.activeStoryBoard instantiateViewControllerWithIdentifier:@"SetUpVC"];
    
    // present the controller
    // on iPad, this will be a Popover
    // on iPhone, this will be an action sheet
    controller.modalPresentationStyle = UIModalPresentationPopover;
    [self presentViewController:controller animated:YES completion:nil];
    
    UIPopoverPresentationController *popController = [controller popoverPresentationController];
    popController.permittedArrowDirections = UIPopoverArrowDirectionAny;
    popController.delegate = self;
    
    UIButton *button = (UIButton *)sender;
    popController.sourceView = button;
    popController.sourceRect = button.bounds;
}

- (void)logout
{
    [[NSUserDefaults standardUserDefaults] setValue:@"" forKey:@"user"];
    [[NSUserDefaults standardUserDefaults] setValue:@"" forKey:@"password"];
    [[NSUserDefaults standardUserDefaults] synchronize];

    AppDelegate *app = (AppDelegate *)[[UIApplication sharedApplication] delegate];

    LoginVC *vc = [app.activeStoryBoard instantiateViewControllerWithIdentifier:@"LoginVC"];

    [self.navigationController pushViewController:vc animated:NO];

}
- (IBAction)showPopOverAbout:(id)sender
{
    AppDelegate *app = (AppDelegate *)[[UIApplication sharedApplication] delegate];

    UIViewController *controller = [app.activeStoryBoard instantiateViewControllerWithIdentifier:@"About"];
    
    controller.modalPresentationStyle = UIModalPresentationPopover;
    [self presentViewController:controller animated:YES completion:nil];
    
    UIPopoverPresentationController *popController = [controller popoverPresentationController];
    popController.permittedArrowDirections = UIPopoverArrowDirectionUp;
    popController.delegate = self;
    
    UIButton *button = (UIButton *)sender;
    popController.sourceView = button;
    popController.sourceRect = button.bounds;

}
-(void) help
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString: @"http://dailygammon.com/help"] options:@{} completionHandler:nil];
}

- (IBAction)playerVC
{
    
    AppDelegate *app = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    
    Player *vc = [app.activeStoryBoard instantiateViewControllerWithIdentifier:@"PlayerVC"];
   
    [self.navigationController pushViewController:vc animated:NO];

}


- (void)feedback
{
    UIAlertController * alert = [UIAlertController
                                  alertControllerWithTitle:@"Feedback"
                                  message:FEEDBACK_TEXT
                                  preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction* cancelButton = [UIAlertAction
                                actionWithTitle:@"Cancel"
                                style:UIAlertActionStyleDestructive
                                handler:^(UIAlertAction * action)
                                {
                                    return;
                                }];

    [alert addAction:cancelButton];

    UIAlertAction* emailButton = [UIAlertAction
                                actionWithTitle:@"Email"
                                style:UIAlertActionStyleDefault
                                handler:^(UIAlertAction * action)
                                  {
                                    [self sendMail];
                                  }];

    [alert addAction:emailButton];
 
    UIAlertAction* contactButton = [UIAlertAction
                                actionWithTitle:@"Contact form"
                                style:UIAlertActionStyleDefault
                                handler:^(UIAlertAction * action)
                                  {
        NSURL *URL = [NSURL URLWithString:[NSString stringWithFormat:@"http://hape42.de/App/contact/"]];
        if ([SFSafariViewController class] != nil)
        {
            SFSafariViewController *sfvc = [[SFSafariViewController alloc] initWithURL:URL];
            [self presentViewController:sfvc animated:YES completion:nil];
        }
        else
        {
            [[UIApplication sharedApplication] openURL:URL options:@{} completionHandler:nil];
        }

                                  }];

 //   [alert addAction:contactButton];

    UIAlertAction* listButton = [UIAlertAction
                                actionWithTitle:@"Show list of upcomming features"
                                style:UIAlertActionStyleDefault
                                handler:^(UIAlertAction * action)
                                  {
        NSURL *URL = [NSURL URLWithString:[NSString stringWithFormat:@"https://hape42.de/hape42/Seiten/DailyGammon.html"]];
        if ([SFSafariViewController class] != nil)
        {
            SFSafariViewController *sfvc = [[SFSafariViewController alloc] initWithURL:URL];
            [self presentViewController:sfvc animated:YES completion:nil];
        }
        else
        {
            [[UIApplication sharedApplication] openURL:URL options:@{} completionHandler:nil];
        }

                                  }];

    [alert addAction:listButton];

    [self presentViewController:alert animated:YES completion:nil];
    return;

}
-(void) sendMail
{

    if (![MFMailComposeViewController canSendMail])
    {

        UIAlertController * alert = [UIAlertController
                                      alertControllerWithTitle:@"Problem gefunden"
                                      message:@"Normally the email is sent with Apple Mail. There seems to be a problem with Apple Mail. Please select your email program and send the email to DG@hape42.de"
                                      preferredStyle:UIAlertControllerStyleAlert];

        UIAlertAction* okButton = [UIAlertAction
                                    actionWithTitle:@"OK"
                                    style:UIAlertActionStyleDestructive
                                    handler:^(UIAlertAction * action)
                                      {
                                          NSArray *objectsToShare = @[];

                                          UIActivityViewController *shareVC = [[UIActivityViewController alloc] initWithActivityItems:objectsToShare applicationActivities:nil];
                                          
                                          [shareVC setValue:@"send your request to DGs@hape42.de by Email" forKey:@"subject"];
                                      //    [shareVC setValue:@"GolfGames@hape42.de" forKey:@"torecipients"];

                                          [self presentViewController:shareVC animated:YES completion:nil];
                                          return;

                                      }];

        [alert addAction:okButton];
        UIAlertAction* cancelButton = [UIAlertAction
                                    actionWithTitle:@"Cancel"
                                    style:UIAlertActionStyleCancel
                                    handler:^(UIAlertAction * action)
                                    {
                                        return;
                                    }];

        [alert addAction:cancelButton];
        [self presentViewController:alert animated:YES completion:nil];
        return;

       XLog(@"Fehler: Mail kann nicht versendet werden");
       return;
    }
    NSString *betreff = [NSString stringWithFormat:@"Feedback"];

    NSString *text = @"";
    NSString *emailText = @"";
    text = [NSString stringWithFormat:@"Hallo Support-Team von %@, <br><br> ", [[[NSBundle mainBundle] infoDictionary]   objectForKey:@"CFBundleName"]];
    emailText = [NSString stringWithFormat:@"%@%@", emailText, text];

    text = [NSString stringWithFormat:@"my data: <br> "];
    emailText = [NSString stringWithFormat:@"%@%@", emailText, text];

    text = [NSString stringWithFormat:@"App <b>%@</b> <br> ", [[[NSBundle mainBundle] infoDictionary]   objectForKey:@"CFBundleName"]];
    emailText = [NSString stringWithFormat:@"%@%@", emailText, text];

    text = [NSString stringWithFormat:@"Version %@ Build %@<br><br>", [[[NSBundle mainBundle] infoDictionary]   objectForKey:@"CFBundleShortVersionString"], [[[NSBundle mainBundle] infoDictionary]   objectForKey:@"CFBundleVersion"]];
    emailText = [NSString stringWithFormat:@"%@%@", emailText, text];

    text = [NSString stringWithFormat:@"Build from <b>%@</b> <br> ", [[[NSBundle mainBundle] infoDictionary]   objectForKey:@"DGBuildDate"]];
    emailText = [NSString stringWithFormat:@"%@%@", emailText, text];

    text = [NSString stringWithFormat:@"Device <b>%@</b> IOS <b>%@</b><br> ", [[UIDevice currentDevice] model], [[UIDevice currentDevice] systemVersion]];
    emailText = [NSString stringWithFormat:@"%@%@", emailText, text];

    text = [NSString stringWithFormat:@" "];
    emailText = [NSString stringWithFormat:@"%@%@<br><br>", emailText, text];
    
    MFMailComposeViewController *emailController = [[MFMailComposeViewController alloc] init];
    emailController.mailComposeDelegate = self;
    NSArray *toGolfGames = [NSArray arrayWithObjects:@"DG@hape42.de",nil];


    [emailController setToRecipients:toGolfGames];
    [emailController setSubject:betreff];
    [emailController setMessageBody:emailText isHTML:YES];
    [self presentViewController:emailController animated:YES completion:NULL];

}

//-(void)mailComposeController:(MFMailComposeViewController *)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError *)error
//{
//    if (error)
//    {
//        XLog(@"Fehler MFMailComposeViewController: %@", error);
//    }
//    [controller dismissViewControllerAnimated:YES completion:NULL];
//}

#endif /* HeaderTest_h */
