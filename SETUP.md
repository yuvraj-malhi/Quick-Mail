
## One Time Setup
Before any demonstration or functioning of code can be shown, it is important to change some settings in the sender’s email account to allow 3rd party applications (like Linux-curl API) to manage emails. This can cause some security issues, but since my code is short and open sourced, one can easily verify if some harmful commands are being run. It is not the case.
Now, follow the following steps for using gmail (read along for other emails also):-

### Step I
Create a new Gmail account. Skip this if an old account is to be used.

![image](https://user-images.githubusercontent.com/76866159/105606149-a5fdae00-5dbd-11eb-8b0f-6c76fa034126.png)

		My ID              ->  dummyname07071@gmail.com
		My Password        ->  07Night!
    
PS - don't bother testing, this account has already been disabled :)

### Step II
On your Linux system (I use Kali), download “mailer.c”.
I have downloaded the file on Desktop and moved it into a new folder.

![image](https://user-images.githubusercontent.com/76866159/105606233-2ae8c780-5dbe-11eb-828f-aaf7d1377115.png)

### Step III 
Run the command:    

```gcc mailer.c -lcurl```

If you see any error, then cURL library is not installed. Install it before proceeding.
If successful, then there will be no message shown.

![image](https://user-images.githubusercontent.com/76866159/105606283-6e433600-5dbe-11eb-9083-34931d508739.png)

### Step IV
Run the command:    

```sudo ./a.out```

Then fill in the details one by one as asked.

![image](https://user-images.githubusercontent.com/76866159/105606319-a185c500-5dbe-11eb-9af8-d2d66781ef9b.png)

Press Enter.

![image](https://user-images.githubusercontent.com/76866159/105606324-ac405a00-5dbe-11eb-8fdb-d0bc7b5232c4.png)

An error will be shown. Don't worry, we expect this error. This is because gmail has not yet authorized linux-curl API to allow sending emails from this particular account. 
To fix the error:

### Step V
Login to the account, and notice that such an email must have been received. (If no email is received then repeat step IV and make sure your credentials are correct).

![image](https://user-images.githubusercontent.com/76866159/105606355-e90c5100-5dbe-11eb-9e86-8f04d4766404.png)

Click on “check activity” and then click “Yes, it was me”. This is to allow linux to send emails from the new account.

### Step VI
(This may not be required for outlook/ office365 accounts).

In the gmail account, click on your profile image > “Manage your Google account”

![image](https://user-images.githubusercontent.com/76866159/105606423-6932b680-5dbf-11eb-974c-fed9a092ad2f.png)

Scroll over to the security section.

![image](https://user-images.githubusercontent.com/76866159/105606434-79e32c80-5dbf-11eb-9432-e8f5273b87d3.png)

Now, change the “Off” to “On” in the “Less secure app access” tab. 
Since, my code is open source, so no worries on that end. This is just to ensure that SMTP mails are allowed.

![image](https://user-images.githubusercontent.com/76866159/105606472-9aab8200-5dbf-11eb-9300-522426fc17dd.png)

Setup Complete! Let's Send some emails!
