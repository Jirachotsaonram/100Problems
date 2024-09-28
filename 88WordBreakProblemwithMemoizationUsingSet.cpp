#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

bool wordBreakUtil(const string& s, const unordered_set<string>& wordSet, int start, unordered_map<int, bool>& memo) {
    // Base case: ถ้าถึงจุดสุดท้ายของสตริง ให้ return true (สามารถแบ่งได้สำเร็จ)
    if (start == s.length()) {
        return true;
    }

    // ถ้าผลลัพธ์ที่ตำแหน่งนี้ถูกคำนวณไว้แล้ว ให้ return ผลลัพธ์ที่เก็บไว้
    if (memo.find(start) != memo.end()) {
        return memo[start];
    }

    // ลองแบ่งสตริงจาก start ไปยังตำแหน่งต่าง ๆ
    for (int end = start + 1; end <= s.length(); ++end) {
        // ถ้าสตริง s[start:end] อยู่ในชุดคำ และส่วนที่เหลือสามารถแบ่งได้
        if (wordSet.find(s.substr(start, end - start)) != wordSet.end() && wordBreakUtil(s, wordSet, end, memo)) {
            memo[start] = true;  // เก็บผลลัพธ์ใน memoization
            return true;
        }
    }

    // ถ้าไม่สามารถแบ่งสตริงได้ ให้เก็บค่าผลลัพธ์เป็น false
    memo[start] = false;
    return false;
}

bool wordBreak(const string& s, const unordered_set<string>& wordSet) {
    unordered_map<int, bool> memo;  // สร้าง map สำหรับ memoization
    return wordBreakUtil(s, wordSet, 0, memo);
}

int main() {
    string s1 = "leetcode";
    unordered_set<string> wordSet1 = {"leet", "code"};
    cout << (wordBreak(s1, wordSet1) ? "True" : "False") << endl;  // Output: True

    string s2 = "applepenapple";
    unordered_set<string> wordSet2 = {"apple", "pen"};
    cout << (wordBreak(s2, wordSet2) ? "True" : "False") << endl;  // Output: True

    string s3 = "catsandog";
    unordered_set<string> wordSet3 = {"cats", "dog", "sand", "and", "cat"};
    cout << (wordBreak(s3, wordSet3) ? "True" : "False") << endl;  // Output: False

    return 0;
}




// อธิบายการทำงานของโค้ด:
// wordBreakUtil: ฟังก์ชันนี้เป็น recursive ที่รับค่าตำแหน่งเริ่มต้นของสตริงและใช้ memoization ในการเก็บผลลัพธ์ว่าตำแหน่งนั้นสามารถแบ่งออกเป็นคำได้หรือไม่ โดยจะวนลูปจากตำแหน่งเริ่มต้น (start) ไปยังตำแหน่งท้าย (end) เพื่อเช็คว่าส่วนของสตริงจาก start ถึง end มีในชุดคำหรือไม่ ถ้าใช่จะเรียกฟังก์ชันต่อไปเพื่อเช็คส่วนที่เหลือ
// memo: เก็บผลลัพธ์ของการเช็คสตริงในแต่ละตำแหน่ง เช่น ถ้าตรวจสอบจากตำแหน่งที่ 3 แล้วไม่สามารถแบ่งออกได้ ครั้งถัดไปที่เรียกตำแหน่ง 3 จะไม่ต้องตรวจซ้ำ
// wordBreak: ฟังก์ชันหลักที่เรียกฟังก์ชัน recursive และส่งคืนผลลัพธ์ว่าตัวสตริงนั้นสามารถแบ่งออกเป็นคำจากชุดคำได้หรือไม่
// การทำงานของตัวอย่าง:
// "leetcode" กับชุดคำ {"leet", "code"}:
// สตริงถูกแบ่งเป็น "leet" และ "code" ได้ จึงได้ผลลัพธ์เป็น True
// "catsandog" กับชุดคำ {"cats", "dog", "sand", "and", "cat"}:
// สตริงไม่สามารถแบ่งส่วนคำออกได้ทั้งหมด เนื่องจาก "andog" ไม่อยู่ในชุดคำ จึงได้ผลลัพธ์เป็น False
// ความซับซ้อนของเวลา (Time Complexity):
// เวลาที่ใช้จะอยู่ที่ O(n^2) โดย n คือความยาวของสตริง เพราะเราลองทุกความยาวของคำที่เป็นไปได้จากตำแหน่งเริ่มต้น