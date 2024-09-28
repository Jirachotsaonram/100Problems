#include <iostream>
#include <vector>
#include <algorithm> // สำหรับการจัดเรียงผลลัพธ์
using namespace std;

// ฟังก์ชันสำหรับสร้าง Permutation ด้วยการเรียกซ้ำ
void permute(string s, int l, int r, vector<string>& result) {
    // ถ้าเราถึงปลายทางของการจัดเรียงแล้ว
    if (l == r) {
        result.push_back(s); // เพิ่มสตริงที่จัดเรียงใหม่ลงในรายการ
    } else {
        // เรียงตัวอักษรจากตำแหน่ง 'l' ไปยัง 'r'
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);  // สลับตัวอักษร
            permute(s, l + 1, r, result); // เรียกตัวเองเพื่อหาการจัดเรียงของสตริงที่เหลือ
            swap(s[l], s[i]);  // สลับกลับเพื่อให้สตริงกลับมาเป็นเหมือนเดิม
        }
    }
}

// ฟังก์ชันหลักสำหรับการหาการจัดเรียงทั้งหมด
vector<string> find_permutations(string s) {
    vector<string> result;
    permute(s, 0, s.size() - 1, result); // เริ่มการจัดเรียงจากตำแหน่งที่ 0 จนถึงสุดท้าย
    sort(result.begin(), result.end());  // จัดเรียงผลลัพธ์ตามลำดับตัวอักษร
    return result;
}

int main() {
    string input = "abc";
    vector<string> permutations = find_permutations(input);
    
    // แสดงผลการจัดเรียง
    cout << "Permutations of " << input << " are:\n";
    for (const string& perm : permutations) {
        cout << perm << endl;
    }

    return 0;
}



// อธิบายโค้ด:
// ฟังก์ชัน permute:

// ฟังก์ชันนี้เป็นการทำงานแบบ Recursion ซึ่งเราจะสลับตัวอักษรจากตำแหน่งซ้าย (l) ไปยังตำแหน่งขวา (r) และหาการจัดเรียงใหม่ในทุกๆ การสลับ
// ถ้าเราถึงตำแหน่งสุดท้าย (เมื่อ l == r) เราจะเพิ่มการจัดเรียงนั้นลงในผลลัพธ์ (result)
// ฟังก์ชัน find_permutations:

// ฟังก์ชันนี้เป็นฟังก์ชันหลักที่จะเรียก permute โดยส่งสตริงเข้าไปหาการจัดเรียงทั้งหมด จากนั้นจัดเรียงผลลัพธ์ตามลำดับตัวอักษร (lexicographical order) ด้วย sort.
// การสลับตัวอักษร (swap):

// เราสลับตัวอักษรจากตำแหน่ง l ไปยังตำแหน่ง i เพื่อสร้างการจัดเรียงใหม่ จากนั้นทำการสลับกลับเมื่อฟังก์ชันย่อยเสร็จสิ้น (เพื่อให้สามารถใช้สตริงเดิมในการสร้างการจัดเรียงอื่นได้)