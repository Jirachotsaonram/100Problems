#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

// ฟังก์ชันสำหรับนับความถี่ของตัวอักษร
map<char, int> character_frequency(const string& str1, const string& str2, const string& str3, const string& str4, const string& str5) {
    // สร้างแผนที่เพื่อเก็บค่าความถี่ของตัวอักษร
    map<char, int> frequency_count;

    // สร้างอาเรย์ของสตริง
    string strings[] = {str1, str2, str3, str4, str5};

    // นับความถี่ของตัวอักษรในแต่ละสตริง
    for (const auto& str : strings) {
        for (char c : str) {
            if (c != ' ') { // ข้ามช่องว่าง
                frequency_count[c]++;
            }
        }
    }

    return frequency_count; // คืนค่าผลลัพธ์
}

// ฟังก์ชันหลัก
int main() {
    // ทดสอบฟังก์ชัน
    auto result = character_frequency("hello", "world", "test", "case", "example");

    // แสดงผลลัพธ์
    for (const auto& pair : result) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
