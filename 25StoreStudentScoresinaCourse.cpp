#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// ฟังก์ชันที่จัดเก็บข้อมูลนักเรียนใน map แบบซ้อน
map<string, map<string, float>> store_student_scores(const vector<tuple<string, string, float>>& student_data) {
    map<string, map<string, float>> student_scores;
    
    for (const auto& data : student_data) {
        string student_id = get<0>(data);
        string name = get<1>(data);
        float score = get<2>(data);
        
        // เก็บชื่อใน map ของ string และคะแนนใน float
        student_scores[student_id]["name"] = name[0];  // เก็บตัวแรกของชื่อเพื่อหลีกเลี่ยงชนิดข้อมูลต่างกัน
        student_scores[student_id]["score"] = score;
    }
    
    return student_scores;
}

int main() {
    // ข้อมูลนักเรียน
    vector<tuple<string, string, float>> student_data = {
        {"123456", "Alice", 85.5},
        {"654321", "Bob", 92.0},
        {"112233", "Charlie", 78.0}
    };
    
    // เรียกใช้ฟังก์ชันและเก็บผลลัพธ์
    map<string, map<string, float>> result = store_student_scores(student_data);
    
    // แสดงผลลัพธ์
    for (const auto& student : result) {
        cout << "Student ID: " << student.first << endl;
        cout << "  Name: " << student.second.at("name") << endl;
        cout << "  Score: " << student.second.at("score") << endl;
    }
    
    return 0;
}
