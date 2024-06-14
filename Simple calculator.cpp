#include <iostream>

using namespace std;

int main() {
    char op;
    float num1, num2;

    cout << "Simple Calculator\n";
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    switch(op) {
        case '+':
            cout << "Result: " << num1 + num2;
            break;
        case '-':
            cout << "Result: " << num1 - num2;
            break;
        case '*':
            cout << "Result: " << num1 * num2;
            break;
        case '/':
            if(num2 != 0)
                cout << "Result: " << num1 / num2;
            else
                cout << "Error! Division by zero.";
            break;
        default:
            cout << "Error! Invalid operator.";
    }

    return 0;
}