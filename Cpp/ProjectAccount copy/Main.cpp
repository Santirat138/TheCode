#include"reader.hpp"
//      class
class Main{
    public:
        Account account;
        Main(){
            account.read();
        }
        void add(Date date, Info info){
            (*account.tArray[date.month]).add(date, info);
        }
        void sort(){
            account.sort();
        }
        void show(){
            account.show();
        }
};
//      main
int main(){
    Main m;
    m.show();
}