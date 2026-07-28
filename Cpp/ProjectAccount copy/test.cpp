#include<iostream>
#include<fstream>
#include<sstream>
#define CAPACITY 10
using namespace std;
string path="C:\\Users\\WIN11\\Desktop\\code\\TheCode\\Cpp\\ProjectAccount copy\\data.csv";
//------------------ class

//------------------ main
int main(){
    ifstream reader(path);
    string day[CAPACITY];
    string month[CAPACITY];
    string type[CAPACITY];
    string name[CAPACITY];
    string price[CAPACITY];
    string line;
    string typeName;
    int i=0;
    getline(reader, typeName);
    while(getline(reader, line)){
        stringstream ss(line);
        getline(ss, day[i], ',');
        getline(ss, month[i], ',');
        getline(ss, type[i], ',');
        getline(ss, name[i], ',');
        getline(ss, price[i++]);
    }
    reader.close();
    cout<<typeName<<endl;
    for(int j=0;j<i;j++){
        cout<<day[j]<<" "<<month[j]<<" "<<type[j]<<" "<<name[j]<<" "<<price[j]<<endl;
    }
}