#include <iostream>
#include <string>
using namespace std;

// ฟังก์ชันสำหรับแปลงเงินบาทเป็นสกุลเงินต่าง ๆ
float convert_thb_to_currency(float amount, string to_currency) {
    // กำหนดอัตราแลกเปลี่ยนตามสกุลเงิน
    if (to_currency == "USD") {
        return amount * 0.030;
    } else if (to_currency == "EUR") {
        return amount * 0.027;
    } else if (to_currency == "GBP") {
        return amount * 0.023;
    } else if (to_currency == "JPY") {
        return amount * 3.4;
    } else if (to_currency == "AUD") {
        return amount * 0.045;
    } else {
        // ถ้าใส่สกุลเงินไม่ถูกต้อง
        cout << "Error: Unsupported currency!" << endl;
        return -1;
    }
}

int main() {
    // รับค่าจำนวนเงินและสกุลเงินที่ต้องการแปลงจากผู้ใช้
    float amount;
    string currency;
    
    cout << "กรุณาใส่จำนวนเงินบาท (THB): ";
    cin >> amount;
    
    cout << "กรุณาใส่สกุลเงินที่ต้องการแปลง (USD, EUR, GBP, JPY, AUD): ";
    cin >> currency;
    
    // เรียกใช้ฟังก์ชันเพื่อแปลงค่าเงิน
    float converted_amount = convert_thb_to_currency(amount, currency);
    
    // แสดงผลลัพธ์
    if (converted_amount != -1) {
        cout << amount << " THB เท่ากับ " << converted_amount << " " << currency << endl;
    }

    return 0;
}
