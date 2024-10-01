#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

// ฟังก์ชันช่วยในการจัดกลุ่มอนาแกรม
vector<vector<string>> group_anagrams(vector<string>& words) {
    unordered_map<string, vector<string>> anagram_map;
    
    // วนลูปผ่านแต่ละคำและจัดกลุ่มอนาแกรม
    for (const string& word : words) {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end()); // เรียงลำดับตัวอักษรในคำ
        anagram_map[sorted_word].push_back(word);     // ใส่คำในกลุ่มที่เหมือนกัน
    }
    
    // สร้างผลลัพธ์ที่เป็นลิสต์ของกลุ่มอนาแกรม
    vector<vector<string>> result;
    for (auto& entry : anagram_map) {
        result.push_back(entry.second);
    }
    
    return result;
}

// ฟังก์ชันในการจัดกลุ่มตามความยาวของอนาแกรม
map<int, vector<vector<string>>> group_by_length(vector<string>& words) {
    map<int, vector<vector<string>>> length_groups;
    vector<vector<string>> anagrams = group_anagrams(words);

    // แยกอนาแกรมตามความยาวของคำ
    for (const vector<string>& group : anagrams) {
        int len = group[0].size();
        length_groups[len].push_back(group);
    }

    return length_groups;
}

int main() {
    // ตัวอย่างการใช้งาน
    vector<string> words1 = {"bat", "tab", "cat", "act", "tac", "rat", "tar", "art", "star", "rats"};
    vector<string> words2 = {"listen", "silent", "enlist", "inlets", "google", "gogole", "elgoog", "cat", "tac", "act"};
    
    // Grouping by length for first example
    auto grouped1 = group_by_length(words1);
    cout << "Output for Example 1:\n";
    for (auto& entry : grouped1) {
        cout << entry.first << ": [";
        for (const auto& group : entry.second) {
            cout << "[";
            for (const auto& word : group) {
                cout << word << " ";
            }
            cout << "] ";
        }
        cout << "]\n";
    }

    // Grouping by length for second example
    auto grouped2 = group_by_length(words2);
    cout << "\nOutput for Example 2:\n";
    for (auto& entry : grouped2) {
        cout << entry.first << ": [";
        for (const auto& group : entry.second) {
            cout << "[";
            for (const auto& word : group) {
                cout << word << " ";
            }
            cout << "] ";
        }
        cout << "]\n";
    }

    return 0;
}


// คำอธิบายโค้ด:
// ฟังก์ชัน group_anagrams: ใช้ unordered_map ในการเก็บกลุ่มอนาแกรม โดยคีย์คือสตริงที่เรียงลำดับตัวอักษรแล้ว และค่าเป็นลิสต์ของคำที่เป็นอนาแกรมกัน
// ฟังก์ชัน group_by_length: ใช้ map ในการเก็บกลุ่มของอนาแกรมที่มีความยาวเท่ากัน โดยคีย์ของ map คือความยาวของคำ และค่าคือกลุ่มของอนาแกรม
// การเรียงลำดับอนาแกรม: เมื่อได้กลุ่มอนาแกรมแล้ว เราจะจัดกลุ่มอนาแกรมตามความยาวคำ และแสดงผลออกมา