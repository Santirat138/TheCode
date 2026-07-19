#include "arrayBST.hpp"
//------------------ main
int main(){
    createArray();
    int *ptr=array;
    pptr=&ptr;
    addNum(pptr, root, 80);
    addNum(pptr, root, 8);
    addNum(pptr, root, 90);
    addNum(pptr, root, 45);
    addNum(pptr, root, 85);
    addNum(pptr, root, 700);
    addNum(pptr, root, 900);
    showArray(pptr);
    deleteNum(pptr, root, 45);
    showArray(pptr);
}