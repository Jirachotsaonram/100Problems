#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sum_matrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    
    // สร้างเมทริกซ์ผลลัพธ์ที่มีขนาดเดียวกันกับเมทริกซ์ที่นำเข้ามา
    vector<vector<int>> result(rows, vector<int>(cols));
    
    // คำนวณผลรวมของเมทริกซ์ที่ตำแหน่งเดียวกัน
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    return result;  // คืนค่าเมทริกซ์ผลลัพธ์
}

int main() {
    // อินพุตเมทริกซ์
    vector<vector<int>> matrix1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    vector<vector<int>> matrix2 = {
        {4, 3, 2, 1},
        {4, 3, 2, 1},
        {4, 3, 2, 1}
    };
    
    // เรียกใช้ฟังก์ชันเพื่อคำนวณผลรวม
    vector<vector<int>> result = sum_matrices(matrix1, matrix2);
    
    // แสดงผลลัพธ์
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
