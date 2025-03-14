//Write a C++ program to implement a class printdata to overload print function as follows:
//void print(int) - outputs value followed by the value of the integer.
//Eg. print(10) outputs - value 10
//void print(char *) – outputs value followed by the string in double quotes.
//Eg. print(“hi”) outputs value “hi”


#include <iostream>
using namespace std;

class PrintData {
public:
    void print(int value) 
    {
        cout << "Value: " << value << endl;
    }

    
    void print(const char* value) 
    {
        cout << "Value: \" " << value << " \" " << endl;
    }
};

int main() 
{
    PrintData pd;

    int num = 10;
    const char* str = "hi";
    pd.print(num);   
    pd.print(str);   
    return 0;
}
