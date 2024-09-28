#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int tsp(int pos, int mask, const vector<vector<int>>& graph, vector<vector<int>>& dp, int n) {
    // ถ้าเราไปเยี่ยมครบทุกเมืองแล้ว กลับไปที่เมืองเริ่มต้น
    if (mask == (1 << n) - 1) {
        return graph[pos][0];  // กลับไปเมืองเริ่มต้น
    }
    
    // ถ้าคำนวณมาก่อนแล้วใน dp ก็ใช้ค่าที่บันทึกไว้
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    
    // ค่าใช้จ่ายต่ำสุดในการเดินทางจากเมือง pos
    int answer = INT_MAX;
    
    // ลองไปทุกเมืองที่ยังไม่ได้เยี่ยม
    for (int city = 0; city < n; city++) {
        // ตรวจสอบว่าเมืองนี้ยังไม่ได้เยี่ยมหรือไม่
        if ((mask & (1 << city)) == 0) {
            // คำนวณค่าใช้จ่ายและอัพเดทผลลัพธ์ที่ต่ำที่สุด
            int newCost = graph[pos][city] + tsp(city, mask | (1 << city), graph, dp, n);
            answer = min(answer, newCost);
        }
    }
    
    // บันทึกค่าใน dp
    return dp[pos][mask] = answer;
}

int solveTSP(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));  // ตาราง DP ที่มีขนาด n x (2^n)
    
    // เริ่มต้นที่เมือง 0 โดยเยี่ยมชมเมือง 0 เป็นที่แรก (mask = 1)
    return tsp(0, 1, graph, dp, n);
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    
    cout << "Enter the graph matrix (distance between cities):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int result = solveTSP(graph);
    
    cout << "The minimum cost to visit all cities is: " << result << endl;
    
    return 0;
}


// คำอธิบายโค้ด:
// รับค่าจากผู้ใช้:
// รับจำนวนเมือง n และกราฟ (matrix) ที่เก็บระยะทางระหว่างแต่ละเมือง
// ใช้ recursive function:
// tsp(pos, mask, graph, dp, n) เป็นฟังก์ชันที่คำนวณค่าใช้จ่ายต่ำสุดในการเยี่ยมชมเมืองจากตำแหน่ง pos โดยดูว่าเมืองไหนถูกเยี่ยมชมแล้วผ่าน mask และบันทึกค่าใช้จ่ายไว้ใน dp
// bitmasking:
// ใช้ bitmask ในการติดตามว่าเมืองไหนถูกเยี่ยมชมแล้ว เพื่อป้องกันการเยี่ยมเมืองเดิมซ้ำ
// ผลลัพธ์:
// ฟังก์ชัน solveTSP จะส่งผลลัพธ์ของค่าใช้จ่ายต่ำสุดในการเดินทางกลับมา