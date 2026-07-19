#include<iostream>
#define nullNum -1
using namespace std;

//---------------------- class biNode
class node2{
    public:
        int num;
        node2 *left;
        node2 *right;
        node2(int numIn){
            num=numIn;
            left=nullptr;
            right=nullptr;
        }
};
node2 *nullNode2=new node2(nullNum);
//---------------------- class tree
class biTree{
    public:
        node2 *root;
        biTree(){
            root=nullptr;
        }
        node2 *insertNumInTree(node2 *currNode, int newNum);
        void showPreorder(node2 *currNode);
        void showInorder(node2 *currNode);
        void showPostorder(node2 *currNode);
        node2 *deleteNumInTree(node2 *currNode, int targetNum);
        node2 *findMaxLeft(node2 *currNode);
        int findMaxHeight(node2 *currNode);
        void showCurrLevel(node2 *currNode, int currLevel);
        void showLevelorder();
        node2 *findShortestSide(node2 *nodeIn);
};
node2 *biTree::insertNumInTree(node2 *currNode, int newNum){
    if(currNode==nullptr){
        return new node2(newNum);
    }
    if(currNode->num<newNum){
        currNode->right=insertNumInTree(currNode->right, newNum);
    }
    else if(currNode->num>newNum){
        currNode->left=insertNumInTree(currNode->left, newNum);
    }
    return currNode;
}
void biTree::showPreorder(node2 *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showPreorder(currNode->left);
        showPreorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::showInorder(node2 *currNode){
    if(currNode!=NULL){
        showInorder(currNode->left);
        cout<<currNode->num<<" ";
        showInorder(currNode->right);
    }
    else{
        cout<<"NULL ";
    }
}
void biTree::showPostorder(node2 *currNode){
    if(currNode!=nullptr){
        showPostorder(currNode->left);
        showPostorder(currNode->right);
        cout<<currNode->num<<" ";
    }
    else{
        cout<<"NULL ";
    }
}
node2 *biTree::deleteNumInTree(node2 *currNode, int targetNum){
    if(currNode==nullptr){
        return nullptr;
    }
    if(currNode->num<targetNum){
        currNode->right=deleteNumInTree(currNode->right, targetNum);
    }
    else if(currNode->num>targetNum){
        currNode->right=deleteNumInTree(currNode->right, targetNum);
    }
    else if(currNode->num==targetNum){
        if((currNode->left==nullptr)&&(currNode->right==nullptr)){
            return nullptr;
        }
        else if((currNode->left!=nullptr)&&(currNode->right!=nullptr)){
            node2 *maxLeftNode=findMaxLeft(currNode);
            currNode->num=maxLeftNode->num;
            currNode->left=deleteNumInTree(currNode->left, maxLeftNode->num);
        }
        else if(currNode->left==nullptr){
            currNode=currNode->right;
        }
        else if(currNode->right==nullptr){
            currNode=currNode->left;
        }
        return currNode;
    }
}
node2 *biTree::findMaxLeft(node2 *currNode){
    if(root==nullptr){
        return nullNode2;
    }
    else{
        currNode=currNode->left;
        for(node2 *currNode=root; currNode->right!=nullptr; currNode=currNode->right){}
        return currNode;
    }
}
int biTree::findMaxHeight(node2 *currNode){
    if(currNode==nullptr){
        return nullNum;
    }
    int leftHeight=findMaxHeight(currNode->left);
    int rightHeight=findMaxHeight(currNode->right);
    return max(leftHeight, rightHeight)+1;
}
void biTree::showCurrLevel(node2 *currNode, int currLevel){
    if(currNode==nullptr){
        return ;
    }
    if(currLevel==0){
        cout<<currNode->num<<" ";
    }
    else{
        showCurrLevel(currNode->left, currLevel-1);
        showCurrLevel(currNode->right, currLevel-1);
    }
}
void biTree::showLevelorder(){
    int treeHeight=findMaxHeight(root);
    for(int i=0;i<=treeHeight;i++){
        showCurrLevel(root, i);
    }
}
node2 *biTree::findShortestSide(node2 *nodeIn){

}