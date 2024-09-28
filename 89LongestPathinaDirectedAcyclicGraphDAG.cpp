#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

// ฟังก์ชันสำหรับทำ Topological Sorting
void topologicalSortUtil(int node, unordered_map<int, vector<pair<int, int>>>& graph, vector<bool>& visited, stack<int>& Stack) {
    visited[node] = true;
    
    // เดินผ่านขอบทุกเส้นที่ออกจาก node
    for (auto& neighbor : graph[node]) {
        int nextNode = neighbor.first;
        if (!visited[nextNode]) {
            topologicalSortUtil(nextNode, graph, visited, Stack);
        }
    }
    
    // ดัน node เข้าไปใน stack หลังจากประมวลผลเสร็จ
    Stack.push(node);
}

vector<int> topologicalSort(unordered_map<int, vector<pair<int, int>>>& graph, int n) {
    vector<bool> visited(n, false);
    stack<int> Stack;
    
    // ทำ Topological Sort โดยเยี่ยมชมทุก node
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, graph, visited, Stack);
        }
    }
    
    // สร้างลำดับ topological จาก stack
    vector<int> topoOrder;
    while (!Stack.empty()) {
        topoOrder.push_back(Stack.top());
        Stack.pop();
    }
    
    return topoOrder;
}

int longest_path_dag(unordered_map<int, vector<pair<int, int>>>& graph, int start_node, int n) {
    vector<int> topoOrder = topologicalSort(graph, n);
    vector<int> dist(n, INT_MIN);  // ใช้ INT_MIN เพื่อแทนระยะทางที่ยังไม่รู้
    
    // ระยะทางจาก start_node ไปยังตัวมันเองคือ 0
    dist[start_node] = 0;
    
    // เดินตามลำดับของ Topological Order
    for (int node : topoOrder) {
        if (dist[node] != INT_MIN) {
            // อัพเดตระยะทางของ successors
            for (auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                if (dist[nextNode] < dist[node] + weight) {
                    dist[nextNode] = dist[node] + weight;
                }
            }
        }
    }
    
    // หาค่าระยะทางที่ยาวที่สุดจากตาราง dist
    int maxDist = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (dist[i] != INT_MIN) {
            maxDist = max(maxDist, dist[i]);
        }
    }
    
    return maxDist;
}

int main() {
    // ตัวอย่างที่ 1
    unordered_map<int, vector<pair<int, int>>> graph1 = {
        {1, {{2, 3}, {3, 6}}},
        {2, {{3, 4}, {4, 11}}},
        {3, {{4, 8}}},
        {4, {}}
    };
    int start_node1 = 1;
    cout << "Longest path length (Example 1): " << longest_path_dag(graph1, start_node1, 5) << endl;  // Output: 15
    
    // ตัวอย่างที่ 2
    unordered_map<int, vector<pair<int, int>>> graph2 = {
        {0, {{1, 5}, {2, 3}}},
        {1, {{3, 6}}},
        {2, {{3, 7}}},
        {3, {{4, 4}}},
        {4, {}}
    };
    int start_node2 = 0;
    cout << "Longest path length (Example 2): " << longest_path_dag(graph2, start_node2, 5) << endl;  // Output: 15

    return 0;
}



// อธิบายการทำงานของโค้ด:
// topologicalSortUtil: ฟังก์ชันนี้ใช้ในการทำ Topological Sorting แบบ Depth-First Search (DFS) โดยหลังจากเยี่ยมชม successors ทั้งหมดของ node แล้วจะนำ node นั้นไปเก็บใน stack
// topologicalSort: ฟังก์ชันนี้ทำการวนลูปเพื่อเยี่ยมชมทุก node โดยใช้ topologicalSortUtil และจะได้ลำดับ topological กลับมาในรูปแบบของ vector
// longest_path_dag:
// ใช้ลำดับ topological ในการประมวลผลเส้นทางที่ยาวที่สุด โดยการเดินทางตามลำดับจาก node ต้นไปยัง successors ของมัน
// มีการเก็บระยะทางที่ยาวที่สุดจาก start_node ไปยัง node อื่น ๆ ในตาราง dist
// ฟังก์ชันจะ return ระยะทางที่ยาวที่สุดที่คำนวณได้
// ตัวอย่างการทำงาน:
// ตัวอย่างที่ 1:
// กราฟ: {1 -> 2 (3), 1 -> 3 (6), 2 -> 3 (4), 2 -> 4 (11), 3 -> 4 (8)}
// เส้นทางที่ยาวที่สุด: 1 -> 2 -> 3 -> 4 โดยมีน้ำหนักรวม = 15
// ตัวอย่างที่ 2:
// กราฟ: {0 -> 1 (5), 0 -> 2 (3), 1 -> 3 (6), 2 -> 3 (7), 3 -> 4 (4)}
// เส้นทางที่ยาวที่สุด: 0 -> 2 -> 3 -> 4 โดยมีน้ำหนักรวม = 15
// ความซับซ้อนของเวลา (Time Complexity):
// การทำ Topological Sorting ใช้เวลา O(V + E) (V = จำนวน node, E = จำนวน edge)
// การคำนวณเส้นทางที่ยาวที่สุดก็ใช้เวลา O(V + E) เช่นกัน