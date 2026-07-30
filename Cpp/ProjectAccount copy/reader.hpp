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
        void write(){
            /* ofstream writer(path);
            if(!writer){
                cout<<"Can't open."<<endl;
                return ;
            } 
            writer<<row<<endl; */
            for(int m=1;m<MONTH_CAPACITY;m++){
                for(int i=0;i<(*tArray[m]).lastIdx;i++){
                    //string name=(*(*(*tArray[m]).tableArray[i].recLL).head).name;
                    //int price=(*(*(*tArray[m]).tableArray[i].recLL).head).price;
                    //cout<<m<<","<<i<<endl;
                    if((*(*tArray[m]).tableArray[i].recLL).head!=NULL){
                        RecNode* node=(*(*tArray[m]).tableArray[i].recLL).head;
                        cout<<"\t"<<m<<","<<i<<","<<(*(*tArray[m]).tableArray[i].recLL).typeName<<",";
                        cout<<(*node).name<<","<<(*node).price<<endl;
                    }
                }
                /*for(int d=0;d<(*tArray[m]).lastIdx;d++){
                    int day=(*tArray[m]).tableArray[d].date.day;
                    int month=(*tArray[m]).tableArray[d].date.month;
                    for(RecNode* cNode=(*(*tArray[m]).tableArray[d].recLL).head;cNode!=NULL;cNode=(*cNode).next){
                        cout<<day<<","<<month<<","<<(*(*tArray[m]).tableArray[d].recLL).typeName<<","<<(*cNode).name<<","<<(*cNode).price<<endl;
                    }
                }*/
            }
            //writer.close();
        }
        void add(Date date, Info info){
            (*tArray[date.month]).add(date, info);
        }
};