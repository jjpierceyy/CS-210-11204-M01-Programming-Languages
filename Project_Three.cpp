/*
Developer: Jerret Piercey
Date: 6/29/2024
Purpose: Project Three Grocery-Tracking Program
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

// Class to manage grocery items and their frequencies
class GroceryItem {
private:
    map<string, int> items; // Map to store item names and their frequencies

public:
    // Loads items and their frequencies from a file
    void LoadItemsFromFile(const string& filename);
    // Gets the frequency of a specific item
    int GetFrequency(const string& item) const;
    // Prints all items and their frequencies
    void PrintFrequencies() const;
    // Prints a histogram of item frequencies
    void PrintHistogram() const;
    // Saves the item frequencies to a file
    void SaveToFile(const string& filename) const;
};

// Loads items and their frequencies from a file
void GroceryItem::LoadItemsFromFile(const string& filename) {
    ifstream file(filename); // Open file for reading
    string item;
    while (file >> item) { // Read each item from the file
        items[item]++; // Increment the frequency count for the item
    }
}

// Gets the frequency of a specific item
int GroceryItem::GetFrequency(const string& item) const {
    auto it = items.find(item); // Find the item in the map
    if (it != items.end()) { // If item is found
        return it->second; // Return its frequency
    } else {
        return 0; // If item is not found, return 0
    }
}

// Prints all items and their frequencies
void GroceryItem::PrintFrequencies() const {
    for (const auto& pair : items) { // Iterate through the map
        cout << pair.first << " " << pair.second << endl; // Print item and its frequency
    }
}

// Prints a histogram of item frequencies
void GroceryItem::PrintHistogram() const {
    for (const auto& pair : items) { // Iterate through the map
        cout << pair.first << " "; // Print item name
        for (int i = 0; i < pair.second; ++i) { // Print asterisks equal to the frequency
            cout << "*";
        }
        cout << endl;
    }
}

// Saves the item frequencies to a file
void GroceryItem::SaveToFile(const string& filename) const {
    ofstream file(filename); // Open file for writing
    for (const auto& pair : items) { // Iterate through the map
        file << pair.first << " " << pair.second << endl; // Write item and its frequency to the file
    }
}

int main() {
    GroceryItem grocery; // Create GroceryItem object
    string inputFileName = "CS210_Project_Three_Input_File.txt"; // Input file name
    string backupFileName = "frequency.dat"; // Backup file name
    grocery.LoadItemsFromFile(inputFileName); // Load items from input file
    grocery.SaveToFile(backupFileName); // Save item frequencies to backup file

    int choice;
    while (choice != 4) { // Loop until user chooses to exit
        // Display menu options
        cout << "1. Find frequency of an item" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram of item frequencies" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice; // Get user choice

        if (choice == 1) { // If user chooses to find frequency of an item
            string item;
            cout << "Enter the item: ";
            cin >> item; // Get item name from user
            int frequency = grocery.GetFrequency(item); // Get frequency of the item
            cout << "Frequency of " << item << " is " << frequency << endl;
        }
        else if (choice == 2) { // If user chooses to print all item frequencies
            grocery.PrintFrequencies(); // Print all item frequencies
        }
        else if (choice == 3) { // If user chooses to print histogram of item frequencies
            grocery.PrintHistogram(); // Print histogram of item frequencies
        }
    }

    return 0; // Exit program
}
