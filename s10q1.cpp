//.Write a C++ program to create a class employee containing salary as a data member. Write
//necessary member functions to overload the operator unary pre and post decrement "--"
//for decrementing salary.

#include <iostream>
using namespace std;

class Employee {
    float salary;

public:
    // Constructor to initialize salary
    Employee(float sal) : salary(sal) {}

    // Function to display salary
    void displaySalary() const {
        cout << "Salary: $" << salary << endl;
    }

    // Overloading the unary pre-decrement operator (--emp)
    Employee& operator--() {
        // Decrement salary by 100
        salary -= 100;
        return *this;
    }

    // Overloading the unary post-decrement operator (emp--)
    Employee operator--(int) {
        Employee temp = *this;  // Save current object to return it after decrement
        salary -= 100;          // Decrement salary by 100
        return temp;
    }
};

int main() {
    // Create an Employee object with initial salary of 5000
    Employee emp1(5000);

    cout << "Original Salary: ";
    emp1.displaySalary();

    // Pre-decrement: Decrements the salary by 100 and displays updated salary
    --emp1;  
    cout << "After pre-decrement: ";
    emp1.displaySalary();

    // Post-decrement: Decrements the salary by 100 but returns the previous salary
    Employee temp = emp1--; 
    cout << "After post-decrement: ";
    emp1.displaySalary();

    // Display the salary of the employee returned by post-decrement
    cout << "Salary after post-decrement (stored in temp): ";
    temp.displaySalary();

    return 0;
}
