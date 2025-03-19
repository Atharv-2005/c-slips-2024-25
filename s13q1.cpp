/*
Write a C++ program to implement a class ‘student’ to overload following functions as follows:
a. int maximum(int, int) – returns the maximum score of two students
b. int maximum(int *a, int arraylength) – returns the maximum score from an array ‘a’
*/

#include<iostream>
using namespace std;
class student
{
    public:
    int maximum(int m1, int m2)
    {
        return (m1 > m2) ? m1:m2;
    }
    int maximum(int *a, int arraylength)
    {
        int maxscore=a[0];
        for(int i=1 ; i < arraylength; i++)
        {
            if(a[i] > maxscore)
            {
                maxscore= a[i];
            }
        }
        return maxscore;
        
    }
};
int main()
{
    student s1;
    int m1,m2;
    cout<<"Enter score of two students: ";
    cin>>m1>>m2;
    
    cout<<"Maximum score from "<< m1 <<"and "<<m2 <<"=" << s1.maximum(m1,m2) <<endl;
    
    int n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter scores of "<< n << " students: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<" Maximum score is = "<<s1.maximum(a , n)<<endl;
    return 0;
}