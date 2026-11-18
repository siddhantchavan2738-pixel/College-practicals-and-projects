++++++++ Practical 1
// Title: Write a C++ program to demonstrate
// data types, constant variables, operators and I/O.

#include <iostream>
using namespace std;

int main()
{
    // Demonstration of Data Types
    int age = 18;
    float marks = 85.5;
    double salary = 25000.75;
    char grade = 'A';
    bool isPassed = true;

    // Constant Variable
    const float PI = 3.14;

    // Input and Output
    string name;
    cout << "Enter your name: ";
    cin >> name;

    cout << "\n--- Student Details ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Marks: " << marks << endl;
    cout << "Salary: " << salary << endl;
    cout << "Grade: " << grade << endl;
    cout << "Passed: " << isPassed << endl;
    cout << "PI: " << PI << endl;

    // Demonstration of Operators
    int a = 10, b = 5;

    cout << "\n--- Operators ---" << endl;
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Modulus: " << a % b << endl;
    cout << "Relational (a > b): " << (a > b) << endl;
    cout << "Logical (a > b && b > 0): "
         << (a > b && b > 0) << endl;

    return 0;
}
