#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

// ฟังก์ชันในการคำนวณกำลังสองและสถิติ
tuple<vector<int>, int, int, int, float> calculate_statistics(const vector<int>& nums) {
    vector<int> squared_values;
    
    // คำนวณกำลังสองของแต่ละจำนวน
    for (int num : nums) {
        squared_values.push_back(pow(num, 2));
    }
    
    // ค่ามากที่สุด
    int max_value = *max_element(squared_values.begin(), squared_values.end());
    
    // ค่าน้อยที่สุด
    int min_value = *min_element(squared_values.begin(), squared_values.end());
    
    // ผลรวม
    int sum = accumulate(squared_values.begin(), squared_values.end(), 0);
    
    // ค่าเฉลี่ย
    float average = static_cast<float>(sum) / squared_values.size();
    
    // คืนค่าผลลัพธ์เป็นทูเพิล
    return make_tuple(squared_values, max_value, min_value, sum, average);
}

int main() {
    // ทูเพิลอินพุต
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // เรียกใช้ฟังก์ชันและรับผลลัพธ์
    auto result = calculate_statistics(input);
    
    // แสดงผลลัพธ์
    cout << "Squared Values: ";
    for (int val : get<0>(result)) {
        cout << val << " ";
    }
    cout << "\nMaximum Value: " << get<1>(result) << endl;
    cout << "Minimum Value: " << get<2>(result) << endl;
    cout << "Sum: " << get<3>(result) << endl;
    cout << "Average: " << get<4>(result) << endl;

    return 0;
}
