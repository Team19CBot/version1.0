#include <iostream>
using namespace std;
 
int main()
{
    cout << "Content-type:text/html\r\n\r\n";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<link rel = 'stylesheet' href='css/layui.css' media='all'>\n";
    cout << "<title>CBot</title>\n";
    cout << "</head>\n";
    cout << "<body>\n";
    cout <<"<ul class='layui-nav layui-bg-cyan' lay-filter=''>\n";
     cout <<"<li class='layui-nav-item layui-this'><a href=''>CBot</a></li>\n";
    cout <<"<li class='layui-nav-item'><a href=''>UPDATE</a></li>\n";
    cout <<"<li class='layui-nav-item'><a href=''>MAINTAIN</a></li>\n";
    cout <<"</ul>\n";
    cout << "</body>\n";
    cout << "</html>\n";
 
    return 0;
}