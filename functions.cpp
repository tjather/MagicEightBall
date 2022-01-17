//
// Project name : MagicEightBall
// Program name : functions.cpp
//
/*
	NAME: Talha Ather
	DESCRIPTION:The prupose of this program is to recreate a Magic Eight Ball with 20 intial responses.
				The program can read the responses from an external file, sort those responses, write the responses to a new file, or even add and delete responses.
				This file contains the the function definitions and algorithms
	STATUS: Fully running and functioning program with no issues.
	IDE: Created using Microsoft Visual Studio 2017 for Windows 10.
*/
// #include "pch.h"		// Needed for compilation to succeed in Visual Studio 2017
#include <iostream>     // Needed for using cin/cout statments
#include <string>       // Needed for using string type
#include <fstream>      // Needed for using files
#include <cstdlib>		// Needed for using random numbers
#include <ctime>		// Needed for access to system time
#include "functions.h"	// Needed to use the header file containing the function prototypes

using namespace std;

void readResponses(ifstream &infile, string responses[], string categories[], int MAXSIZE, int &size) {
	int index = 0;				// Declare space in memory for an int variable called index and assign the number 0 to it.
	string answer, category;	// Declare string answer and category to hold the data that is read from the file.

	infile.open("magicball.txt"); // Open magicball.txt

	cout << "Now opening magicball.txt and reading the content. Press any key to continue:" << endl; // Display a message on the screen that says, "Now opening magicball.txt. Press any key to continue:"

	cin.get();		// Wait for the user to press any key

	if (!infile.is_open()) {
		cout << "Unable to open magicball.txt" << endl; // Display a message on the screen that says, "Unable to open magicball.txt"
	}
	else {
		while (!infile.eof()) { // Start of the scope of a while loop to read from the beginning of the file to the end of the file
			getline(infile, answer);	// Read line 1 and assign it to answer
			getline(infile, category);	// Read line 2 and assign it to category

			responses[index] = answer;		// Assign responses[index] with string answer
			categories[index] = category;	// Assign categories[index] with string area

			index++; // Add 1 to int index
		} // End of the scope of the loop
		size = index; // Assign int index to int size

		infile.close(); // Close magicball.txt

		for (int i = 0; i < size; i++) { // Start of a for loop to read all the responses and their coresponding category
			cout << responses[i] << endl << categories[i] << endl; // Display a message on the screen that reads the response and the category at index i.
		} // End of the for scope
	}
	cout << endl; // Display a blank line
}

void playMagicEightBall(string responses[], string categories[], int size) {
	string userQuestion = ""; // Declare space in memory for string userQuestion
	int randomNumber = 0;	 // Declare space in memory for int randomNumber

	while (userQuestion != "Quit" && userQuestion != "quit") { // Start of the while loop that goes untill the user says "Quit" or "quit" and wants to stop playing.
		cout << "Please ask the Magic Eight Ball any question that you want answered. Say \"Quit\" or \"quit\" to stop." << endl; // Display a message on the screen that says, "Please ask the Magic Eight Ball any question that you want answered. Say \"Quit\" or \"quit\" to stop."

		getline(cin, userQuestion); // Wait for the user to enter a response. Once an input is entered, take the whole line and store data in memory named userQuestion.
		if (userQuestion != "Quit" && userQuestion != "quit") {
			srand(time(0));					// Use the current time as a seed for the random number generator to get diffrent results each time the function is run.
			randomNumber = rand() % size;	// Generate a random number from 0 to int size - 1. Once a number is generated, store data in memory named randomNumber.

			cout << responses[randomNumber] << endl;							// Display a message on the screen that contains the answer in responses[at index randomNumber].
			cout << "This response was " << categories[randomNumber] << endl;	// Display a mesage one the screen that says "This response was " then the answer in categories[at index randomNumber]
		}
		cout << endl; // Display a blank line
	} // End of the pretest loop
}

