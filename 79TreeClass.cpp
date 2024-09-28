#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Tree {
private:
    string species;
    float height;
    int age;
    string location;

public:
    // Constructor with input validation
    Tree(const string& species, float height, int age, const string& location) {
        this->species = validate_species(species);
        this->height = validate_height(height);
        this->age = validate_age(age);
        this->location = validate_location(location);
    }

    // Input validation for species (non-empty string)
    string validate_species(const string& species) {
        string valid_species = species;
        while (valid_species.empty()) {
            cout << "Invalid species name. Please enter a valid species name: ";
            getline(cin, valid_species);
        }
        return valid_species;
    }

    // Input validation for height (positive float)
    float validate_height(float height) {
        while (height <= 0) {
            cout << "Invalid height. Please enter a positive value: ";
            cin >> height;
        }
        return height;
    }

    // Input validation for age (positive integer)
    int validate_age(int age) {
        while (age <= 0) {
            cout << "Invalid age. Please enter a positive integer: ";
            cin >> age;
        }
        return age;
    }

    // Input validation for location (non-empty string)
    string validate_location(const string& location) {
        string valid_location = location;
        while (valid_location.empty()) {
            cout << "Invalid location. Please enter a valid location: ";
            getline(cin, valid_location);
        }
        return valid_location;
    }

    // Method to grow the tree
    void grow(float growth_amount) {
        if (growth_amount > 0) {
            height += growth_amount;
            cout << "The tree grew by " << growth_amount << " meters." << endl;
        } else {
            cout << "Growth amount must be a positive value." << endl;
        }
    }

    // Method to change the tree's location
    void change_location(const string& new_location) {
        location = validate_location(new_location);
        cout << "The tree was moved to " << location << "." << endl;
    }

    // Method to display information about the tree
    void display_info() const {
        cout << "Species: " << species << endl;
        cout << "Height: " << height << " meters" << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Location: " << location << endl;
    }
};

// Main function to demonstrate usage of Tree class
int main() {
    string species, location;
    float height;
    int age;

    // Getting input for tree attributes
    cout << "Enter tree species: ";
    getline(cin, species);
    cout << "Enter tree height (in meters): ";
    cin >> height;
    cout << "Enter tree age (in years): ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
    cout << "Enter tree location: ";
    getline(cin, location);

    // Creating a Tree object
    Tree tree(species, height, age, location);

    // Demonstrating the grow and change_location methods
    tree.grow(0.5);
    tree.change_location("Botanical Garden");

    // Displaying the tree's information
    tree.display_info();

    return 0;
}
