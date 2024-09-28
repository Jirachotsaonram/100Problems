#include <iostream>
using namespace std;

// ฟังก์ชันสำหรับแปลงจากฟาเรนไฮต์เป็นเซลเซียส
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// ฟังก์ชันสำหรับแปลงจากเซลเซียสเป็นฟาเรนไฮต์
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

int main() {
    float fahrenheit, celsius;

    // รับค่าอุณหภูมิจากผู้ใช้และแปลงเป็นเซลเซียส
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;
    celsius = fahrenheit_to_celsius(fahrenheit);
    cout << fahrenheit << " Fahrenheit is equal to " << celsius << " Celsius." << endl;

    // รับค่าอุณหภูมิจากผู้ใช้และแปลงเป็นฟาเรนไฮต์
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    fahrenheit = celsius_to_fahrenheit(celsius);
    cout << celsius << " Celsius is equal to " << fahrenheit << " Fahrenheit." << endl;

    return 0;
}
