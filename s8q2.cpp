//Write a C++ program to create a class Date which contains three
// data members as dd,mm,yyyy.
//Create and initialize the object by using parameterized constructor 
//and display date in dd-monthyyyy format. (Input: 19-12-2014 Output: 19-Dec-2014) 
//Perform validation for month.

#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int dd, mm, yyyy;

public:
    const string months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    Date(int day, int month, int year) {
        if (month < 1 || month > 12) {
            cout << "Invalid month! Please enter a value between 1 and 12." << endl;
            mm = 1; 
        } else {
            mm = month;
        }
        
        dd = day;
        yyyy = year;
    }
    void displayDate() {
        cout << dd << "-" << months[mm - 1] << "-" << yyyy << endl;
    }
};

int main() {
    int day, month, year;

    cout << "Enter the day (dd): ";
    cin >> day;
    cout << "Enter the month (mm): ";
    cin >> month;
    cout << "Enter the year (yyyy): ";
    cin >> year;
    Date date(day, month, year);
    date.displayDate();
    return 0;
}