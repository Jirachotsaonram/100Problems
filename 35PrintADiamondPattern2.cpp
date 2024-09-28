#include <iostream>
using namespace std;

void print_diamond_pattern(int n) {
    // Print the top half of the pattern (including the middle)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // Print the bottom half of the pattern
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows for the widest part of the diamond: ";
    cin >> n;

    print_diamond_pattern(n);

    return 0;
}
