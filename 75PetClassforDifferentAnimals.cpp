#include <iostream>
#include <string>
#include <limits>  // ใช้สำหรับ numeric_limits
using namespace std;

// คลาสสำหรับสัตว์เลี้ยง
class Pet {
private:
    string species;  // ชนิดของสัตว์เลี้ยง (Dog, Cat, Bird)
    string breed;    // สายพันธุ์ของสัตว์เลี้ยง
    string color;    // สีของสัตว์เลี้ยง
    string name;     // ชื่อของสัตว์เลี้ยง
    float height;    // ความสูงของสัตว์เลี้ยง (เซนติเมตร)
    float weight;    // น้ำหนักของสัตว์เลี้ยง (กิโลกรัม)

public:
    // คอนสตรัคเตอร์สำหรับการกำหนดค่าคุณสมบัติเบื้องต้นของสัตว์เลี้ยง
    Pet(string species, string breed, string color, string name, float height, float weight) {
        this->species = species;
        this->breed = breed;
        this->color = color;
        this->name = name;
        this->height = height;
        this->weight = weight;
    }

    // ฟังก์ชันสำหรับแสดงข้อมูลของสัตว์เลี้ยง
    void display_info() {
        cout << "\nPet Information:\n";
        cout << "Species: " << species << endl;
        cout << "Breed: " << breed << endl;
        cout << "Color: " << color << endl;
        cout << "Name: " << name << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

// ฟังก์ชันสำหรับรับข้อมูลที่ไม่ใช่ค่าว่าง
string get_non_empty_input(string prompt) {
    string input;
    do {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) {
            cout << "Input cannot be empty. Please try again.\n";
        }
    } while (input.empty());
    return input;
}

// ฟังก์ชันสำหรับรับค่าเลขบวก
float get_positive_float(string prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear(); // ล้างสถานะความผิดพลาดของการป้อนข้อมูล
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ละเว้นอินพุตที่เหลือ
            cout << "Invalid input. Please enter a positive number.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ละเว้น newline
            return value;
        }
    }
}

int main() {
    string species, breed, color, name;
    float height, weight;
    int choice;

    // แสดงเมนูให้ผู้ใช้เลือกประเภทของสัตว์เลี้ยง
    cout << "Select the type of pet you want to store information about:\n";
    cout << "1. Dog\n";
    cout << "2. Cat\n";
    cout << "3. Bird\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ละเว้น newline หลังจากป้อนตัวเลือก

    switch (choice) {
        case 1:
            species = "Dog";
            break;
        case 2:
            species = "Cat";
            break;
        case 3:
            species = "Bird";
            break;
        default:
            cout << "Invalid choice. Exiting the program.\n";
            return 1;
    }

    // รับข้อมูลอื่น ๆ ของสัตว์เลี้ยง
    breed = get_non_empty_input("Enter breed: ");
    color = get_non_empty_input("Enter color: ");
    name = get_non_empty_input("Enter name: ");
    height = get_positive_float("Enter height in cm: ");
    weight = get_positive_float("Enter weight in kg: ");

    // สร้างอินสแตนซ์ของสัตว์เลี้ยงและแสดงข้อมูล
    Pet pet(species, breed, color, name, height, weight);
    pet.display_info();

    return 0;
}
