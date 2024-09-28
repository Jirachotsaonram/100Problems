#include <iostream>
using namespace std;

// ฟังก์ชันการจัดการบัญชีธนาคาร
void bank_account_management() {
    int balance = 0;  // เริ่มต้นยอดเงินในบัญชีที่ 0
    int choice;
    
    do {
        // แสดงเมนูตัวเลือกให้กับผู้ใช้
        cout << "\nMenu:\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit Program\n";
        cout << "Choose an option: ";
        cin >> choice;
        
        if (choice == 1) {
            // ฝากเงิน
            int deposit_amount;
            cout << "Enter amount to deposit: ";
            cin >> deposit_amount;
            
            if (deposit_amount > 0) {
                balance += deposit_amount;
                cout << "Deposit successful. Current balance: " << balance << endl;
            } else {
                cout << "Invalid amount. Deposit failed." << endl;
            }
            
        } else if (choice == 2) {
            // ถอนเงิน
            int withdraw_amount;
            cout << "Enter amount to withdraw: ";
            cin >> withdraw_amount;
            
            if (withdraw_amount > 0 && withdraw_amount <= balance) {
                balance -= withdraw_amount;
                cout << "Withdrawal successful. Current balance: " << balance << endl;
            } else if (withdraw_amount > balance) {
                cout << "Insufficient balance. Withdrawal failed." << endl;
            } else {
                cout << "Invalid amount. Withdrawal failed." << endl;
            }
            
        } else if (choice == 3) {
            // ตรวจสอบยอดเงินคงเหลือ
            cout << "Current balance: " << balance << endl;
            
        } else if (choice == 4) {
            // ออกจากโปรแกรม
            cout << "Exiting program." << endl;
            
        } else {
            // หากผู้ใช้ป้อนตัวเลือกไม่ถูกต้อง
            cout << "Invalid option. Please choose again." << endl;
        }
        
    } while (choice != 4);  // ทำงานซ้ำจนกว่าจะเลือกออกจากโปรแกรม
}

int main() {
    bank_account_management();
    return 0;
}



// คำอธิบายโค้ด:
// ตัวแปร balance: เริ่มต้นด้วยยอดเงินในบัญชีที่ 0
// ฟังก์ชัน bank_account_management(): ใช้สำหรับจัดการเมนูและการทำงานของระบบตามตัวเลือกของผู้ใช้
// ตัวเลือกในการฝากเงิน: ผู้ใช้ป้อนจำนวนเงิน ถ้าจำนวนเงินถูกต้อง (ค่าบวก) จะเพิ่มยอดในบัญชี
// ตัวเลือกในการถอนเงิน: ผู้ใช้ป้อนจำนวนเงิน ถ้าเงินในบัญชีเพียงพอ จะทำการหักยอดจากบัญชี
// ตรวจสอบยอดคงเหลือ: แสดงยอดเงินปัจจุบัน
// ออกจากโปรแกรม: หยุดการทำงาน
// ลูป do-while: เพื่อให้โปรแกรมทำงานซ้ำจนกว่าผู้ใช้จะเลือกออกจากโปรแกรม (เลือกตัวเลือก 4)
// ผลลัพธ์:
// เมื่อรันโปรแกรม ผู้ใช้สามารถเลือกที่จะฝากเงิน ถอนเงิน ตรวจสอบยอดเงิน หรือออกจากโปรแกรม
// ระบบจะตรวจสอบว่าจำนวนเงินที่ป้อนมาเป็นค่าบวก และสำหรับการถอนเงิน ระบบจะตรวจสอบว่ามีเงินเพียงพอ