#include <iostream>
#include <vector>

using namespace std;

// ฟังก์ชันในการตรวจสอบว่าเลขเป็นจำนวนเฉพาะหรือไม่
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// ฟังก์ชันหลักในการหาหมายเลขเฉพาะในช่วงที่กำหนด
pair<vector<int>, int> primeNumbersInRange(int start, int end) {
    vector<int> primes;
    int sum = 0;

    for (int number = start; number <= end; number++) {
        if (isPrime(number)) {
            primes.push_back(number);
            sum += number;
        }
    }

    return make_pair(primes, sum);
}

int main() {
    int start, end;
    cout << "กรุณากรอกหมายเลขเริ่มต้น: ";
    cin >> start;
    cout << "กรุณากรอกหมายเลขสิ้นสุด: ";
    cin >> end;

    pair<vector<int>, int> result = primeNumbersInRange(start, end);

    // แสดงผลลัพธ์
    cout << "หมายเลขเฉพาะในช่วง: ";
    for (int prime : result.first) {
        cout << prime << " ";
    }
    cout << endl;
    cout << "ผลรวมของหมายเลขเฉพาะ: " << result.second << endl;

    return 0;
}
