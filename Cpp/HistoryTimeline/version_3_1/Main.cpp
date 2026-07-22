#include<iostream>
#include <fstream>
using namespace std;
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
                    cout<<(*c).date.month<<"/"<<(*c).date.year<<": "<<(*c).details<<endl;
                    //cout<<(*c).details<<", ";
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
            for(int i=0;i<13;i++){
                if((*monthTable[i]).head!=NULL){
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
void mainFunc(){
    string cmd;
    YearList yearList;
    int m, y;
    Date date;
    do{
        if(cmd=="search"){
            date.month=m;
            date.year=y;
            (*yearList.search(date)).show();
        }
        else if(cmd=="add"){
            string newDetail;
            cin>>m>>y>>newDetail;
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
    YearList yearList;
    Date date1;
    Date date2;
    Date date3;
    Date date4;
    Date date5;
    date1.month=2;
    date1.year=2001;
    date2.month=2;
    date2.year=2001;
    date3.month=5;
    date3.year=2012;
    date4.month=8;
    date4.year=2012;
    date5.month=8;
    date5.year=2012;
    yearList.add(date1, "e1");
    yearList.add(date2, "e2");
    yearList.add(date3, "e3");
    yearList.add(date4, "e4");
    yearList.add(date5, "e5");
    yearList.show();
    (*yearList.search(date2)).show();
}