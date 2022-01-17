//
// Project name : MagicEightBall
// Program name : main.cpp
//
/*
	NAME: Talha Ather
	DESCRIPTION:The prupose of this program is to recreate a Magic Eight Ball with 20 intial responses.
				The program can read the responses from an external file, sort those responses, write the responses to a new file, or even add and delete responses.
				This file contains the main() scope.
	STATUS: Fully running and functioning program with no issues.
	IDE: Created using Microsoft Visual Studio 2017 for Windows 10.
*/
// #include "pch.h"		// Needed for compilation to succeed in Visual Studio 2017
#include <iostream>     // Needed for using cin/cout statments
#include <string>       // Needed for using string type
#include <fstream>      // Needed for using files
#include "functions.h"	// Needed to use the header file containing the function prototypes

using namespace std;

int main() { // Start of the main scope
	string choice; // Declare space in memory for char choice for the menu options.

	const int MAXSIZE = 10000;		// Declare const MAXSIZE = 10000. This a variable that limits the maximum number of occurences the arrays may contain
	int currentSize = 0;			// Declare int currentSize = 0. This variable will be passed as a reference to the readResponses and will be updated with the number of the records that the file contains.
	string responses[MAXSIZE];		// Declare string responses[MAXSIZE] with the number of elements equal to MAXSIZE
	string categories[MAXSIZE];		// Declare string categories[MAXSIZE] with the number of elements equal to MAXSIZE

	ifstream infile;	// Declare input file stream (ifstream) infile to be able to read a file
	ofstream outfile;	// Declare output file stream (ofstream) outfile to be able to write to a file


	do { //Start of the posttest loop for the menu.
		cout << "Magic Eight Ball!" << endl; // Display a menu that says "Magic Eight Ball!"

		// Display the eight options for the menu on the screen: "A. Read responses from a file",  "B. Play Magic Eight Ball", "C. Sort by responses", "D. Sort by categories", "E. Write responses to a file", "F. Delete response", "G. Add response " , and "H. Exit"
		cout << "A. Read responses from a file" << endl
			<< "B. Play Magic Eight Ball" << endl
			<< "C. Sort by responses" << endl
			<< "D. Sort by categories" << endl
			<< "E. Write responses to a file" << endl
			<< "F. Delete response" << endl
			<< "G. Add response " << endl
			<< "H. Exit" << endl;

		cout << "Pick an option:" << endl;	// Display a message on the screen that says, "Pick an option:"
		cin >> choice;						// Wait for the user to enter their choice. Once an input is entered, store data in memory named choice. 
		cin.ignore();						// Ignore the newline after the user enters their choice for the menu.

		if (choice == "A" || choice == "a") { // Start of the if statment for the option "Read responses from a file"
			readResponses(infile, responses, categories, MAXSIZE, currentSize);	// Call function readResponses(with the information infile, responses, categories, MAXSIZE, and currentSize) to read responses from a file.
		} // End of the if statment
		else if (choice == "B" || choice == "b") { // Start of the else if statment for the option "Play Magic Eight Ball"
			if (currentSize > 0) { // Start of the if statment that checks if the user selected choice A to read responses from a file.
				playMagicEightBall(responses, categories, currentSize); // Call function playMagicEightBall(with the information responses, categories, and currentSize) to read responses from a file.
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice A to read responses before selecting choice B." << endl;	// Display a message on the screen that says, "Please choose choice A to read responses before selecting choice B."
				cout << endl;																			// Display a blank line
			} // End of the else statment
		} // End of the else if statment
		else if (choice == "C" || choice == "c") {	// Start of the else if statment for the option "Sort by responses"
			if (currentSize > 0) { // Start of the if statment that checks if the user selected choice A to read responses from a file.
				sortByResponses(responses, categories, currentSize); // Call function sortByResponses(with the information responses, categories, and currentSize) to sort the responses in Alphabetical Order
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice A to read responses before selecting choice C." << endl;	// Display a message on the screen that says, "Please choose choice A to read responses before selecting choice C."
				cout << endl;																			// Display a blank line
			} // End of the else statment
		} // End of the else if statment
		else if (choice == "D" || choice == "d") { // Start of the else if statment for the option "Sort by categories"
			if (currentSize > 0) { // Start of the if statment that checks if the user selected choice A to read responses from a file.
				sortByCategories(responses, categories, currentSize); // Call function sortByCategories(with the information responses, categories, and currentSize) to sort the categories in Alphabetical Order
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice A to read responses before selecting choice D." << endl;	// Display a message on the screen that says, "Please choose choice A to read responses before selecting choice D."
				cout << endl;																			// Display a blank line
			} // End of the else statment
		} // End of the else if statment
		else if (choice == "E" || choice == "e") {// Start of the else if statment for the option "Write responses to a file"
			if (currentSize > 0) {	// Start of the if statment that checks if the user selected choice A to read responses from a file.
				writeMagicResponses(outfile, responses, categories, currentSize); // Call function writeMagicResponses(with the information outfile, responses, categories, and currentSize) to write responses and categories to a file
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice A to read responses before selecting choice E." << endl;	// Display a message on the screen that says, "Please choose choice A to read responses before selecting choice E."
				cout << endl;																			// Display a blank line
			} // End of the else statment
		} // End of the else if statment
		else if (choice == "F" || choice == "f") {// Start of the else if statment for the option "Delete response"
			if (currentSize > 0) {	// Start of the if statment that checks if the user selected choice A to read responses from a file.
				deleteMagicResponse(responses, categories, currentSize); // Call function deleteMagicResponse(with the information responses, categories, and currentSize) to delete a response
			} // End of the if statment 
			else { // Start of the scope for the else statement
				cout << "Please choose choice A to read responses before selecting choice F." << endl;	// Display a message on the screen that says, "Please choose choice A to read responses before selecting choice F."
				cout << endl;																			// Display a blank line
			} // End of the else statment
		} // End of the else if statment
		else if (choice == "G" || choice == "g") {// Start of the else if statment for the option "Add response"
			if (currentSize > 0) {	// Start of the if statment that checks if the user selected choice A to read responses from a file.
				addMagicResponse(responses, categories, currentSize, MAXSIZE); // Call function addMagicResponse(with the information responses, categories, currentSize, and MAXSIZE) to add a response
			} // End of the if statment
			else { // Start of the scope for the else statement
				cout << "Please choose choice A to read responses before selecting choice G." << endl;	// Display a message on the screen that says, "Please choose choice A to read responses before selecting choice G."
				cout << endl;																			// Display a blank line
			} // End of the else statment
		} // End of the else if statment
		else if (choice == "H" || choice == "h") { // Start of the else if statment for the option "Exit"
			cout << "Goodbye!"; // Display a message on the screen that says, "Goodbye!".
		} // End of the else if statment
		else { // Start of the scope for the else statement that gives an error message if the user enters an invalid menu choice.
			cout << "Please pick a valid choice." << endl;  // Display a message on the screen that says, "Please pick a valid choice." 
			cout << endl;									// Display a blank line
		} // End of the else statment
	} while (choice != "H" && choice != "h"); // Stay in the posttest loop until the user selects choice H. Exit and wants to quit the program.
	return 0;
} // End of the main scope
