#include<iostream>
#include<vector>
using namespace std;
//------------------ variable
int top=0;
//------------------ functions
char pop(string str){
	return str[top++];
}
//------------------ class
class Node{
    public:
        string text;
        Node* next;
        Node(){
            next=NULL;
        }
        Node(string str, Node* nodeIn){
            text=str;
            next=nodeIn;
        }
};
class LinkedList{
	public:
		int nodeAmount=0;
        string mainText;
		Node* head=NULL;
		Node* tail=NULL;
        void setMainText(string newText){
            mainText=newText;
        }
		void showLL(){
			int nodeI=1;
			for(Node* curr=head;curr!=NULL;curr=(*curr).next){
				cout<<(*curr).text<<" ";
			}
			cout<<endl;
		}
		void addLastNode(string newText){
			Node* newNode=new Node(newText, NULL);
			if(head==NULL){
				head=newNode;
			}
			else{
				(*tail).next=newNode;
			}
			tail=newNode;
			nodeAmount++;
		}
};