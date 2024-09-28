#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <unordered_map>
#include <algorithm>  // ใส่ไฟล์หัวข้อนี้เพื่อใช้ 'reverse'

using namespace std;

// ฟังก์ชันสำหรับสลับตัวอักษรพิมพ์เล็กและพิมพ์ใหญ่
char swapCase(char ch) {
    if (islower(ch)) return toupper(ch);
    if (isupper(ch)) return tolower(ch);
    return ch;
}

// ฟังก์ชันสำหรับเปลี่ยนสระ
char replaceVowel(char ch) {
    unordered_map<char, char> vowels = {
        {'a', 'e'}, {'e', 'i'}, {'i', 'o'}, {'o', 'u'}, {'u', 'a'},
        {'A', 'E'}, {'E', 'I'}, {'I', 'O'}, {'O', 'U'}, {'U', 'A'}
    };
    if (vowels.count(ch)) return vowels[ch];
    return ch;
}

string advanced_string_transformation(string s) {
    // ขั้นตอนที่ 1: กลับคำ
    stringstream ss(s);
    string word, transformed_string;
    while (ss >> word) {
        reverse(word.begin(), word.end());  // ใช้ 'reverse' จาก <algorithm>
        if (!transformed_string.empty()) transformed_string += " ";
        transformed_string += word;
    }

    // ขั้นตอนที่ 2: สลับตัวอักษรพิมพ์ใหญ่พิมพ์เล็ก และ ขั้นตอนที่ 3: เปลี่ยนสระ
    for (char& ch : transformed_string) {
        ch = swapCase(ch);       // สลับตัวอักษรพิมพ์ใหญ่และพิมพ์เล็ก
        ch = replaceVowel(ch);   // เปลี่ยนสระ
    }

    // ขั้นตอนที่ 4: ใส่อักขระพิเศษ
    string result;
    int count = 0;
    for (char ch : transformed_string) {
        result += ch;
        count++;
        if (count % 3 == 0 && ch != ' ') {
            result += '#';  // ใส่ '#' หลังจากตัวอักษรที่ 3 ทุกครั้ง
        }
    }

    return result;
}

int main() {
    string input = "Hello World";
    string output = advanced_string_transformation(input);
    cout << "Transformed String: " << output << endl;
    return 0;
}







// อธิบายโค้ด:
// Step 1 - Reverse Words: ใช้ stringstream และ reverse ในการพลิกตัวอักษรภายในแต่ละคำ จากนั้นรวมคำที่พลิกแล้วกลับเข้าไปในสตริง
// Step 2 - Swap Case: ใช้ฟังก์ชัน swapCase() เพื่อสลับ case โดยตรวจสอบว่าตัวอักษรเป็นพิมพ์เล็กหรือพิมพ์ใหญ่ แล้วทำการเปลี่ยน
// Step 3 - Replace Vowels: ใช้พจนานุกรม (unordered_map) สำหรับการแทนที่สระตัวอักษรด้วยตัวถัดไป
// Step 4 - Add Special Characters: ใช้ตัวนับ (count) ในการติดตามจำนวนตัวอักษรที่เพิ่มลงในผลลัพธ์ และเพิ่ม # ทุกครั้งที่เจอตัวอักษรที่ 3