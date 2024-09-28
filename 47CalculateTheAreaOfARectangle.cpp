#include <iostream>
using namespace std;

// ฟังก์ชันสำหรับคำนวณพื้นที่ของสี่เหลี่ยมผืนผ้า
float calculate_rectangle_area(float width, float length) {
    return width * length;
}

int main() {
    float width, length;
    
    // รับค่าความกว้างและความยาวจากผู้ใช้
    cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    
    // คำนวณพื้นที่และแสดงผล
    cout << "The area of the rectangle is: " << calculate_rectangle_area(width, length) << endl;
    
    return 0;
}
