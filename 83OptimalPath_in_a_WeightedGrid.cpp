#include <iostream>
#include <vector>
#include <algorithm> // สำหรับใช้ฟังก์ชัน min
using namespace std;

// ฟังก์ชันสำหรับหาค่า minimum cost ในการเดินทางใน grid
pair<int, vector<pair<int, int>>> min_cost_path(const vector<vector<int>>& grid) {
    int n = grid.size();    // จำนวนแถว
    int m = grid[0].size(); // จำนวนคอลัมน์

    // สร้างตาราง dp ขนาดเท่ากับ grid
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // กำหนดค่าเริ่มต้นที่มุมซ้ายบน
    dp[0][0] = grid[0][0];

    // เติมค่าในแถวแรก (เราสามารถมาได้จากทางซ้ายเท่านั้น)
    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // เติมค่าในคอลัมน์แรก (เราสามารถมาได้จากด้านบนเท่านั้น)
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // เติมค่าในช่องอื่นๆ
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    // หาค่า minimum cost ในการไปถึงจุดปลายทาง
    int min_cost = dp[n-1][m-1];

    // สร้างวิถีที่ใช้
    vector<pair<int, int>> path;
    int i = n - 1, j = m - 1;

    // ย้อนกลับจากจุดปลายทางไปยังจุดเริ่มต้น
    while (i > 0 || j > 0) {
        path.push_back({i, j});
        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else if (dp[i-1][j] < dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    path.push_back({0, 0});

    // กลับลำดับเส้นทาง (จากจุดเริ่มต้นไปยังจุดปลายทาง)
    reverse(path.begin(), path.end());

    return {min_cost, path};
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    auto result = min_cost_path(grid);
    int min_cost = result.first;
    vector<pair<int, int>> path = result.second;

    cout << "Minimum Cost: " << min_cost << endl;
    cout << "Path: ";
    for (const auto& p : path) {
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;

    return 0;
}




// อธิบายโค้ด:
// ตาราง dp:

// ใช้เก็บค่า "minimum cost" ในการเดินทางไปยังแต่ละจุดใน grid โดยค่าของ dp[i][j] คือ "minimum cost" ในการเดินทางไปยังจุด (i,j)
// การเติมตาราง dp:

// ในแถวแรกและคอลัมน์แรก มีเพียงเส้นทางเดียวเท่านั้นในการมาถึงแต่ละจุด ดังนั้นการคำนวณง่ายมาก
// สำหรับจุดอื่นๆ คำนวณจากค่า min(dp[i-1][j], dp[i][j-1]) ซึ่งเป็นการหาว่าเส้นทางจากด้านบนหรือตรงข้างซ้ายที่ให้ค่า cost ต่ำที่สุด
// การหาเส้นทาง (Path):

// เราจะย้อนกลับจากจุดปลายทาง (n-1, m-1) โดยหาว่าจุดไหนที่มาถึงจุดปัจจุบัน (จากบนหรือจากซ้าย) ที่ให้ค่า cost ต่ำสุด
// ผลลัพธ์:

// คำตอบสุดท้ายคือค่า "minimum cost" ในการเดินทาง และเส้นทางที่ใช้ในรูปแบบลิสต์ของตำแหน่งพิกัดในตาราง