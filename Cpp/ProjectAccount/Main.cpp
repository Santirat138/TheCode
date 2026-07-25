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
        void sort(InExLL* array[]){
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
        }
        int setMoneySum(){
            int moneySum=0;
            for(int i=0;i<tArray.lastIdx;i++){
                moneySum=moneySum+(*table[i]).moneySum;
            }
            return moneySum;
        }
        void add(string typeIn, string name, int money){
            int idx=getKey(typeIn);
            if(idx==-1){
                cout<<"Not found "<<name<<"."<<endl;
                tArray.add(typeIn);
                idx=getKey(typeIn);
            }
            (*table[idx]).add(name, money);
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

/* 1	มกราคม	31
2	กุมภาพันธ์	28 หรือ 29
3	มีนาคม	31
4	เมษายน	30
5	พฤษภาคม	31
6	มิถุนายน	30
7	กรกฎาคม	31
8	สิงหาคม	31
9	กันยายน	30
10	ตุลาคม	31
11	พฤศจิกายน	30
12	ธันวาคม	31 */
class Day{
    public:
        TableType table;
        int moneySum;
        Day(){
            moneySum=0;
        }
        void showTable(){
            table.showAll();
        }
        void add(string type, string name, int money){
            table.add(type, name, money);
        }
};
//------------------ main
int main(){
    TableType t;
    t.add("food", "rice", 20);
    t.add("food", "chip", 15);
    t.add("food", "banana", 50);
    t.add("drug", "para", 10);
    t.add("sale", "gold", 50000);
    t.add("media", "games1", 5000);
    t.add("sale", "gold", 60000);
    t.add("media", "games2", 2000);
    t.showAll();
}