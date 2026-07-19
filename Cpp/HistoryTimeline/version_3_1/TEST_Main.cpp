#include<iostream>
using namespace std;
//----------------- class
class Data{
    public:
        int month, year;
        string eventName;
        void createData(int m, int y, string name){
            month=m;
            year=y;
            eventName=name;
        }
};
class Node{
    public:
        Data data;
        Node* next;
        Node(int m, int y, string name, Node* node){
            data.createData(m, y, name);
            next=node;
        }
};
class LinkedList{
    public:
        string name;
        Node* head=nullptr;
        void showLL(){
            for(Node* n=head;n!=nullptr;n=(*n).next){
                cout<<(*n).data.month<<"/"<<(*n).data.year<<": "<<(*n).data.eventName<<endl;
            }
            cout<<endl;
        }
        void addFirst(int m, int y, string name){
            Node* newNode=new Node(m, y, name, head);
            head=newNode;
        }
        void sort(){
            for(Node* node_A=head;node)
        }
};
//----------------- main
int main(){
    LinkedList ll;
    ll.addFirst(1, 5, "a");
    ll.addFirst(1, 7, "b");
    ll.showLL();
}