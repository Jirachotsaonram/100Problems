#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ฟังก์ชันสำหรับค้นหาคำที่มีความยาวตามที่กำหนด
vector<string> find_words_of_length(const vector<string>& words, int length) {
    vector<string> result;
    for (const string& word : words) {
        if (word.length() == length) {
            result.push_back(word);
        }
    }
    return result;
}

int main() {
    // ลิสต์ของคำ
    vector<string> words = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int length;
    
    // รับความยาวของคำที่ต้องการค้นหา
    cout << "Enter the desired length of words: ";
    cin >> length;

    // เรียกใช้ฟังก์ชันค้นหาคำ
    vector<string> filtered_words = find_words_of_length(words, length);

    // แสดงผลลัพธ์
    cout << "Words with length " << length << ": ";
    for (const string& word : filtered_words) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
