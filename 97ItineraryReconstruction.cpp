#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm> // เพิ่ม header นี้สำหรับ reverse

using namespace std;

class Itinerary {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // สร้างกราฟที่เก็บเส้นทางการบิน
        unordered_map<string, multiset<string>> flights;
        
        // จัดเก็บเส้นทางตามลำดับพจนานุกรม
        for (const auto& ticket : tickets) {
            flights[ticket[0]].insert(ticket[1]);
        }
        
        // ผลลัพธ์สุดท้ายของเส้นทางการเดินทาง
        vector<string> itinerary;
        // เริ่มต้น DFS ที่สนามบิน "JFK"
        dfs("JFK", flights, itinerary);
        
        // ผลลัพธ์สุดท้ายจะอยู่ในลำดับย้อนกลับ ดังนั้นต้องกลับลำดับก่อนส่งคืน
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(const string& airport, unordered_map<string, multiset<string>>& flights, vector<string>& itinerary) {
        while (flights[airport].size() > 0) {
            // ดึงสนามบินปลายทางที่เล็กที่สุดออก
            auto next_destination = flights[airport].begin();
            string next_airport = *next_destination;
            flights[airport].erase(next_destination);
            dfs(next_airport, flights, itinerary);
        }
        itinerary.push_back(airport);
    }
};

int main() {
    Itinerary itinerary;
    vector<vector<string>> tickets1 = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<vector<string>> tickets2 = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};

    vector<string> result1 = itinerary.findItinerary(tickets1);
    vector<string> result2 = itinerary.findItinerary(tickets2);
    
    // แสดงผลลัพธ์
    cout << "Itinerary 1: ";
    for (const string& airport : result1) {
        cout << airport << " ";
    }
    cout << endl;

    cout << "Itinerary 2: ";
    for (const string& airport : result2) {
        cout << airport << " ";
    }
    cout << endl;

    return 0;
}


// คำอธิบายของโค้ด:
// สร้างกราฟ: ใช้ unordered_map เพื่อเก็บสนามบินต้นทางเป็นคีย์ และสนามบินปลายทางเป็น multiset เพื่อรักษาลำดับตามพจนานุกรม
// DFS Function: ฟังก์ชัน dfs ใช้สำหรับสำรวจเส้นทางการบิน ถ้าสนามบินต้นทางมีเส้นทางปลายทางอยู่ ให้ดึงสนามบินปลายทางที่เล็กที่สุดออกแล้วเรียก dfs สำหรับสนามบินปลายทางนั้น
// ผลลัพธ์: เมื่อเสร็จสิ้นการสำรวจทุกเส้นทางแล้ว ให้ย้อนกลับลำดับและส่งคืนผลลัพธ์
// วิธีการรัน:
// คอมไพล์โค้ดด้วย C++ compiler (เช่น g++) และรันโปรแกรม
// ผลลัพธ์จะแสดงรายการเส้นทางการเดินทางตามลำดับที่ถูกต้อง