#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 
 
//#include <cgicc/CgiDefs.h> 
//#include <cgicc/Cgicc.h> 
//#include <cgicc/HTTPHTMLHeader.h> 
//#include <cgicc/HTMLClasses.h>  

#include <cstdio>
#include <iostream>

using namespace std;
//using namespace Cgicc; 
 
int main ()
{
   char *method;
   string user[3] = {"user1","user2","user3"};
   string pass[3] = {"password1","2","3"};
   int flag = 0;

   cout << "Content-type:text/html\r\n\r\n";
   cout << "<html>\n";
   cout <<         "<head>\n";
   cout <<                 "<title>CBot-login</title>\n";
   cout <<                 "<link rel=\"shortcut icon\" type=\"image/x-icon\" href=\"/favicon.ico\" />\n";
   cout <<                 "<bookmark href=\"/favicon.ico\"/>\n";
   cout <<                 "<link rel=\"stylesheet\" href=\"/login.css\">\n";
   cout <<         "</head>\n";
   cout <<  "<body background=\"/background.jpg\" style=\"background-repeat:no-repeat;background-size:100% 100%;\"\n>";
   cout <<  "<div class = \"navigation_bar\">\n";
   cout <<  "<a href=\"/cgi-bin/cpp_get.cgi\" rel=\"noopener noreferrer\">CBot</a>\n";
   cout <<  "<a href=\"/cgi-bin/update.cgi\" rel=\"noopener noreferrer\">update</a>\n";
   cout <<  "<a href=\"/cgi-bin/maintain.cgi\" rel=\"noopener noreferrer\">maintain</a>\n";
   cout <<  "</div>\n";
   cout <<  "<div class=\"box\">\n";
   cout <<        "<h2>Login</h2>\n";
   cout <<        "<form action=\"/cgi-bin/cgi_test.cgi\" method=\"get\">\n";
   cout <<            "<div class=\"inputbox\">\n";
   cout <<                "<input type=\"text\" name=\"username\" required=\"\">\n";
   cout <<                "<label>Username</label>\n";
   cout <<            "</div>\n";
   cout <<            "<div class=\"inputbox\">\n";
   cout <<                "<input type=\"password\" name=\"password\" required=\"\">\n";
   cout <<                "<label>Password</label>\n";
   cout <<            "</div>\n";
   cout <<            "<input type=\"submit\" name=\"\" value=\"submit\">\n";
   cout <<        "</form>\n";
   cout <<    "</div>\n";

   cout <<  getenv("QUERY_STRING");
   method = getenv("QUERY_STRING"); 
   if(method == NULL){
      cout <<  "nothing has been entered\n";
   }
 
   string temp =  method;
   for (int i = 0; i<3; i++){
      string tempAccount = "username="+user[i]+"&password="+pass[i];
      if(temp==tempAccount){
            cout <<  "<div style=\"position:absolute;margin-left:40%;margin-top:35%;\">you are a member of our system!</div>\n";
            cout << "</body>\n";
            cout << "</html>\n";
            flag++;
            return 0;
      }  
   }
   if(flag==0){
      cout <<  "<div style=\"position:absolute;margin-left:40%;margin-top:35%;\">username or password is wrong</div>\n";
   }
   else{
      flag=0;
   }

   cout <<  "</body>\n";
   cout << "</html>\n";
   
   return 0;
}