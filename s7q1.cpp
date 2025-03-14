//Write a C++ program using class which contains two data members as type integer. Create and
//initialize the objects using default constructor, parameterized constructor with default value.
//Write a member function to display maximum from given two numbers for all objects.

#include<iostream>
using namespace std;
class number
{
    private:
    int num1,num2;
    public:
    number() : num1(),num2(){}
    
    number(int n1 ,int n2) : num1(n1),num2(n2){}

    void displaymax()
    {
        if(num1>num2)
        {
            cout<<"The gretest number between "<<num1 <<" and " <<num2 <<" is "<< num1;
        }
        else
        {
            cout<<"The gretest number between "<<num1 <<" and " <<num2 <<" is "<< num2;
        }
    }
};
int main()
{
    int n1,n2;
    cout<<"Enter 2 numbers";
    cin>>n1>>n2;
    number m1(n1,n2);
    m1.displaymax();
    return 0;
}