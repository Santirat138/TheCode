#include"das.hpp"
int month[13]={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//------------------
class TableType{
    public:
        TypeArray tArray;
        InExLL* table[CAPACITY];
        int typeSize;
        TableType(){
            tArray.readFile();
            typeSize=tArray.lastIdx;
            for(int i=0;i<CAPACITY;i++){
                table[i]=new InExLL(i);
            }
        }
        int getKey(string type){
            int idx=tArray.search(type);
            return idx;    
        }
        string getTypeName(int keyIdx){
            return tArray.array[keyIdx];
        }
        /* void sort(InExLL* array[]){
            InExLL* data[tArray.lastIdx];
            for(int a=0;a<tArray.lastIdx;a++){
                data[a]=new InExLL(a);
               *data[a]=*table[a];
            }
            for(int a=0;a<tArray.lastIdx-1;a++){
                int minIdx=a;
                for(int b=a+1;b<tArray.lastIdx;b++){
                    if((*data[b]).moneySum<(*data[minIdx]).moneySum){
                        minIdx=b;
                    }
                }
                swap(*data[minIdx], *data[a]);
            }
            for(int a=0;a<tArray.lastIdx;a++){
                array[a]=data[a];
            }
        } */
        int setMoneySum(){
            int moneySum=0;
            for(int i=0;i<tArray.lastIdx;i++){
                moneySum=moneySum+(*table[i]).moneySum;
            }
            return moneySum;
        }
        void add(Info infoIn){
            int idx=getKey(infoIn.type);
            if(idx==-1){
                cout<<"Not found "<<infoIn.name<<"."<<endl;
                tArray.add(infoIn.type);
                idx=getKey(infoIn.type);
            }
            (*table[idx]).add(infoIn.name, infoIn.money);
        }
        void showAll(){
            for(int i=0;i<tArray.lastIdx;i++){
                if((*table[i]).amount>0){
                    string name=getTypeName(i);
                    (*table[i]).show(name);
                }
            }
            cout<<"All money sum: "<<setMoneySum()<<endl;
        }
};
class Day{
    public:
        TableType table;
        int moneySum;
        Day(){
            moneySum=0;
        }
        void add(Info infoIn){
            table.add(infoIn);
        }
};
class Month{
    public:
        int monthNum;
        int lastDay;
        Day day[31];
        void createMonth(int mIn){
            monthNum=mIn;
            if((monthNum==1)||(monthNum==3)||(monthNum==5)||(monthNum==7)||(monthNum==8)||(monthNum==10)||(monthNum==12)){
                lastDay=31;
            }
            else if((monthNum==4)||(monthNum==6)||(monthNum==10)||(monthNum==11)){
                lastDay=30;
            }
            else if((monthNum==2)){
                lastDay=28;
            }
            else{
                lastDay=0;
            }
        }
};
class Main{
    public:
        int currDay;
        Month allMonth[12];
        Main(){
            for(int i=1;i<13;i++){
                allMonth[i].createMonth(i);
            }
        }
        void add(Date currDate, Info infoIn){
            if(currDate.day<=allMonth[currDate.month].lastDay){
                allMonth[currDate.month].day[currDate.day].add(infoIn);
            }
            else{
                cout<<currDate.day<<" > "<<allMonth[currDate.month].lastDay<<"."<<endl;
            }
        }
        void show(Date date){
            for(int i=1;i<allMonth[date.month].lastDay;i++){
                if(allMonth[date.month].day[i].moneySum>0){
                    allMonth[date.month].day[i].table.showAll();
                }
            }
        }
};
//------------------ main
int main(){
    Main t;
    Date date[5];
    Info info[5];
    date[0].day=1;
    date[0].month=10;
    date[1].day=2;
    date[1].month=10;
    date[2].day=4;
    date[2].month=10;
    date[3].day=6;
    date[3].month=10;
    date[4].day=8;
    date[4].month=10;

    info[0].money=5;
    info[0].name="item A";
    info[0].type="type1";
    info[1].money=10;
    info[1].name="item B";
    info[1].type="type3";
    info[2].money=900;
    info[2].name="item C";
    info[2].type="type1";
    info[3].money=5000;
    info[3].name="item D";
    info[3].type="type3";
    info[4].money=150;
    info[4].name="item E";
    info[4].type="type3";
    for(int i=0;i<5;i++){
        t.add(date[i], info[i]);
    }
    for(int i=0;i<4;i++){
        t.show(date[i]);
    }
}