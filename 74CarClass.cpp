#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;  // ยี่ห้อของรถ
    string model;  // รุ่นของรถ
    int year;      // ปีที่ผลิต
    string color;  // สีของรถ

public:
    // Constructor สำหรับกำหนดค่าเริ่มต้นให้กับยี่ห้อ รุ่น ปี และสีของรถ
    Car(string car_brand, string car_model, int car_year, string car_color)
        : brand(car_brand), model(car_model), year(car_year), color(car_color) {}

    // ฟังก์ชันสำหรับแสดงรายละเอียดของรถ
    void display_details() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Color: " << color << endl;
    }
};

// ฟังก์ชันสำหรับแสดงเมนู
void display_menu() {
    cout << "\nMenu Options:\n";
    cout << "1. Create a new car\n";
    cout << "2. Display car details\n";
    cout << "3. Exit\n";
}

int main() {
    Car* car = nullptr;  // ตัวชี้ไปยังวัตถุ Car (เริ่มต้นเป็น nullptr)
    int choice;
    string brand, model, color;
    int year;

    do {
        display_menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // สร้างรถใหม่
                cout << "Enter car brand: ";
                cin.ignore();  // ลบ newline ที่เหลือจากการกรอกตัวเลข
                getline(cin, brand);
                cout << "Enter car model: ";
                getline(cin, model);
                cout << "Enter year of manufacture: ";
                cin >> year;
                cout << "Enter car color: ";
                cin.ignore();  // ลบ newline ที่เหลือ
                getline(cin, color);

                // สร้างวัตถุ Car ใหม่
                car = new Car(brand, model, year, color);
                cout << "Car created successfully!\n";
                break;

            case 2:  // แสดงรายละเอียดของรถ
                if (car != nullptr) {
                    car->display_details();
                } else {
                    cout << "No car information available. Please create a car first.\n";
                }
                break;

            case 3:  // ออกจากโปรแกรม
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    // ลบข้อมูลรถถ้ามี
    if (car != nullptr) {
        delete car;
    }

    return 0;
}
