#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ฟังก์ชันคำนวณความยาวเฉลี่ยของสตริง
float average_length_of_strings(const vector<string>& strings) {
    int totalLength = 0;

    // วนลูปเพื่อหาความยาวของแต่ละสตริงและรวมความยาวทั้งหมด
    for (const string& str : strings) {
        totalLength += str.length();
    }

    // หาค่าเฉลี่ยโดยหารความยาวรวมด้วย 5
    return static_cast<float>(totalLength) / strings.size();
}

int main() {
    vector<string> strings(5);
    
    // รับข้อมูลสตริง 5 ตัวจากผู้ใช้
    cout << "Enter 5 strings: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "String " << i+1 << ": ";
        getline(cin, strings[i]);
    }

    // เรียกใช้ฟังก์ชันเพื่อหาความยาวเฉลี่ย
    float averageLength = average_length_of_strings(strings);

    // แสดงผลลัพธ์
    cout << "Average Length of Strings: " << averageLength << endl;

    return 0;
}
