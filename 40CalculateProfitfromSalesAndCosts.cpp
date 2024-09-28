#include <iostream>
#include <tuple>
#include <vector>

// ฟังก์ชันคำนวณกำไรจากยอดขายและต้นทุน
std::tuple<std::tuple<float, float, float, float, float>, float> calculate_profit(
    const std::tuple<float, float, float, float, float>& sales,
    const std::tuple<float, float, float, float, float>& costs) {
    
    // ตัวแปรเก็บกำไรประจำปีและกำไรทั้งหมด
    float profit_year1 = std::get<0>(sales) - std::get<0>(costs);
    float profit_year2 = std::get<1>(sales) - std::get<1>(costs);
    float profit_year3 = std::get<2>(sales) - std::get<2>(costs);
    float profit_year4 = std::get<3>(sales) - std::get<3>(costs);
    float profit_year5 = std::get<4>(sales) - std::get<4>(costs);
    
    // กำไรทั้งหมดคือการรวมกำไรในแต่ละปี
    float total_profit = profit_year1 + profit_year2 + profit_year3 + profit_year4 + profit_year5;

    // คืนค่ากำไรประจำปีและกำไรทั้งหมด
    return std::make_tuple(
        std::make_tuple(profit_year1, profit_year2, profit_year3, profit_year4, profit_year5), 
        total_profit
    );
}

int main() {
    // ข้อมูลยอดขายสำหรับแต่ละปี
    std::tuple<float, float, float, float, float> sales = {10000.0, 15000.0, 20000.0, 25000.0, 30000.0};
    // ข้อมูลต้นทุนสำหรับแต่ละปี
    std::tuple<float, float, float, float, float> costs = {7000.0, 8000.0, 9000.0, 11000.0, 12000.0};

    // เรียกฟังก์ชัน calculate_profit เพื่อคำนวณกำไร
    auto result = calculate_profit(sales, costs);

    // ดึงข้อมูลกำไรประจำปีจากผลลัพธ์
    std::tuple<float, float, float, float, float> annual_profits = std::get<0>(result);
    // ดึงข้อมูลกำไรทั้งหมดจากผลลัพธ์
    float total_profit = std::get<1>(result);

    // แสดงผลกำไรประจำปี
    std::cout << "Annual Profits: ";
    std::cout << std::get<0>(annual_profits) << ", "
              << std::get<1>(annual_profits) << ", "
              << std::get<2>(annual_profits) << ", "
              << std::get<3>(annual_profits) << ", "
              << std::get<4>(annual_profits) << std::endl;

    // แสดงผลกำไรทั้งหมด
    std::cout << "Total Profit: " << total_profit << std::endl;

    return 0;
}
