#include <iostream>

using namespace std;

// ฟังก์ชันคำนวณค่าใช้จ่ายทั้งหมด
int calculate_total_cost(int fried_eggs, int omelets, int boiled_eggs)
{
    // ราคาของแต่ละเมนู
    int fried_egg_price = 7;
    int omelet_price = 10;
    int boiled_egg_price = 5;

    // คำนวณค่าใช้จ่ายรวม
    int total_cost = (fried_eggs * fried_egg_price) +
                     (omelets * omelet_price) +
                     (boiled_eggs * boiled_egg_price);

    return total_cost;
}

int main()
{
    // จำนวนการสั่งแต่ละเมนู
    int fried_eggs = 2;
    int omelets = 3;
    int boiled_eggs = 1;

    // คำนวณค่าใช้จ่ายรวม
    int total_cost = calculate_total_cost(fried_eggs, omelets, boiled_eggs);

    // แสดงผลลัพธ์
    cout << "Total cost: " << total_cost << " Baht" << endl;

    return 0;
}
