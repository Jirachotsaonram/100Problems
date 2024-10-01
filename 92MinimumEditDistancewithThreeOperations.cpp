#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // สำหรับ std::min

using namespace std;

// ฟังก์ชันในการคำนวณ minimum edit distance
int min_edit_distance(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();
    
    // สร้างตาราง dp ขนาด (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    // เติมค่าเริ่มต้นในตาราง dp สำหรับกรณีลบหรือแทรกตัวอักษรทั้งหมด
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;  // กรณีลบตัวอักษรใน str1
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;  // กรณีแทรกตัวอักษรใน str2
    }
    
    // เติมค่าตาราง dp ที่เหลือ
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // ถ้าอักษรเหมือนกัน ไม่ต้องทำอะไร
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1,      // ลบ
                                dp[i][j - 1] + 1,      // แทรก
                                dp[i - 1][j - 1] + 1}); // แทนที่
            }
        }
    }
    
    // ค่าที่อยู่ใน dp[m][n] คือคำตอบสุดท้าย
    return dp[m][n];
}

int main() {
    // ตัวอย่างการใช้งาน
    string str1 = "kitten";
    string str2 = "sitting";
    
    int result = min_edit_distance(str1, str2);
    cout << "Minimum Edit Distance between \"" << str1 << "\" and \"" << str2 << "\" is: " << result << endl;

    // ตัวอย่างอื่น
    str1 = "flaw";
    str2 = "lawn";
    result = min_edit_distance(str1, str2);
    cout << "Minimum Edit Distance between \"" << str1 << "\" and \"" << str2 << "\" is: " << result << endl;

    return 0;
}



// คำอธิบายโค้ด:
// Initialization:
// สร้างตาราง dp ขนาด (m+1) x (n+1) ซึ่ง m และ n คือความยาวของสตริงทั้งสอง
// ตั้งค่าเริ่มต้นสำหรับกรณีที่ลบหรือแทรกตัวอักษรจากสตริงที่ต้องการแปลง
// Dynamic Programming Filling:
// วนลูปเพื่อเติมค่าตาราง dp โดยใช้การคำนวณที่เลือกการกระทำที่มีต้นทุนน้อยที่สุดระหว่าง insert, delete, หรือ substitute
// ถ้าตัวอักษรที่ตำแหน่ง i และ j ในสตริงเท่ากัน ค่า dp[i][j] จะเท่ากับ dp[i-1][j-1] ซึ่งหมายความว่าไม่ต้องทำอะไรเพิ่ม
// Return the Result:
// ผลลัพธ์จะอยู่ที่ dp[m][n] ซึ่งแสดงถึงจำนวนครั้งที่น้อยที่สุดในการเปลี่ยนแปลงสตริงแรกให้เป็นสตริงที่สอง
// Output:
// ผลลัพธ์คือจำนวนการแก้ไขที่น้อยที่สุด เช่น 3 สำหรับ "kitten" และ "sitting" หรือ 2 สำหรับ "flaw" และ "lawn"