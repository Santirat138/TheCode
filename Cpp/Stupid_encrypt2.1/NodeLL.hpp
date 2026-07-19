#include<iostream>
using namespace std;
//------------------ variable
int top=0;
//------------------ class
class Info{
    public:
        int numOrder;
        string str;
        int num;
        Info(){
            numOrder=-1;
            num=-1;
        }
        void addInfo(int noIn, string strIn, int numIn){
            numOrder=noIn;
            str=strIn;
            num=numIn;
        }
};
class Node{
    public:
        Info info;
        Node* next=NULL;
        Node(Node* nodeIn){
            next=nodeIn;
        }
        void showInfo(){
            cout<<info.numOrder<<": "<<info.str<<", "<<info.num<<endl;
        }
};
class LinkedList{
    public:
        int nodeAmount=0;
        Node* head=NULL;
        Node* tail=NULL;
        void addInfoLastNode(string newStr, int newInt){
            Node* newNode=new Node(NULL);
            if(head==NULL){
                head=newNode;
                nodeAmount=1;
            }
            else{
                (*tail).next=newNode;
                nodeAmount++;
            }
            tail=newNode;
            (*newNode).info.addInfo(nodeAmount, newStr, newInt);
        }
        void addStrLastNode(string newStr){
            Node* newNode=new Node(NULL);
            if(head==NULL){
                head=newNode;
                nodeAmount=1;
            }
            else{
                (*tail).next=newNode;
                nodeAmount++;
            }
            tail=newNode;
            (*newNode).info.addInfo(nodeAmount, newStr, -1);
        }
        void addIntLastNode(int newNum){
            Node* newNode=new Node(NULL);
            if(head==NULL){
                head=newNode;
                nodeAmount=1;
            }
            else{
                (*tail).next=newNode;
                nodeAmount++;
            }
            tail=newNode;
            (*newNode).info.addInfo(nodeAmount, "_", newNum);
        }
        void showLL(){
            for(Node* curr=head;curr!=NULL;curr=(*curr).next){
                (*curr).showInfo();
            }
        }
};
//------------------ functions
char pop(string str){
	return str[top++];
}