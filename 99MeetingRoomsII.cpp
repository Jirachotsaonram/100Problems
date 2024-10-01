#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ฟังก์ชันหาจำนวนห้องประชุมขั้นต่ำที่ต้องใช้
int minMeetingRooms(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }

    // สร้างเวกเตอร์สำหรับเวลาเริ่มต้นและเวลาสิ้นสุด
    vector<int> startTimes, endTimes;
    for (auto& interval : intervals) {
        startTimes.push_back(interval.first);
        endTimes.push_back(interval.second);
    }

    // เรียงลำดับเวลาเริ่มต้นและเวลาสิ้นสุด
    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    int startPointer = 0, endPointer = 0;
    int roomsInUse = 0, maxRooms = 0;

    // เดินทางผ่านเวลาเริ่มต้น
    while (startPointer < intervals.size()) {
        // ถ้าเวลาเริ่มต้นของการประชุมใหม่มากกว่าเวลาสิ้นสุดของการประชุมก่อนหน้า
        if (startTimes[startPointer] < endTimes[endPointer]) {
            roomsInUse++;  // เพิ่มห้องประชุมที่ใช้งาน
            startPointer++;
        } else {
            roomsInUse--;  // ลดห้องประชุมที่ใช้งานเมื่อการประชุมก่อนหน้าเสร็จสิ้น
            endPointer++;
        }

        // เก็บค่าห้องประชุมที่ใช้มากที่สุด
        maxRooms = max(maxRooms, roomsInUse);
    }

    return maxRooms;
}

int main() {
    vector<pair<int, int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    
    cout << "Minimum number of meeting rooms required: " << minMeetingRooms(intervals) << endl;

    return 0;
}


// อธิบายโค้ด:
// การจัดการข้อมูล:

// เรารับ intervals เป็นเวกเตอร์ของคู่ (pair<int, int>) ซึ่งแต่ละคู่เก็บเวลาเริ่มต้นและเวลาสิ้นสุดของการประชุมแต่ละรายการ
// จากนั้นแยกเวลาเริ่มต้น (startTimes) และเวลาสิ้นสุด (endTimes) ออกมาเป็นสองเวกเตอร์ต่างหาก
// เรียงลำดับเวลา:

// เราเรียงลำดับเวลาเริ่มต้นและเวลาสิ้นสุดเพื่อใช้ในการเปรียบเทียบห้องประชุมที่ว่างอยู่และที่ใช้งานอยู่
// การใช้ตัวชี้ (pointer):

// เราใช้สองตัวชี้ (pointer) สำหรับการเดินทางผ่านเวกเตอร์เวลาเริ่มต้นและเวลาสิ้นสุด และคำนวณจำนวนห้องประชุมที่จำเป็นในช่วงเวลานั้น ๆ
// การคำนวณจำนวนห้องประชุม:

// หากการประชุมใหม่เริ่มต้นก่อนที่การประชุมเดิมจะสิ้นสุด เราต้องใช้ห้องประชุมเพิ่ม
// หากการประชุมเดิมสิ้นสุดก่อน เราจะลดจำนวนห้องประชุมที่ใช้ไป
// ผลลัพธ์:

// ค่าที่มากที่สุดของ maxRooms คือจำนวนห้องประชุมที่ต้องใช้มากที่สุดในช่วงเวลาใดเวลาหนึ่ง