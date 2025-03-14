//Write a C++ program to create a class Shape with functions to find area of the shape and display
//the name of the shape and other essential components of the class. Create derived classes circle,
//rectangle and trapezoid each having overridden function area and display. Write a suitable
//program to illustrate Virtual Function

#include<iostream>
using namespace std;
class shape
{
    public: 
    void calculatearea(){}
    void shapedisplay(){}
};
class circle : public shape
{
    private: 
    float radius;
    public:
    circle(float r) : radius(r){}
    float calculatearea()
    {
        cout<<"area of Circle "<< 3.14 * radius * radius<<endl;
    }   
    void shapedisplay()
    {
        cout<<"Shape : Circle"<<endl;
    }
};
class rectangle : public shape
{
    private:
        float length,breadth;
    public:
        rectangle(float l,float b) : length(l),breadth(b){}
        float calculatearea()
        {
            cout<<"Area of Rectangle = "<<length * breadth <<endl;
        }
        void shapedisplay()
        {
            cout<<"Shape : Rectangle"<<endl;
        }

};
class trapezoid : public shape
{
    private:
        float base1,base2,height;
    public:
        trapezoid(float b1, float b2,float h) : base1(b1),base2(b2),height(h){}

        float calculatearea()
        {
            cout<<"Area of Trapezoid : "<< 0.5 * (base1 + base2) * height<<endl;
        }
        void shapedisplay()
        {
            cout<<"Shape : Trapezoid";
        }
};
int main()
{   
    float radius,base1,base2,height,length,breadth;
    cout<<"Enter radius "<<endl;
    cin>>radius;
    circle c1(radius);
    c1.calculatearea();
    c1.shapedisplay();

    cout<<"Enter length and breadth "<<endl;
    cin>>length>>breadth;
    rectangle r1(length,breadth);
    r1.calculatearea();
    r1.shapedisplay();

    cout<<"Enter base1 base2 and height"<<endl;
    cin>>base1>>base2>>height;
    trapezoid t1(base1,base2,height);
    t1.calculatearea();
    t1.shapedisplay();

    return 0;
}