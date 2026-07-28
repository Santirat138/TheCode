#include<iostream>
#define CAPACITY 10
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
                cout<<(*cNode).name<<" "<<(*cNode).price<<endl;
            }
            cout<<"\t"<<endl<<"money sum "<<getMoneySum()<<endl<<"-----------------"<<endl;
        }
        void add(Info info){
            RecNode* newNode=new RecNode(info);
            (*newNode).next=head;
            head=newNode;
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
};

//      month, array of hash table
class TableArray{
    public:
        int lastIdx;
        RecTable tableArray[31];
        TableArray(int monthNum){
            if((monthNum==1)||(monthNum==3)||(monthNum==5)||(monthNum==7)||(monthNum==8)||(monthNum==10)||(monthNum==12)){
                lastIdx=31;
            }
            else if((monthNum==4)||(monthNum==6)||(monthNum==9)||(monthNum==11)){
                lastIdx=30;
            }
            else if((monthNum==2)){
                lastIdx=28;
            }
            else{
                lastIdx=0;
            }
        }
        void show(){
            for(int i=0;i<lastIdx;i++){
                if(tableArray[i].date.day!=0){
                    cout<<"\t"<<tableArray[i].date.day<<" / "<<tableArray[i].date.month<<endl;
                    tableArray[i].show();
                    cout<<"<><><><><><><><><>"<<endl;
                }
            }
            cout<<endl;
        }
        void add(Date date, Info info){
            tableArray[date.day].date=date;
            tableArray[date.day].addRecLL(info);
        }
};