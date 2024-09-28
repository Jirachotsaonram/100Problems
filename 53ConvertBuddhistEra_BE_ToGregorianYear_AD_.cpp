#include <iostream>
using namespace std;

// ฟังก์ชันสำหรับแปลงปีพุทธศักราชเป็นคริสต์ศักราช
int convert_be_to_ad(int be_year) {
    return be_year - 543;
}

int main() {
    // รับค่าปีพุทธศักราชจากผู้ใช้
    int be_year;
    cout << "กรุณาใส่ปีพุทธศักราช (B.E.): ";
    cin >> be_year;
    
    // เรียกใช้ฟังก์ชันเพื่อแปลงเป็นปีคริสต์ศักราช
    int ad_year = convert_be_to_ad(be_year);
    
    // แสดงผลลัพธ์
    cout << "ปีคริสต์ศักราช (A.D.) คือ: " << ad_year << endl;
    
    return 0;
}
