// @author: Zhengrui Xue
// @date: Dec 23rd, 2019
// @version: 1.0
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <ctime>
#include <ctype.h>
#include <algorithm>
#include <sstream>
#include "abstractDataType.h"
#include "function.h"

using namespace std;

int main(){
        
        T_BST *head = cons_topic_from_file();
        
        string sInput = "";
        string response = "";
        
        cout << "> Hi, I am CBot. Please enter your question: "<<endl;
        while(1) {
                cout<< "> ";
                getline(cin, sInput);
                
                // remove space
                // sInput.erase( remove_if ( sInput.begin(), sInput.end(), static_cast<int(*)(int)>(&isspace)),sInput.end());
                
                // remove punctuation
                sInput.erase(remove_if ( sInput.begin(), sInput.end(), static_cast<int(*)(int)>(&ispunct)),sInput.end());
                // transform to lower case
                transform(sInput.begin(),sInput.end(),sInput.begin(),::tolower);
                
                response = match2(sInput, head);
                if(sInput == "bye") {
                        cout << "See you!" << endl;
                        break;
                }
                else if(response == "") {
                        cout << "Sorry, I don't understand"<<endl;
                }
                else{
                        cout<<response<<endl;
                }
        }
        
        // delete database
        free_all(head);
        
        
}
