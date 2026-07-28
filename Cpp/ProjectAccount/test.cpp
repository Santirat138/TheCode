#include<iostream>
#include<fstream>
#define CAPACITY 10
using namespace std;
string path="C:\\Users\\WIN11\\Desktop\\code\\TheCode\\Cpp\\ProjectAccount\\data.csv";
//------------------ class
//------------------ main
int main(){
    ifstream reader(path);
    string typeName;
    int type=0;
    string array[CAPACITY];
    while(reader>>typeName){
        array[type++]=typeName;
    }
    reader.close();
    for(int i=0;i<type;i++){
        cout<<array[i]<<endl;
    }
}