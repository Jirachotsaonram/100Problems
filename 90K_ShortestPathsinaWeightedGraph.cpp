#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// โครงสร้างข้อมูลสำหรับเก็บเส้นทางที่สั้นที่สุด
struct Path {
    int total_weight;
    vector<int> nodes;

    // การเปรียบเทียบเส้นทางตาม total_weight เพื่อใช้ใน priority_queue
    bool operator>(const Path &other) const {
        return total_weight > other.total_weight;
    }
};

// Dijkstra's Algorithm
Path dijkstra(const map<int, vector<pair<int, int>>> &graph, int start_node, int end_node) {
    priority_queue<Path, vector<Path>, greater<Path>> pq;
    map<int, int> dist;  // เก็บระยะทางที่สั้นที่สุดของแต่ละโหนด
    map<int, vector<int>> paths;  // เก็บเส้นทางของแต่ละโหนด

    pq.push({0, {start_node}});
    dist[start_node] = 0;

    while (!pq.empty()) {
        Path current = pq.top();
        pq.pop();
        int node = current.nodes.back();

        // ถ้าเจอ end_node ให้ return เส้นทางที่สั้นที่สุด
        if (node == end_node) {
            return current;
        }

        for (auto neighbor : graph.at(node)) {
            int next_node = neighbor.first;
            int weight = neighbor.second;
            int new_dist = current.total_weight + weight;

            // อัพเดตระยะทางและเส้นทางหากพบเส้นทางที่สั้นกว่า
            if (dist.find(next_node) == dist.end() || new_dist < dist[next_node]) {
                dist[next_node] = new_dist;
                Path new_path = current;
                new_path.total_weight = new_dist;
                new_path.nodes.push_back(next_node);
                pq.push(new_path);
            }
        }
    }

    return {INT_MAX, {}};  // ถ้าไม่มีเส้นทางให้ return ค่า infinity
}

// Yen's K-Shortest Paths Algorithm
vector<vector<int>> k_shortest_paths(const map<int, vector<pair<int, int>>> &graph, int start_node, int end_node, int k) {
    vector<Path> paths;  // เก็บ k-shortest paths
    vector<Path> potential_paths;  // เก็บเส้นทางที่เป็นไปได้แต่ละรอบ

    // หาเส้นทางที่สั้นที่สุดเส้นแรกด้วย Dijkstra's Algorithm
    Path shortest_path = dijkstra(graph, start_node, end_node);
    if (shortest_path.nodes.empty()) {
        return {};  // ถ้าไม่มีเส้นทางให้ return ค่าว่าง
    }

    paths.push_back(shortest_path);

    // วนลูปหาเส้นทางที่สองถึง k โดยใช้ Yen's Algorithm
    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < paths[i-1].nodes.size() - 1; ++j) {
            int spur_node = paths[i-1].nodes[j];
            vector<int> root_path(paths[i-1].nodes.begin(), paths[i-1].nodes.begin() + j + 1);

            // สร้างกราฟชั่วคราวโดยการลบเส้นทางบางส่วนออก
            map<int, vector<pair<int, int>>> temp_graph = graph;
            for (const auto &p : paths) {
                if (vector<int>(p.nodes.begin(), p.nodes.begin() + j + 1) == root_path && p.nodes.size() > j) {
                    auto &neighbors = temp_graph[p.nodes[j]];
                    neighbors.erase(remove_if(neighbors.begin(), neighbors.end(),
                                              [&](const pair<int, int> &edge) {
                                                  return edge.first == p.nodes[j + 1];
                                              }), neighbors.end());
                }
            }

            // หา spur path จาก spur_node ไปยัง end_node
            Path spur_path = dijkstra(temp_graph, spur_node, end_node);
            if (!spur_path.nodes.empty()) {
                // รวม root path และ spur path
                vector<int> total_path = root_path;
                total_path.insert(total_path.end(), spur_path.nodes.begin() + 1, spur_path.nodes.end());

                // คำนวณน้ำหนักของ total_path
                int total_weight = 0;
                for (int idx = 0; idx < total_path.size() - 1; ++idx) {
                    for (const auto &neighbor : graph.at(total_path[idx])) {
                        if (neighbor.first == total_path[idx + 1]) {
                            total_weight += neighbor.second;
                            break;
                        }
                    }
                }

                potential_paths.push_back({total_weight, total_path});
            }
        }

        // ถ้าไม่มี potential paths ให้หยุด
        if (potential_paths.empty()) {
            break;
        }

        // เพิ่มเส้นทางที่สั้นที่สุดจาก potential paths ไปยัง paths
        sort(potential_paths.begin(), potential_paths.end(), greater<Path>());
        paths.push_back(potential_paths.back());
        potential_paths.pop_back();
    }

    // แปลง paths ให้เป็นรูปแบบ list of list of nodes
    vector<vector<int>> result;
    for (const auto &p : paths) {
        result.push_back(p.nodes);
    }

    return result;
}

int main() {
    // ตัวอย่างที่ 1
    map<int, vector<pair<int, int>>> graph1 = {
        {1, {{2, 1}, {3, 5}}},
        {2, {{3, 1}, {4, 2}}},
        {3, {{4, 1}}},
        {4, {}}
    };
    int start_node1 = 1, end_node1 = 4, k1 = 2;
    vector<vector<int>> result1 = k_shortest_paths(graph1, start_node1, end_node1, k1);

    for (const auto &path : result1) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    // ตัวอย่างที่ 2
    map<int, vector<pair<int, int>>> graph2 = {
        {0, {{1, 2}, {2, 4}}},
        {1, {{2, 1}, {3, 7}}},
        {2, {{3, 3}}},
        {3, {}}
    };
    int start_node2 = 0, end_node2 = 3, k2 = 3;
    vector<vector<int>> result2 = k_shortest_paths(graph2, start_node2, end_node2, k2);

    for (const auto &path : result2) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}




// อธิบายโค้ด C++:
// โครงสร้าง Path: ใช้สำหรับเก็บเส้นทางและน้ำหนักรวมของเส้นทางนั้นๆ และใช้ operator > เพื่อเปรียบเทียบเส้นทางตามน้ำหนัก
// ฟังก์ชัน dijkstra: ใช้อัลกอริทึม Dijkstra's Algorithm เพื่อหาเส้นทางที่สั้นที่สุดจาก start_node ไปยัง end_node
// ฟังก์ชัน k_shortest_paths: ใช้ Yen's Algorithm เพื่อหา k เส้นทางที่สั้นที่สุด โดยเริ่มจากการหาเส้นทางแรก และใช้การปรับแต่งเส้นทางเพื่อหาเส้นทางที่สองและเส้นทางถัดไป
// การทำงานของ main(): แสดงตัวอย่างการใช้ฟังก์ชัน k_shortest_paths ในการหาเส้นทางที่สั้นที่สุดในกราฟ