// Linked list of linked list.
#include<iostream>
using namespace std;
//------------------ class
class Node{
    public:
        int num;
        Node* next;
        Node(int numIn, Node* nodeIn){
            num=numIn;
            next=nodeIn;
        }
};
class LinkedList{
    public:
        Node* head;
        int mainNum;
        LinkedList* next;
        LinkedList(LinkedList* llIn){
            head=NULL;
            mainNum=0;
            next=llIn;
        }
        void addFirst(int newNum){
            head=new Node(newNum, head);
            mainNum++;
        }
};
class LIST_LinkedList{
    public:
        LinkedList* headLL;
        int num;
        LIST_LinkedList(){
            headLL=NULL;
            num=0;
        }
        void addLL(LinkedList* newLL){
            
        }
};
//------------------ main
int main(){

}