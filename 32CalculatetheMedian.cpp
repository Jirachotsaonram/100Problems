#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ฟังก์ชันคำนวณมัธยฐาน
float calculate_median(vector<int>& lst) {
    // จัดเรียงลิสต์จากน้อยไปมาก
    sort(lst.begin(), lst.end());
    
    int n = lst.size();
    
    // ถ้าจำนวนตัวเลขเป็นจำนวนคี่ ให้คืนค่าตัวเลขตรงกลาง
    if (n % 2 == 1) {
        return lst[n / 2];
    }
    // ถ้าจำนวนตัวเลขเป็นจำนวนคู่ ให้คืนค่าเฉลี่ยของสองตัวตรงกลาง
    else {
        return (lst[n / 2 - 1] + lst[n / 2]) / 2.0;
    }
}

int main() {
    // อินพุตข้อมูล
    vector<int> lst = {8, 4, 7, 4, 6, 2, 10, 9, 3, 7, 1};
    
    // คำนวณและแสดงมัธยฐาน
    cout << "Median: " << calculate_median(lst) << endl;
    
    return 0;
}
