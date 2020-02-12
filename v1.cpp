#include <iostream>
#include <string.h>
using namespace std;
 

int main()
{

    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<link rel = 'stylesheet' href='css/layui.css' media='all'>\n";
    cout << "<title>CBot</title>\n";
    cout << "</head>\n";
    cout << "<body'>\n";
    cout <<"<div>\n";
    cout <<"<ul class='layui-nav layui-bg-cyan' lay-filter=''>\n";
    cout <<"<li class='layui-nav-item layui-this'><a href=''>CBot</a></li>\n";
    cout <<"<li class='layui-nav-item'><a href=''>UPDATE</a></li>\n";
    cout <<"<li class='layui-nav-item'><a href=''>MAINTAIN</a></li>\n";
    cout <<"</ul>\n";
    cout <<"</div>\n";

    cout <<"<div  class='layui-fluid' style='height: 55% '>\n";
    cout <<"<img src='../image/cbot.jpg' width='3%' height='10%'  style='position:absolute; top:0.1% ;left:2%'/>\n";
    cout <<"<div style='margin-left:6% ;margin-top:3%'>Welcome!<br>what's your problem?</div>\n";
    cout <<"</div>\n";

    

    cout <<"<div  class='layui-fluid' style='height: 20% margin: 0 auto; border:1.5px solid #778899 ; color:#FFFAFA ;background:#778899'>\n";
    cout << "Maybe you want to ask:  \n";
    cout << "<button type='button' onclick='askPointer()' class='layui-btn layui-btn-sm layui-btn-radius' style='margin-left:10px; background:#ADD8E6 ;color:#FFFACD'>Pointer</button>\n";
    cout << "<button type='button'  onclick='askPointer()'class='layui-btn layui-btn-sm layui-btn-radius' style='margin-left:15px;background:#ADD8E6 ;color:#FFFACD'>Memory Management</button> \n";
    cout << "<button type='button' onclick='askPointer()' class='layui-btn layui-btn-sm layui-btn-radius' style='margin-left:20px;background:#ADD8E6 ;color:#FFFACD'>Structure</button>\n";
    cout <<"</div>\n";

    cout <<"<iframe name='server' style='display:none' id='server'></iframe>\n";
    cout <<"<form class='layui-form' action='/cgi-bin/getpost.cgi' method='post' target='server'>\n"; 
    //cout <<"<form class='layui-form' action='/cgi-bin/v1.cgi' method='post'  target='server'>\n";
    cout <<" <div class='layui-form-item layui-form-text' style='left:1%'>\n";
    cout <<"<textarea name='desc' placeholder='Please enter your question...' class='layui-textarea'></textarea>\n";
    cout <<"<div class='layui-form-item' style='margin-left:93%'>\n";
    cout << "<button class='layui-btn'>Send(S)</button>\n";
    cout <<"</div>\n";
    cout <<"</div>\n";
    cout <<"</div>\n";
    cout <<"</form>\n";
    cout << "</body>\n";
    cout << "</html>\n";



   
    return 0;
}