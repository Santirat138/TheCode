#include<iostream>
#include <fstream>
using namespace std;
string mainPath="C:\\Users\\WIN11\\Desktop\\code\\GitHubCode\\code\\Cpp\\HistoryTimeline\\TEST_FILE.txt";
//------------------ class
class InfoStorage{
    public:
        int infoAmount;
        string infoList[10];
        InfoStorage(){
            infoAmount=0;
            for(int i=0;i<10;i++){
                infoList[i]="-";
            }
        }
        bool isEmpty(){
            if(infoAmount==0){
                return true;
            }
            return false;
        }
        void addInfo(string newInfo){
            if(infoAmount==10){
                cout<<"Can't add more info."<<endl;
                return ;
            }
            for(int i=0;i<10;i++){
                if(infoList[i]=="-"){
                    infoList[i]=newInfo;
                    infoAmount++;
                    break;
                }
            }
        }
        void showInfo(){
            for(int i=0;i<10;i++){
                if(infoList[i]!="-"){
                    cout<<infoList[i]<<endl;
                }
            }
            cout<<endl;
        }
};
class Date{
    public:
        int yearNumber;
		InfoStorage month[12];
};
class Year{
	public:
        Date date;
		Year* nextYear;
        Year(int newYear, Year* yearIn){
            date.yearNumber=newYear;
            nextYear=yearIn;
        }
        void showInfo(){
            for(int currMonth=0;currMonth<12;currMonth++){
                if(date.month[currMonth].isEmpty()==false){
                    cout<<"Month "<<currMonth+1<<endl;
                    date.month[currMonth].showInfo();
                }
            }
            cout<<endl;
        }
};
class YearsList{
    public:
        Year* firstYear;
        YearsList(){
            firstYear=NULL;
        }
        void showAllData(){
            for(Year* currYear=firstYear;currYear!=NULL;currYear=(*currYear).nextYear){
                cout<<"Year: "<<(*currYear).date.yearNumber<<endl;
                (*currYear).showInfo();
                cout<<"---------------"<<endl;
            }
        }
        bool isSameYear(int yearIn){
            for(Year* currY=firstYear;currY!=NULL;currY=(*currY).nextYear){
                if((*currY).date.yearNumber==yearIn){
                    return true;
                }
            }
            return false;
        }
        void addLastYear(int newYearNumber){
            if(isSameYear(newYearNumber)==true){
                return ;
            }
            Year* newYear=new Year(newYearNumber, NULL);
            (*newYear).date.yearNumber=newYearNumber;
            if(firstYear==NULL){
                firstYear=newYear;
                return ;
            }
            for(Year* currY=firstYear;currY!=NULL;currY=(*currY).nextYear){
                if((*currY).nextYear==NULL){
                    (*currY).nextYear=newYear;
                    break;
                }
            }
        }
        void addData(int targetMonth, int targetYear, string newData){
            for(Year* currY=firstYear;currY!=NULL;currY=(*currY).nextYear){
                if((*currY).date.yearNumber==targetYear){
                    for(int currM=0;currM<12;currM++){
                        if(currM==targetMonth-1){
                            (*currY).date.month[currM].addInfo(newData);
                            return ;
                        }
                    }
                }
            }
        }
        void sortYear(){
            for(Year* yearA=firstYear;(*yearA).nextYear!=NULL;yearA=(*yearA).nextYear){
                for(Year* yearB=(*yearA).nextYear;yearB!=NULL;yearB=(*yearB).nextYear){
                    if((*yearA).date.yearNumber>(*yearB).date.yearNumber){
                        swap((*yearA).date, (*yearB).date);
                    }
                }
            }
        }
};
//------------------ functions
void updateFile(YearsList newList){
    ofstream writer(mainPath);
    for(Year* currYear=newList.firstYear;currYear!=NULL;currYear=(*currYear).nextYear){
        for(int i=0;i<12;i++){
            for(int j=0;j<(*currYear).date.month[i].infoAmount;j++){
                writer<<i+1<<" "<<(*currYear).date.yearNumber<<" "<<(*currYear).date.month[i].infoList[j]<<endl;
            }
        }
    }
    writer.close();
}
void DetailsReader(){
    YearsList yearList;
    int month, year;
    string details;
    ifstream reader(mainPath);
    if(reader.is_open()==false){
        cout<<"Can't open."<<endl;
        return ;
    }
    while(reader>>month>>year>>details){
        yearList.addLastYear(year);
        yearList.addData(month, year, details);
    }
    reader.close();
    yearList.sortYear();
    yearList.showAllData();
    updateFile(yearList);
}
//------------------ main
int main(){
    DetailsReader();
}