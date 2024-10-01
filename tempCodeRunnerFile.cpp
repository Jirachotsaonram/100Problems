#include <iostream>
#include <string>
#include <map>

using namespace std;

// ฟังก์ชันสำหรับ flatten dictionary
void flatten(const map<string, any>& d, map<string, any>& result, string prefix = "", string separator = ".") {
    for (const auto& kv : d) {
        // สร้างคีย์ใหม่โดยเชื่อมกับ prefix และคีย์เดิม
        string new_key = prefix.empty() ? kv.first : prefix + separator + kv.first;

        // ตรวจสอบว่าค่าเป็น dictionary ซ้ำหรือไม่
        if (kv.second.type() == typeid(map<string, any>)) {
            // ถ้าเป็น dictionary ให้ flatten ต่อไป
            flatten(any_cast<map<string, any>>(kv.second), result, new_key, separator);
        } else {
            // ถ้าไม่ใช่ dictionary ให้นำค่าใส่ลงในผลลัพธ์
            result[new_key] = kv.second;
        }
    }
}

int main() {
    // ตัวอย่างอินพุต 1
    map<string, any> d1 = {
        {"a", 1},
        {"b", map<string, any>{{"c", 2}, {"d", map<string, any>{{"e", 3}, {"f", 4}}}}}
    };

    map<string, any> result1;
    flatten(d1, result1, "", ".");

    // แสดงผลลัพธ์
    cout << "Output 1:" << endl;
    for (const auto& kv : result1) {
        cout << kv.first << ": " << any_cast<int>(kv.second) << endl;
    }

    // ตัวอย่างอินพุต 2
    map<string, any> d2 = {
        {"user", map<string, any>{
            {"name", "Alice"},
            {"address", map<string, any>{{"city", "Wonderland"}, {"zip", "12345"}}},
            {"email", "alice@example.com"}
        }}
    };

    map<string, any> result2;
    flatten(d2, result2, "", "_");

    // แสดงผลลัพธ์
    cout << "\nOutput 2:" << endl;
    for (const auto& kv : result2) {
        cout << kv.first << ": " << any_cast<string>(kv.second) << endl;
    }

    return 0;
}





// คำอธิบายโค้ด:
// ฟังก์ชัน flatten: ฟังก์ชันนี้จะรับ dictionary ที่ซ้อนอยู่และ flatten มันลงไปใน dictionary ผลลัพธ์ โดยใช้ตัวคั่นที่กำหนด
// ถ้าพบว่าค่าเป็น dictionary จะเรียกฟังก์ชัน flatten ซ้ำเพื่อทำการ flatten ต่อ
// ถ้าพบว่าค่าไม่ใช่ dictionary จะนำค่าที่พบใส่ลงใน dictionary ผลลัพธ์ทันที
// การสร้างคีย์ใหม่: ใช้ prefix ที่สร้างจากการรวมคีย์ในแต่ละระดับ และใช้ตัวคั่นในการเชื่อมคีย์เข้าด้วยกัน