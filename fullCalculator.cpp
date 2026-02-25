#include <iostream>
using namespace std;

int main() {
    double a, b, result;
    char op;

    cout << "=== Simple Calculator ===" << endl;
    cout << "Enter: number operator number" << endl;
    cout << "Example: 5 + 3" << endl << endl;

    cout << "Input: ";
    cin >> a >> op >> b;

    switch(op) {
        case '+':
            result = a + b;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = a - b;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = a * b;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if(b == 0) {
                cout << "Error: Zero diye bhag hoy na!" << endl;
            } else {
                result = a / b;
                cout << "Result: " << result << endl;
            }
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
    }

    return 0;
}

