#include <iostream>
using namespace std;

// ฟังก์ชันสำหรับคำนวณเส้นรอบรูปของสามเหลี่ยม
float calculate_perimeter(float a, float b, float c) {
    return a + b + c;
}

int main() {
    float a, b, c;
    
    // รับความยาวของด้านทั้งสามจากผู้ใช้
    cout << "Enter the length of side a: ";
    cin >> a;
    cout << "Enter the length of side b: ";
    cin >> b;
    cout << "Enter the length of side c: ";
    cin >> c;
    
    // ตรวจสอบเงื่อนไขสามเหลี่ยม
    if (a + b > c && a + c > b && b + c > a) {
        // คำนวณและแสดงเส้นรอบรูป
        cout << "Perimeter of the triangle is: " << calculate_perimeter(a, b, c) << endl;
    } else {
        // กรณีที่ค่าที่กรอกมาไม่สามารถสร้างเป็นสามเหลี่ยมได้
        cout << "The values entered do not form a valid triangle." << endl;
    }
    
    return 0;
}
