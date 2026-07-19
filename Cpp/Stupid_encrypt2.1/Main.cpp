#include"NodeLL.hpp"
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
Info removeRepeatChar(string plaintext){
    Info info;
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
			info.str=newStr;
            info.num=stoi(fullKey);
            return info;
		}
	}
	return info;
}
LinkedList encrypt(LinkedList textLL){
	LinkedList encryptLL;
	for(Node* currNode=textLL.head;currNode!=NULL;currNode=(*currNode).next){
		Info textInfo=removeRepeatChar((*currNode).info.str);
		encryptLL.addInfoLastNode(textInfo.str, textInfo.num);
	}
	return encryptLL;
}
string repeatChar(char ch, int repeatNum){
	string str;
	for(int i=0;i<repeatNum;i++){
		str=str+ch;
	}
	return str;
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
LinkedList decrypt(Node* cipherHead){
	LinkedList plaintextLL;
	for(Node* currNode=cipherHead;currNode!=NULL;currNode=(*currNode).next){
		string binaryText;
		string plaintext;
        for(int charIdx=0;charIdx<(*currNode).info.str.length();charIdx++){
            binaryText=binaryText+repeatChar((*currNode).info.str[charIdx], (to_string((*currNode).info.num)[charIdx])-48);
		}
		plaintext=char(binaryToDecimal(binaryText));
		plaintextLL.addStrLastNode(plaintext);	
	}
    return plaintextLL;
}

//------------------ main
int main(){
    /* string stupidText="Hello world !!! @123"; */
	string stupidText="Hello my name";
    LinkedList binaryLL;
    LinkedList cipherLL;
	LinkedList plaintextLL;
    for(int i=0;i<stupidText.length();i++){
        binaryLL.addStrLastNode(decimal_to_binary(int(stupidText[i])));
    }
    cipherLL=encrypt(binaryLL);
    plaintextLL=decrypt((cipherLL).head);
	cipherLL.showLL();
    plaintextLL.showLL();
}
