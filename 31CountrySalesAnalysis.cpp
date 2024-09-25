#include <iostream>
#include <map>
#include <string>
using namespace std;

// ฟังก์ชันเพื่อหาประเทศที่มียอดขายสูงที่สุด
pair<string, int> highest_sales_country(const map<string, int>& sales) {
    string max_country;
    int max_sales = 0;

    // วนลูปหายอดขายสูงสุด
    for(const auto& entry : sales){
        if(entry.second > max_sales){
            max_sales = entry.second;
            max_country = entry.first;
        }
    }

    // คืนค่าชื่อประเทศที่มียอดขายสูงสุดและยอดขาย
    return make_pair(max_country, max_sales);
}

int main() {
    // ตัวอย่าง input
    map<string, int> sales = {
        {"Thailand", 1500},
        {"Laos", 1200},
        {"Vietnam", 1800},
        {"Japan", 1700},
        {"China", 2000}
    };

    // หาประเทศที่มียอดขายสูงที่สุด
    pair<string, int> result = highest_sales_country(sales);

    // แสดงผลลัพธ์
    cout << "Country with highest sales: " << result.first << endl;
    cout << "Sales amount: " << result.second << endl;

    return 0;
}
