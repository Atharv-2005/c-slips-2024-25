//Write a C++ program to create a class Array that contains one float array as member. Overload
//the Unary ++ and -- operators to increase or decrease the value of each element of an array. Use
//friend function for operator function

#include<iostream>
using namespace std;
class array
{
    private:
    static const int size=5;
    float arr[size];
    public:

    array()
    {
        for(int i=0;i<size;i++)
        {
            arr[i]=0.0;
        }
    }

    void acceptarray( )
    {
        cout<<"Enter array elements: "<<endl;
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }

    }

    void printarray()
    {
        for(int i=0;i<size;i++)
        {
            cout<<" "<<arr[i]<<",";
        }
        cout<<endl;
    }
    friend array operator++(array &a);
    friend array operator--(array &a);
};
array operator++(array &a)
{
    for(int i=0;i<array::size;i++)
    {
        a.arr[i]+=1.0;
    }
}
array operator--(array &a)
{
    for(int i=0;i<array::size;i++)
    {
        a.arr[i]-=1.0;
    }
}
int main()
{
    
    array ar;
    ar.acceptarray();
    cout<<"Orignal array: "<<endl;
    ar.printarray();

    ++ar;
    cout<<"after increment : \n";
    ar.printarray();

    --ar;
    cout<<"after decrement: \n";
    ar.printarray();

    return 0;

}
