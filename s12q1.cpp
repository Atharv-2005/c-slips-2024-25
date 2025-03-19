/*
Write a C++ program to accept length and width of a rectangle. Calculate and display perimeter
as well as area of a rectangle by using inline function. 
*/
#include<iostream>
using namespace std;
inline float perimeter(float l, float b)
{
    float per= l*2+b*2;
    return per;
}
inline  float area(float l,float b)
{
    float rarea = l*b;
    return rarea;
}
int main()
{
    float length , breadth;
    cout<<"Enter length and breadth of the Rectangle: "<<endl;
    cin>>length>>breadth;
    cout<<"Perimeter of the Rectangle is = "<<perimeter(length,breadth)<<endl;
    cout<<"Area of the Rectangle is = "<<area(length,breadth)<<endl;
    return 0;

}