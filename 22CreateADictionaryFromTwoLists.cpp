#include <iostream>
#include <vector>
#include <map>
using namespace std;

// ฟังก์ชันสำหรับสร้างแผนที่ (map) จากสองรายการ
map<int, string> create_dictionary(const vector<int>& list1, const vector<string>& list2) {
    map<int, string> result;

    // ตรวจสอบว่าขนาดของ list1 และ list2 เท่ากัน
    if (list1.size() == list2.size()) {
        for (size_t i = 0; i < list1.size(); ++i) {
            result[list1[i]] = list2[i];  // จับคู่ค่าใน list1 กับ list2
        }
    }
    
    return result;
}

int main() {
    // ตัวอย่างรายการ list1 และ list2
    vector<int> list1 = {1, 2, 3, 4};
    vector<string> list2 = {"blue", "green", "pink", "yellow"};

    // เรียกใช้ฟังก์ชันเพื่อสร้างแผนที่
    map<int, string> result = create_dictionary(list1, list2);

    // แสดงผลลัพธ์
    for (const auto& pair : result) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
