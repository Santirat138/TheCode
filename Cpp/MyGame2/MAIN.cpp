#include "functions2.hpp"
int main(){
    Node *root1=NULL;
    int array[]={76, 85, 86, 79, 78, 25, 62, 6, 1, 31};
    int size=sizeof(array)/sizeof(array[0]);
    createBST(&root1, array, size);
    
    int ansArray[]={1, 2, 3};
    int ansSize=sizeof(ansArray)/sizeof(ansArray[0]);

    input[0].ptrArray=array;
    input[0].size=size;
    input[1].ptrArray=ansArray;
    input[1].size=ansSize;
    showInputData();
    cout<<endl;
    TEST_showBST(root1);
}