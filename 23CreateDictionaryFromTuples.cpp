#include <iostream>
#include <tuple>
#include <map>
#include <string>
using namespace std;

// ฟังก์ชันสำหรับสร้างแผนที่ (map) จากสองทูเพิล
map<int, string> create_dictionary(const tuple<int, int, int, int>& tuple1, const tuple<string, string, string, string>& tuple2) {
    map<int, string> result;
    
    // ใส่ค่าเข้าไปในแผนที่ (map) จากทูเพิลทั้งสอง
    result[get<0>(tuple1)] = get<0>(tuple2);
    result[get<1>(tuple1)] = get<1>(tuple2);
    result[get<2>(tuple1)] = get<2>(tuple2);
    result[get<3>(tuple1)] = get<3>(tuple2);
    
    return result;
}

int main() {
    // ตัวอย่างทูเพิล tuple1 และ tuple2
    tuple<int, int, int, int> tuple1 = make_tuple(1, 2, 3, 4);
    tuple<string, string, string, string> tuple2 = make_tuple("ant", "cat", "dog", "cow");

    // สร้างแผนที่จากทูเพิล
    map<int, string> result = create_dictionary(tuple1, tuple2);

    // แสดงผลลัพธ์
    for (const auto& pair : result) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
