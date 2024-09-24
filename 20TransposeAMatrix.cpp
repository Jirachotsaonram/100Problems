#include <iostream>
#include <vector>
using namespace std;

// ฟังก์ชันสำหรับการ transpose ของเมทริกซ์
vector<vector<int>> transpose_matrix(const vector<vector<int>>& matrix) {
    // ตรวจสอบขนาดของแถวและคอลัมน์
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // สร้างเมทริกซ์ใหม่ที่มีขนาดสลับแถวและคอลัมน์
    vector<vector<int>> transposed_matrix(cols, vector<int>(rows));

    // ทำการสลับตำแหน่งจาก (i, j) เป็น (j, i)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }
    return transposed_matrix;
}

int main() {
    // ตัวอย่างอินพุตจากโจทย์
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // เรียกใช้ฟังก์ชันเพื่อทำการ transpose
    vector<vector<int>> result = transpose_matrix(matrix);

    // แสดงผลลัพธ์เมทริกซ์ที่ทำการ transpose แล้ว
    cout << "Transposed Matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}