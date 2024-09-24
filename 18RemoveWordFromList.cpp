#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // สำหรับ find

using namespace std;

vector<string> remove_word_from_list(vector<string>& words, const string& word) {
    // ใช้ find เพื่อตรวจสอบว่ามีคำที่ต้องการลบอยู่ในลิสต์หรือไม่
    auto it = find(words.begin(), words.end(), word);
    
    // ถ้าพบคำในลิสต์
    if (it != words.end()) {
        words.erase(it);  // ลบคำที่พบออกจากลิสต์
    }
    
    return words;  // คืนค่าลิสต์ที่แก้ไขแล้ว
}

int main() {
    // อินพุตลิสต์คำ
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    
    string word_to_remove = "cherry";  // คำที่ต้องการลบ
    
    // เรียกใช้ฟังก์ชันเพื่อลบคำ
    vector<string> updated_words = remove_word_from_list(words, word_to_remove);
    
    // แสดงผลลิสต์ที่แก้ไขแล้ว
    cout << "[";
    for (size_t i = 0; i < updated_words.size(); ++i) {
        cout << "\"" << updated_words[i] << "\"";
        if (i < updated_words.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}
