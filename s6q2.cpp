//Write a C++ program to design a class complex to represent complex number. The complex class
//uses an external function (as a friend function) to add two complex number. The function should
//return an object of type complex representing the sum of two complex Numbers

#include<iostream>
using namespace std;
class complex
{
    private:
        float real,imag;
    public:
    complex( float r , float i) : real(r),imag(i){}
    void display()
    {
        cout<<"Complex number "<<real <<" + "<<imag<<"i"<<endl;
    }
    friend complex addcomplex( complex c1 ,complex c2);


};
complex addcomplex(complex c1 , complex c2)
{
    float realpart= c1.real+c2.real;
    float imaginarypart=c1.imag+c2.imag;
    return complex(realpart,imaginarypart);
}
int main()
{
    float real1,real2,imag1,imag2;
    cout<<"Enter real and imaginary part of the first complex number respectively: "<<endl;
    cin>>real1>>imag1;
    complex c1(real1,imag1);
    cout<<"Enter real and imaginary part of the second complex number respectively:  "<<endl;
    cin>>real2>>imag2;
    complex c2(real2,imag2);
    cout<<"First complex number: "<<endl;
    c1.display();
    cout<<"Second complex number: "<<endl;
    c2.display();
    complex c3= addcomplex(c1,c2);
    cout<<"addition of two complex number is "<<endl;
    c3.display();
    return 0;
}
