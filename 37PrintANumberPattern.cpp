#include <iostream>
using namespace std;

void print_number_pattern(int n) {
    for (int i = 1; i <= n; i++) {
        // Print leading dashes
        for (int j = 1; j <= n - i; j++) {
            cout << "-";
        }
        // Print numbers in decreasing order
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;

    print_number_pattern(n);

    return 0;
}
