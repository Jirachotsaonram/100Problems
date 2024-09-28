#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชันสำหรับแยกตัวเลขคู่และคี่
void separate_even_odd(const vector<int>& numbers, vector<int>& even_list, vector<int>& odd_list) {
    for (int num : numbers) {
        if (num % 2 == 0) {
            even_list.push_back(num); // ถ้าตัวเลขเป็นเลขคู่ เพิ่มลงใน even_list
        } else {
            odd_list.push_back(num);  // ถ้าตัวเลขเป็นเลขคี่ เพิ่มลงใน odd_list
        }
    }
}

int main() {
    // ลิสต์ของตัวเลข 10 ตัว
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> even_list, odd_list;

    // เรียกใช้ฟังก์ชันแยกตัวเลขคู่และคี่
    separate_even_odd(numbers, even_list, odd_list);

    // แสดงผลลัพธ์
    cout << "Even numbers: ";
    for (int num : even_list) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Odd numbers: ";
    for (int num : odd_list) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
