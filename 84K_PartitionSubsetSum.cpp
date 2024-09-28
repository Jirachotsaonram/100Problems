#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ฟังก์ชันสำหรับ backtracking เพื่อเช็คว่า nums สามารถแบ่งเป็น k กลุ่มที่มีผลรวมเท่ากันได้หรือไม่
bool backtrack(vector<int>& nums, vector<int>& subsets, int index, int target) {
    // ถ้าตัวเลขทั้งหมดถูกใช้หมดแล้ว ให้เช็คว่าทุกกลุ่มมีค่าเท่ากับ target หรือไม่
    if (index == nums.size()) {
        for (int subset_sum : subsets) {
            if (subset_sum != target) {
                return false;
            }
        }
        return true;
    }
    
    // พยายามใส่ตัวเลข nums[index] ลงในแต่ละ subset
    for (int i = 0; i < subsets.size(); ++i) {
        if (subsets[i] + nums[index] <= target) {
            subsets[i] += nums[index]; // ใส่ตัวเลขลงไปใน subset
            if (backtrack(nums, subsets, index + 1, target)) {
                return true; // ถ้าพบวิธีที่สำเร็จ return true
            }
            subsets[i] -= nums[index]; // ถ้าไม่สำเร็จ ให้เอาตัวเลขออกแล้วลองใส่ในกลุ่มอื่น
        }
        
        // หาก subset นี้ยังว่าง (sum == 0) และเราได้ลองแล้วว่าการใส่ใน subset นี้ไม่ได้ผล 
        // ไม่ต้องลองต่อไปใน subset ที่ว่างอื่นๆ เนื่องจากจะให้ผลลัพธ์เหมือนกัน
        if (subsets[i] == 0) break;
    }
    
    return false; // ถ้าไม่สามารถใส่ตัวเลขได้ในทุก subset return false
}

bool can_partition_k_subsets(vector<int>& nums, int k) {
    int total_sum = accumulate(nums.begin(), nums.end(), 0); // ผลรวมของ nums
    if (total_sum % k != 0) return false; // ถ้าผลรวมหารด้วย k ไม่ลงตัว ให้ return false
    
    int target = total_sum / k; // ค่าเป้าหมายของแต่ละ subset
    sort(nums.rbegin(), nums.rend()); // เรียงตัวเลขจากมากไปน้อยเพื่อเพิ่มประสิทธิภาพ
    if (nums[0] > target) return false; // ถ้าตัวเลขที่มากที่สุดใน nums เกินกว่าเป้าหมาย ให้ return false
    
    vector<int> subsets(k, 0); // สร้างลิสต์เก็บผลรวมของแต่ละ subset
    return backtrack(nums, subsets, 0, target); // เริ่มต้น backtracking
}

int main() {
    vector<int> nums1 = {4, 3, 2, 3, 5, 2, 1};
    int k1 = 4;
    cout << "Can partition? " << (can_partition_k_subsets(nums1, k1) ? "Yes" : "No") << endl;
    
    vector<int> nums2 = {1, 2, 3, 4};
    int k2 = 3;
    cout << "Can partition? " << (can_partition_k_subsets(nums2, k2) ? "Yes" : "No") << endl;
    
    return 0;
}
// อธิบายโค้ด:
// accumulate และ sort:

// ฟังก์ชัน accumulate ใช้สำหรับหาผลรวมของตัวเลขในลิสต์ nums
// เราเรียงลำดับตัวเลขจากมากไปน้อยเพื่อให้ตัวเลขที่ใหญ่ที่สุดถูกลองใส่ก่อน ซึ่งจะช่วยลดจำนวนการคำนวณใน backtracking
// backtrack function:

// ฟังก์ชัน backtrack ใช้สำหรับการทำ recursive backtracking โดยจะพยายามใส่ตัวเลขแต่ละตัวใน subset ต่างๆ และตรวจสอบว่าผลรวมของแต่ละ subset ตรงตามเป้าหมายหรือไม่
// ถ้าตัวเลขทั้งหมดถูกใช้งานแล้ว (เมื่อ index == nums.size()), ให้เช็คว่าทุก subset มีผลรวมเท่ากับ target หรือไม่ ถ้าใช่ return true
// การหยุด backtracking:

// ถ้าผลรวมของ subset ใดเกิน target หรือหากไม่สามารถจัดกลุ่มได้ return false