#include<iostream>
#include<cmath>
using namespace std;
//------------------ functions
int getNumAtDigi(int numIn, int target_digi){
    int tempNum;
    tempNum=numIn;
    numIn=tempNum%int(pow(10, target_digi+1));
    numIn=numIn/pow(10, target_digi);
	return numIn;
}
//------------------ class
class Node{
private:
    int num;
public:
    string text;
    Node *next;
    Node(string textIn, Node *nodeIn){
        text=textIn;
        next=nodeIn;
    }
    int get_num(){
        try{
            return stoi(text);
        }
        catch(invalid_argument){
            //cout<<text<<" is not number. ";
            return int(text[0]);
        }
    }
    int getAsciiNum(int textIdx){
        if(text.length()>textIdx){
            return int(text[textIdx]);
        }
        return -1;
    }
    int getTextToDecNum(){
        int tempNum=stoi(text);
        int digi_text=0;
        int newNum=0;
        try{
            tempNum=stoi(text);
        }
        catch(invalid_argument){
            cout<<text<<" can't be number."<<endl;
            return -1;
        }
        while(tempNum!=0){
            tempNum=tempNum/10;
            digi_text++;
        }
        for(int currDigi=0;currDigi<digi_text;currDigi++){
            newNum=newNum+(getNumAtDigi(stoi(text), currDigi)*pow(2, currDigi));
        }
        return newNum;
    }
};
class LinkedList{
public:
    Node *head=NULL;
    void showLL(){
        for(Node *curr=head;curr!=NULL;curr=curr->next){
            cout<<curr->text<<" ";
        }
        cout<<endl;
    }
    void showLLNum(){
        for(Node *curr=head;curr!=NULL;curr=curr->next){
            cout<<curr->get_num()<<" ";
        }
        cout<<endl;
    }
    void showLLChar(){
        for(Node *curr=head;curr!=NULL;curr=curr->next){
            if((char(stoi(curr->text))>=0)&&(char(stoi(curr->text))<=9)){
                cout<<curr->text;
            }
            else{
                cout<<char(stoi(curr->text));
            }
        }
    }
    Node *getFirstNode(){
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        return temp;
    }
    Node *getLastNode(){
        Node *curr=head;
        Node *lastNode=NULL;
        while(curr!=NULL){
            if(curr->next==NULL){
                lastNode=new Node(curr->text, NULL);
                head=NULL;
                break;
            }
            else if(curr->next->next==NULL){
                lastNode=curr->next;
                curr->next=NULL;
                break;
            }
            curr=curr->next;
        }
        return lastNode;
    }
    void addFirst(string newText){
        head=new Node(newText, head);
    }
    void addLast(string newText){
        if(head==NULL){
            head=new Node(newText, NULL);
            return ;
        }
        for(Node *curr=head;curr!=NULL;curr=curr->next){
            if(curr->next==NULL){
                curr->next=new Node(newText, NULL);
                return ;
            }
        }
    }
};
