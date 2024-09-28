#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// ฟังก์ชันสำหรับ backtracking เพื่อเช็คว่า nums สามารถแบ่งเป็น k กลุ่มที่มีผลรวมเท่ากันได้หรือไม่
bool backtrack(vector<int>& nums, vector<int>& subsets, int index, int target) {
    if (index == nums.size()) {
        for (int subset_sum : subsets) {
            if (subset_sum != target) {
                return false;
            }
        }
        return true;
    }
    
    for (int i = 0; i < subsets.size(); ++i) {
        if (subsets[i] + nums[index] <= target) {
            subsets[i] += nums[index];
            if (backtrack(nums, subsets, index + 1, target)) {
                return true;
            }
            subsets[i] -= nums[index];
        }
        if (subsets[i] == 0) break;
    }
    
    return false;
}

bool can_partition_k_subsets(vector<int>& nums, int k) {
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    if (total_sum % k != 0) return false;
    
    int target = total_sum / k;
    sort(nums.rbegin(), nums.rend());
    if (nums[0] > target) return false;
    
    vector<int> subsets(k, 0);
    return backtrack(nums, subsets, 0, target);
}

int main() {
    int n, k;
    
    // รับจำนวนตัวเลขและจำนวนกลุ่มจากผู้ใช้
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    
    // รับค่าตัวเลขในลิสต์จากผู้ใช้
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    // รับค่า k จากผู้ใช้
    cout << "Enter the number of subsets (k): ";
    cin >> k;
    
    // เรียกฟังก์ชันตรวจสอบการแบ่งกลุ่ม
    if (can_partition_k_subsets(nums, k)) {
        cout << "Can partition into " << k << " subsets with equal sum." << endl;
    } else {
        cout << "Cannot partition into " << k << " subsets with equal sum." << endl;
    }
    
    return 0;
}
