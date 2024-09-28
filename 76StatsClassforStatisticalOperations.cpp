#include <iostream>
#include <vector>
#include <limits>
#include <numeric>    // สำหรับ accumulate (ผลรวมของรายการ)
#include <algorithm>  // สำหรับ min_element และ max_element

using namespace std;

class Stats {
private:
    vector<float> data;  // เก็บค่าข้อมูลตัวเลขเป็น float หรือ int

public:
    // คอนสตรัคเตอร์รับค่า vector ของตัวเลข
    Stats(vector<float> data) {
        // ตรวจสอบว่าในข้อมูลมีแต่ตัวเลข (integer หรือ float) หรือไม่
        for (float num : data) {
            if (!cin) {
                throw invalid_argument("Data contains non-numeric values");
            }
        }
        // ถ้าข้อมูลเป็นตัวเลขทั้งหมด ให้เก็บค่าในตัวแปร
        this->data = data;
    }

    // เมธอดคำนวณผลรวมของข้อมูล
    float sum() {
        if (data.empty()) return 0;  // ถ้าข้อมูลเป็นลิสต์ว่าง ให้คืนค่า 0
        return accumulate(data.begin(), data.end(), 0.0f);  // ใช้ accumulate สำหรับหาผลรวม
    }

    // เมธอดคำนวณค่าเฉลี่ยของข้อมูล
    float mean() {
        if (data.empty()) return 0;  // ถ้าข้อมูลเป็นลิสต์ว่าง ให้คืนค่า 0
        return sum() / data.size();
    }

    // เมธอดหาค่าต่ำสุดของข้อมูล
    float min() {
        if (data.empty()) return numeric_limits<float>::quiet_NaN();  // ถ้าข้อมูลเป็นลิสต์ว่าง คืน NaN (ไม่ใช่เลข)
        return *min_element(data.begin(), data.end());  // ใช้ min_element หาค่าต่ำสุด
    }

    // เมธอดหาค่ามากสุดของข้อมูล
    float max() {
        if (data.empty()) return numeric_limits<float>::quiet_NaN();  // ถ้าข้อมูลเป็นลิสต์ว่าง คืน NaN (ไม่ใช่เลข)
        return *max_element(data.begin(), data.end());  // ใช้ max_element หาค่ามากสุด
    }
};

int main() {
    vector<float> data = {10, 20, 30, 40, 50};

    // สร้างอินสแตนซ์ของ Stats และคำนวณข้อมูลที่รับมา
    try {
        Stats stats(data);

        cout << "Sum: " << stats.sum() << endl;
        cout << "Mean: " << stats.mean() << endl;
        cout << "Min: " << stats.min() << endl;
        cout << "Max: " << stats.max() << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    return 0;
}



// อธิบายโค้ด:
// การสร้างคลาส Stats:
// คลาสนี้มี attribute ชื่อ data เป็น vector ที่เก็บค่า float (สามารถเก็บ int ได้เช่นกัน) โดยคอนสตรัคเตอร์จะตรวจสอบว่าใน list ที่ป้อนไม่มีค่านอกเหนือจากตัวเลข
// ฟังก์ชัน sum():
// ใช้ฟังก์ชัน accumulate เพื่อนำค่าทุกค่ามาบวกกัน ถ้าลิสต์ว่างจะคืนค่าเป็น 0
// ฟังก์ชัน mean():
// ใช้ผลรวมจากฟังก์ชัน sum() แล้วหารด้วยจำนวนข้อมูลทั้งหมด
// ฟังก์ชัน min() และ max():
// ใช้ฟังก์ชัน min_element และ max_element ในการหาค่าต่ำสุดและสูงสุดของข้อมูล