#include <iostream>

// ฟังก์ชันคำนวณจำนวนเพลงที่สามารถฟังได้ภายในเวลาที่กำหนด
int calculate_number_of_songs(float hours, float avg_song_length = 3.5) {
    // แปลงจำนวนชั่วโมงทั้งหมดเป็นนาที
    float total_minutes = hours * 60;
    
    // คำนวณจำนวนเพลงทั้งหมดที่สามารถฟังได้
    int num_songs = static_cast<int>(total_minutes / avg_song_length);
    
    return num_songs;
}

int main() {
    // ตัวอย่างข้อมูลเข้า
    float hours = 2.0; // จำนวนชั่วโมงที่ต้องการฟังเพลง
    float avg_song_length = 4.0; // ความยาวเฉลี่ยของเพลง (หน่วย: นาที)

    // เรียกฟังก์ชันและแสดงผลลัพธ์
    int result = calculate_number_of_songs(hours, avg_song_length);
    std::cout << result << std::endl; // จะแสดงผล 30

    return 0;
}
