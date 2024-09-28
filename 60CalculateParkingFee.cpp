#include <iostream>
using namespace std;

int calculate_parking_fee(int hours, int minutes) {
    // First hour is free
    if (hours == 0 && minutes == 0) {
        return 0;
    }
    
    // Subtract the first free hour
    int total_hours = (hours > 0) ? hours - 1 : 0;

    // If there are minutes, count them as a full hour
    if (minutes > 0) {
        total_hours++;
    }

    // Each additional hour costs 50 Baht
    return total_hours * 50;
}

int main() {
    int hours, minutes;
    cout << "Enter hours: ";
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;

    int fee = calculate_parking_fee(hours, minutes);
    cout << "Parking fee: " << fee << " Baht" << endl;

    return 0;
}
