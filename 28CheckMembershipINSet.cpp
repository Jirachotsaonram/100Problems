#include <iostream>
#include <set>
#include <string>

using namespace std;

// ฟังก์ชันสำหรับตรวจสอบว่าสมาชิกอยู่ในเซ็ตหรือไม่
bool check_membership(set<string> s, string value) {
    // ตรวจสอบว่าสมาชิก value อยู่ในเซ็ต s หรือไม่
    if (s.find(value) != s.end()) {
        return true; // ถ้าเจอ
    }
    return false; // ถ้าไม่เจอ
}

int main() {
    // กำหนดเซ็ตที่มีสมาชิกเป็นตัวเลข สระ และชื่อสี
    set<string> s = {"1", "2", "3", "a", "e", "i", "o", "u", "red", "green", "blue"};
    
    string value;
    cout << "Enter a value to check: ";
    cin >> value;

    // เรียกใช้ฟังก์ชันเพื่อตรวจสอบสมาชิกในเซ็ต
    if (check_membership(s, value)) {
        cout << value << " is in the set." << endl;
    } else {
        cout << value << " is not in the set." << endl;
    }

    return 0;
}
