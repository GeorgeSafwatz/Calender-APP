#pragma once

#include<iostream>
#include<string>
#include "Utils.h"
#include "Checkers.h"

using namespace std;

namespace prompting {
	template <typename T> T prompt(string promptingText) {
		T arg;
		bool invalidInput = false;
		cout << promptingText << endl;
		do
		{
			cin >> arg;
			invalidInput = false;
			if (!checkers::checkIfCinPass("Enter a valid data type"))
			{
				invalidInput = true;
			}
		} while (invalidInput);
		return arg;
	}
	bool promptYesOrNo(string promptingText) {
		char character;
		bool invalidInput = false;
		cout << promptingText << endl;
		do
		{
			cin >> character;
			invalidInput = false;
			if (!(checkers::checkIfCinPass("Enter a valid data type") && checkers::checkIfYorN(character)))
			{
				invalidInput = true;
			}
		} while (invalidInput);
		character = tolower(character);
		if (character == 'y') return true;
		return false;
	}
	string readText(string promptingText) {
		string arg;
		bool invalidInput = false;
		cout << promptingText << endl;
		do
		{
			invalidInput = false;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, arg);
			if (!checkers::checkIfCinPass("Please enter a valid data type"))	invalidInput = true;
		} while (invalidInput);
		return arg;
	}
	static unsigned short promptNumberBetween(unsigned short const& lowerLimit, unsigned short const& upperLimit, string promptingTxt) {
		unsigned short num;
		bool invalidInput = false;
		cout << promptingTxt << endl;
		do
		{
			cin >> num;
			if (!checkers::checkIfCinPass("Please enter a valid data type") || !checkers::checkIfNumberInRange(lowerLimit, upperLimit, num))
				invalidInput = true;
			else
				invalidInput = false;
		} while (invalidInput);
		return num;
	}

}