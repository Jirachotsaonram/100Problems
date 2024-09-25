#include <iostream>
#include <set>
using namespace std;

void build_set() {
    set<int> unique_numbers;
    int num;

    // รับค่าจากผู้ใช้จนกว่าจะได้จำนวนที่ไม่ซ้ำกัน 5 ค่า
    while (unique_numbers.size() < 5) {
        cout << "Enter an integer: ";
        cin >> num;

        // ตรวจสอบว่าค่าที่กรอกเข้ามาซ้ำหรือไม่
        if (unique_numbers.find(num) != unique_numbers.end()) {
            cout << "Duplicate number! Please enter a unique number." << endl;
        } else {
            unique_numbers.insert(num);
        }
    }

    // แสดงผลเซ็ตที่ได้
    cout << "Set of 5 unique integers: {";
    for (auto it = unique_numbers.begin(); it != unique_numbers.end(); ++it) {
        cout << *it;
        if (next(it) != unique_numbers.end()) cout << ", ";
    }
    cout << "}" << endl;
}

int main() {
    build_set();
    return 0;
}
