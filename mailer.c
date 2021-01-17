#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <stdlib.h>
 
 
char *payload_text[8]; 

struct upload_status 
{ int lines_read; };
 
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
	struct upload_status *upload_ctx = (struct upload_status *)userp;
 	const char *data;
 
  	if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) 
    		return 0;
  	
 
  	data = payload_text[upload_ctx->lines_read];
 
  	if(data) 
	{
    		size_t len = strlen(data);
    		memcpy(ptr, data, len);
    		upload_ctx->lines_read++;
 
    		return len;
  	}
 
	return 0;
}

void mailer(char* YOUR_MAIL,char* MAIL_TYPE,char* PASSWORD,char* YOUR_NAME,char *TO,char* CC,char* CC_NAME,char* SUBJECT,char* BODY)
{
	int i=0;

	payload_text[i]= (char *)malloc(10+strlen(TO));
	strcpy(payload_text[i],"To: ");
	strcat(payload_text[i],TO);
	strcat(payload_text[i],"\r\n");

	i++;

	payload_text[i]= (char *)malloc(10+ strlen(YOUR_MAIL)+ strlen(YOUR_NAME));
	strcpy(payload_text[i],"From: ");
	strcat(payload_text[i],YOUR_MAIL);
	strcat(payload_text[i],"(");
	strcat(payload_text[i],YOUR_NAME);
	strcat(payload_text[i],")\r\n");
	
	i++;

	if(strlen(CC)>1)
	{
		payload_text[i]= (char *)malloc(10+ strlen(CC)+ strlen(CC_NAME));
		strcpy(payload_text[i],"Cc: ");
		strcat(payload_text[i],CC);
		strcat(payload_text[i],"(");
		strcat(payload_text[i],CC_NAME);
		strcat(payload_text[i],")\r\n");
	
		i++;		
	}




	payload_text[i]= (char *)malloc(12+strlen(SUBJECT));
	strcpy(payload_text[i],"Subject: ");
	strcat(payload_text[i],SUBJECT);
	strcat(payload_text[i],"\r\n");

	i++;
	
	payload_text[i]= (char *)malloc(3);
	strcpy(payload_text[i],"\r\n");

	i++;					

	payload_text[i]= (char *)malloc(2+strlen(BODY));
	strcpy(payload_text[i],BODY);
	strcat(payload_text[i],"\r\n");


	char MAIL_TYPES[4][30]={"gmail"         ,"outlook"              ,"office"                       ,"yahoo"              };
	char SERVERS[4][30]   ={"smtp.gmail.com","smtp-mail.outlook.com","smtp://smtp.office365.com:587","smtp://smtp.mail.yahoo.com:587"};
	char SERVER[30];

	for(int i=0; i<5; i++)
	{
		if(i==4)
		{
			printf("Error - server not listed in code\n");
			for(int i=0; i<8; i++) free(payload_text[i]);
		}
		
		if(strcmp(MAIL_TYPES[i],MAIL_TYPE)==0)
		{
			strcpy(SERVER,SERVERS[i]);
			break;
		}

	}

	CURL *curl;
  	CURLcode res = CURLE_OK;
  	struct curl_slist *recipients = NULL;
  	struct upload_status upload_ctx;
 
  	upload_ctx.lines_read = 0;
 
  	curl = curl_easy_init();
  	if(curl) {
    		curl_easy_setopt(curl, CURLOPT_USERNAME, YOUR_MAIL);
    	
		curl_easy_setopt(curl, CURLOPT_PASSWORD, PASSWORD);
    	
		curl_easy_setopt(curl, CURLOPT_URL, SERVER);
    	
		curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
    	
		curl_easy_setopt(curl, CURLOPT_CAINFO, "/path/to/certificate.pem");
    	
		curl_easy_setopt(curl, CURLOPT_MAIL_FROM, YOUR_MAIL);
    	
		recipients = curl_slist_append(recipients, TO);
	
		if(strlen(CC)>1)
    			recipients = curl_slist_append(recipients, CC);
    	
		curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
    	
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
    	
		curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
    	
		curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
 
		//Un-comment the below line to see exactly what is happening (OR)
		//if an error is being encountered, what exactly it is
    		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
 
    		res = curl_easy_perform(curl);
    	
		if(res != CURLE_OK)
      			fprintf(stderr, "curl_easy_perform() failed: %s\n",
        
		curl_easy_strerror(res));
    	
		curl_slist_free_all(recipients);
    	
		curl_easy_cleanup(curl);
  	}
	for(int i=0; i<8; i++) free(payload_text[i]);

	//The variable "res" stores the state of transfer, eg error encountered etc.
	//Maybe used by the programmer later	
	//return (int)res;
}

int main()
{
	char your_mail[50],mail_type[20],password [30] ,your_name[30];
	char to[50],cc[50],cc_name[30] ,subject[20], body[100];

	printf("Enter the following details:\n");
	printf("Your mail       (xyz@abc.com)         - "); scanf("%[^\n]s",your_mail); getchar();
	printf("Your mail type  (gmail/yahoo/office)  - "); scanf("%[^\n]s",mail_type); getchar();
	printf("Your password                         - "); scanf("%[^\n]s", password); getchar();
	printf("Your Name       (Mr. XYZ)             - "); scanf("%[^\n]s",your_name); getchar();
	printf("Receiver's mail (pqr@uvw.com)         - "); scanf("%[^\n]s",       to); getchar();
	printf("CC mail         (efg@mno.com)         - "); scanf("%[^\n]s",       cc); getchar();
	printf("CC name         (Mr. EFG)             - "); scanf("%[^\n]s",  cc_name); getchar();
	printf("Subject                               - "); scanf("%[^\n]s",  subject); getchar();
	printf("Body -                                \n"); scanf("%[^\n]s",     body); getchar();
	

	
	mailer(your_mail,mail_type,password,your_name,to,cc,cc_name,subject,body);
	return 1;
}

