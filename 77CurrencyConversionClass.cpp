#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>

using namespace std;

class CurrencyConverter {
private:
    float amount;
    string currency;
    unordered_map<string, unordered_map<string, float>> rates;

public:
    CurrencyConverter(float amt, string curr) : amount(amt), currency(curr) {
        // Define conversion rates (hardcoded)
        rates["USD"]["EUR"] = 0.85;
        rates["USD"]["GBP"] = 0.75;
        rates["USD"]["JPY"] = 110;
        rates["USD"]["THB"] = 32;

        rates["EUR"]["USD"] = 1.18;
        rates["EUR"]["GBP"] = 0.88;
        rates["EUR"]["JPY"] = 129.5;
        rates["EUR"]["THB"] = 37.65;

        rates["GBP"]["USD"] = 1.33;
        rates["GBP"]["EUR"] = 1.14;
        rates["GBP"]["JPY"] = 147.3;
        rates["GBP"]["THB"] = 42.68;

        rates["JPY"]["USD"] = 0.0091;
        rates["JPY"]["EUR"] = 0.0077;
        rates["JPY"]["GBP"] = 0.0068;
        rates["JPY"]["THB"] = 0.29;

        rates["THB"]["USD"] = 0.031;
        rates["THB"]["EUR"] = 0.0266;
        rates["THB"]["GBP"] = 0.0234;
        rates["THB"]["JPY"] = 3.44;
    }

    float convert_to(string target_currency) {
        if (rates[currency].find(target_currency) != rates[currency].end()) {
            return amount * rates[currency][target_currency];
        } else {
            return -1;  // Return -1 if the conversion rate is not available
        }
    }

    void display_conversion(string target_currency, float converted_amount) {
        cout << fixed << setprecision(2);  // Set precision to 2 decimal places
        cout << amount << " " << currency << " is equal to " << converted_amount << " " << target_currency << endl;
    }
};

int main() {
    float amount;
    string currency, target_currency;

    // Input the amount of money
    cout << "Enter the amount: ";
    while (!(cin >> amount) || amount <= 0) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Input the currency type
    cout << "Enter the currency (USD, EUR, GBP, JPY, THB): ";
    cin >> currency;

    // Validate the currency input
    while (currency != "USD" && currency != "EUR" && currency != "GBP" && currency != "JPY" && currency != "THB") {
        cout << "Invalid currency. Please enter a valid currency (USD, EUR, GBP, JPY, THB): ";
        cin >> currency;
    }

    // Input the target currency
    cout << "Enter the target currency (USD, EUR, GBP, JPY, THB): ";
    cin >> target_currency;

    // Validate the target currency input
    while (target_currency != "USD" && target_currency != "EUR" && target_currency != "GBP" && target_currency != "JPY" && target_currency != "THB") {
        cout << "Invalid currency. Please enter a valid target currency (USD, EUR, GBP, JPY, THB): ";
        cin >> target_currency;
    }

    // Create an object of CurrencyConverter
    CurrencyConverter converter(amount, currency);

    // Perform the conversion
    float converted_amount = converter.convert_to(target_currency);

    if (converted_amount != -1) {
        // Display the conversion result
        converter.display_conversion(target_currency, converted_amount);
    } else {
        cout << "Conversion rate not available!" << endl;
    }

    return 0;
}




// อธิบายโค้ด:
// คลาส CurrencyConverter:

// มีสอง attribute คือ amount (จำนวนเงิน) และ currency (สกุลเงินปัจจุบัน) และใช้ unordered_map เก็บอัตราแลกเปลี่ยน.
// เมธอด convert_to() ใช้แปลงจำนวนเงินจากสกุลเงินปัจจุบันไปยังสกุลเงินที่ต้องการ.
// เมธอด display_conversion() ใช้แสดงผลลัพธ์การแปลงเงิน.
// เมนูการใช้งาน:

// รับข้อมูลจำนวนเงินและสกุลเงินจากผู้ใช้ พร้อมตรวจสอบข้อมูลว่าถูกต้องหรือไม่.
// เมื่อข้อมูลถูกต้อง จะทำการแปลงสกุลเงินตามที่ผู้ใช้ระบุ และแสดงผลลัพธ์.
// การตรวจสอบข้อมูล:

// ถ้าข้อมูลไม่ถูกต้อง (เช่น จำนวนเงินเป็นลบ หรือสกุลเงินไม่ถูกต้อง) โปรแกรมจะขอให้ผู้ใช้กรอกใหม่.