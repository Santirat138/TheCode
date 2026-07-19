#include <cstdlib>
#include <iostream>
#include <fstream>
#define EVENT_CAPACITY 100
#define TIMELINE_CAPACITY 10
using namespace std;
//------------------ variable
string MAIN_filePath="FilePath.txt";

//------------------ functions 1

//------------------ class 1
class Details{
	public:
		string eventYear;
		string eventName;
};
//------------------ functions 2
void updateFile(Details details[], int detailSize, string filePath){
    ofstream writer(filePath);
    for(int i=0;i<detailSize;i++){
        writer<<details[i].eventYear<<" "<<details[i].eventName<<endl;
    }
    writer.close();
}
void sort(Details details[], int size){
    for(int last_idx=0;last_idx+1<size;last_idx++){
        for(int curr=last_idx+1;curr<size;curr++){
            if(stoi(details[curr].eventYear)<stoi(details[last_idx].eventYear)){
                swap(details[curr].eventYear, details[last_idx].eventYear);
                swap(details[curr].eventName, details[last_idx].eventName);
            }
        }
    }
}
//------------------ class 2
class Timeline{
	public:
		string timelineName;
        Details timeDetails[EVENT_CAPACITY];
        int timeSize=0;
        string filePath;
        Timeline(string nameIn, string filePathIn){
            timelineName=nameIn;
            filePath=filePathIn;
            ifstream reader(filePathIn);
            while(reader>>timeDetails[timeSize].eventYear>>timeDetails[timeSize].eventName){
                timeSize++;
            }
            reader.close();
            sort(timeDetails, timeSize);
		}
        void show(){
            for(int i=0;i<timeSize;i++){
                cout<<timeDetails[i].eventYear<<" "<<timeDetails[i].eventName<<endl;
            }
            cout<<endl;
        }
        void addEvent(Details newDetails){
            timeDetails[timeSize].eventYear=newDetails.eventYear;
            timeDetails[timeSize++].eventName=newDetails.eventName;
            sort(timeDetails, timeSize);
        }
        void mainFunc(){
            string cmd;
            do{
                cout<<"cmd: search, insert, delete, exit"<<endl<<endl;
                cin>>cmd;
                if(cmd=="search"){
                    string targetYear;
                    cout<<"Find year: ";
                    cin>>targetYear;
                    for(int i=0;i<timeSize;i++){
                        if(timeDetails[i].eventYear==targetYear){
                            cout<<endl<<"Result: "<<timeDetails[i].eventYear<<" "<<timeDetails[i].eventName<<endl;
                            break;
                        }
                        else if(i > 0 && stoi(timeDetails[i-1].eventYear) < stoi(targetYear) && stoi(timeDetails[i].eventYear) > stoi(targetYear)){
                            cout<<endl<<"After: "<<timeDetails[i-1].eventYear<<timeDetails[i-1].eventName<<endl;
                            cout<<"Result: "<<targetYear<<" Not found."<<endl;
                            cout<<"Before: "<<timeDetails[i].eventYear<<" "<<timeDetails[i].eventName<<endl;
                            break;
                        }
                    }
                    cout<<endl;
                }
                else if(cmd=="insert"){
                    Details newDetails;
                    cout<<"Enter new event year: ";
                    cin>>newDetails.eventYear;
                    cout<<"Enter new event name: ";
                    cin>>newDetails.eventName;
                    cout<<endl;
                    addEvent(newDetails);
                }
                else if(cmd=="delete"){
                    string targetYear;
                    cin>>targetYear;
                    bool found=false;
                    for(int i=0;i<timeSize;i++){
                        if(timeDetails[i].eventYear==targetYear){
                            found=true;
                            cout<<"Delete year: "<<timeDetails[i].eventYear<<" "<<timeDetails[i].eventName<<endl<<"Y/N"<<endl;
                            char confirm;
                            cin>>confirm;
                            if(confirm=='N'){
                                break;
                            }
                            else if(confirm=='Y'){
                                while(i<timeSize-1){
                                    timeDetails[i].eventYear=timeDetails[i+1].eventYear;
                                    timeDetails[i].eventName=timeDetails[i+1].eventName;
                                    i++;
                                }
                                timeSize--;
                            }
                            break;
                        }
                    }
                    if(found==false){
                        cout<<"Can't delete "<<targetYear<<"."<<endl;
                    }
                    cout<<endl;
                }
                updateFile(timeDetails, timeSize, filePath);
            }
            while(cmd!="exit");
        }
};
class TimelineList{
	public:
		Timeline* timeline[TIMELINE_CAPACITY];
        string timelineFilePath[TIMELINE_CAPACITY];
        int amountFilePath=0;
		TimelineList(){
            ifstream pathReader(MAIN_filePath);
            while(getline(pathReader, timelineFilePath[amountFilePath])){
                timeline[amountFilePath]=NULL;
                amountFilePath++;
            }
            pathReader.close();
            for(int i=0;i<amountFilePath;i++){
                timeline[i]=new Timeline(to_string(i), timelineFilePath[i]);
            }
        }
};
//------------------ main
int main(){
	//system("chcp 65001");
	TimelineList TEST_timeline;
    Details worldDetails[EVENT_CAPACITY];
    string zone;
    do{
        cout<<"Enter history timeline zone."<<endl<<endl;
		int i=0;
        for(i=0;i<TEST_timeline.amountFilePath;i++){
            cout<<"  "<<i+1<<". "<<TEST_timeline.timelineFilePath[i]<<endl;
        }
		cout<<"  "<<i+1<<". "<<"world"<<endl;
		cout<<"     quit"<<endl<<endl<<"Enter file path or name: ";
        cin>>zone;
		cout<<endl;
        if(zone=="quit"){
            break;
        }
        else if(zone=="world"){
            cout<<endl<<"World"<<endl;
            int worldSize=0;
            for(int bigI=0;bigI<TEST_timeline.amountFilePath;bigI++){
                for(int i=0;i<(*(TEST_timeline.timeline[bigI])).timeSize;i++){
                    worldDetails[worldSize].eventYear=(*(TEST_timeline.timeline[bigI])).timeDetails[i].eventYear;
                    worldDetails[worldSize++].eventName=(*(TEST_timeline.timeline[bigI])).timeDetails[i].eventName;
                }
            }
            sort(worldDetails, worldSize);
            string cmd;
            do{
                cout<<"cmd: search, exit"<<endl;
                cin>>cmd;
                if(cmd=="search"){
                    string targetYear;
                    cout<<"Find year: ";
                    cin>>targetYear;
                    for(int i=0;i<worldSize;i++){
                        if(worldDetails[i].eventYear==targetYear){
                            cout<<endl<<"Result: "<<worldDetails[i].eventYear<<" "<<worldDetails[i].eventName<<endl;
                            break;
                        }
                        else if(i > 0 && stoi(worldDetails[i-1].eventYear) < stoi(targetYear) && stoi(worldDetails[i].eventYear) > stoi(targetYear)){
                            cout<<endl<<"After: "<<worldDetails[i-1].eventYear<<worldDetails[i-1].eventName<<endl;
                            cout<<"Result: "<<targetYear<<" Not found."<<endl;
                            cout<<"Before: "<<worldDetails[i].eventYear<<" "<<worldDetails[i].eventName<<endl;
                            break;
                        }
                    }
                }
                cout<<endl;
            }
            while(cmd!="exit");
        }
		else{
			for(int i=0;i<TEST_timeline.amountFilePath;i++){
				if(zone==TEST_timeline.timelineFilePath[i]){
					cout<<(*(TEST_timeline.timeline[i])).filePath<<endl;
					(*(TEST_timeline.timeline[i])).mainFunc();
					break;
				}
			}
		}

    }
    while(zone!="quit");
}