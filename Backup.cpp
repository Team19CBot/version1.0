// this file is the back-up file
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <math.h>
#include <vector>
#include <sstream>
#include "abstractDataType.h"
#include "function.h"

using namespace std;

// 最初版本的转化函数，将原始答案数据库文件转换为对应匹配值的答案数据库，加快运行时构造答案树的速度
// 该版本已废置
void trans_solution_to_file1(string filein, string fileout, BST *first_level_head, BST *second_level_head) {
        
        string str = "";
        int full_match = 0;
        int first_level_val = 0;
        int second_level_val = 0;
        BST *head = NULL;
        string solution = "";
        ifstream in(filein);
        ofstream out(fileout);
        
        if (!out.is_open()) {
                cout<< "Error: Cannot Open Data.txt File"<< endl;
                /**
                 * release memory...
                 *
                 */
                exit(2);
        }
        
        if (in.is_open())
        {
                while(!in.eof())
                {
                        getline(in, str);
                        // read combinational second_level keyword for each
                        // first_level keyword
                        while(str != "#")
                        {
                                // read first second_level keyword
                                if (str == "##" && !full_match)
                                {
                                        getline(in,str);
                                        if (str != "")
                                        {
                                                // get match value of second_level keyword
                                                if((second_level_val = get_match_val(str, second_level_head)) == -1)
                                                {
                                                        /**
                                                         * release memory...
                                                         *
                                                         */
                                                        exit(1);
                                                }
                                        }
                                        else
                                        {
                                                second_level_val = 0;
                                        }
                                        full_match = 1;
                                }
                                // read following second_level keyword
                                else if (str == "##" && full_match)
                                {
                                        // finish matching solution for last round
                                        // translate solution with match value into data file
                                        out<< "#"<< endl;
                                        out<< first_level_val+second_level_val<< endl;
                                        out<< solution<< endl;
                                        
                                        solution = "";
                                        getline(in, str);
                                        if (str != "")
                                        {
                                                // get match value of second_level keyword
                                                if ((second_level_val = get_match_val(str, second_level_head)) == -1)
                                                {
                                                        /**
                                                         * release memory...
                                                         *
                                                         */
                                                        exit(1);
                                                }
                                        }
                                        else
                                        {
                                                second_level_val = 0;
                                        }
                                }
                                else
                                {
                                        // read solution string
                                        solution += str;
                                }
                                getline(in, str);
                                
                                if (in.eof())
                                {
                                        // meet end and finish reading
                                        solution += str;
                                        // translate solution with match value into data file
                                        out<< "#"<< endl;
                                        out<< first_level_val+second_level_val<< endl;
                                        out<< solution<< endl;
                                        break;
                                }
                        }
                        
                        if (full_match && !in.eof())
                        {
                                // finish one-round of solution matching for
                                // a first_level keyword group
                                full_match = 0;
                                // translate solution with match value into data file
                                out<< "#"<< endl;
                                out<< first_level_val+second_level_val<< endl;
                                out<< solution<< endl;
                                first_level_val = 0;
                                solution = "";
                        }
                        if (!in.eof())
                        {
                                // get match value of first_level keyword
                                getline(in,str);
                                if (str != "")
                                {
                                        if ((first_level_val = get_match_val(str, first_level_head)) == -1)
                                        {
                                                /**
                                                 * release memory...
                                                 *
                                                 */
                                                exit(1);
                                        }
                                }
                                else
                                {
                                        first_level_val = 0;
                                }
                        }
                }
        }
        else
        {
                cout << "Error: Cannot Open Solution.txt File" << endl;
                /**
                 * release memory...
                 *
                 */
                exit(2);
        }
        
        in.close();
        out.close();
}

// search keyword tree and return match value
// 关键字搜寻函数，给定关键字和对应的关键字树，返回关键字的匹配值，若不存在返回-1
int get_match_val(string str, BST *head){
        if (head == NULL)
        {
                cout <<"Error: Tree Dose Not Exist" << endl;
                return -1;
        }
        else
        {
                BST *temp = head;
                do {
                        // check left
                        if ((temp->keyword).compare(str) > 0)
                        {
                                temp = temp->left;
                        }
                        // check right
                        else if ((temp->keyword).compare(str) < 0)
                        {
                                temp = temp->right;
                        }
                        else if ((temp->keyword).compare(str) == 0){
                                return temp->match_val;
                        }
                } while (temp != NULL);
        }
        cout << "Error: No Such keyword" << endl;
        return -1;
}

// construct solution tree from data file
// NOTE: must ensure data.txt file exists, otherwise call trans_solution_to_file()
// return head pointer of solution if succeed, otherwise return NULL
// 根据转换好的答案数据库文件构造数据树，没有优化结构，仅按文件内容顺序构造
BST *cons_solution_from_file(string filename){

}

