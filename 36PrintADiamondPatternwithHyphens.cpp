#include <iostream>
using namespace std;

void print_diamond_pattern(int n) {
    // Print the top half of the pattern (including the middle)
    for (int i = 0; i < n; i++) {
        // Print leading asterisks on the left
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        // Print dashes in the middle
        for (int j = 0; j < 2 * i; j++) {
            cout << "-";
        }
        // Print trailing asterisks on the right
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Print the bottom half of the pattern
    for (int i = n - 2; i >= 0; i--) {
        // Print leading asterisks on the left
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        // Print dashes in the middle
        for (int j = 0; j < 2 * i; j++) {
            cout << "-";
        }
        // Print trailing asterisks on the right
        for (int j = 0; j < n - i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows (half of the diamond's height): ";
    cin >> n;

    print_diamond_pattern(n);

    return 0;
}
