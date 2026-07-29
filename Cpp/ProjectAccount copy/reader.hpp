#include"da.hpp"
#include<fstream>
#include<sstream>
using namespace std;
string path="C:\\Users\\WIN11\\Desktop\\code\\TheCode\\Cpp\\ProjectAccount copy\\data.csv";

class Account{
    public:
        TableArray* tArray[MONTH_CAPACITY];
        string row;
        void sort(){
            sortTableArray(tArray);
        }
        void show(){
            for(int i=1;i<MONTH_CAPACITY;i++){
                (*tArray[i]).show();
            }
        }
        void read(){
            ifstream reader(path);
            string line;
            int i=0;        
            Date date;
            Info info;
            if(!reader){
                cout<<"Can't open."<<endl;
                return ;
            }
            getline(reader, row);
            for(int i=1;i<13;i++){
                tArray[i]=new TableArray(i);
            }
            while(reader>>line){
                string day, month, type, name, price;
                stringstream ss(line);
                getline(ss, day, ',');
                getline(ss, month, ',');
                getline(ss, type, ',');
                getline(ss, name, ',');
                getline(ss, price);
                date.day=stoi(day);
                date.month=stoi(month);
                info.type=type;
                info.name=name;
                info.price=stoi(price);
                (*tArray[stoi(month)]).add(date, info);
            }
            reader.close();
        }
        void write(TableArray* newTArray[]){
            ofstream writer(path);
            if(!writer){
                cout<<"Can't open."<<endl;
                return ;
            }
            writer<<row<<endl;
            
            writer.close();
        }
};