#include "Node.hpp"
//------------------ class

//------------------ functions
void insert(Node **rootRef, int newNum){
	if(*rootRef==NULL){
		*rootRef=new Node(newNum, NULL, NULL);
		return;
	}
	if(newNum < (*rootRef)->num){
		insert(&((*rootRef)->left), newNum);
	}
	else{
		insert(&((*rootRef)->right), newNum);
	}
}
void showPreorder(Node *root){
    if(root==NULL) return;
    cout<<root->num<<" ";
    showPreorder(root->left);
    showPreorder(root->right);
}
void showInorder(Node *root){
	if(root==NULL) return;
	showInorder(root->left);
	cout<<root->num<<" ";
	showInorder(root->right);
}
void showPostorder(Node *root){
    if(root==NULL) return;
    showPostorder(root->left);
    showPostorder(root->right);
    cout<<root->num<<" ";
}
void deleteNum(Node **currNode, int targetNum){
	if((*currNode)->num<targetNum){
		deleteNum(&((*currNode)->right), targetNum);
	}
	else if((*currNode)->num>targetNum){
		deleteNum(&((*currNode)->left), targetNum);
	}
	else{
		if(((*currNode)->left==NULL)&&((*currNode)->right==NULL)){
			*currNode=NULL;
		}
		else if((*currNode)->left==NULL){
			*currNode=(*currNode)->right;
		}
		else if((*currNode)->right==NULL){
			*currNode=(*currNode)->left;
		}
		else{
			Node *mostLeftNode=(*currNode)->left;
			while(mostLeftNode->right!=NULL){
				mostLeftNode=mostLeftNode->right;
			}
			(*currNode)->num=mostLeftNode->num;
			deleteNum(&((*currNode)->left), mostLeftNode->num);
		}
	}
}
