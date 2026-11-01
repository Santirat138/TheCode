#include<iostream>
#include<fstream>
using namespace std;
//      variables
string path="C:\\Users\\WIN11\\Desktop\\code\\TheCode\\Cpp\\ProjectHistoryTimeline\\version_3_1\\FilePath.txt";
string pathArray[3];
//      functions
void readPath(){
    int pathIdx=0;
    ifstream pathReader(path);
    while(getline(pathReader, pathArray[pathIdx])){
        cout<<"Read "<<pathArray[pathIdx++]<<"\n";
    }
    pathReader.close();
}
//      main
int main(){
    readPath();
}