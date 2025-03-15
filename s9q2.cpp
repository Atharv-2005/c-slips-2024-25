//Create a class Time which contains data members as: Hours, Minutes and Seconds. Write a
//C++ program to perform following necessary member functions:
//a. To read time
//b. To display time in format like: hh:mm:ss
//c. To add two different times (Use Objects as argument)

#include <iostream>
using namespace std;

class Time 
{
    private:
    int hours;
    int minutes;
    int seconds;

    public:
    // Default constructor
    Time() : hours(0), minutes(0), seconds(0) {}

    // Function to read time
    void readTime() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }

    // Function to display time in hh:mm:ss format
    void displayTime() {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    // Function to add two times
    Time addTime(const Time &t) {
        Time sum;
        sum.seconds = seconds + t.seconds;
        sum.minutes = minutes + t.minutes + sum.seconds / 60;
        sum.seconds %= 60;
        sum.hours = hours + t.hours + sum.minutes / 60;
        sum.minutes %= 60;
        sum.hours %= 24; // To handle 24-hour clock
        return sum;
    }
};

int main() {
    Time time1, time2, time3;

    cout << "Enter the first time:\n";
    time1.readTime();
    
    cout << "Enter the second time:\n";
    time2.readTime();

    cout << "\nFirst time: ";
    time1.displayTime();
    
    cout << "Second time: ";
    time2.displayTime();

    // Adding the two times
    time3 = time1.addTime(time2);

    cout << "\nSum of times: ";
    time3.displayTime();

    return 0;
}
