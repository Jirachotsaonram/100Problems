#include <iostream>
#include <string>

// ฟังก์ชันคำนวณค่าปรับจากความเร็ว
std::string calculate_speeding_fine(float speed) {
    

    // ตรวจสอบว่าขับเร็วเกินหรือไม่
    if (speed < 90) {
        return "No fine."; // ไม่มีค่าปรับ
    } else if (speed >= 90 & speed <= 120) { // ถ้าเกินไม่เกิน 20 km/h
        return "Fine: 500 Baht.";
    } else if (speed >= 121 & speed <= 140) { // ถ้าเกินไม่เกิน 40 km/h
        return "Fine: 1,000 Baht.";
    } else if (speed >= 141 & speed <= 160) { // ถ้าเกินไม่เกิน 60 km/h
        return "Fine: 1,500 Baht."; // ปรับใหม่ตามที่ต้องการ
    } else {
        return "Fine: 2,000 Baht."; // ถ้าเกินมากกว่า 60 km/h
    }
}

int main() {
    // กำหนดความเร็วของรถและขีดจำกัดความเร็ว
    float speed = 141;
    

    // คำนวณค่าปรับ
    std::string result = calculate_speeding_fine(speed);

    // แสดงผลลัพธ์
    std::cout << result << std::endl;

    return 0;
}
