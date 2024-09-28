#include <iostream>
#include <vector>

// ฟังก์ชันคำนวณจำนวนเงินทั้งหมดหลังใช้ส่วนลด
float calculate_total_payment(int num_bills, std::vector<float> bills) {
    float total_sum = 0.0;
    
    // คำนวณยอดรวมของบิลทั้งหมด
    for (float bill : bills) {
        total_sum += bill;
    }

    // ตรวจสอบเงื่อนไขเพื่อให้ส่วนลด
    if (total_sum >= 10000) {
        total_sum *= 0.8; // ลด 20%
    } else if (total_sum >= 5000) {
        total_sum *= 0.9; // ลด 10%
    } else if (total_sum >= 1000) {
        total_sum *= 0.95; // ลด 5%
    }

    return total_sum; // คืนค่าจำนวนเงินรวมหลังหักส่วนลด
}

int main() {
    // จำนวนบิล
    int num_bills = 3;
    // จำนวนเงินในแต่ละบิล
    std::vector<float> bills = {3000, 4000, 3500};

    // คำนวณจำนวนเงินรวมหลังหักส่วนลด
    float total_payment = calculate_total_payment(num_bills, bills);

    // แสดงผลลัพธ์
    std::cout << "Total payment after discount: " << total_payment << " Baht" << std::endl;

    return 0;
}
