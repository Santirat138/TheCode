#include<iostream>
#include<vector>
using namespace std;
//------------------ variable

//------------------ functions

//------------------ class
class Node{
    public:
        char ch;
        int num;
        Node* left;
		Node* right;
        Node(char newCh){
            ch=newCh;
            num=int(ch);
            left=NULL;
            right=NULL;
        }
};
