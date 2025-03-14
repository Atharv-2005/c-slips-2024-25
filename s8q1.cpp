//Write a C++ program to subtract two integer numbers of two different classes using friend
//function

#include <iostream>
using namespace std;
class ClassB;
class ClassA 
{
    private:
        int numA;
    public:
    ClassA(int a) : numA(a) {}
    friend int subtract(ClassA, ClassB);
};
class ClassB 
{
    private:
        int numB;
    public:
        ClassB(int b) : numB(b) {}
        friend int subtract(ClassA, ClassB);
};
int subtract(ClassA objA, ClassB objB)
{
    return objA.numA - objB.numB;
}
int main() 
{
    int a,b;
    cout << "Enter an integer for ClassA: ";
    cin >> a;
    cout << "Enter an integer for ClassB: ";
    cin >> b;
    ClassA objA(a);
    ClassB objB(b);
    int result = subtract(objA, objB) ;
    cout << "The result of subtraction (ClassA - ClassB) is: " << result << endl;
    return 0;
}