#include<iostream>
#include<sstream>
#define CAPACITY 10
#define MONTH_CAPACITY 13
using namespace std;
//      class
class Date{
    public:
        int day=0;
        int month=0;
};
class Info{
    public:
        string type="-";
        string name="-";
        int price=0;
        void setInfo(string dataIn){
            stringstream ss(dataIn);
            string token;
            string info[3];
            int i=0;
            while (getline(ss, token, ',')) {
                cout<<token<<endl;
                info[i++]=token;
            }
            type=info[0];
            name=info[1];
            price=stoi(info[2]);
        }
};
class RecNode{
    public:
        string name;
        int price;
        RecNode* next;
        RecNode(Info info){
            name=info.name;
            price=info.price;
            next=NULL;
        }
};
class RecLL{
    public:
        string typeName;
        RecNode* head;
        int moneySum;
        RecLL(){
            typeName="-";
            head=NULL;
            moneySum=0;
        }
        int getMoneySum(){
            for(RecNode* cNode=head;cNode!=NULL;cNode=(*cNode).next){
                moneySum=moneySum+(*cNode).price;
            }
            return moneySum;
        }
        void show(){
            cout<<"Type "<<typeName<<endl<<endl;
            for(RecNode* cNode=head;cNode!=NULL;cNode=(*cNode).next){
                cout<<"  - "<<(*cNode).name<<" "<<(*cNode).price<<endl;
            }
            cout<<"\t"<<endl<<"Type money sum "<<getMoneySum()<<endl<<"-----------------"<<endl;
        }
        void add(Info info){
            RecNode* newNode=new RecNode(info);
            (*newNode).next=head;
            head=newNode;
        }
        RecNode* deleteNode(RecNode* currNode, string target){
            if(currNode==NULL){
                return NULL;
            }
            if((*currNode).name==target){
                RecNode* temp=(*currNode).next;
                (*currNode).next=NULL;
                return temp;
            }
            (*currNode).next=deleteNode((*currNode).next, target);
            return currNode;
        }
};

//      day, type hash table
class RecTable{
    public:
        Date date;
        RecLL recLL[CAPACITY];
        int lastIdx;
        RecTable(){
            lastIdx=0;
            for(int i=0;i<CAPACITY;i++){
                recLL[0]=RecLL();
            }
        }
        int getMoneySum(){
            int sum=0;
            for(int i=0;i<lastIdx;i++){
                sum=sum+recLL[i].moneySum;
            }
            return sum;
        }
        void show(){
            for(int i=0;i<lastIdx;i++){
                recLL[i].show();
            }
            cout<<"\t"<<date.day<<" / "<<date.month<<" money sum "<<getMoneySum()<<endl;
        }
        int getKey(string type){
            for(int i=0;i<lastIdx;i++){
                if(recLL[i].typeName==type){
                    return i;
                }
            }
            return lastIdx++;
        }
        void addRecLL(Info info){
            int key=getKey(info.type);
            recLL[key].typeName=info.type;
            recLL[key].add(info);
        }
        void deleteNode(Info info){
            int key=getKey(info.type);
            recLL[key].head=recLL[key].deleteNode(recLL[key].head, info.name);
            if(recLL[key].head==NULL){
                cout<<"Not found "<<info.type<<","<<info.name<<endl;
                return ;
            }
        }
};

//      month, array of hash table
class TableArray{
    public:
        int monthNumber;
        int lastIdx;
        RecTable tableArray[32];
        TableArray(int monthNum){
            monthNumber=monthNum;
            if((monthNum==1)||(monthNum==3)||(monthNum==5)||(monthNum==7)||(monthNum==8)||(monthNum==10)||(monthNum==12)){
                lastIdx=31;
            }
            else if((monthNum==4)||(monthNum==6)||(monthNum==9)||(monthNum==11)){
                lastIdx=30;
            }
            else if(monthNum==2){
                lastIdx=28;
            }
            else{
                lastIdx=0;
            }
        }
        void show(){
            for(int i=0;i<lastIdx;i++){
                if(tableArray[i].lastIdx!=0){
                    cout<<"\t"<<tableArray[i].date.day<<" / "<<tableArray[i].date.month<<endl;
                    tableArray[i].show();
                    cout<<"<><><><><><><><><>"<<endl<<endl;
                }
            }
        }
        void add(Date date, Info info){
            if(date.day>lastIdx){
                cout<<date.day<<" can't more than "<<lastIdx<<"."<<endl;
                return ;
            }
            tableArray[date.day].date=date;
            tableArray[date.day].addRecLL(info);
        }
        void deleteData(Date date, Info info){
            if(date.day>lastIdx){
                cout<<date.day<<" can't more than "<<lastIdx<<"."<<endl;
                return ;
            }
            tableArray[date.day].deleteNode(info);
        }
};
//      functions
void sortTableArray(TableArray* month[]){
    for(int i=1;i<MONTH_CAPACITY;i++){
        int minM=i;
        for(int j=i+1;j<MONTH_CAPACITY;j++){
            if((*month[j]).monthNumber<(*month[minM]).monthNumber){
                minM=j;
            }
        }
        swap(*month[i], *month[minM]);
    }
}