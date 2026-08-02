#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;
string filePath="C:\\Users\\WIN11\\Desktop\\code\\TheCode\\Cpp\\HistoryTimeline\\version_3_1\\TEST_FILE.txt";
//------------------ class
class Date{
    public:
        int month;
        int year;
        Date(){
            month=0;
            year=0;
        }
};
class EventNode{
    public:
        Date date;
        string details;
        EventNode* next;
        EventNode(){
            next=NULL;
        }
};
class EventList{
    public:
        int eventAmount;
        EventNode* head;
        EventList(){
            eventAmount=0;
            head=NULL;
        }
        void show(){
            cout<<eventAmount<<" events"<<endl;
            for(EventNode* c=head;c!=NULL;c=(*c).next){
                if((*c).date.month!=0){
                    //cout<<(*c).date.month<<"/"<<(*c).date.year<<": "<<(*c).details<<endl;
                    cout<<"- "<<(*c).details<<endl;
                }
            }
            cout<<endl;
        }
        void add(Date date, string detailIn){
            eventAmount++;
            EventNode* newNode=new EventNode();
            (*newNode).date=date;
            (*newNode).details=detailIn;
            if(head!=NULL){
                (*newNode).next=head;
            }
            head=newNode;
        }
};
class YearNode{
    public:
        int year;
        EventList* monthTable[13];
        YearNode* next;
        YearNode(){
            year=0;
            next=NULL;
            for(int i=0;i<13;i++){
                monthTable[i]=new EventList();
            }
        }
        void show(){
            for(int i=1;i<13;i++){
                if((*monthTable[i]).head!=NULL){
                    cout<<i<<'/'<<year<<": ";
                    (*monthTable[i]).show();
                }
            }
            cout<<endl;
        }
        void add(Date dateIn, string detailIn){
            (*monthTable[dateIn.month]).add(dateIn, detailIn);
        }
};
class YearList{
    public:
        YearNode* head;
        YearList(){
            head=NULL;
        }
        void show(){
            for(YearNode* c=head;c!=NULL;c=(*c).next){
                (*c).show();
            }
            cout<<endl;
        }
        YearNode* search(Date date){
            for(YearNode* c=head;c!=NULL;c=(*c).next){
                if((*c).year==date.year){
                    return c;
                }
            }
            return NULL;
        }
        void add(Date dateIn, string detailIn){
            YearNode* targetNode=search(dateIn);
            if(targetNode==NULL){
                YearNode* newNode=new YearNode();
                (*newNode).add(dateIn, detailIn);
                (*newNode).year=dateIn.year;
                if(head==NULL){
                    head=newNode;
                }
                else{
                    for(YearNode* c=head;c!=NULL;c=(*c).next){
                        if((*c).next==NULL){
                            (*c).next=newNode;
                            break;
                        }
                    }
                }
            }
            else{
                (*targetNode).add(dateIn, detailIn);
            }
        }      
};
//------------------ functions
YearList readFile(){
    YearList yearList;
    ifstream reader(filePath);
    string line;
    Date date;
    while(getline(reader, line)){
        stringstream ss(line);
        string m, y, detail;
        getline(ss, m, '|');
        getline(ss, y, '|');
        getline(ss, detail);
        date.month=stoi(m);
        date.year=stoi(y);
        yearList.add(date, detail);
    }
    reader.close();
    return yearList;
}
void mainFunc(){
    string cmd;
    YearList yearList=readFile();
    int m, y;
    Date date;
    do{
        cin>>cmd;
        if(cmd=="search"){
            cin>>m>>y;
            date.month=m;
            date.year=y;
            (*yearList.search(date)).show();
        }
        else if(cmd=="add"){
            string newDetail;
            cin>>m>>y>>newDetail;
            date.month=m;
            date.year=y;
            yearList.add(date, newDetail);
        }
        else if(cmd=="show"){
            yearList.show();
        }
    }
    while(cmd!="exit");
}
//------------------ main
int main(){
    mainFunc();
}