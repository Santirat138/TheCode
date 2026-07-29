#include"DS.hpp"
#include<fstream>
//------------------ functions
string readFile(string filePath){
    string ciphertext;
    string line;
    ifstream reader(filePath);
    if(!reader){
        cout<<"Can't open."<<endl;
        return "-";
    }
    while(reader>>ciphertext){
        
    }
    reader.close();
    return ciphertext;
}
void writeFile(string filePath, string ciphertext){
    ofstream file(filePath);
    if(!file){
        cout<<"Can't open file."<<endl;
    }
    file<<ciphertext;
    file.close();
}
string decimal_to_binary(int decIn){
    int decNum=(decIn);
    string biNum;
    while(decNum>0){
        biNum=to_string(decNum%2)+biNum;
        decNum=decNum/2;
    }
    return biNum;
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
    string filePath="C:\\Users\\WIN11\\Desktop\\code\\GitHubCode\\code\\Cpp\\Stupid_encrypt2.2\\text.txt";
    string ciphertext=readFile(filePath);
    LinkedList keyLL;
    string key;
    getline(cin, key);
    string keyText;
    for(int i=0;i<key.length();i++){
		if(key[i]==' '){
			keyLL.addLastNode(keyText);
			keyText="";
		}
		else{
			keyText=keyText+key[i];
		}
	}
	if(keyText!=""){
		keyLL.addLastNode(keyText);
	}
    keyLL.showLL();
	if(keyText!=""){
		keyLL.addLastNode(keyText);
	}
    string plaintext=decrypt(ciphertext, keyLL.head);
    writeFile(filePath, plaintext);
}