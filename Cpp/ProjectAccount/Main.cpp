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
            string textIn, token;
            cin>>date.day>>date.month;
            getline(cin>>ws, textIn);
            info.setInfo(textIn);
            cout<<"**********"<<endl;
            if(date.month>=13){
                cout<<"Month can't more than 12."<<endl;
            }
            else{
                acc.add(date, info);
                acc.write();
            }
        }
        else if(cmd=="delete"){
            Date date;
            Info info;
            cin>>date.day>>date.month>>info.type>>info.name;
            if(date.month>=13){
                cout<<"Month can't more than 12."<<endl;
            }
            else{
                acc.deleteData(date, info);
                acc.write();
            }
        }
        else if(cmd=="sort"){
            acc.sort();
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