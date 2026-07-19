#include"DAS.hpp"
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
string readFile(string filePath){
    string line;
    string text;
    ifstream reader(filePath);
    if(!reader){
        cout<<"Can't open."<<endl;
        return "-";
    }
    while(getline(reader, line)){
        text=text+" "+line;
    }
    reader.close();
    return text;
}
string removeRepeatChar(string* ptrKey, string plaintext){
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
            *ptrKey=fullKey;
            break;
		}
	}
	return newStr;
}
int power(int base, int pow){
	if(pow==0){
		return 1;
	}
	return base*power(base, pow-1);
}
int binaryToDecimal(string binary){
	int decNum=0;
	for(int i=binary.length()-1;i>=0;i--){
		decNum=decNum+((int(binary[binary.length()-1-i])-48)*(power(2, i)));
	}
	return decNum;
}
string repeatChar(char ch, int repeatNum){
	string str;
	for(int i=0;i<repeatNum;i++){
		str=str+ch;
	}
	return str;
}
string decrypt(string ciphertext, Node* keyHead){
    string plaintext;
    for(Node* currKeyNode=keyHead;currKeyNode!=NULL;currKeyNode=(*currKeyNode).next){
        string currKey=(*currKeyNode).text;
        int keyIdx=0;
        string binaryText;
        for(int idx=0;idx<ciphertext.length();idx++){
            binaryText=binaryText+repeatChar(ciphertext[idx], currKey[keyIdx++]-48);
            if(keyIdx==currKey.length()){
                plaintext=plaintext+char(binaryToDecimal(binaryText));
                break;
            }
        }
    }
    return plaintext;
}
//------------------ main
int main(){
    string filePath="C:\\Users\\Santirat\\Desktop\\code\\GitHubCode\\code\\Cpp\\Stupid_encrypt3.0\\text.txt";
    string plaintext=readFile(filePath);
    string plaintextNum;
    LinkedList plainCharLL;
    string key;
    string* ptr_key=&key;
    for(int i=0;i<plaintext.length();i++){
        plainCharLL.addLastNode(plaintext[i]);
    }
    /* plainCharLL.showNumLL(); */
    for(Node* curr=plainCharLL.head;curr!=NULL;curr=(*curr).right){
        plaintextNum=plaintextNum+" "+decimal_to_binary((*curr).num);
    }
    /* cout<<plaintextNum<<endl; */
    cout<<removeRepeatChar(ptr_key, plaintextNum)<<endl;
    cout<<key<<endl;
}