#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("example.txt");  // ถ้าไม่มีไฟล์ จะสร้างใหม่

    if (file.is_open()) {
        file << "Hello World\n";
        file << "This is a text file.";
        file.close();
        cout << "สร้างไฟล์สำเร็จ\n";
    } else {
        cout << "ไม่สามารถสร้างไฟล์ได้\n";
    }

    return 0;
}