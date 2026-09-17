#include"daStruct.hpp"
#include<fstream>
string filePath="C:\\Users\\WIN11\\Desktop\\code\\TheCode\\Cpp\\ProjectWantList\\list.csv";
//      class
class List{
    public:
        TypeArray typeArray;
        string row;
        void read(){
            ifstream reader(filePath);
            string line;
            if(!reader){
                cout<<"Can't open."<<endl;
                return ;
            }
            getline(reader, row);
            while(getline(reader, line)){
                string name, type, price, need, want;
                stringstream ss(line);
                getline(ss, name, ',');
                getline(ss, type, ',');
                getline(ss, price, ',');
                getline(ss, need, ',');
                getline(ss, want);
                typeArray.addLL(name, type, stoi(price), stoi(need), stoi(want));
            }
            reader.close();
        }
        void write(){
            ofstream writer(filePath);
            if(!writer){
                cout<<"Can't open."<<endl;
                return ;
            } 
            writer<<row<<endl;
            for(int i=0;i<CAPACITY;i++){
                if((typeArray.itemLL[i]).head!=NULL){
                    for(ItemNode* cNode=(typeArray.itemLL[i]).head;cNode!=NULL;cNode=(*cNode).next){
                        writer<<(*cNode).name<<","<<(*cNode).price<<","<<(*cNode).pws.needVal<<","<<(*cNode).pws.wantVal<<endl;
                    }
                }
            }
            writer.close();
        }
};