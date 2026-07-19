#include<iostream>
#define nullNum -1
using namespace std;

//---------------------- class node
class node1{
    public:
        int num;
        node1 *next;
        node1(int numIn){
            num=numIn;
            next=nullptr;
        }
};
node1 *nullNode=new node1(nullNum);
//---------------------- class linkList
class linkList{
    public:
        node1 *head;
        node1 *tail;
        linkList(){
            head=nullptr;
            tail=nullptr;
        }
        void addLast(int newNum);
        void showLL();
};
void linkList::addLast(int newNum){
    node1 *newNode=new node1(newNum);
    if(tail!=nullptr){
        tail->next=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::showLL(){
    for(node1 *currNode=head;currNode!=nullptr;currNode=currNode->next){
        cout<<currNode->num<<", ";
    }
    cout<<endl;
}