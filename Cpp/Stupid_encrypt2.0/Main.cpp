#include "NodeLL.hpp"
using namespace std;
//------------------ functions
string decimal_to_binary(int decIn){
    int decNum=(decIn);
    string biNum;
    while(decNum>0){
        biNum=to_string(decNum%2)+biNum;
        decNum=decNum/2;
    }
    return biNum;
}
void add_charToLL(string strIn, LinkedList *ll){
    for(int i=0;i<strIn.length();i++){
        ll->addLast(string(1, strIn[i]));
    }
}
string removeRepeatChar(string text, string *key){
    string new_text;
    int key_num;
    string key_text;
    int currA;
    int currB;
    for(currA=0;currA<text.length()-1;currA++){
        currB=currA+1;
        key_num=1;
        while(text[currA]==text[currB]){
            key_num++;
            currB++;
        }
        new_text=new_text+text[currA];
        currA=currB-1;
        key_text=key_text+to_string(key_num);
    }
    *key=key_text;
    return new_text+text[text.length()-1];
}
string repeatChar(string textIn, string key){
    int keySize=key.length();
    string newText;
    for(int currA=0;currA<keySize;currA++){
        if(key[currA]==' '){
            continue;
        }
        int currKeyNum=int(key[currA])-48;
        while(currKeyNum>0){
            newText=newText+textIn[currA];
            currKeyNum--;
        }
    }
    return newText;
}
void put_biNumTo_decNumInLL(string org_text, LinkedList *ll){
    int currIdx=0;
    while(currIdx<org_text.length()-1){
        string curr_text;
        int sub_currIdx=currIdx;
        while(org_text[sub_currIdx]!=' '){
            curr_text=curr_text+org_text[sub_currIdx];
            if(sub_currIdx==org_text.length()){
                break;
            }
            sub_currIdx++;
        }
        currIdx=sub_currIdx+1;
        Node *tempNode=new Node(curr_text, NULL);
        string numIn=to_string(tempNode->getTextToDecNum());
        ll->addLast(numIn);
    }
}
//------------------ main
int main(){
    string stupidText="Hello world !!! @123";
    LinkedList *textLL=new LinkedList();
    LinkedList *biNumLL=new LinkedList();
    LinkedList *decNumLL=new LinkedList();
    add_charToLL(stupidText, textLL);
    for(Node *curr=textLL->head;curr!=NULL;curr=curr->next){
        biNumLL->addLast(decimal_to_binary(curr->get_num()));
    }
    cout<<"TEST: ";biNumLL->showLL();
	string biNumText, keyText;
    string *ptr_keyText=&keyText;
    while(biNumLL->head!=NULL){
        biNumText=biNumText+biNumLL->getFirstNode()->text+" ";
    }
    string ciphertext=removeRepeatChar(biNumText, ptr_keyText);
    cout<<"Plaintext: "<<stupidText<<endl;
    cout<<"Plaintext binary number: "<<biNumText<<endl<<endl;
    cout<<"Ciphertext: "<<ciphertext<<endl;
    cout<<"Key: "<<keyText<<endl<<endl;
    cout<<"Decrypt to binary text: "<<repeatChar(ciphertext, keyText)<<endl;
    cout<<"Decrypt to decimal text: ";
    put_biNumTo_decNumInLL(biNumText, decNumLL);decNumLL->showLL();
    cout<<"Decrypt to normal text: ";
    decNumLL->showLLChar();
    cout<<endl<<endl<<"Ciphertext (char)"<<endl;
}