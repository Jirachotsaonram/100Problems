#include <iostream>
#include <string>
using namespace std;

string compare_string_lengths(const string& str1, const string& str2) {
    // คำนวณความยาวของสตริงทั้งสอง
    int len1 = str1.length();
    int len2 = str2.length();

    // เปรียบเทียบความยาวและคืนค่า
    if (len1 > len2) {
        return "The first string is longer by " + to_string(len1 - len2) + " character(s).";
    } else if (len1 < len2) {
        return "The second string is longer by " + to_string(len2 - len1) + " character(s).";
    } else {
        return "Both strings have the same length.";
    }
}

int main() {
    // ทดสอบฟังก์ชันด้วยตัวอย่างที่ให้มา
    string str1 = "apple";
    string str2 = "banana";

    // เรียกใช้ฟังก์ชันและแสดงผลลัพธ์
    cout << compare_string_lengths(str1, str2) << endl;

    return 0;
}
