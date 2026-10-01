#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;
string filePath="C:\\Users\\WIN11\\Desktop\\code\\TheCode\\Cpp\\ProjectHistoryTimeline\\version_3_1\\TEST_FILE.csv";
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
        string details[3];
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
                if((*c).details[0]!="0"){
                    cout<<"- "<<(*c).details[2]<<endl;
                }
            }
            cout<<endl;
        }
        void add(Date date, string detailIn){
            eventAmount++;
            EventNode* newNode=new EventNode();
            (*newNode).details[0]=date.month;
            (*newNode).details[1]=date.year;
            (*newNode).details[2]=detailIn;
            if(head!=NULL){
                (*newNode).next=head;
            }
            head=newNode;
        }
        void deleteEvent(int eventNum){
            for(int i=1;i<=eventAmount;i++){
                if(i==eventNum){
                    if(i==1){
                        EventNode* temp=head;
                        head=(*head).next;
                        (*temp).next=NULL;
                    }
                    else if(i==eventAmount){

                    }
                    else{

                    }
                    eventAmount--;
                }
            }
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
        void deleteNode(Date targetDate){
            YearNode* targetYear=search(targetDate);
            if(targetYear!=NULL){
                (*targetYear).monthTable[targetDate.month].
            }
        }
        void sort(){
            for(YearNode* nodeA=head;(*(*nodeA).next).next!=NULL;nodeA=(*nodeA).next){
                YearNode* keyNode=nodeA;
                for(YearNode* nodeB=(*nodeA).next;nodeB!=NULL;nodeB=(*nodeB).next){
                    if((*keyNode).year>(*nodeB).year){
                        keyNode=nodeB;
                    }
                }
                swap((*nodeA).monthTable, (*keyNode).monthTable);
                swap((*nodeA).year, (*keyNode).year);
            }
        }
};
//------------------ functions
YearList readFile(){
    YearList yearList;
    ifstream reader(filePath);
    if(!reader){
        cout<<"Can't open."<<endl;
    }
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
void writeFile(YearList listIn){
    ofstream writer(filePath);
    for(YearNode* cNode=listIn.head;cNode!=NULL;cNode=(*cNode).next){
        if((*cNode).monthTable!=NULL){
            for(int month=1;month<13;month++){
                for(EventNode* cEvent=(*(*cNode).monthTable[month]).head;cEvent!=NULL;cEvent=(*cEvent).next){
                    writer<<month<<"|"<<(*cNode).year<<"|"<<(*cEvent).details[2]<<endl;
                }
            }
        }
    }
    writer.close();
}
void mainFunc(){
    string cmd;
    YearList yearList=readFile();
    int m, y;
    Date date;
    do{
        cin>>cmd;
        if(cmd=="search"){
            YearNode* temp;
            cout<<"Search month: ";
            cin>>m;
            cout<<"Search year: ";
            cin>>y;
            date.month=m;
            date.year=y;
            int prevM=m-1;
            int nextM=m+1;
            temp=yearList.search(date);
            while(prevM>1){
                if((*(*temp).monthTable[prevM]).eventAmount>0){
                    cout<<"\tBefore "<<m<<"/"<<y<<endl<<prevM<<"/"<<y<<endl;
                    (*(*temp).monthTable[prevM]).show();
                    break;
                }
                prevM--;
            }
            while(nextM<12){
                if((*(*temp).monthTable[nextM]).eventAmount>0){
                    cout<<"\tAfter "<<m<<"/"<<y<<endl<<nextM<<"/"<<y<<endl;
                    (*(*temp).monthTable[nextM]).show();
                    break;
                }
                nextM++;
            }
            if(temp!=NULL){
                for(int cM=1;cM<13;cM++){
                    if(cM==m){
                        cout<<"\t**** Found ****"<<endl;
                        (*(*temp).monthTable[cM]).show();
                        break;
                    }
                }
            }
            else{
                cout<<"Not found."<<endl;
            }
        }
        else if(cmd=="add"){
            string newDetail;
            cout<<"month: ";
            cin>>m;
            cout<<"year: ";
            cin>>y;
            cin.ignore();
            cout<<"New details: ";
            getline(cin, newDetail);
            date.month=m;
            date.year=y;
            yearList.add(date, newDetail);
            yearList.sort();
            writeFile(yearList);
        }
        else if(cmd=="delete"){
            
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