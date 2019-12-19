#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <ctime>
#include <ctype.h>
#include <algorithm>
#include <sstream>

using namespace std;

struct tree {
        string word;
        int val;
        tree *left;
        tree *right;
};
typedef tree Tree;

class Topic {
public:
        string name;
        Tree * first_level;
        Tree * second_level;
        Tree * solution;
};

void Database(Tree ** head1, Tree ** head2, Tree ** sol);
void deleteDatabase(Tree *head1, Tree *head2, Tree *sol);
string find_match(string input, Topic *topic);
int findInLevel(string target, Tree * head);
string getSolution(int val, Tree * head);
void deleteDatabase(Topic *head);

int main(){
        Topic * topic = new Topic();
        topic->name = "array";
        Database(&(topic->first_level),&(topic->second_level),&(topic->solution));
        
        string sInput = "";
        string sResponse = "";
        
        
        cout << "> Hi, I am CBot. Please enter your question: "<<endl;
        while(1) {
                cout<< "> ";
                getline(cin, sInput);
                
                // remove space
                //sInput.erase( remove_if ( sInput.begin(), sInput.end(), static_cast<int(*)(int)>(&isspace)),sInput.end());
                // remove punctuation
                sInput.erase(remove_if ( sInput.begin(), sInput.end(), static_cast<int(*)(int)>(&ispunct)),sInput.end());
                // transform to lower case
                transform(sInput.begin(),sInput.end(),sInput.begin(),::tolower);
                
                string response = find_match(sInput, topic);
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
        //deleteDatabase(topic);
        
        
}

void Database(Tree ** head1, Tree ** head2, Tree ** sol){
        // construct 1st level
        Tree * t11 = new Tree;
        Tree * t12 = new Tree;
        Tree * t13 = new Tree;
        
        t11->word = "how";
        t11->val = 1;
        t12->word = "what";
        t12->val = 2;
        t13->word = "why";
        t13->val = 3;
        
        t12->left = t11;
        t12->right = t13;
        t11->left = NULL;
        t11->right = NULL;
        t13->left = NULL;
        t13->right = NULL;
        
        *head1 = t12;
        
        // construct 2nd level
        Tree * t21 = new Tree;
        Tree * t22 = new Tree;
        Tree * t23 = new Tree;
        Tree * t24 = new Tree;
        Tree * t25 = new Tree;
        Tree * t26 = new Tree;
        Tree * t27 = new Tree;
        
        t21->word = "use";
        t21->val = 1;
        
        t22->word = "declare";
        t22->val = 2;
        
        t23->word = "access";
        t23->val = 1;
        
        t24->word = "create";
        t24->val = 2;
        
        t25->word = "length";
        t25->val = 3;
        
        t26->word = "type";
        t26->val = 4;
        
        t27->word = "size";
        t27->val = 3;
        
        
        t25->left = t24;
        t25->right = t26;
        t24->left = t23;
        t24->right = t22;
        t23->left = NULL;
        t23->right = NULL;
        t22->left = NULL;
        t22->right = NULL;
        t26->left = t27;
        t26->right = t21;
        t27->left = NULL;
        t27->right = NULL;
        t21->left = NULL;
        t21->right = NULL;
        
        *head2 = t25;
        
        //construct solution
        Tree *s1 = new Tree;
        Tree *s2 = new Tree;
        Tree *s3 = new Tree;
        Tree *s4 = new Tree;
        Tree *s5 = new Tree;
        Tree *s6 = new Tree;
        
        // how to use array
        s1->word="\nYou can read/write individual elements of the array by using the array name and index in the same way you would use any other variable\nExample:\nhighscores[2] = 42\n";
        s1->val=11;
        // what is array
        s2->word="\nArray is a collection of data with same type\n";
        s2->val=20;
        // how to create/declare the array
        s3->word="\nDataType VaribleName[size] \nExample:\n int num[2]\n";
        s3->val=12;
        // why to use array
        s4->word="\nImprove effciency when manipulating multiple data with same type\n";
        s4->val=31;
        // get length/size of array
        s5->word="\nUsing sizeof(array)/sizeof(data type of array)\n Example:\n arr = int[2] length = sizeof(arr)/sizeof(int)\n";
        s5->val=13;
        // what data type of array can store
        s6->word="\nBasically array can be declared as any data type\n";
        s6->val=24;
        
        
        s2->left = s3;
        s2->right = s6;
        s6->left = NULL;
        s6->right = s4;
        s4->left = NULL;
        s4->right = NULL;
        s3->left = s1;
        s3->right = s5;
        s1->left = NULL;
        s1->right = NULL;
        s5->left = NULL;
        s5->right = NULL;
        
        *sol=s2;
}

string find_match(string sInput, Topic *topic) {
        
        int val;
        vector<string> res;
        //暂存从word中读取的字符串
        string result;
        //将字符串读到input中
        stringstream input(sInput);
        //依次输出到result中，并存入res中
        while(input>>result){
                res.push_back(result);
        }
        
        int find = 0;
        for(int i=0;i<res.size();i++){
                if (!strcmp(res[i].c_str(),topic->name.c_str())){
                        // find the topic
                        find = 1;
                        break;
                }
        }
        if (!find) {
                return "";
        }
        
        //search in first level
        int val1;
        find = 0;
        for (int i=0; i<res.size();i++){
                if ((val1 = findInLevel(res[i],topic->first_level)) != 0){
                        find = 1;
                        break;
                }
        }
        
        if (!find){
                return "";
        }
        
        //search in second level
        int val2;
        for (int i=0;i<res.size();i++){
                if((val2 = findInLevel(res[i], topic->second_level)) != 0){
                        break;
                }
        }
        
        return getSolution(val1*10+val2, topic->solution);
        
}

int findInLevel(string target, Tree * head) {
        Tree *temp = head;
        while (temp != NULL){
                int result = strcmp(target.c_str(), temp->word.c_str());
                if (!result){
                        return temp->val;
                }
                else if (result < 0){
                        temp = temp->left;
                }
                else {
                        temp = temp->right;
                }
        }
        return 0;
}


string getSolution(int val, Tree * head) {
        Tree *temp = head;
        while (temp != NULL) {
                if (val == temp->val) {
                        return temp->word;
                }
                else if (val < temp->val) {
                        temp = temp->left;
                }
                else {
                        temp = temp->right;
                }
        }
        return "";
}

void deleteDatabase(Topic *head){
        // delete
}