void sortByResponses(string responses[], string categories[], int size) {
	bool swap;							// Declare bool swap
	int responseIndex;					// Declare int responseIndex
	string responseTemp, categoryTemp;  // Declare string responseTemp and categoryTemp

	cout << "Now sorting by responses and reading the sorted answers. Press any key to continue:" << endl; // Display a message on the screen that says, "Now sorting by responses and reading the sorted answers. Press any key to continue:"

	cin.get(); // Wait for the user to press any key

	do { // Start of the posttest loop to sort by categories
		swap = false; // Initialize bool swap with false
		for (responseIndex = 0; responseIndex < (size - 1); responseIndex++) { // Start of the for loop that checks every response.
			if (responses[responseIndex] > responses[responseIndex + 1]) { // Start of the if statment that compares categories[categoryIndex] to the category at categoryIndex plus one to see if categories[categoryIndex] is larger
				responseTemp = responses[responseIndex];					// Assign responses[responseIndex] to responseTemp
				responses[responseIndex] = responses[responseIndex + 1];	// Assign responses[responseIndex] with the string responses[responseIndex + 1]
				responses[responseIndex + 1] = responseTemp;				// Assign responses[responseIndex + 1] with the string in responseTemp

				categoryTemp = categories[responseIndex];					// Assign categories[responseIndex] to categoryTemp
				categories[responseIndex] = categories[responseIndex + 1];	// Assign categories[responseIndex] with the string categories[responseIndex + 1]
				categories[responseIndex + 1] = categoryTemp;				// Assign categories[responseIndex + 1] with the string in categoryTemp

				swap = true; // Set bool swap to true
			} // End of if statment
		} // End of the for scope
	} while (swap); // Stay in the posttest loop until bool swap is false

	for (int i = 0; i < size; i++) { // Start of a for loop to read all the sorted responses and their coresponding category
		cout << responses[i] << endl << categories[i] << endl; // Display a message on the screen that reads the response and the category at index i.
	} // End of the for scope
	cout << endl; // Display a blank line
}

void sortByCategories(string responses[], string categories[], int size) {
	bool swap;							// Declare bool swap
	int categoryIndex;					// Declare int categoryIndex
	string responseTemp, categoryTemp;  // Declare string responseTemp and categoryTemp

	cout << "Now sorting by categories and reading the sorted answers. Press any key to continue:" << endl; // Display a message on the screen that says, "Now sorting by categories and reading the sorted answers. Press any key to continue:"

	cin.get(); // Wait for the user to press any key

	do { // Start of the posttest loop to sort by categories
		swap = false; // Initialize bool swap with false
		for (categoryIndex = 0; categoryIndex < (size - 1); categoryIndex++) { // Start of the for loop that checks every category.
			if (categories[categoryIndex] > categories[categoryIndex + 1]) { // Start of the if statment that compares categories[categoryIndex] to the category at categoryIndex plus one to see if categories[categoryIndex] is larger
				responseTemp = responses[categoryIndex];					// Assign responses[categoryIndex] to responseTemp
				responses[categoryIndex] = responses[categoryIndex + 1];	// Assign responses[categoryIndex] with the string responses[categoryIndex + 1]
				responses[categoryIndex + 1] = responseTemp;				// Assign responses[categoryIndex + 1] with the string in responseTemp

				categoryTemp = categories[categoryIndex];					// Assign categories[categoryIndex] to categoryTemp
				categories[categoryIndex] = categories[categoryIndex + 1];	// Assign categories[categoryIndex] with the string categories[categoryIndex + 1]
				categories[categoryIndex + 1] = categoryTemp;				// Assign categories[categoryIndex + 1] with the string in categoryTemp

				swap = true; // Set bool swap to true
			} // End of if statment
		} // End of the for scope
	} while (swap); // Stay in the posttest loop until bool swap is false

	for (int i = 0; i < size; i++) { // Start of a for loop to read all the sorted categories and their coresponding response
		cout << responses[i] << endl << categories[i] << endl; // Display a message on the screen that reads the response and the category at index i.
	} // End of the for scope
	cout << endl; // Display a blank line
}

void writeMagicResponses(ofstream &outfile, string magicResponse[], string categories[], int currentSize) {
	int i; // Declare int i

	outfile.open("MagicBallResponses.txt"); // Create and open MagicBallResponses.txt

	cout << "Now creating MagicBallResponses.txt and writing the responses and categories to it. Press any key to continue:" << endl; // Display a message on the screen that says, "Now creating MagicBallResponses.txt and writing the responses and categories to it. Press any key to continue:"

	cin.get();		// Wait for the user to press any key

	for (i = 0; i < currentSize; i++) { // Start of a for loop to read all the responses and their coresponding category
		outfile << magicResponse[i] << endl << categories[i] << endl; // Write the response and the category at index i to the file "MagicBallResponses.txt"
	} // End of the for scope

	outfile.close(); // Close MagicBallResponses.txt
}

