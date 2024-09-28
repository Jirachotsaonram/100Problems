#include <iostream>
using namespace std;

// Function for addition
float add(float a, float b) {
    return a + b;
}

// Function for subtraction
float subtract(float a, float b) {
    return a - b;
}

// Function for multiplication
float multiply(float a, float b) {
    return a * b;
}

// Function for division, with error handling for division by zero
float divide(float a, float b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;  // or return a special value, or throw an exception
    }
    return a / b;
}

int main() {
    float num1, num2;
    char operation;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    float result;
    // Perform operation based on user input
    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            cout << "Invalid operation!" << endl;
            return 1;  // Exit program with error code
    }
    
    // Display the result
    cout << "Result: " << result << endl;

    return 0;
}
