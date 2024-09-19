#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2;

    // Display a welcome message
    cout<< "hello user" << endl;
    cout<< "welcome to the calculator" << endl;
    cout << "Simple Calculator" << endl;
    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    // Input the numbers
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Perform the operation based on the user input
    switch(operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            // Check if the second number is not zero to avoid division by zero
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
            break;
    }

    return 0;
}