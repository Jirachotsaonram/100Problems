#include <iostream>
#include <cmath>  // สำหรับใช้ M_PI ในการคำนวณค่า Pi
using namespace std;

class Circle {
private:
    float radius;  // รัศมีของวงกลม

public:
    // Constructor สำหรับตั้งค่ารัศมี
    Circle(float r) {
        if (r > 0) {
            radius = r;
        } else {
            throw invalid_argument("Radius must be a positive number.");
        }
    }

    // ฟังก์ชันสำหรับคำนวณพื้นที่วงกลม
    float area() const {
        return M_PI * radius * radius;  // พื้นที่ = πr²
    }

    // ฟังก์ชันสำหรับคำนวณเส้นรอบวงของวงกลม
    float circumference() const {
        return 2 * M_PI * radius;  // เส้นรอบวง = 2πr
    }

    // ฟังก์ชันสำหรับคืนค่ารัศมี
    float get_radius() const {
        return radius;
    }
};

int main() {
    try {
        // สร้างอินสแตนซ์ของคลาส Circle โดยกำหนดรัศมี
        Circle circle(5.0);

        // แสดงผลพื้นที่และเส้นรอบวงของวงกลม
        cout << "Radius: " << circle.get_radius() << endl;
        cout << "Area: " << circle.area() << endl;  // พื้นที่วงกลม
        cout << "Circumference: " << circle.circumference() << endl;  // เส้นรอบวง
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}





// คำอธิบายโค้ด:
// คลาส Circle:

// คลาสนี้ประกอบด้วยตัวแปร radius เพื่อเก็บค่ารัศมีของวงกลม
// มีฟังก์ชันที่ใช้ในการคำนวณพื้นที่ (area()) และเส้นรอบวง (circumference()) ของวงกลม
// คอนสตรัคเตอร์ Circle(float r):

// ใช้ในการกำหนดค่ารัศมีเมื่อสร้างวงกลม โดยตรวจสอบให้แน่ใจว่ารัศมีเป็นค่าบวก หากรัศมีเป็นค่าลบจะขว้างข้อผิดพลาด (invalid_argument)
// ฟังก์ชัน area():

// ใช้สูตร 
// พื้นที่
// =
// 𝜋
// 𝑟
// 2
// พื้นที่=πr 
// 2
//   เพื่อคำนวณพื้นที่ของวงกลม
// ฟังก์ชัน circumference():

// ใช้สูตร 
// เส้นรอบวง
// =
// 2
// 𝜋
// 𝑟
// เส้นรอบวง=2πr เพื่อคำนวณเส้นรอบวงของวงกลม
// การใช้ M_PI:

// M_PI เป็นค่าคงที่ที่นิยามใน <cmath> เพื่อแทนค่าของ 
// 𝜋
// π ซึ่งมีค่าเท่ากับ 3.14159...
// การจัดการข้อผิดพลาด:

// ใช้ try-catch ในการตรวจจับข้อผิดพลาดหากรัศมีไม่เป็นค่าบวก
// ผลลัพธ์ตัวอย่าง:
// เมื่อรันโปรแกรมจะได้ผลลัพธ์ดังนี้:

// makefile
// คัดลอกโค้ด
// Radius: 5
// Area: 78.5398
// Circumference: 31.4159
// หมายเหตุ:
// โปรแกรมนี้จะใช้ค่า 
// 𝜋
// π จาก cmath ซึ่งมีความแม่นยำสูง