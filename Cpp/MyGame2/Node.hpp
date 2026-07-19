#include<iostream>
using namespace std;
//------------------ class
class Node{
    public:
        int num;
        Node *left;
        Node *right;
        Node(int numIn, Node *nodeL, Node *nodeR){
            num=numIn;
            left=nodeL;
            right=nodeR;
        }
};
