#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Person {
private:
    string name;  // เก็บชื่อของบุคคล
    int age;      // เก็บอายุของบุคคล

public:
    // Constructor สำหรับเริ่มต้นค่า name และ age
    Person(string name, int age) {
        set_name(name);  // เรียกใช้ฟังก์ชันตั้งค่าชื่อ
        set_age(age);    // เรียกใช้ฟังก์ชันตั้งค่าอายุ
    }

    // ฟังก์ชันเพื่อคืนค่าชื่อของบุคคล
    string get_name() const {
        return name;
    }

    // ฟังก์ชันเพื่อคืนค่าอายุของบุคคล
    int get_age() const {
        return age;
    }

    // ฟังก์ชันเพื่อกำหนดชื่อใหม่ให้กับบุคคล
    void set_name(const string& new_name) {
        if (!new_name.empty()) {
            name = new_name;
        } else {
            throw invalid_argument("Name must be a non-empty string.");
        }
    }

    // ฟังก์ชันเพื่อกำหนดอายุใหม่ให้กับบุคคล
    void set_age(int new_age) {
        if (new_age >= 0) {
            age = new_age;
        } else {
            throw invalid_argument("Age must be a non-negative integer.");
        }
    }
};

int main() {
    try {
        // สร้างอินสแตนซ์ของคลาส Person
        Person person("Alice", 30);

        // แสดงชื่อและอายุปัจจุบัน
        cout << "Name: " << person.get_name() << endl;   // Output: Alice
        cout << "Age: " << person.get_age() << endl;     // Output: 30

        // อัปเดตชื่อและอายุ
        person.set_name("Bob");
        person.set_age(35);

        // แสดงข้อมูลที่อัปเดต
        cout << "Updated Name: " << person.get_name() << endl;   // Output: Bob
        cout << "Updated Age: " << person.get_age() << endl;     // Output: 35
    }
    catch (const invalid_argument& e) {
        // จัดการข้อผิดพลาดถ้าค่าที่ป้อนไม่ถูกต้อง
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}



// คำอธิบายโค้ด:
// คลาส Person:

// ประกอบด้วยสองข้อมูลหลัก คือ name (ชื่อ) และ age (อายุ) ซึ่งถูกเก็บเป็นตัวแปร private
// ใช้คอนสตรัคเตอร์ (Person(string, int)) สำหรับตั้งค่าชื่อและอายุ เมื่อมีการสร้างอินสแตนซ์ใหม่
// ฟังก์ชัน get_name() และ get_age():

// ฟังก์ชันเหล่านี้ทำหน้าที่คืนค่าชื่อและอายุของบุคคล
// ฟังก์ชัน set_name() และ set_age():

// ฟังก์ชันเหล่านี้ใช้ในการตรวจสอบข้อมูลก่อนที่จะกำหนดค่าชื่อและอายุ
// ถ้าชื่อเป็นสายอักขระว่างเปล่า หรืออายุเป็นค่าติดลบ จะทำการขว้างข้อผิดพลาด (throw invalid_argument)
// try-catch block:

// ใช้เพื่อจัดการข้อผิดพลาดที่เกิดจากการตั้งค่าข้อมูลที่ไม่ถูกต้อง