#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <algorithm>  // เพิ่มบรรทัดนี้เพื่อใช้ฟังก์ชัน remove_if

using namespace std;

// ฟังก์ชันเพื่อประเมินผลนิพจน์คณิตศาสตร์
int evaluateExpression(const string& expression, unordered_map<string, int>& variables);

// ฟังก์ชันเพื่อประเมินผลนิพจน์ที่กำหนดตัวแปร
int evaluateAssignment(const string& expression, unordered_map<string, int>& variables);

// ฟังก์ชันเพื่อดำเนินการทางคณิตศาสตร์ (เช่น บวก ลบ คูณ หาร)
int applyOperator(int a, int b, char op);

// ฟังก์ชันเพื่อกำหนดลำดับความสำคัญของตัวดำเนินการ
int precedence(char op);

// ฟังก์ชันหลัก
int evaluateExpression(const string& expression, unordered_map<string, int>& variables) {
    stack<int> values;
    stack<char> ops;
    string token;
    istringstream iss(expression);

    while (iss >> token) {
        // ตรวจสอบว่าค่าเป็นตัวเลขหรือตัวแปร
        if (isdigit(token[0])) {
            values.push(stoi(token));
        } else if (isalpha(token[0])) {
            if (variables.find(token) == variables.end()) {
                throw runtime_error("Undefined variable: " + token);
            }
            values.push(variables[token]);
        } else if (token == "(") {
            ops.push('(');
        } else if (token == ")") {
            while (!ops.empty() && ops.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.pop(); // เอาวงเล็บซ้ายออก
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token[0])) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.push(token[0]);
        }
    }

    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperator(a, b, op));
    }

    return values.top();
}

// ฟังก์ชันเพื่อประเมินผลนิพจน์ที่มีการกำหนดค่าตัวแปร
int evaluateAssignment(const string& expression, unordered_map<string, int>& variables) {
    size_t equalPos = expression.find('=');
    if (equalPos != string::npos) {
        string varName = expression.substr(0, equalPos);
        string expr = expression.substr(equalPos + 1);
        // ใช้ remove_if เพื่อลบช่องว่างออกจากชื่อของตัวแปร
        varName.erase(remove_if(varName.begin(), varName.end(), ::isspace), varName.end());
        int value = evaluateExpression(expr, variables);
        variables[varName] = value;
        return value;
    } else {
        return evaluateExpression(expression, variables);
    }
}

// ฟังก์ชันเพื่อดำเนินการคณิตศาสตร์
int applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        default: throw runtime_error("Invalid operator");
    }
}

// ฟังก์ชันเพื่อกำหนดลำดับความสำคัญของตัวดำเนินการ
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ฟังก์ชันหลักในการทดสอบ
int main() {
    unordered_map<string, int> variables;

    try {
        cout << evaluateAssignment("x = 3 + 5 * (2 - 1)", variables) << endl; // Output: 8
        cout << evaluateAssignment("y = x + 4", variables) << endl;           // Output: 12
        cout << evaluateAssignment("z = (x + y) * 2", variables) << endl;     // Output: 40
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}







// คำอธิบายโค้ด:
// ฟังก์ชัน evaluateExpression:

// ใช้ในการประเมินผลของนิพจน์ทางคณิตศาสตร์โดยการใช้กองซ้อน (stack) สำหรับเก็บค่าและตัวดำเนินการ
// รองรับการใช้ตัวแปรในนิพจน์ และจะคำนวณตามลำดับความสำคัญของตัวดำเนินการ เช่น * และ / ก่อน + และ -
// ฟังก์ชัน evaluateAssignment:

// ใช้สำหรับประเมินนิพจน์ที่มีการกำหนดตัวแปร เช่น x = 3 + 5 และเก็บค่าผลลัพธ์ลงใน variables
// ฟังก์ชัน applyOperator:

// ใช้ในการดำเนินการทางคณิตศาสตร์ เช่น บวก ลบ คูณ หาร และจัดการกับกรณีหารด้วยศูนย์
// ฟังก์ชัน precedence:

// กำหนดลำดับความสำคัญของตัวดำเนินการ เช่น * และ / มีความสำคัญมากกว่า + และ -
// การทำงานของโค้ด:
// โค้ดจะรับนิพจน์ที่เป็น string และทำการคำนวณ โดยใช้กองซ้อนเพื่อจัดการลำดับการคำนวณและลำดับความสำคัญของตัวดำเนินการ
// สามารถจัดการกับการกำหนดตัวแปรและใช้ตัวแปรในนิพจน์ได้