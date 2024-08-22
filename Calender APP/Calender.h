#pragma once

#include<iostream>
#include <string>
#include"utils.h"
#include "prompt.h"
#include "Checkers.h"

using namespace std;

class Calender
{
public:
	static void execute() {
		unsigned short choosenYear = prompting::prompt<unsigned short>("Please enter a year");
		cout << boolalpha << "Is " << to_string(choosenYear) << " a leap year?\t" << checkers::isALeapYear2(choosenYear) << endl;
		cout << "--------------------------------------" << endl;
		utils::detailedYearInfo(choosenYear);
		cout << "--------------------------------------" << endl;
		unsigned short choosenMonth = prompting::promptNumberBetween(1, 12, "Enter a month:");
		unsigned short monthDaysNum = utils::numOfDaysInAMonth(choosenMonth, choosenYear);
		cout << "Month " + utils::months[choosenMonth - 1] << " has:";
		cout << to_string(monthDaysNum) << " days" << endl;
		cout << "--------------------------------------" << endl;
		unsigned short choosenDay = prompting::promptNumberBetween(1, monthDaysNum, "Enter a day:");
		cout << setw(20) << left << "date" << setw(15)
			<< ": " + to_string(choosenDay) + "/" + to_string(choosenMonth) + "/" + to_string(choosenYear) << endl;
		unsigned short dayIndex = utils::generateDayIndex(choosenDay, choosenMonth, choosenYear);
		cout << setw(20) << left << "Day order" << setw(15) << ": " + to_string(dayIndex + 1) << endl;
		cout << setw(20) << left << "Day name" << setw(15) << ": " + utils::generateDay(dayIndex) << endl;
		cout << "--------------------------------------" << endl;
		utils::printMonthCal(choosenMonth, choosenYear);
		cout << "--------------------------------------" << endl;
		utils::printYearCal(choosenYear);
		cout << "--------------------------------------" << endl;
		utils::howManyDaysLeftThisYear(monthDaysNum, choosenDay, choosenMonth, choosenYear);
	}

};