// construct keyword tree
// first level base_weight = 50
// second level base_weight = 1
// 根据关键字文件构造关键字树，没有优化结构，仅按文件内容顺序构造
BST* cons_keyword_from_file(string filename, int base_weight){
        
        string keyword_str ="";
        BST *head = NULL;
        int num_keyword = 0;
        
        ifstream in(filename);
        
        // open info file...
        if (in.is_open())
        {
                while (!in.eof())
                {
                        num_keyword++;
                        // read keyword line from file
                        getline(in,keyword_str);
                        
                        // split synonym keyword string
                        vector<string> res;
                        string result;
                        stringstream input(keyword_str);
                        // remove space and split
                        while(input>>result)
                        {
                                res.push_back(result);
                        }
                        // construct tree using each keyword
                        for(int i=0;i<res.size();i++)
                        {
                                // synonym has same match value
                                cons_keyword_BST(res[i].c_str(), &head, num_keyword*base_weight);
                        }
                }
        }
        else
        {
                cout<<"Error: cannot open keyword file"<<endl;
                // memory release...
                
                exit(1);
        }
        in.close();
        return head;
}

// construct binary search tree for keywords according to alphabet
// 关键字数构造具体实现的函数，根据字母表顺序构造搜寻二叉树
void cons_keyword_BST(string keyword, BST ** head, int match_val) {
        
        if (*head == NULL)
        {
                BST *bst = new BST();
                bst->keyword = keyword;
                bst->match_val = match_val;
                bst->left = NULL;
                bst->right = NULL;
                *head = bst;
        }
        else
        {
                BST *temp = *head;
                do {
                        // check left
                        if ((temp->keyword).compare(keyword) > 0)
                        {
                                if (temp->left == NULL){
                                        BST *bst = new BST();
                                        bst->keyword = keyword;
                                        bst->match_val = match_val;
                                        bst->left = NULL;
                                        bst->right = NULL;
                                        temp->left = bst;
                                        break;
                                }
                                else
                                {
                                        temp = temp->left;
                                }
                        }
                        // check right
                        else
                        {
                                if (temp->right == NULL){
                                        BST *bst = new BST();
                                        bst->keyword = keyword;
                                        bst->match_val = match_val;
                                        bst->left = NULL;
                                        bst->right = NULL;
                                        temp->right = bst;
                                        break;
                                }
                                else
                                {
                                        temp = temp->right;
                                }
                        }
                } while (temp != NULL);
        }
}


// 目前使用的答案数据库转换函数
void trans_solution_to_file(string filein, string fileout, BST *first_level_head, BST *second_level_head) {
        
        string str = "";
        string solution = "";
        
        int full_match = 0;
        int first_keyword_matched = 0;
        int first_level_val = 0;
        int second_level_val = 0;
        
        ifstream in(filein);
        ofstream out(fileout);
        
        if (!out.is_open()) {
                cout<< "Error: Cannot Open Data.txt File"<< endl;
                /**
                 * release memory...
                 *
                 */
                exit(2);
        }
        
        if (in.is_open())
        {
                while(!in.eof())
                {
                        getline(in, str);
                        
                        if (str == "#" && !first_keyword_matched)
                        {
                                first_keyword_matched = 1;
                                getline(in, str);
                                if (str != "")
                                {
                                        if((first_level_val = get_match_val(str, first_level_head)) == -1)
                                        {
                                                /**
                                                 * release memory...
                                                 */
                                                exit(1);
                                        }
                                        cout<< "1: ";
                                        cout<< first_level_val << endl;
                                }
                                else
                                {
                                        first_level_val = 0;
                                }
                        }
                        else if (str == "#" && first_keyword_matched)
                        {
                                //first_keyword_matched = 0;
                                full_match = 0;
                                
                                out<< "#"<< endl;
                                out<< first_level_val+second_level_val<< endl;
                                out<< solution<< endl;
                                solution = "";
                                
                                getline(in,str);
                                if (str != "")
                                {
                                        if((first_level_val = get_match_val(str, first_level_head)) == -1)
                                        {
                                                /**
                                                 * release memory...
                                                 */
                                                exit(1);
                                        }
                                        cout<< "2: ";
                                        cout<< first_level_val << endl;
                                }
                                else
                                {
                                        first_level_val = 0;
                                }
                        }
                        else if (str == "##" && !full_match)
                        {
                                full_match = 1;
                                getline(in,str);
                                if (str != "")
                                {
                                        // get match value of second_level keyword
                                        if((second_level_val = get_match_val(str, second_level_head)) == -1)
                                        {
                                                /**
                                                 * release memory...
                                                 */
                                                exit(1);
                                        }
                                }
                                else
                                {
                                        second_level_val = 0;
                                }
                        }
                        else if (str == "##" && full_match)
                        {
                                out<< "#"<< endl;
                                out<< first_level_val+second_level_val<< endl;
                                out<< solution<< endl;
                                solution = "";
                                
                                getline(in,str);
                                if (str != "")
                                {
                                        // get match value of second_level keyword
                                        if((second_level_val = get_match_val(str, second_level_head)) == -1)
                                        {
                                                /**
                                                 * release memory...
                                                 */
                                                exit(1);
                                        }
                                }
                                else
                                {
                                        second_level_val = 0;
                                }
                        }
                        else
                        {
                                solution += str;
                        }
                }
                cout<< first_level_val << endl;
                out<< "#"<< endl;
                out<< first_level_val+second_level_val<< endl;
                out<< solution<< endl;
        }
        else
        {
                cout << "Error: Cannot Open Solution.txt File" << endl;
                /**
                 * release memory...
                 */
                exit(2);
        }
        in.close();
        out.close();
}