void deleteMagicResponse(string responses[], string categories[], int &currentSize) {
	bool remove;		// Declare bool remove
	int index, choice;	// Declare int index and choice

	cout << "What response number would you like to delete? The valid numbers are 1 to " << currentSize << "." << endl; // Display a message on the screen that says, "What response number would you like to delete? The valid numbers are 1 to " currentSize
	do { // Start of the posttest loop to remove a response and the coresponding category
		cin >> choice; // Wait for the user to enter their choice. Once an input is entered, store data in memory named choice. 

		remove = true; // Set bool remove to true

		if (choice <= currentSize && choice >= 1) { // Start of the if statment that checks if the user enter a valid choice
			cout << "The response that will be deleted is \"" << responses[choice - 1] << "\"" << endl; // Display a message on the screen that says, "The response that will be deleted is "responses[at index choice]""
			cout << "This response is in the category: " << categories[choice - 1] << endl; // Display a message on the screen that says, "This response is in category " categories[at index choice]
			cout << "Press any key to continue:" << endl; // Display a message on the screen that says, "Press any key to continue:"

			cin.ignore();	// Ignore the newline after the user enters their choice
			cin.get();		// Wait for the user to press any key

			for (index = (choice - 1); index < (currentSize - 1); index++) {  // Start of the for loop that starts at the index the user entered
				responses[index] = responses[index + 1]; // Shift every response over by one to the left. This will "delete" the response the user wanted to be deleted
				categories[index] = categories[index + 1]; // Shift every category over by one to the left. This will "delete" the category relating to the response the user wanted to be deleted
			} // End of the for scope

			currentSize = currentSize - 1; // Subtract 1 from currentSize because a response and category was deleted

			for (int i = 0; i < currentSize; i++) { // Start of a for loop to read all the remaining responses and their coresponding category
				cout << responses[i] << endl << categories[i] << endl; // Display a message on the screen that reads the response and the category at index i.
			} // End of the for scope

			remove = false; // Set bool remove to false
		} // End of the if statment
		else { // Start of the scope for the else statement that gives an error message if the user enters an invalid index number.
			cout << "Please enter a number between 1 and " << currentSize << "." << endl; // Display a message on the screen that says, "Please enter a number between 1 and " currentSize
		} // End of the else statment
	} while (remove); // Stay in the posttest loop until bool remove is false
	cout << endl; // Display a blank line
}

void addMagicResponse(string responses[], string categories[], int &currentSize, const int MAXSIZE) {
	string newResponse, newCategory;
	if (currentSize < MAXSIZE) {
		cout << "Enter the new response that you would like to add:" << endl; // Display a message on the screen that says, "Enter the new response you would like to add:"
		getline(cin, newResponse);											  // Wait for the user to enter their choice. Once an input is entered, take the whole line and store data in memory named newResponse.
		newResponse.at(0) = toupper(newResponse.at(0));						  // Change the first letter of the string to uppercase to make sure it can be sorted properly

		cout << "Enter the category that this new response be in:" << endl; // Display a message on the screen that says, "Enter the new response you would like to add:"
		getline(cin, newCategory);											// Wait for the user to enter their choice. Once an input is entered, take the whole line and store data in memory named newCategory.
		newCategory.at(0) = tolower(newCategory.at(0));						// Change the first letter of the string to lowercase to make sure it can be sorted properly

		responses[currentSize] = newResponse;  // Assign the next avalible response array index with the data in newResponse
		categories[currentSize] = newCategory; // Assign the next avalible category array index with the data in newCategory

		currentSize = currentSize + 1; // Add 1 to currentSize because a new response and category was added

		for (int i = 0; i < currentSize; i++) { // Start of a for loop to read all the responses and their coresponding category
			cout << responses[i] << endl << categories[i] << endl; // Display a message on the screen that reads the response and the category at index i.
		} // End of the for scope
	}
	else {
		cout << "There is no room left in the array to add a new response." << endl; // Display a message on the screen that says, "There is no room left in the array to add a new response."
	}
	cout << endl; // Display a blank line
}


