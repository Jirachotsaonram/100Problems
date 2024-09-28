#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int max_sum_with_one_deletion(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];  // กรณีที่มีแค่ตัวเดียว
    
    vector<int> dp_no_deletion(n), dp_with_deletion(n);
    
    dp_no_deletion[0] = arr[0];
    dp_with_deletion[0] = 0; // ไม่สามารถลบที่ตำแหน่งแรกได้
    
    int max_sum = arr[0];  // เก็บผลรวมสูงสุด
    
    for (int i = 1; i < n; ++i) {
        // กรณีไม่ลบ: ต่อเนื่องจาก subarray ก่อนหน้า หรือเริ่มใหม่ที่ arr[i]
        dp_no_deletion[i] = max(arr[i], dp_no_deletion[i-1] + arr[i]);
        
        // กรณีลบ: อาจลบ arr[i] หรือก่อนหน้าแล้ว (dp_no_deletion[i-1])
        dp_with_deletion[i] = max(dp_no_deletion[i-1], dp_with_deletion[i-1] + arr[i]);
        
        // อัพเดทผลรวมสูงสุด
        max_sum = max({max_sum, dp_no_deletion[i], dp_with_deletion[i]});
    }
    
    return max_sum;
}

int main() {
    // รับค่าจากผู้ใช้
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // เรียกใช้ฟังก์ชันและแสดงผลลัพธ์
    int result = max_sum_with_one_deletion(arr);
    cout << "The maximum subarray sum with one deletion is: " << result << endl;
    
    return 0;
}
