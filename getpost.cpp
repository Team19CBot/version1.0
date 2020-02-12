#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

#define MAXLEN 80

int main(void)
{
      printf("Content-Type:text/html\n\n");
     char *pRequestMethod;
    setvbuf(stdin, NULL, _IONBF, 0);     /*turn off stdin's cache*/ 
    pRequestMethod = getenv("REQUEST_METHOD"); 
        if (strcmp(pRequestMethod, "POST") == 0) {
        char *lenstr = getenv("CONTENT_LENGTH");
            //if(lenstr == NULL || len > MAXLEN)
            if(lenstr == NULL)
            {
                printf("<P>Post form error");
            }
            else
            {
                char question[256];
                long len = atoi(lenstr);
                fgets(question, len + 1, stdin);
                printf("%s",question);
            }
    }
    return 0;        
}