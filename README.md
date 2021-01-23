# Quick Mail

## Description
The task of sending emails is often boring and **_time consuming_**. Opening the browser, opening email, logging in, composing and then sending. By chance if you have a slow internet, then it will take forever!

On these lines (as we fo with every other problem), this programs is a solution to make this task much **simpler**, **faster**, and **easily scalable**.

The program sends mails from any linux distro having a cURL library, thus making it a very general purpose and reliable method of sending quick mails. The user interface has been made very functional yet simple. Simplicity is key. 

Before you proceed, a one time setup has to be done for every new sender. So do this for every new email ID you want to use to send emails via Quick Mail.

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


