#include <iostream>
#include <cmath>  // สำหรับใช้ฟังก์ชัน pow()

using namespace std;

// ฟังก์ชันคำนวณอัตราผลตอบแทนรายปี
float calculate_annual_return(float initial_investment, float final_investment, int years) {
    // คำนวณอัตราผลตอบแทนรายปีตามสูตร
    float annual_return = pow(final_investment / initial_investment, 1.0 / years) - 1;
    return annual_return * 100;  // แปลงเป็นเปอร์เซ็นต์
}

int main() {
    float initial_investment = 1000;  // เงินลงทุนตั้งต้น
    float final_investment = 1500;    // เงินที่ได้หลังจากการลงทุน
    int years = 5;                    // จำนวนปี

    // เรียกฟังก์ชันและรับผลลัพธ์
    float annual_return = calculate_annual_return(initial_investment, final_investment, years);

    // แสดงผลลัพธ์
    cout << "Annual Rate of Return: " << annual_return << "%" << endl;

    return 0;
}
