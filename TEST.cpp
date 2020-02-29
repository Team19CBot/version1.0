// test function in function.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <math.h>
#include "abstractDataType.h"
#include "function.h"

using namespace std;

void printTree(BST *head);

int main() {
        //Topic * topic = set_up_topic("array");
        
        fstream word("newtext.txt",ios::app|ios::out);
        
        
        T_BST *head = cons_topic_from_file();
        
        match1("what is array", head, word);
        cout<< match2("how to use array", head) << endl;
        free_all(head);
        
        //trans_solution_to_file("array");
        
        /*
        BST *head1 = NULL;
        head1 = cons_keyword_from_file("./array/first_level.txt", 50);
        //printTree(head1);
        
        BST * head2 = NULL;
        head2 = cons_keyword_from_file("./array/second_level.txt", 1);
        //printTree(head2);
        
        trans_solution_to_file("./array/solution.txt","./array/database.txt", head1, head2);
        
        BST * head3 = NULL;
        head3 = cons_solution_from_file("./array/data.txt");
        printTree(head3);
        */
        
}

