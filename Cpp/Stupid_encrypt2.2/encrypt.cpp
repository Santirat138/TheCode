#include"DS.hpp"
#include<fstream>
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
LinkedList readFile(string filePath){
    LinkedList plaintextLL;
    string line;
    ifstream reader(filePath);
    if(!reader){
        cout<<"Can't open."<<endl;
        return plaintextLL;
    }
    while(reader>>line){
        plaintextLL.addLastNode(line);
        plaintextLL.addLastNode(" ");
    }
    reader.close();
    return plaintextLL;
}
void writeFile(string filePath, string ciphertext){
    ofstream file(filePath);
    if(!file){
        cout<<"Can't open file."<<endl;
    }
    file<<ciphertext;
    file.close();
}
string removeRepeatChar(LinkedList* keyLL, string plaintext){
	string str=plaintext;
	int nextTop=top+1;
	int key=1;
	string fullKey;
	string newStr;
	while(true){
		char popNum=pop(str);
		if(popNum==str[nextTop]){
			key++;
		}
		else{
			newStr=newStr+popNum;
			fullKey=fullKey+to_string(key);
			key=1;
		}
		if(nextTop<str.length()-1){
			nextTop++;
		}
		else{
            top=0;
			if(popNum!=str[nextTop]){
				key=1;
				newStr=newStr+str[nextTop];
			}
			else{
				newStr=newStr+popNum;
			}
			fullKey=fullKey+to_string(key);
            (*keyLL).addLastNode(fullKey);
            break;
		}
	}
	return newStr;
}

//------------------ main
int main(){
    string filePath="C:\\Users\\Santirat\\Desktop\\code\\GitHubCode\\code\\Cpp\\Stupid_encrypt2.0.2\\text.txt";
    LinkedList wordLL=readFile(filePath);
    LinkedList wordTableLL[wordLL.nodeAmount];
    LinkedList charLL;
    LinkedList keyLL;
    string ciphertext;
    int idx=0;
    for(Node* curr=wordLL.head;curr!=NULL;curr=(*curr).next){
        string currText=(*curr).text;
        for(int i=0;i<currText.length();i++){
            wordTableLL[idx].addLastNode(to_string(int(currText[i])));
        }
        idx++;
    }
    for(int i=0;i<wordLL.nodeAmount;i++){
        for(Node* curr=wordTableLL[i].head;curr!=NULL;curr=(*curr).next){
            charLL.addLastNode(decimal_to_binary(stoi((*curr).text)));
        }
    }
    for(Node* curr=charLL.head;curr!=NULL;curr=(*curr).next){
        ciphertext=ciphertext+removeRepeatChar(&keyLL, (*curr).text);
    }
    keyLL.showLL();
    writeFile(filePath, ciphertext);
}