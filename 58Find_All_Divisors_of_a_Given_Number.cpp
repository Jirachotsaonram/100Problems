#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชันสำหรับหาตัวหารทั้งหมดของจำนวนที่กำหนด
vector<int> find_divisors(int num) {
    vector<int> divisors;
    
    // หาและเก็บตัวหาร
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            divisors.push_back(i); // เก็บ i ลงใน vector ถ้ามันเป็นตัวหาร
        }
    }
    
    return divisors; // ส่งคืนตัวหารทั้งหมด
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    // เรียกใช้ฟังก์ชันและเก็บผลลัพธ์
    vector<int> divisors = find_divisors(num);
    
    // แสดงผลลัพธ์
    cout << "Divisors of " << num << ": ";
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}
