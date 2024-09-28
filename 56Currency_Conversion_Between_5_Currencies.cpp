#include <iostream>
#include <string>
using namespace std;

// ฟังก์ชันสำหรับแปลงค่าเงินจากสกุลหนึ่งไปยังอีกสกุลหนึ่ง
float convert_currency(float amount, string from_currency, string to_currency) {
    // อัตราแลกเปลี่ยนเมื่อเทียบกับ USD
    float usd_to_eur = 0.85;
    float usd_to_gbp = 0.75;
    float usd_to_jpy = 110.0;
    float usd_to_thb = 32.0;
    
    // แปลงจากสกุลที่เลือกเป็น USD ก่อน
    if (from_currency == "USD") {
        // ไม่มีการแปลงเพราะเริ่มจาก USD อยู่แล้ว
    } else if (from_currency == "EUR") {
        amount /= usd_to_eur;
    } else if (from_currency == "GBP") {
        amount /= usd_to_gbp;
    } else if (from_currency == "JPY") {
        amount /= usd_to_jpy;
    } else if (from_currency == "THB") {
        amount /= usd_to_thb;
    } else {
        cout << "Error: Unsupported currency!" << endl;
        return -1;
    }
    
    // แปลงจาก USD ไปยังสกุลเงินที่ต้องการ
    if (to_currency == "USD") {
        // ไม่มีการแปลงเพราะเป็น USD แล้ว
    } else if (to_currency == "EUR") {
        amount *= usd_to_eur;
    } else if (to_currency == "GBP") {
        amount *= usd_to_gbp;
    } else if (to_currency == "JPY") {
        amount *= usd_to_jpy;
    } else if (to_currency == "THB") {
        amount *= usd_to_thb;
    } else {
        cout << "Error: Unsupported currency!" << endl;
        return -1;
    }
    
    return amount;
}

int main() {
    // ตัวอย่าง Input
    float amount = 1000.0;
    string from_currency = "JPY";
    string to_currency = "THB";
    
    // เรียกใช้ฟังก์ชันแปลงค่าเงิน
    float converted_amount = convert_currency(amount, from_currency, to_currency);
    
    // แสดงผลลัพธ์
    if (converted_amount != -1) {
        cout << amount << " " << from_currency << " is equivalent to " << converted_amount << " " << to_currency << endl;
    }

    return 0;
}
