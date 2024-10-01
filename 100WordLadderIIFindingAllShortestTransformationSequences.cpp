#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// ฟังก์ชันช่วยเพื่อเปลี่ยนตัวอักษรหนึ่งตัวในคำ
vector<string> get_neighbors(const string& word, const unordered_set<string>& wordList) {
    vector<string> neighbors;
    string temp = word;
    for (int i = 0; i < word.length(); ++i) {
        char original_char = temp[i];
        for (char c = 'a'; c <= 'z'; ++c) {
            if (c == original_char) continue;
            temp[i] = c;
            if (wordList.find(temp) != wordList.end()) {
                neighbors.push_back(temp);
            }
        }
        temp[i] = original_char;  // กลับไปเป็นตัวอักษรเดิม
    }
    return neighbors;
}

// ฟังก์ชัน Backtracking เพื่อสร้างผลลัพธ์ทั้งหมด
void backtrack(const string& word, const string& begin_word, unordered_map<string, vector<string>>& parents, vector<string>& path, vector<vector<string>>& result) {
    if (word == begin_word) {
        result.push_back(vector<string>(path.rbegin(), path.rend()));  // เพิ่มเส้นทางที่หาได้
        return;
    }
    for (const string& parent : parents[word]) {
        path.push_back(parent);
        backtrack(parent, begin_word, parents, path, result);
        path.pop_back();
    }
}

vector<vector<string>> findLadders(string begin_word, string end_word, vector<string>& word_list) {
    unordered_set<string> wordSet(word_list.begin(), word_list.end());
    vector<vector<string>> result;
    
    if (wordSet.find(end_word) == wordSet.end()) return result;  // ถ้าไม่มี end_word ใน word_list ให้คืนค่าลิสต์ว่าง
    
    unordered_map<string, vector<string>> parents;  // เก็บเส้นทางที่ใช้ใน backtracking
    unordered_set<string> visited;
    unordered_set<string> current_level;
    
    queue<string> q;
    q.push(begin_word);
    current_level.insert(begin_word);
    bool found = false;
    
    while (!q.empty() && !found) {
        int level_size = q.size();
        unordered_set<string> next_level;
        
        while (level_size--) {
            string word = q.front(); q.pop();
            vector<string> neighbors = get_neighbors(word, wordSet);
            
            for (const string& neighbor : neighbors) {
                if (neighbor == end_word) found = true;  // เจอ end_word แล้ว
                if (visited.find(neighbor) == visited.end()) {
                    if (next_level.find(neighbor) == next_level.end()) {
                        next_level.insert(neighbor);
                        q.push(neighbor);
                    }
                    parents[neighbor].push_back(word);  // บันทึกเส้นทางการแปลง
                }
            }
        }
        for (const string& word : next_level) visited.insert(word);
    }
    
    if (found) {
        vector<string> path = {end_word};
        backtrack(end_word, begin_word, parents, path, result);  // เริ่มทำ backtracking เพื่อหาทุกเส้นทาง
    }
    
    return result;
}

int main() {
    string begin_word = "hit";
    string end_word = "cog";
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    vector<vector<string>> result = findLadders(begin_word, end_word, word_list);
    
    // แสดงผลลัพธ์
    if (result.empty()) {
        cout << "No transformation sequence found." << endl;
    } else {
        for (const auto& path : result) {
            for (const auto& word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}


// อธิบายโค้ด:
// ฟังก์ชัน get_neighbors:

// ใช้สำหรับค้นหาคำที่แตกต่างจากคำปัจจุบันเพียงหนึ่งตัวอักษรและอยู่ใน word_list
// ฟังก์ชัน backtrack:

// ใช้ในการสร้างผลลัพธ์โดยย้อนกลับจาก end_word ไปยัง begin_word โดยใช้ข้อมูลใน parents ซึ่งบันทึกไว้ว่าแต่ละคำมาจากคำใด
// ฟังก์ชันหลัก findLadders:

// ทำ BFS เพื่อหาเส้นทางที่สั้นที่สุดจาก begin_word ไปยัง end_word
// หากหาเจอ จะใช้ฟังก์ชัน backtrack เพื่อหาทุกเส้นทางที่เป็นไปได้
// ผลลัพธ์:

// โปรแกรมจะแสดงเส้นทางการแปลงที่สั้นที่สุดทั้งหมด ถ้าไม่มีเส้นทางที่เป็นไปได้ จะคืนค่าลิสต์ว่าง