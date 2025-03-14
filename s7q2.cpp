//Create a class College containing data members as College_Id, College_Name,
//Establishment_year, University_Name. Write a C++ program with following functions
//a. Accept n College details
//b. Display College details of specified University
//c. Display College details according to Establishment year (Use Array of Objects and
//Function Overloading).

#include <iostream>
#include <string>
using namespace std;

class College {
private:
    int College_Id;
    string College_Name;
    int Establishment_year;
    string University_Name;

public:
    // Default constructor
    College() : College_Id(0), Establishment_year(0), College_Name(""), University_Name("") {}

    // Parameterized constructor to initialize the college details
    College(int id, string name, int year, string university)
        : College_Id(id), College_Name(name), Establishment_year(year), University_Name(university) {}

    // Function to accept college details
    void acceptDetails() {
        cout << "Enter College ID: ";
        cin >> College_Id;
        cin.ignore();  // To ignore newline character from previous input
        cout << "Enter College Name: ";
        getline(cin, College_Name);
        cout << "Enter Establishment Year: ";
        cin >> Establishment_year;
        cin.ignore();
        cout << "Enter University Name: ";
        getline(cin, University_Name);
    }

    // Function to display college details
    void displayDetails() const {
        cout << "College ID: " << College_Id << endl;
        cout << "College Name: " << College_Name << endl;
        cout << "Establishment Year: " << Establishment_year << endl;
        cout << "University Name: " << University_Name << endl;
    }

    // Function to display college details based on university name
    static void displayDetailsByUniversity(College colleges[], int n, string university) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (colleges[i].University_Name == university) {
                colleges[i].displayDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "No colleges found for the specified university." << endl;
        }
    }

    // Function to display details sorted by establishment year (function overloading)
    static void displayDetailsByEstablishmentYear(College colleges[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colleges[i].Establishment_year > colleges[j].Establishment_year) {
                    swap(colleges[i], colleges[j]);
                }
            }
        }

        // Displaying sorted details
        cout << "\nColleges sorted by Establishment Year:" << endl;
        for (int i = 0; i < n; i++) {
            colleges[i].displayDetails();
            cout << endl;
        }
    }

    // Overloaded function to display details by establishment year for a specific year
    static void displayDetailsByEstablishmentYear(College colleges[], int n, int year) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (colleges[i].Establishment_year == year) {
                colleges[i].displayDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "No colleges found for the specified establishment year." << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of colleges: ";
    cin >> n;

    // Creating an array of College objects
    College colleges[n];

    // Accept details for each college
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for College " << i + 1 << ":\n";
        colleges[i].acceptDetails();
    }

    // Display college details for a specified university
    string university;
    cout << "\nEnter the university name to search: ";
    cin.ignore();  // To ignore newline character after entering n
    getline(cin, university);
    College::displayDetailsByUniversity(colleges, n, university);

    // Display college details sorted by establishment year
    College::displayDetailsByEstablishmentYear(colleges, n);

    // Display college details for a specified establishment year
    int year;
    cout << "\nEnter the establishment year to search: ";
    cin >> year;
    College::displayDetailsByEstablishmentYear(colleges, n, year);

    return 0;
}

