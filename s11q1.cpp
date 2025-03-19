/*Write a C++ program to read two float numbers. Perform arithmetic binary operations +,-,*,/ on
these numbers using inline function. Display the resultant value*/

#include<iostream>
using namespace std;
inline float add(float a,float b){
    return a+b;
}
inline float sub(float a,float b){
    return a-b;
}
inline float mult(float a,float b){
    return a*b;
}
inline float div(float a,float b){
    if(b != 0)
    {
        return a/b;
    }
    else
    {
        " :Error division by zero: ";
        return 0;
    }
    
}

int main()
{
float a, b;
cout<<"Enter value of first number";
cin>>a;
cout<<"Enter value of second number";
cin>>b;
cout<<"addition of "<<a<<" and "<<b<<" is= "<<add(a,b)<<endl;
cout<<"subtraction of "<<a<<" and "<<b<<" is= "<<sub(a,b)<<endl;
cout<<"multiplication of "<<a<<" and "<<b<<" is= "<<mult(a,b)<<endl;
cout<<"division of "<<a<<" and "<<b<<" is= "<<div(a,b)<<endl;
return 0;


}