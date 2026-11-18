// Practical 3
// Title: Implement a class demonstrating all
// types of constructors (Default, Parameterized,
// Copy and Move).


#include <iostream>
using namespace std;

class Student
{
    int id;
    string name;

public:

    // Default Constructor
    Student()
    {
        id = 0;
        name = "Unknown";
    }

    // Parameterized Constructor
    Student(int i, string n)
    {
        id = i;
        name = n;
    }

    // Copy Constructor
    Student(const Student &s)
    {
        id = s.id;
        name = s.name;
    }

    // Move Constructor
    Student(Student &&s) noexcept
    {
        id = s.id;
        name = move(s.name);
        s.id = 0;
    }

    // Member Function
    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

int main()
{
    // Default Constructor
    Student s1;
    cout << "\nDefault Constructor:\n";
    s1.display();

    // Parameterized Constructor
    Student s2(101, "Rahul");
    cout << "\nParameterized Constructor:\n";
    s2.display();

    // Copy Constructor
    Student s3(s2);
    cout << "\nCopy Constructor:\n";
    s3.display();

    // Move Constructor
    Student s4(move(s2));
    cout << "\nMove Constructor:\n";
    s4.display();

    return 0;
}
