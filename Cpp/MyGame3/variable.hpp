#include<iostream>
#define CAPACITY 50
using namespace std;
//------------------ variable
int array[CAPACITY];
int **pptr;
int root=0;
//------------------ functions
void createArray(){
    for(int i=0;i<CAPACITY;i++){
        array[i]=-1;
    }
}