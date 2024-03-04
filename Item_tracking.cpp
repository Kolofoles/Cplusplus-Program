#include <iostream>
#include<iomanip>
#include <string>
#include <map>
#include <fstream>

using namespace std;

// Define data type for map, allows to be passed to functions
typedef map<string, int> itemListMap;

// If item is in map, incremement frequency
void WordCounter(istream& readFile, itemListMap& freq) {
	string groceryItem;
	// Read from file into groceryItem, if item exists, increment item frequency in map
	while (readFile >> groceryItem) {
		++freq[groceryItem];
	}
}

// Writes the contents of the given map to a file
void WriteOutfile(ostream& outStream, itemListMap& someMap) {
	// Iterate through map, writing each value to out file 
	for (itemListMap::iterator it = someMap.begin(); it != someMap.end(); ++it) {
		outStream << left << setw(12) << it->first << " " << it->second << endl;
	}
}

// Prints an options menu for the user
void PrintMenu() {
	cout << "Welcome to The Corner Grocer!\n\n";
	cout << "Please select an option from the menu:\n";
	cout << "1) Search for an item and find its' purchase frequency.\n";
	cout << "2) Print all items and their purchase frequency.\n";
	cout << "3) Print all items with a histogram for purchase frequency.\n";
	cout << "4) Quit the program.\n";
}

int main() {
	int userInput;
	string userWord;
	bool quit = false;
	bool search = true;

	// Create and open input file stream
	ifstream groceryInputFS("CS210_Project_Three_Input_File.txt");

	// Print error if input file fails to open
	if (!groceryInputFS.is_open()) {
		cout << "CS210_Project_Three_Input_File failed to open.\n";
		return 1;
	}

	// Create and open output file stream
	ofstream groceryOutputFS("frequency.dat");
	
	// Print error if output file fails to open
	if (!groceryOutputFS.is_open()) {
		cout << "frequency.dat.\n";
		return 1;
	}

	// Create a map
	itemListMap newMap;
	WordCounter(groceryInputFS, newMap);
	
	// Write contents of map newList to file, then close the file
	WriteOutfile(groceryOutputFS, newMap);
	groceryOutputFS.close();

	while (!quit) {
		PrintMenu();
		cin >> userInput;
		switch (userInput) {
		// Prompt a user to input the item, or word, they wish to look for.
		// Return a numeric value for the frequency of the specific word.
		case 1:
			system("CLS");	
			cout << "Enter an item to search for, starting with a capital letter.\n";
			cin >> userWord;	

			// Check that user search is an existing key
			// If key exists, print its' frequency
			if (newMap.count(userWord) == 1) {
				cout << "\n" << newMap.at(userWord) << " " << userWord << " were sold today.\n";
			}
			// If no key match found, print error statement
			else {
				cout << "Incorrect spelling or item didn't sell today.\n\n";
			}
			cout << endl;
			system("pause");
			system("CLS");
			break;

		// Print the list with numbers that represent the frequency of all items purchased.
		case 2:
			system("CLS");
			cout << "List of Grocery Items and Amount Purchased\n\n";
			// Iterrate through map, incrememnts each reoccuring item. 
			for (itemListMap::iterator it = newMap.begin(); it != newMap.end(); ++it) {
				cout << left << setw(12) << it->first << " " << it->second << endl;
			}
			cout << endl;
			system("pause");
			system("CLS");
			break;

		// Print the same frequency for all items in the form of a histogram
		case 3:
			system("CLS");
			cout << "Histogram of Grocery Items Purchased\n\n";
			// Iterrate through map, incrememnts each reoccuring item. 
			for (itemListMap::iterator it = newMap.begin(); it != newMap.end(); ++it) {
				string histogram(it->second, '*'); // Creates a line of asterisks for frequency of item
				cout << right << setw(12) << it->first << " " << histogram << endl;
			}
			cout << endl;
			system("pause");
			system("CLS");
			break;

		// Exit the program.
		case 4:
			system("CLS");
			cout << "You entered 4, to quit.\nGoodbye.\n";
			quit = true;
			break;

		// For invalid input, clear error state of cin
		default:
			system("CLS");
			cout << "Inccorrect input!\nPlease enter a valid option.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
			system("CLS");
			break;

		}
	}

	// Close input file
	groceryInputFS.close();

	return 0;
}
