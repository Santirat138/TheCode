#include<iostream>
#include "LinkList.hpp"
#include "BiSearchTree.hpp"
using namespace std;

class Main{
    public:
        linkList *solveLL;
        linkList *ansLL;
        biTree *tree;
        Main(){
            solveLL=new linkList();
            ansLL=new linkList();
            tree=new biTree();
        }
        void addTree(int numIn);
        void insertAns(int ansIn);
        void showSolveLL();
        void showAnsLL();
        void buildSolveLLPreorder(node2 *currNode);
        void buildSolveLLInorder(node2 *currNode);
        void buildSolveLLPostorder(node2 *currNode);
        void checkAns();
        void deleteNum(int targetNum);
        
};
void Main::addTree(int numIn){
    tree->insertNumInTree(tree->root, numIn);
}
void Main::insertAns(int ansIn){
    ansLL->addLast(ansIn);
}
void Main::showSolveLL(){
    solveLL->showLL();
}
void Main::showAnsLL(){
    ansLL->showLL();
}
void Main::buildSolveLLPreorder(node2 *currNode){
    if(currNode!=NULL){
        solveLL->addLast(currNode->num);
        buildSolveLLPreorder(currNode->left);
        buildSolveLLPreorder(currNode->right);
    }
    else{
        solveLL->addLast(nullNum);
    }
}
void Main::buildSolveLLInorder(node2 *currNode){
    if(currNode!=NULL){
        buildSolveLLInorder(currNode->left);
        solveLL->addLast(currNode->num);
        buildSolveLLInorder(currNode->right);
    }
    else{
        solveLL->addLast(nullNum);
    }
}
void Main::buildSolveLLPostorder(node2 *currNode){
    if(currNode!=NULL){
        buildSolveLLPostorder(currNode->left);
        buildSolveLLPostorder(currNode->right);
        solveLL->addLast(currNode->num);
    }
    else{
        solveLL->addLast(nullNum);
    }
}
void Main::checkAns(){
    node1 *currAnsNode=ansLL->head;
    node1 *currSolveNode=solveLL->head;
    bool status=false;
    while(currAnsNode!=NULL){
        if(currAnsNode==NULL){
            status=false;
            cout<<"answer is NULL."<<endl;
            return;
        }
        if(currSolveNode==NULL){
            status=false;
            cout<<"SolveLL doesn't exist."<<endl;
            return;
        }
        if(currAnsNode->num!=currSolveNode->num){
            status=false;
            cout<<"Wrong"<<endl;
            cout<<"Solve : Answer"<<endl;
            cout<<currSolveNode->num<<" != "<<currAnsNode->num;
            return;
        }
        else{
            status=true;
            currAnsNode=currAnsNode->next;
            currSolveNode=currSolveNode->next;
        }
    }
    if(!status){
        cout<<"Not pass."<<endl;
    }
    else if(status){
        cout<<"Pass."<<endl;
    }
}
void Main::deleteNum(int targetNum){
    tree->root=tree->deleteNumInTree(tree->root, targetNum);
}
