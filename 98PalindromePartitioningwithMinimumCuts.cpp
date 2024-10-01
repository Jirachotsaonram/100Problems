#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

// ฟังก์ชันหลักในการคำนวณการตัดขั้นต่ำ
int minCutPalindromePartition(string s) {
    int n = s.length();
    
    // สร้างตารางเพื่อตรวจสอบว่าเป็นพาลินโดรมหรือไม่
    vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
    
    // ตาราง DP เพื่อเก็บจำนวนการตัดขั้นต่ำ
    vector<int> min_cuts(n, 0);
    
    // เตรียมข้อมูลพาลินโดรม
    for (int end = 0; end < n; ++end) {
        min_cuts[end] = end;  // จำนวนตัดสูงสุดที่เป็นไปได้คือ end เอง (ตัดทุกตัวอักษร)
        
        for (int start = 0; start <= end; ++start) {
            if (s[start] == s[end] && (end - start <= 2 || is_palindrome[start + 1][end - 1])) {
                is_palindrome[start][end] = true;
                
                // ถ้าเป็นพาลินโดรม
                if (start == 0) {
                    min_cuts[end] = 0;  // ถ้าทั้งหมดตั้งแต่เริ่มต้นถึง end เป็นพาลินโดรม ไม่ต้องตัด
                } else {
                    // หากไม่ใช่ ให้พิจารณาจำนวนการตัด
                    min_cuts[end] = min(min_cuts[end], min_cuts[start - 1] + 1);
                }
            }
        }
    }
    
    return min_cuts[n - 1];
}

int main() {
    string s;
    cout << "กรุณาใส่สตริง: ";
    cin >> s;

    int result = minCutPalindromePartition(s);
    cout << "จำนวนการตัดขั้นต่ำ: " << result << endl;

    return 0;
}
