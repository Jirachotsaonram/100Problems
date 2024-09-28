#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;

// ฟังก์ชันที่จะแปลง string เป็นโครงสร้าง tm
tm string_to_tm(const string& date) {
    tm t = {};
    stringstream ss(date);
    ss >> get_time(&t, "%Y-%m-%d");
    return t;
}

// ฟังก์ชันที่คำนวณจำนวนวันระหว่างสองวันที่
int days_between_dates(const string& date1, const string& date2) {
    tm tm1 = string_to_tm(date1);
    tm tm2 = string_to_tm(date2);
    
    // แปลงวันที่ให้เป็นวินาทีตั้งแต่ยุค (epoch time)
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    // คำนวณความแตกต่างของวัน (ระยะเวลาในวินาที ÷ จำนวนวินาทีต่อวัน)
    double difference = difftime(time2, time1) / (60 * 60 * 24);

    // ส่งคืนค่า absolute (บวก) เพื่อให้ได้จำนวนวันที่บวกไม่ว่าเรียงวันที่อย่างไร
    return abs(difference);
}

int main() {
    string date1, date2;
    cout << "Enter the first date (YYYY-MM-DD): ";
    cin >> date1;
    cout << "Enter the second date (YYYY-MM-DD): ";
    cin >> date2;

    int days = days_between_dates(date1, date2);
    cout << "Number of days between " << date1 << " and " << date2 << ": " << days << " days" << endl;

    return 0;
}
