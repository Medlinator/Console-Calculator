/*
* Name: Sean Medlin 
* Date: 21 Jan 2017
* Assignment: 1
* Student Number: XXXXXX
* Description: C++ console program that allows a user to enter two numbers, 
*			   followed by one of four arithmetic operators (+,-,/,*). The 
*			   program will validate all inputs are correct, otherwise kick 
*			   an error back to the user. The program then performs the 
*			   operation with the inputs given, displays a message if the 
*			   result is between one and one hundred, and then displays the 
*			   result as float and integer. Lastly, the program will ask the
*			   user for their first and last name, and then repeat it back to 
*			   them.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <istream>

using namespace std;
using std::string;


int main()
{
	int number1;
	int number2;
	int resultInt;
	float resultFloat;
	string operatorSign;
	string name = "";

	cout << "Enter the first number: ";
	cin >> number1;
	while (cin.fail()) {
		cout << "Error: Please enter a number: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> number1;
	}
	cout << "Enter the second number: ";
	cin >> number2;
	while (cin.fail()) {
		cout << "Error: Please enter a number: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> number2;
	}
	cout << "Enter the arithmetic operator (choose from +,-,/ or *): ";
	cin >> operatorSign;
	while (operatorSign != "+" && operatorSign != "-" && operatorSign != "/" && operatorSign != "*") {
		cout << "Error: Please enter one of the permitted operators (+,-,/, or *): ";
		cin >> operatorSign;
	}

	if (operatorSign == "+") {
		resultFloat = (float)number1 + number2;
		resultInt = (int)number1 + (int)number2;
	}
	else if (operatorSign == "-") {
		resultFloat = (float)number1 - number2;
		resultInt = (int)number1 - (int)number2;
	}
	else if (operatorSign == "/") {
		resultFloat = (float)number1 / number2;
		resultInt = (int)number1 / (int)number2;
	}
	else if (operatorSign == "*") {
		resultFloat = (float)number1 * number2;
		resultInt = (int)number1 * (int)number2;
	}

	cout << fixed << setprecision(2) << resultFloat << endl;
	cout << resultInt << endl;

	if (resultInt > 1 && resultInt < 100) {
		cout << "Your result is between 1 and 100!" << endl;
	}

	cin.ignore(100, '\n');
	cout << "Enter your first and last name (with a space in between): ";
	getline(cin, name);
	transform(name.begin(), name.end(), name.begin(), toupper);
	/* 
		The instructions in the pdf were a bit unclear on this next part. 
	    I wasn't sure if I was to display the captured name or my actual name, so I did both.
	*/
	cout << "This program was written by " << name << endl;
	cout << "This program was written by SEAN MEDLIN" << endl;
}

