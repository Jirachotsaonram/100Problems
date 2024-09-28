#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <limits> // เพิ่ม header นี้เพื่อให้แน่ใจว่ามีการใช้ numeric_limits ได้
using namespace std;

class Cashier {
private:
    struct Product {
        float price;
        int quantity;
    };
    unordered_map<string, Product> products;

public:
    // Constructor
    Cashier() {}

    // Method to add a product
    void add_product(const string& name, float price, int quantity) {
        if (products.find(name) != products.end()) {
            // Update the product if it already exists
            products[name].price = price;
            products[name].quantity += quantity;
        } else {
            // Add new product
            products[name] = { price, quantity };
        }
        cout << "Product added/updated: " << name << endl;
    }

    // Method to remove a product
    void remove_product(const string& name) {
        if (products.find(name) != products.end()) {
            products.erase(name);
            cout << "Product removed: " << name << endl;
        } else {
            cout << "Product not found: " << name << endl;
        }
    }

    // Method to calculate total cost of all products
    float calculate_total() const {
        float total = 0.0;
        for (const auto& pair : products) {
            total += pair.second.price * pair.second.quantity;
        }
        return total;
    }

    // Method to display all products
    void display_products() const {
        if (products.empty()) {
            cout << "No products available." << endl;
            return;
        }
        cout << "Product List:" << endl;
        for (const auto& pair : products) {
            cout << pair.first << " - Price: $" << fixed << setprecision(2) 
                 << pair.second.price << ", Quantity: " << pair.second.quantity << endl;
        }
    }
};

// Input validation functions
string input_product_name() {
    string name;
    while (true) {
        cout << "Enter product name: ";
        getline(cin, name);
        if (!name.empty()) return name;
        cout << "Invalid product name. Please enter a non-empty string." << endl;
    }
}

float input_product_price() {
    float price;
    while (true) {
        cout << "Enter product price: ";
        if (cin >> price && price > 0) return price;
        cout << "Invalid price. Please enter a positive number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int input_product_quantity() {
    int quantity;
    while (true) {
        cout << "Enter product quantity: ";
        if (cin >> quantity && quantity > 0) return quantity;
        cout << "Invalid quantity. Please enter a positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    Cashier cashier;
    int choice;

    while (true) {
        cout << "\nMenu:\n"
             << "1. Add a product\n"
             << "2. Remove a product\n"
             << "3. Calculate total cost\n"
             << "4. Display all products\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline after number input

        if (choice == 1) {
            string name = input_product_name();
            float price = input_product_price();
            int quantity = input_product_quantity();
            cashier.add_product(name, price, quantity);
        } else if (choice == 2) {
            string name = input_product_name();
            cashier.remove_product(name);
        } else if (choice == 3) {
            cout << "Total Cost: $" << fixed << setprecision(2) << cashier.calculate_total() << endl;
        } else if (choice == 4) {
            cashier.display_products();
        } else if (choice == 5) {
            cout << "Exiting program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
