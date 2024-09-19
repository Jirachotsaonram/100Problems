#include <iostream>
#include <string>
#include <tuple>

using namespace std;

// ฟังก์ชันแยกตัวอักษรตำแหน่งคู่และคี่
tuple<string, string> separate_by_index(const string& input) {
    string evenIndexedChars;
    string oddIndexedChars;
    
    // วนลูปผ่านสตริงที่รับเข้ามา
    for (size_t i = 0; i < input.length(); ++i) {
        if (i % 2 == 0) {
            evenIndexedChars += input[i];  // ตัวอักษรที่ตำแหน่งคู่
        } else {
            oddIndexedChars += input[i];   // ตัวอักษรที่ตำแหน่งคี่
        }
    }

    return make_tuple(evenIndexedChars, oddIndexedChars);
}

int main() {
    string input;

    // รับสตริงจากผู้ใช้
    cout << "Enter a string: ";
    getline(cin, input);

    // เรียกฟังก์ชันแยกตัวอักษรตำแหน่งคู่และคี่
    auto [evenChars, oddChars] = separate_by_index(input);

    // แสดงผลลัพธ์
    cout << "Even Indexed Characters: " << evenChars << endl;
    cout << "Odd Indexed Characters: " << oddChars << endl;

    return 0;
}
