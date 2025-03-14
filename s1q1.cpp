//Q1.Write the definition for a class Cylinder that contains data members radius and height. The class
//has the following member functions:
//a. void setradius(float) to set the radius of data member.
//b. void setheight(float) to set the height of data member.
//c. float volume( ) to calculate and return the volume of the cylinder.
//Write a C++ program to create cylinder object and display its volume.

#include<iostream>
using namespace std;
class Cylinder
{
    private:
    float radius,height;
    public:
    void setradius(float r) 
    {
        radius=r;
    }
    
    void setheight(float h) 
    {
        height=h;
    }

    float volume()
    {
        return 3.14 * radius * radius * height; 
    }
};
int main()
{
<<<<<<< HEAD
    Cylinder c1;
    float radius,height;
    cout<<"Enter radius "<<endl;
    cin>>radius;
    c1.setradius(radius);
    cout<<"Enter height "<<endl;
    cin>>height;
    c1.setheight(height);
    cout<<"Volum of the cylinder is = "<<c1.volume()<<endl;

=======
    cout<<" hi Atharv"<<endl;
>>>>>>> 10264a96324790c4c8d5c48de8862b04def4e9a8
    return 0;
}
