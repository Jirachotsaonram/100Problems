#include <iostream>
#include <vector>
#include <string>
#include <cmath>  // สำหรับใช้ฟังก์ชัน ceil()

using namespace std;

// ฟังก์ชันคำนวณเกรดที่ต้องการในแต่ละวิชา
vector<string> calculate_required_grades(float current_gpa, float target_gpa, vector<int> credits) {
    // จำนวนชั่วโมงเรียนรวม
    int total_credits = 0;
    for (int credit : credits) {
        total_credits += credit;
    }
    
    // หาจำนวนชั่วโมงเรียนรวมของเทอมที่กำลังจะเรียน
    int semester_credits = 0;
    for (int i = 0; i < 5; ++i) {
        semester_credits += credits[i];
    }

    // GPA รวมที่ต้องการเมื่อจบภาคเรียน
    float total_gpa_needed = target_gpa * total_credits;

    // GPA จากภาคเรียนที่ผ่านมา
    float current_gpa_contribution = current_gpa * (total_credits - semester_credits);

    // GPA ที่ต้องได้จากภาคเรียนนี้
    float gpa_needed_this_semester = (total_gpa_needed - current_gpa_contribution) / semester_credits;

    // เกรดตามคะแนน
    vector<pair<float, string>> grade_scale = {
        {4.0, "A"}, {3.5, "B+"}, {3.0, "B"}, {2.5, "C+"}, {2.0, "C"}, {1.5, "D+"}, {1.0, "D"}, {0.0, "F"}
    };

    // หาว่าเกรดไหนที่ต้องได้ในแต่ละวิชา
    vector<string> required_grades;
    for (int i = 0; i < 5; ++i) {
        float grade_needed = ceil(gpa_needed_this_semester * 2) / 2;  // ปัดเป็นทศนิยมครึ่ง

        // หาเกรดที่ใกล้เคียงที่สุด
        for (auto grade : grade_scale) {
            if (grade_needed >= grade.first) {
                required_grades.push_back(grade.second);
                break;
            }
        }
    }

    return required_grades;
}

int main() {
    float current_gpa = 2.8;       // GPA ปัจจุบัน
    float target_gpa = 3.2;        // GPA เป้าหมาย
    vector<int> credits = {3, 3, 3, 3, 3};  // จำนวนชั่วโมงเรียนในแต่ละวิชา

    // เรียกฟังก์ชันและรับผลลัพธ์
    vector<string> results = calculate_required_grades(current_gpa, target_gpa, credits);

    // แสดงผลลัพธ์
    cout << "Required grades to reach target GPA: " << endl;
    for (int i = 0; i < results.size(); ++i) {
        cout << "Course " << i + 1 << ": " << results[i] << endl;
    }

    return 0;
}
