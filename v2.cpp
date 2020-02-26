#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>          
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAXLEN 80
#define QUESTION_LENGTH 256

int main(void)
{
    printf("Content-Type:text/html\n\n");
    cout << "<!DOCTYPE>";
    cout << "<html>\n";
    cout << "<head>\n";
    cout << "<link rel = 'stylesheet' href='css/layui.css' media='all'>\n";
    cout << "<title>CBot</title>\n";
    cout << "</head>\n";
//    cout << "<body onbeforeunload=\"checkLeave()\">\n";
    cout <<"<div>\n";
    cout <<"<ul class='layui-nav layui-bg-cyan' lay-filter=''>\n";
    cout <<"<li class='layui-nav-item layui-this'><a href=''>CBot</a></li>\n";
    cout <<"<li class='layui-nav-item'><a href=''>UPDATE</a></li>\n";
    cout <<"<li class='layui-nav-item'><a href=''>MAINTAIN</a></li>\n";
    cout <<"</ul>\n";
    cout <<"</div>\n";

    cout <<"<div  id='chatBox' class='layui-fluid' style='overflow:auto; height: 60%  '>\n";

    cout <<"<div >\n";
    cout <<"<img src='../image/cbot.jpg' width='3%' height='10%'  style='position:absolute; top:7% ;left:2%'/>\n";
    cout <<"<div style='margin-left:6% ;margin-top:3% ;border-style:outset;max-width:200px;min-width:100px background:'#97cbff''>Welcome!<br>what's your problem?</div>\n";
    cout <<"</div>\n";

    cout <<"</div>\n";

    cout <<"<div  class='layui-fluid' style='height: 20% margin: 0 auto; border:1.5px solid #778899 ; color:#FFFAFA ;background:#778899'>\n";
    cout << "Maybe you want to ask:  \n";
    cout << "<button type='button' onclick=\"alert('askPointer')\" class='layui-btn layui-btn-sm layui-btn-radius' style='margin-left:10px; background:#ADD8E6 ;color:#FFFACD'>Pointer</button>\n";
    cout << "<button type='button'  onclick=\"alert('askMemory')\"class='layui-btn layui-btn-sm layui-btn-radius' style='margin-left:15px;background:#ADD8E6 ;color:#FFFACD'>Memory Management</button> \n";
    cout << "<button type='button' onclick=\"alert('askStructure')\" class='layui-btn layui-btn-sm layui-btn-radius' style='margin-left:20px;background:#ADD8E6 ;color:#FFFACD'>Structure</button>\n";
    cout <<"</div>\n";

    cout <<"<iframe name='server' style='display:none' id='server'></iframe>\n";
    cout <<"<form class='layui-form' action='/cgi-bin/v2.cgi' method='post'  target='server'>\n";
    //cout <<"<form class='layui-form' action='/cgi-bin/v1.cgi' method='post'  target='server'>\n";
    cout <<" <div class='layui-form-item layui-form-text' style='left:1%' id='words'>\n";
    cout <<"<textarea name='ques' id='question' placeholder='Please enter your question...' class='layui-textarea'></textarea>\n";
    cout <<"<div class='layui-form-item' style='margin-left:93%'>\n";
    cout << "<button onclick=\"func('Please wirte your question')\" class='layui-btn' id='quesSubmit'>Send(S)</button>\n";
    cout <<"</div>\n";
    cout <<"</div>\n";
    cout <<"</div>\n";
    cout <<"</form>\n";
    cout << "</body>\n";

    cout << "<script>\n";      
    cout << "var layer=document.createElement(\"div\")\n";        
    cout << "layer.id=\"layer\"\n";     
    cout << "function func(date){\n";   
    //cout <<     "alert(\"you\");";    
    //cout <<     "var value=document.getElementById(\"question\").value;\n";
    //cout <<     "document.write(value)\n";  
    //printf("%s",value);      
    cout <<    "var style={\n";            
    //cout <<    "background:\"#f00\",\n";            
    cout <<    "background: \"8A8A8A\",\n";
    cout <<    "position:\"absolute\",\n";            
    cout <<    "zIndex:10,\n";           
    cout <<    "width:\"300px\",\n";            
    cout <<    "height:\"80px\",\n";           
    cout <<    "left:\"45%\",\n";            
    cout <<    "top:\"50%\",\n";            
    cout <<    "marginLeft:\"-100px\",\n";            
    cout <<    "marginTop:\"-40px\"\n";        
    cout <<    "}\n";



     
    cout <<        "for(var i in style)\n";            
    cout <<            "layer.style[i]=style[i];\n";       
    cout <<         "var value=document.getElementById(\"question\").value;\n";
    cout <<         "if(document.getElementById(\"layer\")==null){\n";    
     //cout <<     "alert(\"you\");";            
    //cout <<                "layer.innerHTML=date;\n";                    
    //cout <<                "var value=document.getElementById(\"question\").value;\n";
    cout <<                "if(value.length==0)\n";
    cout <<                "{\n";
    cout <<                    "document.body.appendChild(layer);\n";                     
    cout <<                    "layer.innerHTML=date;\n";      
    cout <<                    "layer.style.textAlign=\"center\";\n";            
    cout <<                    "layer.style.lineHeight=\"80px\";\n";        
    cout <<                    "setTimeout(\"document.body.removeChild(layer)\",2500)\n";
    // cout <<                      "setTimeout(function(){\n";
    // cout <<                          "document.body.removeChild(layer);\n";
    // cout <<                          "},10000);\n";
    cout <<                "}\n";
    cout<<             "else{\n";  
         //cout <<     "alert(\"you\");";  
    cout <<                    "document.getElementById(\"question\").value='';\n";   
    cout <<                    "var newQues=document.createElement(\"div\");\n";        
    cout <<                     "newQues.id=\"newQues\";\n"; 
    cout<<                      "newQues.style.height='70px';\n";
    cout<<                      "newQues.style.position='relative';\n";
     cout<<                     "newQues.setAttribute('text-align','center');\n";
    cout<<                     "newQues.setAttribute('line-height','70px');\n";
    


    cout<<                      "var user=document.createElement(\"img\");\n";
    cout<<                      "user.src='../image/user.jpg';\n";
    cout<<                       "var imgWidth=document.createAttribute(\"width\");\n";
    cout<<                      "imgWidth.value='50px' ;\n";
    cout<<                       "var imgHeight=document.createAttribute(\"height\");\n";
    cout<<                      "imgHeight.value='50px' ;\n";
    cout<<                      "user.setAttributeNode(imgWidth);\n";
    cout<<                      "user.setAttributeNode(imgHeight);\n";
    cout<<                     "user.style.position='absolute';\n";
    cout<<                     "user.style.right='2%';\n";
    cout<<                     "user.style.margin='auto';\n";
    cout<<                      "newQues.appendChild(user);\n"; 

    /* cout <<    "var textStyle={\n";            
    //cout <<    "background:\"#f00\",\n";            
    cout <<    "background: \"0099ff\",\n";
    cout <<    "position:\"absolute\",\n";            
    cout <<    "right:'10%',\n";           
    cout <<    "max-width:\"300px\",\n";            
    cout <<    "min-width:\"100px\",\n";           
    cout <<    "border-style:\"outset\",\n";            
    cout <<    "word-wrap:\"break-word\"\n";            
    cout <<    "}\n";
*/
  
  cout<<                      "var text=document.createElement(\"div\");\n";
    //cout <<                      "for(var i in textStyle)\n";            
    //cout <<                         "text.style[i]=textStyle[i];\n";  
  // cout<<                       "text.setAttribute('max-width','50px');\n";
   //cout<<                       "text.setAttribute('min-width','20px');\n";
   cout<<                      "text.setAttribute('word-wrap','break-word');\n";
   cout<<                       "text.style.backgroundColor='#0099ff';\n";
    cout<<                     "text.style.position='absolute';\n";
    cout<<                     "text.style.right='10%';\n";
    //cout<<                      "text.setAttribute('border-style',\"outset\");\n";
   // cout<<                     "text.setAttribute('text-align','center');\n";
    //cout<<                     "text.setAttribute('line-height','70px');\n";
    cout<<                      "text.innerHTML=value;\n"; 
    cout<<                      "newQues.appendChild(text);\n";                     

   //cout <<     "alert(\"you\");";  
    cout <<                     "var newBox=document.getElementById(\"chatBox\");\n";
    cout<<                      "newBox.appendChild(newQues);\n";  
    cout<<                      "newBox.scrollTop=newBox.scrollHeight;\n";   
    cout<<               "}\n";
    cout <<            "}\n";  
    cout <<        "}\n";
    // cout <<    "}\n";   
    cout <<    "change();\n";      
    cout <<    "function change(){\n";          
    cout <<        "var today;\n";          
    cout <<        "today = new Date();\n";          
    cout <<        "timeString = today.toLocaleString();\n";          
    cout <<        "document.getElementById(\"date\").innerHTML = timeString;\n";          
    cout <<        "setTimeout(\"change();\", 100);\n";      
    cout <<    "}\n";
    // cout <<    "window.onbeforeunload = function (e) {\n";        
    // cout <<        "var e = window.event||a;\n";       
    // // cout <<        "if (e) {\n";          
    // // cout <<           "e.returnValue = 'a';\n";        
    // // cout <<        "}\n";       // Chrome, Safari, Firefox 4+, Opera 12+ , IE 9+        
    // cout <<         "e.returnValue=(\"a\");";
    // cout <<            "return 'a';\n";      
    // cout <<     "};\n";
// cout <<"function checkLeave(){\n";
// cout << "if(event.clientX>document.body.clientWidth&&event.clientY<0||event.altKey){\n";
// cout <<       "event.returnValue=\"asdf\";\n";
// cout <<   "}\n";
// cout <<"}\n";
    cout << "</script>\n";
    cout << "</html>\n";

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
                string answer;
                long len = atoi(lenstr);
                fgets(question, len + 1, stdin);
               /* if(strcmp(question, "ques=")==0)
                {
                     //cout << "You haven't typed anything yet!" <<endl;//change it to an alert box later
                     //exit(0);
                    clock_t delay = 2000; //seconds
                    clock_t start = clock(); //start time
                    while(clock()-start<delay) //wait for seconds
                    {
                        ;
                    } 
                }*/
                //else{
                printf("%s",question);       //print question sentence
                for (int num_of_letters = 0; num_of_letters < QUESTION_LENGTH; num_of_letters++)
                {
                    
                }
                ofstream questionD;          //define
                questionD.open("question.txt",ios::app);  //create an file
                if(!questionD)            //check 
                {
                    cout << "error open" <<endl; //report error
                    exit(0);   
                }
                questionD << question << endl;
                questionD.close();
                ifstream answerD;
                answerD.open("answer.txt",ios::in);
                if(!answerD){
                    cout << "error open" <<endl;
                    exit(0);
                }
                //char ch = answerD.get();
                //if (ch == NULL){
               //     cout << "meta http-equiv=\"refresh\" content=\"200\";url=getpost.cgi";
               // }
               // while(!answerD.eof()) //have not reached the end of file
               // {
              //      if(ch != NULL){
               //         break;
              //      }
               //     cout << "nothing";
               //     cout << "<meta http-equiv=\"refresh\" content=\"200\";url=getpost.cgi\">";                    
               // }
                string temp;
                while (!answerD.eof()){
                    answerD >> temp;
                    answer = answer + " " + temp;
                }
                answerD.close();
                while(answer == " ") 
                {
                    answer = "";
                    clock_t delay = 2000; //seconds
                    clock_t start = clock(); //start time
                    while(clock()-start<delay) //wait for seconds
                    {
                        ;
                    }
                    ifstream answerD;
                    answerD.open("answer.txt",ios::in);
                    if(!answerD){
                        cout << "error open" <<endl;
                        exit(0);
                    }
                    string temp;
                    while (!answerD.eof()){
                        answerD >> temp;
                        answer = answer + " " + temp;
                    }
                    answerD.close();
                    cout <<"1" << answer << "1";
                }
                ofstream answerD2;
                answerD2.open("answer.txt",ios::trunc);
                answerD2.close();
                cout <<"1" << answer << "1";
                //cout << "<meta http-equiv=\"refresh\" content=\"1\";url=getpost.cgi\">";
           // }
            }
        }

    
    return 0;        
}
