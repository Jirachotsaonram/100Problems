#include <iostream>
#include <vector>
#include <cmath>  // สำหรับใช้ฟังก์ชัน pow()

using namespace std;

// ฟังก์ชันคำนวณการเติบโตของเงินลงทุน
vector<float> calculate_investment_growth(float principal, float annual_rate, int years) {
    vector<float> amounts;  // ลิสต์เก็บจำนวนเงินสะสมในแต่ละปี

    // คำนวณจำนวนเงินสะสมในแต่ละปี
    for (int year = 1; year <= years; ++year) {
        float amount = principal * pow(1 + annual_rate / 100, year);
        amounts.push_back(amount);  // เก็บผลลัพธ์ในลิสต์
    }

    return amounts;  // คืนลิสต์ของจำนวนเงินในแต่ละปี
}

int main() {
    float principal = 1000;      // จำนวนเงินลงทุนตั้งต้น
    float annual_rate = 5;       // อัตราดอกเบี้ยต่อปี (%)
    int years = 5;               // จำนวนปี

    // เรียกฟังก์ชันและรับผลลัพธ์
    vector<float> results = calculate_investment_growth(principal, annual_rate, years);

    // แสดงผลลัพธ์
    cout << "Accumulated amounts for each year: " << endl;
    for (int i = 0; i < results.size(); ++i) {
        cout << "Year " << i + 1 << ": " << results[i] << endl;
    }

    return 0;
}
