#include <iostream>
#include <vector>

using namespace std;

// ฟังก์ชันแปลงเกรดเป็นคะแนน GPA
float calculate_gpa(vector<int> grades) {
    // แปลงเกรดเป็นคะแนน GPA
    float total_points = 0;
    for (int grade : grades) {
        if (grade >= 80) {
            total_points += 4.0;  // A
        } else if (grade >= 75) {
            total_points += 3.5;  // B+
        } else if (grade >= 70) {
            total_points += 3.0;  // B
        } else if (grade >= 65) {
            total_points += 2.5;  // C+
        } else if (grade >= 60) {
            total_points += 2.0;  // C
        } else if (grade >= 55) {
            total_points += 1.5;  // D+
        } else if (grade >= 50) {
            total_points += 1.0;  // D
        } else {
            total_points += 0.0;  // F
        }
    }
    
    // หาค่าเฉลี่ย GPA
    return total_points / grades.size();
}

int main() {
    // ตัวอย่างเกรดนักเรียนใน 5 วิชา
    vector<int> grades = {85, 72, 63, 58, 49};

    // คำนวณ GPA
    float gpa = calculate_gpa(grades);

    // แสดงผลลัพธ์
    cout << "GPA for the term: " << gpa << endl;

    return 0;
}
