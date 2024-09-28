#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string name;   // ชื่อหนังสือ
    string status; // สถานะหนังสือ (available, checked out)

public:
    // Constructor สำหรับกำหนดค่าเริ่มต้นให้กับชื่อและสถานะของหนังสือ
    Book(string book_name, string book_status) : name(book_name), status(book_status) {}

    // ฟังก์ชันสำหรับแสดงข้อมูลหนังสือในรูปแบบข้อความ
    string to_string() const {
        return "Book Name: " + name + ", Status: " + status;
    }

    // ฟังก์ชันสำหรับการอัปเดตสถานะของหนังสือ
    void set_status(string new_status) {
        status = new_status;
    }

    // ฟังก์ชันสำหรับรับชื่อหนังสือ
    string get_name() const {
        return name;
    }

    // ฟังก์ชันสำหรับรับสถานะหนังสือ
    string get_status() const {
        return status;
    }
};

// ฟังก์ชันสำหรับแสดงเมนู
void display_menu() {
    cout << "\nMenu Options:\n";
    cout << "1. Create a new book\n";
    cout << "2. Display book information\n";
    cout << "3. Update book status\n";
    cout << "4. Exit\n";
}

int main() {
    Book* book = nullptr;  // ตัวชี้ไปยังวัตถุหนังสือ (เริ่มต้นเป็น nullptr)
    int choice;
    string name, status;

    do {
        display_menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // สร้างหนังสือใหม่
                cout << "Enter book name: ";
                cin.ignore();  // ลบ newline ที่เหลือจากการกรอกตัวเลข
                getline(cin, name);
                cout << "Enter book status (e.g., 'available' or 'checked out'): ";
                getline(cin, status);
                book = new Book(name, status);  // สร้างหนังสือใหม่
                cout << "Book created successfully!\n";
                break;

            case 2:  // แสดงข้อมูลหนังสือ
                if (book != nullptr) {
                    cout << book->to_string() << endl;
                } else {
                    cout << "No book information available. Please create a book first.\n";
                }
                break;

            case 3:  // อัปเดตสถานะหนังสือ
                if (book != nullptr) {
                    cout << "Enter new status: ";
                    cin.ignore();  // ลบ newline ที่เหลือ
                    getline(cin, status);
                    book->set_status(status);  // อัปเดตสถานะหนังสือ
                    cout << "Book status updated successfully!\n";
                } else {
                    cout << "No book to update. Please create a book first.\n";
                }
                break;

            case 4:  // ออกจากโปรแกรม
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    // ลบข้อมูลหนังสือถ้ามี
    if (book != nullptr) {
        delete book;
    }

    return 0;
}



// คำอธิบายโค้ด:
// คลาส Book:

// ประกอบด้วยตัวแปร name และ status สำหรับเก็บชื่อและสถานะของหนังสือ
// ฟังก์ชัน to_string() ใช้สำหรับแสดงข้อมูลหนังสือในรูปแบบข้อความ เช่น Book Name: [name], Status: [status]
// ฟังก์ชัน set_status() ใช้ในการอัปเดตสถานะของหนังสือ
// เมนูในโปรแกรม:

// เมนูจะมีตัวเลือก 4 แบบ:
// สร้างหนังสือใหม่: รับข้อมูลชื่อและสถานะของหนังสือจากผู้ใช้
// แสดงข้อมูลหนังสือ: แสดงชื่อและสถานะของหนังสือ
// อัปเดตสถานะหนังสือ: เปลี่ยนสถานะของหนังสือตามที่ผู้ใช้ป้อน
// ออกจากโปรแกรม
// การจัดการเมนู:

// ใช้ลูป do-while เพื่อแสดงเมนูซ้ำจนกว่าผู้ใช้จะเลือกออกจากโปรแกรม
// ตัวเลือก 1-3 จะทำงานตามเงื่อนไขของแต่ละตัวเลือก หากผู้ใช้เลือกตัวเลือกอื่น ๆ จะได้รับข้อความแจ้งว่าการเลือกไม่ถูกต้อง