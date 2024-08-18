#include<iostream>

using namespace std;

int main() {
    int num1, num2;
    char operation;

    cout << "Simple Calculator Application" << endl;
    
    cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nChoose an operation: ";
    cin >> operation;
    
    cout << "Enter the First Number: ";
    cin >> num1;
    cout << "Enter the Second Number: ";
    cin >> num2;

    switch (operation) {
        case '1':
            cout << "Addition: " << num1 + num2 << endl;
            break;
        case '2':
            cout << "Subtraction: " << num1 - num2 << endl;
            break;
        case '3':
            cout << "Multiplication: " << num1 * num2 << endl;
            break;
        case '4':
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } else {
                cout << "Division: " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "You chose an invalid operation." << endl;
    }

    return 0;
}