#include <iostream>
using namespace std;

// ฟังก์ชันสำหรับคำนวณผลรวมสะสม
int cumulative_sum(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n;
    
    // รับค่าจำนวนเต็มบวกจากผู้ใช้
    cout << "Enter a positive integer: ";
    cin >> n;
    
    // คำนวณและแสดงผลลัพธ์ผลรวมสะสม
    cout << "The cumulative sum from 1 to " << n << " is: " << cumulative_sum(n) << endl;
    
    return 0;
}
