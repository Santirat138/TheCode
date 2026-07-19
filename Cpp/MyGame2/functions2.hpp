#include "functions1.hpp"
#include "inputStorage.hpp"


void createBST(Node **rootRef, int *ptrArr, int arrSize){
    for(int currI=0;currI<arrSize;currI++){
        insert(rootRef, *(ptrArr+currI));
    }
}
bool checkAns(int *ansPtr, int ansSize, Index input){
    if(ansSize!=input.size){
        return false;
    }
    for(int i=0;i<ansSize;i++){
        if(*(ansPtr+i)!=*(input.ptrArray+i)){
            return false;
        }
    }
    return true;
}
void TEST_showBST(Node *root){
    if(root==NULL){
        cout<<"NULL";
        return ;
    }
    showInorder(root);
}