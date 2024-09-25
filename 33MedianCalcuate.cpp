#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// ฟังก์ชันคำนวณมัธยฐานของจำนวนจังหวัด
vector<pair<string, int>> calculate_median(map<string, int>& provinces) {
    vector<int> province_counts;
    vector<pair<string, int>> result;

    // ดึงจำนวนจังหวัดจาก dictionary ใส่ลงใน vector
    for (const auto& entry : provinces) {
        province_counts.push_back(entry.second);
    }

    // จัดเรียงจำนวนจังหวัดจากน้อยไปมาก
    sort(province_counts.begin(), province_counts.end());

    int n = province_counts.size();
    double median;

    // ตรวจสอบว่าจำนวนจังหวัดเป็นเลขคี่หรือเลขคู่
    if (n % 2 == 1) {
        median = province_counts[n / 2];
    } else {
        median = (province_counts[n / 2 - 1] + province_counts[n / 2]) / 2.0;
    }

    // หาประเทศที่มีจำนวนจังหวัดตรงกับค่ามัธยฐาน
    for (const auto& entry : provinces) {
        if (entry.second == static_cast<int>(median)) {
            result.push_back({entry.first, entry.second});
        }
    }

    return result;
}

int main() {
    // ข้อมูลจำนวนจังหวัดในแต่ละประเทศ
    map<string, int> provinces = {
        {"Thailand", 76},
        {"Laos", 17},
        {"Vietnam", 58},
        {"Japan", 47},
        {"China", 23}
    };

    // คำนวณและแสดงผล
    vector<pair<string, int>> result = calculate_median(provinces);

    cout << "Countries with median number of provinces:" << endl;
    for (const auto& entry : result) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
