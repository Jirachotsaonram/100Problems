#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชันสำหรับจัดกลุ่มตัวเลขตามหลักหน่วย
vector<vector<int>> group_by_unit_digit(const vector<int>& numbers) {
    // สร้างลิสต์หลักสำหรับจัดเก็บผลลัพธ์ โดยมี 10 กลุ่ม (สำหรับหลักหน่วย 0-9)
    vector<vector<int>> result(10);
    
    // วนลูปผ่านแต่ละตัวเลขในลิสต์
    for (int num : numbers) {
        // คำนวณหาหลักหน่วยโดยใช้ mod 10
        int unit_digit = abs(num) % 10;
        // เพิ่มตัวเลขเข้าไปในกลุ่มที่ตรงกับหลักหน่วยนั้น ๆ
        result[unit_digit].push_back(num);
    }
    
    return result;
}

int main() {
    // ลิสต์ของเลขจำนวนเต็ม 10 ตัว
    vector<int> numbers = {21, 34, 51, 23, 37, 44, 60, 11, 91, 99};
    
    // เรียกใช้ฟังก์ชันเพื่อจัดกลุ่มเลขตามหลักหน่วย
    vector<vector<int>> grouped_numbers = group_by_unit_digit(numbers);
    
    // แสดงผลลัพธ์
    for (int i = 0; i < grouped_numbers.size(); ++i) {
        cout << "Group " << i << ": ";
        for (int num : grouped_numbers[i]) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
