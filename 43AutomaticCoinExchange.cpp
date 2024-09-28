#include <iostream>
#include <tuple>
using namespace std;

// ฟังก์ชันคำนวณจำนวนเหรียญ
tuple<int, int, int, int> calculate_coins(int amount) {
    int count10 = amount / 10;   // หาจำนวนเหรียญ 10 หน่วย
    amount %= 10;                // คำนวณจำนวนที่เหลือหลังจากใช้เหรียญ 10 หน่วย
    
    int count5 = amount / 5;     // หาจำนวนเหรียญ 5 หน่วย
    amount %= 5;                 // คำนวณจำนวนที่เหลือหลังจากใช้เหรียญ 5 หน่วย
    
    int count2 = amount / 2;     // หาจำนวนเหรียญ 2 หน่วย
    amount %= 2;                 // คำนวณจำนวนที่เหลือหลังจากใช้เหรียญ 2 หน่วย
    
    int count1 = amount;         // เหรียญที่เหลือเป็นเหรียญ 1 หน่วยทั้งหมด
    
    return make_tuple(count10, count5, count2, count1); // ส่งผลลัพธ์เป็น tuple
}

int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    auto [count10, count5, count2, count1] = calculate_coins(amount); // รับผลลัพธ์จากฟังก์ชัน

    cout << "10-unit coins: " << count10 << endl;
    cout << "5-unit coins: " << count5 << endl;
    cout << "2-unit coins: " << count2 << endl;
    cout << "1-unit coins: " << count1 << endl;

    return 0;
}
