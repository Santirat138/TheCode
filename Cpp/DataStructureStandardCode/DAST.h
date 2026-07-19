#include"Node.h"
//------------------ functions
void linkNode(Node* nodeA, Node* nodeB){
    (*nodeA).right=nodeB;
    (*nodeB).left=nodeA;
}
//------------------ class
class Single_LinkedList{
    public:
        Node* head;
        Node* tail;
        Single_LinkedList(){
            head=NULL;
            tail=NULL;
        }
        void show(){
            for(Node* curr=head;curr!=NULL;curr=(*curr).right){
                cout<<(*curr).num<<" ";
            }
        }
        void push(int newNum){
            Node* newNode=new Node(newNum, NULL, NULL);
            if(head==NULL){
                tail=newNode;
            }
            else{
                (*newNode).right=head;
            }
            head=newNode;
        }
        Node* pop(){
            for(Node* curr=head;curr!=NULL;curr=(*curr).right){
                if((*curr).right==tail){
                    Node* temp=tail;
                    tail=curr;
                    (*curr).right=NULL;
                    return temp;
                }
            }
            return NULL;
        }
        void enqueue(int newNum){
            Node* newNode=new Node(newNum, NULL, NULL);
            if(head==NULL){
                tail=newNode;
            }
            for(Node* curr=head;curr!=NULL;curr=(*curr).right){
                if((*curr).right==NULL){
                    (*curr).right=newNode;
                    break;
                }
            }
            head=newNode;
        }
        Node* dequeue(){
            Node* temp=head;
            head=(*head).right;
            (*temp).right=NULL;
            return temp;
        }
};
//------------------ functions
Node* getMaxLeftNode(Node* currNode){
    if((*currNode).left!=NULL){
        currNode=(*currNode).left;
        while((*currNode).right!=NULL){
            currNode=(*currNode).right;
        }
        return currNode;
    }

    return NULL;
}
//------------------ class
class Tree {
    public:
        Node* root=nullptr;
        void showPreorder(Node* currNode) {
            if (currNode != NULL) {
                cout << (*currNode).num << " ";
                showPreorder((*currNode).left);
                showPreorder((*currNode).right);
            }
        }
        Node* insert(Node* currNode, int newNum) {
            if (root == NULL) {
                currNode = new Node(newNum, NULL, NULL);
            }
            if(newNum<(*currNode).num){
                (*currNode).left=insert((*currNode).left, newNum);
            }
            else if(newNum>(*currNode).num){
                (*currNode).right=insert((*currNode).right, newNum);
            }
            return currNode;
        }
        Node* remove(Node* currNode, int targetNum){
            if(targetNum<(*currNode).num){
                (*currNode).left=remove((*currNode).left, targetNum);
            }
            else if(targetNum>(*currNode).num){
                (*currNode).right=remove((*currNode).right, targetNum);
            }
            else{
                if(((*currNode).left==nullptr)&&((*currNode).right==nullptr)){
                    currNode=nullptr;
                }
                else if((*currNode).left==nullptr){
                    return (*currNode).right;
                }
                else if((*currNode).right==nullptr){
                    return (*currNode).left;
                }
                else{
                    int maxLeftNum=(*getMaxLeftNode(currNode)).num;
                    (*currNode).num=maxLeftNum;
                    (*currNode).left=remove((*currNode).left, maxLeftNum);
                }
            }
            return currNode;
        }
};
class AVLtree{
    public:
        
};