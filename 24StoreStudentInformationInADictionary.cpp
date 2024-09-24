#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// ฟังก์ชันสำหรับเก็บข้อมูลนักเรียนในแผนที่ (map)
map<string, string> store_student_info(const vector<pair<string, string>>& student_data) {
    map<string, string> student_map;

    // เพิ่มข้อมูลแต่ละคู่ในแผนที่ (map)
    for (const auto& student : student_data) {
        student_map[student.first] = student.second;
    }

    return student_map;
}

int main() {
    // ข้อมูลนักเรียนในรูปแบบของ vector ของคู่ (pair) ที่มี Student ID และ Nickname
    vector<pair<string, string>> student_data = {
        {"123456", "Alice"},
        {"654321", "Bob"},
        {"112233", "Charlie"}
    };

    // สร้างแผนที่ (map) จากข้อมูลนักเรียน
    map<string, string> result = store_student_info(student_data);

    // แสดงผลลัพธ์
    for (const auto& student : result) {
        cout << student.first << ": " << student.second << endl;
    }

    return 0;
}
