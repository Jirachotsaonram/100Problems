#include <iostream>
#include <ctime> // ใช้เพื่อเข้าถึงวันที่ปัจจุบัน
using namespace std;

tuple<int, int, int> calculate_age(int day_of_birth, int month_of_birth, int year_of_birth) {
    // ได้วันที่ปัจจุบันจากระบบ
    time_t t = time(0);
    tm* now = localtime(&t);
    
    int current_day = now->tm_mday;
    int current_month = now->tm_mon + 1; // เดือนเริ่มจาก 0 ต้องบวก 1
    int current_year = now->tm_year + 1900; // ปีนับจาก 1900 ต้องบวก 1900

    int years = current_year - year_of_birth;
    int months = current_month - month_of_birth;
    int days = current_day - day_of_birth;

    // ถ้าเดือนเกิดยังไม่ถึงเดือนปัจจุบันต้องลดอายุลง 1 ปี
    if (months < 0) {
        years--;
        months += 12;
    }

    // ถ้าวันเกิดยังไม่ถึงวันปัจจุบัน ต้องลดเดือนลง 1 เดือน
    if (days < 0) {
        months--;
        // จำนวนวันในเดือนก่อนหน้า
        int days_in_prev_month = 30;
        if (current_month == 3) { // กุมภาพันธ์ต้องเช็คปีอธิกสุรทิน
            days_in_prev_month = (current_year % 4 == 0 && (current_year % 100 != 0 || current_year % 400 == 0)) ? 29 : 28;
        } else if (current_month == 5 || current_month == 7 || current_month == 10 || current_month == 12) {
            days_in_prev_month = 30;
        } else {
            days_in_prev_month = 31;
        }
        days += days_in_prev_month;
    }

    return make_tuple(years, months, days);
}

int main() {
    int day_of_birth = 15, month_of_birth = 8, year_of_birth = 1990;

    auto age = calculate_age(day_of_birth, month_of_birth, year_of_birth);

    cout << "Age: " << get<0>(age) << " years, "
         << get<1>(age) << " months, "
         << get<2>(age) << " days." << endl;

    return 0;
}
