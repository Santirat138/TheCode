#include<iostream>
#include<vector>
#include "Main.hpp"
using namespace std;

int main(){
    Main *m=new Main();
    vector<int> array({50, 40, 85, 15, 45, 60, 90, 5, 25, 42, 55, 75, 87, 95, 6, 20, 41, 43, 53, 70, 80, 88, 13, 65, 76, 77, 78});
    // Your answer.
    vector<int> ansArray({50, 40, 15, 5, -1, 6, -1, 13, -1, -1, 25, 20, -1, -1, -1, 45, 42, 41, -1, -1, 43, -1, -1, -1, 85, 60, 55, 53, -1, -1, -1, 75, 70, 65, -1, -1, -1, 80, 76, -1, 77, -1, 78, -1, -1, -1, 90, 87, -1, 88, -1, -1, 95, -1, -1});
    for(int i=0;i<ansArray.size();i++){
        m->insertAns(ansArray.at(i));
    }

    for(int i=0;i<array.size();i++){
        m->addTree(array.at(i));
    }
    m->buildSolveLLPreorder(m->tree->root);
    m->checkAns();
    m->showSolveLL();
}