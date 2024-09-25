#include <iostream>
#include <set>
#include <tuple>
using namespace std;

// ฟังก์ชันคำนวณ Set Difference
tuple<set<char>, set<char>> calculate_set_differences(const set<char>& set1, const set<char>& set2) {
    set<char> diff1, diff2;

    // คำนวณ set1 - set2 (องค์ประกอบที่อยู่ใน set1 แต่ไม่อยู่ใน set2)
    for (char c : set1) {
        if (set2.find(c) == set2.end()) {
            diff1.insert(c);
        }
    }

    // คำนวณ set2 - set1 (องค์ประกอบที่อยู่ใน set2 แต่ไม่อยู่ใน set1)
    for (char c : set2) {
        if (set1.find(c) == set1.end()) {
            diff2.insert(c);
        }
    }

    // คืนผลลัพธ์เป็น tuple
    return make_tuple(diff1, diff2);
}

int main() {
    // ตัวอย่าง input
    set<char> set1 = {'a', 'b', 'c'};
    set<char> set2 = {'b', 'c', 'd'};

    // คำนวณ Set Difference
    auto result = calculate_set_differences(set1, set2);

    // แสดงผลลัพธ์
    cout << "set1 - set2: ";
    for (char c : get<0>(result)) {
        cout << c << " ";
    }
    cout << endl;

    cout << "set2 - set1: ";
    for (char c : get<1>(result)) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
