/*
Project 3 - Corner Grocer
Joshua Shults
10/14/2023
*/

//include libraries for maps, strings, cin
#include <iostream> 
#include <map>
#include <fstream>
#include <string> 


using namespace std; // standard namespace

//Create a class for searching for items and printing
class ItemSearch { 
public: // define public members and functions
	map<string, int> itemFrequency; //frequency of items map to store information in
	string inputFileName = "1.txt"; // name of the file to open
	string outputFileName = "frequency.dat"; // file to create
	void readInputFile() { // function to read the input file
		ifstream inputFile(inputFileName);
		string item;
		int frequency;
		if (inputFile.fail()) { // catch problems openning the file
			cout << "Error openning file" << endl;
		}
		while (inputFile >> item) { // while the input file has an item...
			itemFrequency[item]++; // the amount of times that item appears is increased and held in the map
		}
		inputFile.close(); // close the file after reading
		
	}
	void writeOutputFile() { // function creating output file
		ofstream outputFile(outputFileName);
		for (auto item : itemFrequency) {
			outputFile << item.first << " " << item.second << endl; // writes the item followed by its frequency
		}
		outputFile.close(); // close the file after writing
	}
	
	void searchItem() { // function for user to search for items
		string item;
		cout << "Enter the item to search for: ";
		cin >> item;
		if (itemFrequency.count(item)) { // if the item is present on the text file
			cout << item << ": " << itemFrequency[item] << endl; // print the name of the item followed by the amount of times it is in the file
		}
		else { // else...
			cout << item << " not found." << endl; // inform user that item was not found
		}
	}
	void printList() { // function to print a list of produce items sold
		cout << "Produce frequency list:" << endl;
		for (auto item : itemFrequency) {
			cout << item.first << " " << item.second << endl;
		}
	}
	void printHistogram() { // function to print a histogram of items sold
		cout << "Produce frequency histogram:" << endl;
		for (auto item : itemFrequency) {
			cout << item.first << " ";
			for (int i = 0; i < item.second; i++) {
				cout << "*";
			}
			cout << endl;
		}
	}
};

int main() {
	ItemSearch ItemSearch;
	int option;
	
	ItemSearch.readInputFile(); // first read the input file to store information in the map
	ItemSearch.writeOutputFile();


	do { // show menu to user to interact with until they wish to quit
		
		cout << "*************Menu****************" << endl; // menu followed by options
		cout << "1. Search for an item" << endl;
		cout << "2. Print item frequency list" << endl;
		cout << "3. Print item frequency histogram" << endl;
		cout << "4. Close Program" << endl;
		cout << "*********************************" << endl;
		cin >> option;
		switch (option) { // user's input used as options in the menu
		case 1:
			ItemSearch.searchItem(); // case 1: call search item
			break;
		case 2:
			ItemSearch.printList(); // case 2: call print list
			break;
		case 3:
			ItemSearch.printHistogram(); // case 3: print the histogram
			break;
		case 4: // case 4: quit program
			cout << "Goodbye" << endl;
			break;
		default:
			cout << "Invalid input, please pick an option from the menu (1-4)" << endl; // default if no valid input was given
		}

	} while (option != 4);
	return 0;
}
		
	
	
