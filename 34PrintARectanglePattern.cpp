#include <iostream>
using namespace std;

void print_rectangle_pattern(int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "*";
        }
        cout << endl;  // Move to the next line after each row
    }
}

int main() {
    int rows, columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
    
    print_rectangle_pattern(rows, columns);
    
    return 0;
}
