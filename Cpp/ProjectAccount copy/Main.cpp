#include"reader.hpp"
//      functions
void mainFunc(){
    Account acc;
    string cmd;
    acc.read();
    do{
        cout<<"cmd: ";
        cin>>cmd;
        if(cmd=="add"){
            Date date;
            Info info;
            cin>>date.day>>date.month>>info.type>>info.name>>info.price;
            acc.add(date, info);
            acc.sort();
            acc.write();
        }
        else if(cmd=="show"){
            acc.show();
        }
    }
    while(cmd!="exit");
}
//      main
int main(){
    mainFunc();
}