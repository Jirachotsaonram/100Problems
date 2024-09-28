#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

// ฟังก์ชันสำหรับหาเวลาในการส่งสัญญาณไปถึงทุกโหนด
int network_delay_time(vector<vector<int>>& times, int N, int K) {
    // สร้างกราฟเป็น adjacency list
    vector<vector<pair<int, int>>> graph(N + 1); // กราฟที่มี N โหนด
    for (auto& t : times) {
        int u = t[0], v = t[1], w = t[2];
        graph[u].push_back({v, w});
    }

    // ใช้ priority_queue เป็น min-heap สำหรับเก็บเวลาและโหนด
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N + 1, INT_MAX); // เก็บค่าเวลาในการเดินทางไปแต่ละโหนด
    dist[K] = 0;
    pq.push({0, K}); // เริ่มที่โหนด K โดยใช้เวลา 0 หน่วย

    // Dijkstra's algorithm
    while (!pq.empty()) {
        auto [time, node] = pq.top();
        pq.pop();
        
        if (time > dist[node]) continue; // ถ้าเวลาปัจจุบันมากกว่าเวลาที่คำนวณไว้แล้วให้ข้าม

        for (auto& neighbor : graph[node]) {
            int next_node = neighbor.first;
            int next_time = time + neighbor.second;
            if (next_time < dist[next_node]) {
                dist[next_node] = next_time;
                pq.push({next_time, next_node});
            }
        }
    }

    // หาเวลาที่นานที่สุดในการไปถึงโหนดทุกโหนด
    int max_time = *max_element(dist.begin() + 1, dist.end());

    return (max_time == INT_MAX) ? -1 : max_time; // ถ้ามีโหนดที่ไม่สามารถเข้าถึงได้ คืนค่า -1
}

int main() {
    // รับค่าจากผู้ใช้
    int N, M, K;
    cout << "Enter the number of nodes (N): ";
    cin >> N;
    cout << "Enter the number of edges (M): ";
    cin >> M;
    cout << "Enter the starting node (K): ";
    cin >> K;

    vector<vector<int>> times(M, vector<int>(3));
    cout << "Enter the edges (u, v, w): " << endl;
    for (int i = 0; i < M; ++i) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    // เรียกใช้ฟังก์ชันและแสดงผลลัพธ์
    int result = network_delay_time(times, N, K);
    if (result == -1) {
        cout << "Not all nodes can receive the signal." << endl;
    } else {
        cout << "The time it takes for the last node to receive the signal is: " << result << " units." << endl;
    }

    return 0;
}




// การอธิบายโค้ด:
// การสร้างกราฟ:
// กราฟสร้างจากข้อมูลที่ผู้ใช้ป้อนเข้ามาโดยใช้ adjacency list ที่เก็บคู่ (โหนดปลายทาง, เวลา)
// Dijkstra's Algorithm:
// ใช้ priority_queue เพื่อเก็บคู่ (เวลา, โหนด) โดยเรียงลำดับจากเวลาที่น้อยที่สุด (min-heap) เพื่อให้สามารถหาค่าเส้นทางที่สั้นที่สุดได้อย่างมีประสิทธิภาพ
// การคำนวณเวลา:
// เมื่อเจอโหนดแล้ว คำนวณเวลาในการเดินทางไปยังโหนดถัดไป และเก็บค่าเวลาที่น้อยที่สุด
// ผลลัพธ์:
// หาค่าเวลาที่นานที่สุด (max time) และเช็คว่ามีโหนดใดที่ไม่สามารถเข้าถึงได้หรือไม่ ถ้ามีคืนค่า -1