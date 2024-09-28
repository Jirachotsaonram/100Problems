#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// คลาสที่แทนหนังสือในห้องสมุด
class LibraryBook {
private:
    string title;
    string author;
    int year_published;
    string isbn;
    string status;

public:
    // Constructor พร้อมกับการตรวจสอบข้อมูล
    LibraryBook(const string& title, const string& author, int year_published, const string& isbn)
        : title(validate_non_empty(title, "Title")), author(validate_non_empty(author, "Author")),
          year_published(validate_year(year_published)), isbn(validate_isbn(isbn)), status("available") {}

    // ตรวจสอบสตริงที่ไม่ใช่ค่าว่าง
    static string validate_non_empty(const string& input, const string& field_name) {
        string value = input;
        while (value.empty()) {
            cout << "Invalid " << field_name << ". Please enter a non-empty string: ";
            getline(cin, value);
        }
        return value;
    }

    // ตรวจสอบว่าปีเป็นค่าบวกและไม่เกินปีปัจจุบัน
    static int validate_year(int year) {
        int current_year = 2024; // ปีปัจจุบันที่ใช้เป็นตัวอย่าง
        while (year <= 0 || year > current_year) {
            cout << "Invalid year. Please enter a positive number not greater than the current year: ";
            cin >> year;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ล้าง input buffer
        }
        return year;
    }

    // ตรวจสอบว่าเลข ISBN มีความยาว 10 หรือ 13 หลัก
    static string validate_isbn(const string& isbn) {
        string value = isbn;
        while (value.length() != 10 && value.length() != 13) {
            cout << "Invalid ISBN. Please enter a 10 or 13-digit ISBN: ";
            getline(cin, value);
        }
        return value;
    }

    // เมธอดสำหรับยืมหนังสือ
    void check_out() {
        if (status == "available") {
            status = "checked out";
            cout << "Book checked out: " << title << endl;
        } else {
            cout << "The book is already checked out." << endl;
        }
    }

    // เมธอดสำหรับคืนหนังสือ
    void return_book() {
        if (status == "checked out") {
            status = "available";
            cout << "Book returned: " << title << endl;
        } else {
            cout << "The book is already available." << endl;
        }
    }

    // เมธอดแสดงข้อมูลหนังสือ
    void display_info() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year Published: " << year_published << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << status << endl;
    }

    // เมธอดรับค่า title ของหนังสือ
    string get_title() const {
        return title;
    }
};

// ฟังก์ชันตรวจสอบการเลือกเมนู
int validate_menu_choice() {
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 6) {
        cout << "Invalid choice. Please enter a number between 1 and 6: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ล้าง buffer
    return choice;
}

// ฟังก์ชันป้อนรายละเอียดหนังสือ
LibraryBook input_book() {
    string title, author, isbn;
    int year;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter year published: ";
    cin >> year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter ISBN (10 or 13 digits): ";
    getline(cin, isbn);

    return LibraryBook(title, author, year, isbn);
}

// ฟังก์ชันหลักที่มีเมนูการใช้งาน
int main() {
    vector<LibraryBook> library;
    int choice;

    while (true) {
        cout << "\nMenu:\n"
             << "1. Add a new book\n"
             << "2. Check out a book\n"
             << "3. Return a book\n"
             << "4. Display information about a specific book\n"
             << "5. Display all books in the library\n"
             << "6. Exit\n"
             << "Enter your choice: ";

        choice = validate_menu_choice();

        if (choice == 1) {
            library.push_back(input_book());
        } else if (choice == 2) {
            if (library.empty()) {
                cout << "No books in the library.\n";
            } else {
                string title;
                cout << "Enter the title of the book to check out: ";
                getline(cin, title);
                bool found = false;
                for (LibraryBook& book : library) {
                    if (book.get_title() == title) {
                        book.check_out();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Book not found.\n";
            }
        } else if (choice == 3) {
            if (library.empty()) {
                cout << "No books in the library.\n";
            } else {
                string title;
                cout << "Enter the title of the book to return: ";
                getline(cin, title);
                bool found = false;
                for (LibraryBook& book : library) {
                    if (book.get_title() == title) {
                        book.return_book();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Book not found.\n";
            }
        } else if (choice == 4) {
            if (library.empty()) {
                cout << "No books in the library.\n";
            } else {
                string title;
                cout << "Enter the title of the book to display: ";
                getline(cin, title);
                bool found = false;
                for (const LibraryBook& book : library) {
                    if (book.get_title() == title) {
                        book.display_info();
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Book not found.\n";
            }
        } else if (choice == 5) {
            if (library.empty()) {
                cout << "No books in the library.\n";
            } else {
                for (const LibraryBook& book : library) {
                    book.display_info();
                    cout << "------------------------\n";
                }
            }
        } else if (choice == 6) {
            cout << "Exiting program.\n";
            break;
        }
    }

    return 0;
}






// โค้ดด้านล่างเป็นการสร้างโปรแกรมจัดการหนังสือในห้องสมุด โดยใช้คลาส LibraryBook สำหรับเก็บข้อมูลของหนังสือแต่ละเล่ม พร้อมทั้งมีเมนูเพื่อโต้ตอบกับผู้ใช้ในการเพิ่มข้อมูลหนังสือ ยืมหนังสือ คืนหนังสือ และแสดงข้อมูลหนังสือ ซึ่งรายละเอียดทั้งหมดนี้อธิบายเป็นภาษาไทยได้ดังนี้:

// คุณสมบัติ (Attributes) ของคลาส LibraryBook:
// title (ชื่อหนังสือ): เป็นสตริงที่เก็บชื่อของหนังสือ
// author (ผู้เขียน): เป็นสตริงที่เก็บชื่อผู้แต่งหนังสือ
// year_published (ปีที่ตีพิมพ์): เป็นจำนวนเต็มที่แสดงปีที่หนังสือตีพิมพ์
// isbn (เลข ISBN): เป็นสตริงที่แสดงเลข ISBN ของหนังสือ
// status (สถานะหนังสือ): เป็นสตริงที่แสดงว่าสถานะของหนังสือเป็น "available" (พร้อมให้ยืม) หรือ "checked out" (ถูกยืมแล้ว)
// เมธอด (Methods) ของคลาส LibraryBook:
// Constructor: เมธอดนี้จะถูกเรียกเมื่อมีการสร้างออบเจ็กต์หนังสือใหม่ โดยมันจะทำหน้าที่ตรวจสอบความถูกต้องของข้อมูลที่ใส่เข้ามา เช่น ตรวจสอบชื่อหนังสือ ผู้เขียน ปีที่ตีพิมพ์ และเลข ISBN พร้อมทั้งตั้งสถานะเริ่มต้นของหนังสือเป็น "available" (พร้อมให้ยืม)

// validate_non_empty: ฟังก์ชันตรวจสอบค่าว่าต้องไม่เป็นสตริงว่างเปล่า
// validate_year: ฟังก์ชันตรวจสอบว่าปีที่กรอกต้องเป็นค่าที่ไม่เกินปีปัจจุบัน
// validate_isbn: ฟังก์ชันตรวจสอบว่าเลข ISBN ต้องมีความยาว 10 หรือ 13 หลัก
// check_out: เมธอดนี้ทำหน้าที่เปลี่ยนสถานะของหนังสือเป็น "checked out" หากหนังสือยังมีสถานะ "available" หากหนังสือถูกยืมไปแล้ว จะแสดงข้อความแจ้งเตือนว่าหนังสือนั้นถูกยืมไปแล้ว

// return_book: เมธอดนี้ทำหน้าที่เปลี่ยนสถานะหนังสือกลับมาเป็น "available" หากสถานะปัจจุบันเป็น "checked out" แต่หากหนังสือยังไม่ได้ถูกยืม จะแสดงข้อความแจ้งเตือนว่าหนังสือยังพร้อมให้ยืมอยู่แล้ว

// display_info: เมธอดนี้ใช้สำหรับแสดงข้อมูลของหนังสือ เช่น ชื่อหนังสือ ผู้แต่ง ปีที่ตีพิมพ์ เลข ISBN และสถานะของหนังสือ

// get_title: ใช้สำหรับรับค่าชื่อของหนังสือ เพื่อช่วยในการค้นหาหนังสือจากคลังข้อมูล

// เมนูการใช้งานของโปรแกรม:
// โปรแกรมจะมีเมนูเพื่อให้ผู้ใช้เลือกการกระทำต่าง ๆ ได้แก่:

// เพิ่มหนังสือ: ผู้ใช้สามารถเพิ่มหนังสือใหม่ได้ โดยป้อนชื่อหนังสือ ผู้แต่ง ปีที่ตีพิมพ์ และเลข ISBN จากนั้นข้อมูลจะถูกเก็บในคลังหนังสือ
// ยืมหนังสือ: ผู้ใช้สามารถยืมหนังสือ โดยค้นหาหนังสือจากชื่อ หากหนังสือนั้นพร้อมให้ยืม สถานะจะเปลี่ยนเป็น "checked out"
// คืนหนังสือ: ผู้ใช้สามารถคืนหนังสือได้ โดยค้นหาจากชื่อหนังสือ หากหนังสือถูกยืมอยู่ สถานะจะเปลี่ยนกลับเป็น "available"
// แสดงข้อมูลหนังสือ: สามารถแสดงข้อมูลของหนังสือเฉพาะเล่มตามชื่อที่ผู้ใช้ค้นหา
// แสดงหนังสือทั้งหมด: โปรแกรมจะแสดงข้อมูลของหนังสือทุกเล่มในคลัง
// ออกจากโปรแกรม: ผู้ใช้สามารถเลือกที่จะออกจากโปรแกรมได้