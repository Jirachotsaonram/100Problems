#include <iostream>
#include <cmath> // สำหรับ std::ceil

// ฟังก์ชันคำนวณจำนวนครั้งที่ต้องกระโดด
int calculate_jumps(int d, int s) {
    // ถ้าระยะทาง d น้อยกว่าหรือเท่ากับ s ให้กระโดดครั้งเดียว
    if (d <= s) {
        return 1;
    }
    // ถ้าระยะทาง d มากกว่า s คำนวณจำนวนครั้งโดยปัดเศษขึ้น
    return std::ceil(static_cast<float>(d) / s);
}

int main() {
    // ตัวอย่างระยะทาง d และระยะกระโดด s
    int d = 20;
    int s = 7;

    // เรียกใช้ฟังก์ชันเพื่อคำนวณจำนวนครั้งที่กบต้องกระโดด
    int jumps = calculate_jumps(d, s);

    // แสดงผลลัพธ์
    std::cout << "Number of jumps required: " << jumps << std::endl;

    return 0;
}
