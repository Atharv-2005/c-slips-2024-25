//Create a class String which contains a character pointer (Use new and delete operator)
//Write a C++ program to overload following operators
//a. ! To reverse the case of each alphabet from given string.
//b. [ ] To print a character present at specified index

#include <iostream>
#include <string>

using namespace std;  // Makes all components from the std namespace available

class String {
private:
    char* str;  // Pointer to hold the string

public:
    // Constructor
    String(const string& input) {
        // Calculate length of input string manually (no strlen)
        int length = input.length();
        
        // Allocate memory for the string (+1 for null terminator)
        str = new char[length + 1];

        // Copy the string manually
        for (int i = 0; i < length; ++i) 
        {
            str[i] = input[i];
        }
        str[length] = '\0';  // Null-terminate the string
    }

    // Destructor to release memory
    ~String() {
        delete[] str;
    }

    // Overload ! operator to reverse the case of each alphabetic character
     char& operator!() {
        for (int i = 0; str[i] != '\0'; ++i) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                // Convert lowercase to uppercase
                str[i] = str[i] - ('a' - 'A');
            } else if (str[i] >= 'A' && str[i] <= 'Z') {
                // Convert uppercase to lowercase
                str[i] = str[i] + ('a' - 'A');
            }
        }
    }

    // Overload [] operator to access a character at a specific index
    char& operator[](int index) {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }

        // Check if the index is within bounds
        if (index >= 0 && index < length) {
            return str[index];
        } else {
            cout << "Index out of bounds!" << endl;
            exit(1);  // Exit if the index is invalid
        }
    }

    // Function to display the string
    void display() const {
        for (int i = 0; str[i] != '\0'; ++i) {
            cout << str[i];
        }
        cout << endl;
    }
};

int main() {
    // Read input using std::string and then convert to C-style string
    string input;
    cout << "Enter a string: ";
    getline(cin, input);  // Read input

    // Create String object using the C-style string
    String s(input);

    cout << "Original string: ";
    s.display();

    // Use ! operator to reverse the case
    !s;
    cout << "After reversing case: ";
    s.display();

    // Use [] operator to access characters at specific indexes
    cout << "Character at index 6: " << s[6] << endl;  // Should print character at index 6

    // Modify the character at index 6
    s[6] = 'W';
    cout << "After modifying character at index 6: ";
    s.display();

    return 0;
}
