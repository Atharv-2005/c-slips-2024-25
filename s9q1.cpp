//Write a C++ program to create a class Item with data members Item_code, Item_name, Item_Price.
//Write member functions to accept and display item information and also display number 

class Item {
    private:
        int Item_code;
        string Item_name;
        float Item_Price;
    
        static int count;
    
    public:
        // Default constructor
        Item() {
            Item_code = 0;
            Item_name = "Unknown";
            Item_Price = 0.0;
            count++;
        }
    
        // Parameterized constructor
        Item(int code, string name, float price) {
            Item_code = code;
            Item_name = name;
            Item_Price = price;
            count++;
        }
    
        static int getObjectCount() {
            return count;
        }
    
        void acceptDetails() {
            cout << "Enter Item code: ";
            cin >> Item_code;
            cin.ignore();
            cout << "Enter Item name: ";
            getline(cin, Item_name);
            cout << "Enter Item price: ";
            cin >> Item_Price;
        }
    
        void displayDetails() {
            cout << "Item Code: " << Item_code << endl;
            cout << "Item Name: " << Item_name << endl;
            cout << "Item Price: " << Item_Price << endl;
        }
    };
    
    // Initialize static member
    int Item::count = 0;
    int main() {
        int n;
        cout << "Enter number of items: ";
        cin >> n;
    
        // Dynamically allocate memory for an array of Item objects
        Item* items = new Item[n];  // Dynamic array of Item objects
    
        // Accept and display details of each item
        for (int i = 0; i < n; i++) {
            cout << "\nEnter details for Item " << i + 1 << ":\n";
            items[i].acceptDetails();
        }
    
        // Display the details of each item
        cout << "\nItem details:\n";
        for (int i = 0; i < n; i++) {
            cout << "\nDetails of Item " << i + 1 << ":\n";
            items[i].displayDetails();
        }
    
        // Display the total number of objects created
        cout << "\nTotal number of Item objects created: " << Item::getObjectCount() << endl;
    
        // Clean up dynamically allocated memory
        delete[] items;
    
        return 0;
    }
        