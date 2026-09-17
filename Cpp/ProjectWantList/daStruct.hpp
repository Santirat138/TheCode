#include<iostream>
#include<sstream>
#define CAPACITY 10
using namespace std;
//      class
class Date{
    public:
        int day;
        int month;
        int year;
};
class Pws{
    public:
        float needVal=0;
        float wantVal=0;
        float getPWS(){
            return (needVal*7)+(wantVal*3);
        }
};
class ItemNode{
    public:
        string name="-";
        float price=0;
        //Date date;
        Pws pws;
        ItemNode* next;
        ItemNode(ItemNode* nodeIn){
            next=nodeIn;
        }
        void setItemNode(string nameIn, float priceIn, Pws pwsIn){
            name=nameIn;
            price=priceIn;
            pws.needVal=pwsIn.needVal;
            pws.wantVal=pwsIn.wantVal;
        }
};
class ItemLL{
    public:
        ItemNode* head;
        string type="-";
        int amount=0;
        float totalPrice=0;
        ItemLL(){
            head=NULL;
        }
        void add(string nameIn, float priceIn, Pws pwsIn){
            amount++;
            ItemNode* newNode=new ItemNode(head);
            (*newNode).setItemNode(nameIn, priceIn, pwsIn);
            head=newNode;
            totalPrice=totalPrice+priceIn;
        }
        void show(){
            cout<<"    Category: "<<type<<" total price: "<<totalPrice<<endl;
            for(ItemNode* currN=head;currN!=NULL;currN=(*currN).next){
                cout<<(*currN).name<<" "<<(*currN).price<<" "<<(*currN).pws.needVal<<" "<<(*currN).pws.wantVal<<" "<<(*currN).pws.getPWS()<<endl;
            }
            cout<<endl;
        }
        void swapData(ItemNode* a, ItemNode* b) {
            swap(a->name, b->name);
            swap(a->price, b->price);
            swap(a->pws, b->pws);
        }
        void sortPWS(){
            for(ItemNode* node1=head;(*node1).next!=NULL;node1=(*node1).next){
                ItemNode* minPws=node1;
                for(ItemNode* node2=(*node1).next;node2!=NULL;node2=(*node2).next){
                    if((*node2).pws.getPWS()<(*minPws).pws.getPWS()){
                        minPws=node2;
                    }
                }
                swapData(node1, minPws);
            }
        }
        void sortPrice(){
            for(ItemNode* node1=head;(*node1).next!=NULL;node1=(*node1).next){
                ItemNode* minPws=node1;
                for(ItemNode* node2=(*node1).next;node2!=NULL;node2=(*node2).next){
                    if((*node2).price<(*minPws).price){
                        minPws=node2;
                    }
                }
                swapData(node1, minPws);
            }
        }
        ItemNode findItemNode(){

        }
        void deleteItemNode(){

        }
};
class TypeArray{
    public:
        ItemLL itemLL[CAPACITY];
        int lastIdx;
        TypeArray(){
            lastIdx=0;
            for(int i=0;i<CAPACITY;i++){
                itemLL[i]=ItemLL();
            }
        }
        int getTotalPrice(){
            int totalPrice=0;
            for(int i=0;i<lastIdx;i++){
                totalPrice=totalPrice+itemLL[i].totalPrice;
            }
            return totalPrice;
        }
        void show(){
            for(int i=0;i<CAPACITY;i++){
                if((itemLL[i]).head!=NULL){
                    (itemLL[i]).show();
                }
            }
            cout<<"Total price: "<<getTotalPrice()<<endl;
        }
        int getTypeKey(string typeIn){
            for(int i=0;i<lastIdx;i++){
                if(itemLL[i].type==typeIn){
                    return i;
                }
            }
            return lastIdx++;
        }
        void addLL(string name, string type, float price, float need, float want){
            Pws pws;
            pws.needVal=need;
            pws.wantVal=want;
            int key=getTypeKey(type);
            itemLL[key].type=type;
            itemLL[key].add(name, price, pws);
        }
        void sortPWS(){
            for(int i=0;i<CAPACITY;i++){
                if((itemLL[i]).head!=NULL){
                    (itemLL[i]).sortPWS();
                }
            }
        }
};