//
// Project name : MagicEightBall
// Program name : functions.h
//
/*
	NAME: Talha Ather
	DESCRIPTION:The prupose of this program is to recreate a Magic Eight Ball with 20 intial responses.
				The program can read the responses from an external file, sort those responses, write the responses to a new file, or even add and delete responses.
				This file contains the the function headers
	STATUS: Fully running and functioning program with no issues.
	IDE: Created using Microsoft Visual Studio 2017 for Windows 10.
*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>	// Needed for using string type
#include <fstream>	// Needed for using files

using namespace std;

// Declare function prototype for requried function readResponses()
void readResponses(ifstream &infile, string responses[], string categories[], int MAXSIZE, int &size);

// Declare function prototype for requried function playMagicEightBall()
void playMagicEightBall(string responses[], string categories[], int size);

// Declare function prototype for requried function sortByResponses()
void sortByResponses(string responses[], string categories[], int size);

// Declare function prototype for requried function sortByCategories()
void sortByCategories(string responses[], string categories[], int size);

// Declare function prototype for requried function writeMagicResponses()
void writeMagicResponses(ofstream &outfile, string magicResponse[], string categories[], int currentSize);

// Declare function prototype for extra credit function deleteMagicResponse()
void deleteMagicResponse(string responses[], string categories[], int &currentSize);

// Declare function prototype for extra credit function addMagicResponse()
void addMagicResponse(string responses[], string categories[], int &currentSize, const int MAXSIZE);

#endif

