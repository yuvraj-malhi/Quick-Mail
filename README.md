# Quick Mail

## Description
The task of sending emails is often boring and **_time consuming_**. Opening the browser, opening email, logging in, composing and then sending. By chance if you have a slow internet, then it will take forever!

On these lines (as we fo with every other problem), this programs is a solution to make this task much **simpler**, **faster**, and **easily scalable**.

The program sends mails using **_SMTP in C_** from any linux distro having a cURL library, thus making it a very general purpose and reliable method of sending quick mails. The user interface has been made very functional yet simple. Simplicity is key. 

Before you proceed, a one time setup has to be done for every new sender. So do this for every new email ID you want to use to send emails via Quick Mail.

## One Time Setup
Read SETUP.md for details.

## Usage
Now, maximum of 300 mails (or 100 depending on whether the account is gmail, yahoo, office) per day can be sent without any hassle. Here’s an example:

Run the command:    

```sudo ./a.out```

![image](https://user-images.githubusercontent.com/76866159/105606695-e4e13300-5dc0-11eb-8bac-99d2d7bd0c61.png)


Fillout the details for every tab according to the below meanings.

TAB | MEANING
-------|-------
YOUR_MAIL     | Sender’s email ID
MAIL_TYPE     | Among: gmail / yahoo / office / outlook 
PASSWORD      | Sender’s email password. Incorrect password gives “login denied error”
YOUR NAME     | Doesn’t need to be correct, (but it does show up in the receiver’s inbox)
TO	      | Receiver’s email. Incorrect email here would not give an error, but email won’t be sent.
CC	      | CC’s email ID. If left black or if only single digit is passed (like "A" or “1”) then no CC is sent.
CC_NAME       | Again, doesn’t need to be correct, but shows the name in inbox.
SUBJECT       | Subject of email.
BODY  	      | Body of email. (Currently, it can be only text, file upload feature has not been added).

After entering all the details, wait for a few seconds and the program will terminate without showing any error.

Check in the receiver's email:

![image](https://user-images.githubusercontent.com/76866159/105607308-05f75300-5dc4-11eb-808b-64505e36167f.png)

Thus, we can now send multiple TLS encrypter emails without any hastle.

## Scalability & Automation

The best part about this whole program is that it can be very easily used in automation.
There is just a single function mailer() which is taking arguements and doing everything. The main() function has no use at all. 

![image](https://user-images.githubusercontent.com/76866159/105607388-5e2e5500-5dc4-11eb-8214-a22a83bd62f2.png)

main() function just scans and passes the arguements to mailer() which does all the job. Hence, it can be used as an API for any and all purposes.

Do share if you liked my work. Thanks!

:smile:
