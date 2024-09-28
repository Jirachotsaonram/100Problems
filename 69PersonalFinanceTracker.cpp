#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Entry {
    float amount;
    string description;
};

vector<Entry> income_entries;
vector<Entry> expense_entries;

// ฟังก์ชันสำหรับเพิ่มรายรับ
void add_income(float amount, string description) {
    if (amount > 0 && !description.empty()) {
        income_entries.push_back({amount, description});
        cout << "Income entry added: " << description << " - " << amount << endl;
    } else {
        cout << "Invalid income entry." << endl;
    }
}

// ฟังก์ชันสำหรับเพิ่มรายจ่าย
void add_expense(float amount, string description) {
    if (amount > 0 && !description.empty()) {
        expense_entries.push_back({amount, description});
        cout << "Expense entry added: " << description << " - " << amount << endl;
    } else {
        cout << "Invalid expense entry." << endl;
    }
}

// ฟังก์ชันสำหรับแสดงรายรับทั้งหมด
void display_income_entries() {
    cout << "\nIncome Entries:" << endl;
    for (const auto& entry : income_entries) {
        cout << entry.description << ": " << entry.amount << endl;
    }
}

// ฟังก์ชันสำหรับแสดงรายจ่ายทั้งหมด
void display_expense_entries() {
    cout << "\nExpense Entries:" << endl;
    for (const auto& entry : expense_entries) {
        cout << entry.description << ": " << entry.amount << endl;
    }
}

// ฟังก์ชันสำหรับคำนวณยอดคงเหลือ
float calculate_balance() {
    float total_income = 0, total_expense = 0;

    for (const auto& entry : income_entries) {
        total_income += entry.amount;
    }

    for (const auto& entry : expense_entries) {
        total_expense += entry.amount;
    }

    return total_income - total_expense;
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. Display Income Entries\n";
        cout << "4. Display Expense Entries\n";
        cout << "5. Calculate Balance\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            float amount;
            string description;
            cout << "Enter income amount: ";
            cin >> amount;
            cin.ignore();
            cout << "Enter income description: ";
            getline(cin, description);
            add_income(amount, description);
        } else if (choice == 2) {
            float amount;
            string description;
            cout << "Enter expense amount: ";
            cin >> amount;
            cin.ignore();
            cout << "Enter expense description: ";
            getline(cin, description);
            add_expense(amount, description);
        } else if (choice == 3) {
            display_income_entries();
        } else if (choice == 4) {
            display_expense_entries();
        } else if (choice == 5) {
            float balance = calculate_balance();
            cout << "\nCurrent balance: " << balance << endl;
        } else if (choice == 6) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid option, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}



// คำอธิบายโค้ด:
// โครงสร้าง Entry:

// ใช้เพื่อเก็บข้อมูลรายรับและรายจ่าย ประกอบด้วยจำนวนเงิน (amount) และคำอธิบาย (description)
// ตัวแปร income_entries และ expense_entries:

// เก็บข้อมูลรายการรายรับและรายจ่ายทั้งหมดในรูปแบบ vector ของโครงสร้าง Entry
// ฟังก์ชัน add_income():

// ใช้สำหรับเพิ่มรายการรายรับ โดยรับจำนวนเงินและคำอธิบายเป็นพารามิเตอร์ ถ้าจำนวนเงินเป็นบวกและคำอธิบายไม่เป็นค่าว่าง จะเพิ่มรายการลงใน income_entries
// ฟังก์ชัน add_expense():

// ใช้สำหรับเพิ่มรายการรายจ่ายโดยกระบวนการคล้ายกับการเพิ่มรายรับ
// ฟังก์ชัน display_income_entries() และ display_expense_entries():

// ใช้แสดงรายการรายรับและรายจ่ายทั้งหมดจากรายการที่เก็บไว้
// ฟังก์ชัน calculate_balance():

// คำนวณยอดคงเหลือโดยการนำรายรับทั้งหมดมาหักลบกับรายจ่ายทั้งหมด แล้วคืนค่าเป็นยอดคงเหลือ
// ฟังก์ชัน main():

// ทำหน้าที่แสดงเมนูให้ผู้ใช้เลือกว่าจะทำอะไร โดยวนลูปจนกว่าผู้ใช้จะเลือกออกจากโปรแกรม
// ผลลัพธ์:
// เมื่อรันโปรแกรม ผู้ใช้จะสามารถเลือกที่จะ:

// เพิ่มรายรับ
// เพิ่มรายจ่าย
// แสดงรายการรายรับทั้งหมด
// แสดงรายการรายจ่ายทั้งหมด
// คำนวณยอดคงเหลือ
// ออกจากโปรแกรม