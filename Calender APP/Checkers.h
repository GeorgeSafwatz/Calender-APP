#pragma once

#include <iostream>
#include <string>
#include <cctype>

using namespace std;
namespace checkers {
	bool checkIfCinPass(string errorMsg) {
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << errorMsg << endl;
			return false;
		}
		return true;
	}
	bool checkIfNumberInRange(unsigned short const& lowerLimit, unsigned short const& upperLimit, unsigned short const& num) {
		if (num >= lowerLimit && num <= upperLimit)	return true;
		else {
			cerr << "The number should be between "
				<< to_string(lowerLimit)
				<< " and "
				<< to_string(upperLimit)
				<< endl;
			return false;
		}
	}
	bool isALeapYear(unsigned short year) {
		return year % 400 == 0 ? true : !(year % 100 == 0) && (year % 4 == 0) ? true : false;
	}
	bool isALeapYear2(unsigned short year) {
		return (year % 400 == 0) || (!(year % 100 == 0) && (year % 4 == 0));
	}
	bool checkIfYorN(char char1) {
		char1 = tolower(char1);
		if (char1 == 'y' || char1 == 'n') return true;
		cerr << "Please enter Y or N" << endl;
		return false;
	}
	template <typename T, size_t N> bool checkIfItemInCollection(T item, T(&collection)[N]) {
		for (T& i : collection)
		{
			if (i == item) return true;
		}
		return false;
	}

}