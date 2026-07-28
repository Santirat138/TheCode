#include<iostream>
#include<fstream>
#define CAPACITY 10
using namespace std;
string path="C:\\Users\\WIN11\\Desktop\\code\\TheCode\\Cpp\\ProjectAccount\\data.csv";
//------------------ class
class Date{
    public:
        int day;
        int month;
};
class Info{
    public:
        string type;
        string name;
        int money;
};
class InExNode{     // Income and Expense
    public:
        string name;
        int money;
        InExNode* next;
        InExNode(string n, int m, InExNode* nodeIn){
            name=n;
            money=m;
            next=nodeIn;
        }
};
class InExLL{
    public:
        int type;
        int moneySum;
        int amount;
        InExNode* head;
        InExLL(int t){
            type=t;
            moneySum=0;
            amount=0;
            head=NULL;
        }
        void readFile(){
            
        }
        void show(string name){
            if(amount==0){
                return ;
            }
            cout<<"Type: "<<name<<", Amount: "<<amount<<endl;
            for(InExNode* c=head;c!=NULL;c=(*c).next){
                cout<<(*c).name<<" = "<<(*c).money<<endl;
            }
            cout<<"Total money of "<<name<<": "<<moneySum<<endl;
            cout<<endl;
        }
        void add(string n, int m){
            InExNode* newNode=new InExNode(n, m, head);
            (*newNode).next=head;
            head=newNode;
            moneySum=moneySum+m;
            amount++;
        }
};
class TypeArray{
    public:
        string array[CAPACITY];
        int lastIdx=0;
        void readFile(){
            ifstream reader(path);
            string typeName;
            getline(reader, typeName);
            while(reader>>typeName){
                array[lastIdx++]=typeName;
            }
            reader.close();
        }
        int search(string tName){
            for(int i=0;i<lastIdx;i++){
                if(array[i]==tName){
                    return i;
                }
            }
            return -1;
        }
        void updateFile(string newArray[], int arraySize){
            ofstream writer(path);
            for(int i=0;i<arraySize;i++){
                writer<<newArray[i]<<" ";
            }
            writer.close();
        }
        void add(string newName){
            cout<<"Add new "<<newName<<" type."<<endl;
            if(lastIdx<CAPACITY-1){
                array[lastIdx++]=newName;
                updateFile(array, lastIdx);
            }
            else{
                cout<<"Type storage is full."<<endl;
            }
        }
};