#include <iostream>
#include <vector>
#include <iomanip> // สำหรับ std::fixed และ std::setprecision()
#include <cmath>   // สำหรับ std::round()

// ฟังก์ชันสำหรับคำนวณราคาหลังหักส่วนลด
std::vector<float> calculate_discounted_prices(const std::vector<float>& prices, float discount_percentage) {
    std::vector<float> discounted_prices; // เก็บราคาหลังหักส่วนลด

    // วนลูปผ่านราคาสินค้าแต่ละรายการ
    for (float price : prices) {
        // คำนวณราคาหลังหักส่วนลดตามสูตร
        float discounted_price = price * (1 - discount_percentage / 100);
        // ปัดเศษให้เป็นทศนิยมสองตำแหน่ง
        discounted_price = std::round(discounted_price * 100) / 100;
        // เพิ่มราคาที่ได้ลงใน vector
        discounted_prices.push_back(discounted_price);
    }

    return discounted_prices;
}

int main() {
    // ตัวอย่างข้อมูลราคาสินค้า
    std::vector<float> prices = {100.0, 250.0, 75.0};
    // ตัวอย่างส่วนลดเป็นเปอร์เซ็นต์
    float discount_percentage = 20.0;

    // เรียกใช้ฟังก์ชันเพื่อคำนวณราคาหลังหักส่วนลด
    std::vector<float> result = calculate_discounted_prices(prices, discount_percentage);

    // แสดงผลลัพธ์ราคาหลังหักส่วนลด
    std::cout << "Discounted Prices: ";
    for (float price : result) {
        // กำหนดให้แสดงผลเป็นทศนิยมสองตำแหน่ง
        std::cout << std::fixed << std::setprecision(2) << price << " ";
    }
    std::cout << std::endl;

    return 0;
}