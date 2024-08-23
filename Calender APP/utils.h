#pragma once

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include"Checkers.h"
#include "prompt.h"

using namespace std;

namespace utils {
	string months[13] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug","Sep","Oct","Nov","Dec" };
	string days[7] = { "Sunday", "Monday", "Tuesday","Wednesday","Thursday","Friday","Saturday" };
	template<size_t N> void logInfo(string(&arr)[N]) {
		for (size_t i = 0; i < N - 1; i++)
		{
			cout << setw(15) << left << arr[i];
		}
		cout << arr[N - 1] << endl;
	}
	template<size_t N, size_t L> void logInfo(unsigned short(&arr)[N][L]) {
		for (size_t i = 0; i < N; i++)
		{
			for (size_t k = 0; k < L; k++)
			{
				if (arr[i][k] == 0) cout << setw(15) << left << " ";
				else cout << setw(15) << left << to_string(arr[i][k]);
			}
			cout << endl;
		}
	}

	unsigned short calcNumOfDaysPerYear(unsigned short const& year) {
		return checkers::isALeapYear2(year) ? 366 : 365;
	}
	void detailedYearInfo(unsigned short const& year) {
		unsigned short DAYS_PER_YEAR = calcNumOfDaysPerYear(year);
		const unsigned short HOURS_PER_DAY = 24;
		const unsigned short MINS_PER_HOUR = 60;
		const unsigned short SECS_PER_MIN = 60;
		cout << setw(25) << left << "Number of days =" << setw(15) << to_string(DAYS_PER_YEAR) << endl;
		cout << setw(25) << left << "Number of hours =" << setw(15) << to_string(DAYS_PER_YEAR * HOURS_PER_DAY) << endl;
		cout << setw(25) << left << "Number of minutes =" << setw(15) << to_string(DAYS_PER_YEAR * HOURS_PER_DAY * MINS_PER_HOUR) << endl;
		cout << setw(25) << left << "Number of seconds =" << setw(15) << to_string(DAYS_PER_YEAR * HOURS_PER_DAY * MINS_PER_HOUR * SECS_PER_MIN) << endl;
	}
	unsigned short numOfDaysInAMonth(unsigned short const& choosenMonth, unsigned short const& year) {
		//unsigned short monthsWithDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		unsigned short monthDays = checkers::isALeapYear(year) && choosenMonth == 2 ? 29
			: choosenMonth == 2 ? 28
			: choosenMonth < 8 && choosenMonth % 2 == 0 ? 30
			: choosenMonth < 8 && choosenMonth % 2 != 0 ? 31
			: choosenMonth >= 8 && choosenMonth % 2 == 0 ? 31
			: 30;
		return  monthDays;
		//if (checkers::isALeapYear2(year) && choosenMonth == 2)return 29;
		//else if (!checkers::isALeapYear2(year) && choosenMonth == 2) return 28;
		//if (checkers::checkIfItemInCollection<unsigned short>(choosenMonth, monthsWith31Days))
		//	return 31;		
		//return 30;
	}
	unsigned short generateDayIndex(short day, short month, unsigned short year) {
		short a = (14 - month) / 12;
		year = year - a;
		month = month + 12 * a - 2;
		day = (day + year + (year / 4) - (year / 100) + (year / 400) + (31 * month / 12)) % 7;
		return day;
	}
	string generateDay(unsigned short const& dayIndex) {
		return days[dayIndex];
	}
	void showCalenderForMonth(short const& month, unsigned short const& year) {
		unsigned short day = 1;
		unsigned short dayIndex = generateDayIndex(day, month, year);
		unsigned short numOfMonthDays = numOfDaysInAMonth(month, year);
		unsigned short arr[5][7];
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t k = 0; k < 7; k++)
			{
				if (day > numOfMonthDays) arr[i][k] = 0;
				else if (dayIndex == k)
				{
					arr[i][k] = day;
					dayIndex++;
					day++;
				}
				else arr[i][k] = 0;
			}
			dayIndex = 0;
		}
		logInfo(days);
		logInfo<5, 7>(arr);
	}
	void printMonthCal(unsigned short const& choosenMonth, unsigned short const& choosenYear) {
		bool printMonthCalender = prompting::promptYesOrNo("Do you want to get calender for this month? y/n");
		if (printMonthCalender)
		{
			cout << '\t' << "Calender for month " << utils::months[choosenMonth - 1] << endl;
			utils::showCalenderForMonth(choosenMonth, choosenYear);
		}
	}
	void printYearCal(unsigned short const& choosenYear) {
		bool printYearCalender = prompting::promptYesOrNo("Do you want to get calender for this year? y/n");
		if (printYearCalender)
		{
			for (size_t i = 0; i < 12; i++)
			{
				cout << '\t' << "Calender for month " << utils::months[i] << endl;
				cout << "\t-------------------" << endl;
				utils::showCalenderForMonth(i + 1, choosenYear);
				cout << "\t-------------------" << endl;
			}
		}
	}
	void howManyDaysLeftThisYear(unsigned short const& monthDaysNum, unsigned short const& choosenDay, unsigned short const& choosenMonth, unsigned short const& choosenYear) {
		bool printHowManyDays = prompting::promptYesOrNo("Do you want to get how many days info? y/n");
		unsigned short totalDaysTillThisDay = 0;
		if (printHowManyDays)
		{
			for (size_t i = 1; i < choosenMonth; i++)
			{
				totalDaysTillThisDay += utils::numOfDaysInAMonth(i, choosenYear);
			}
			totalDaysTillThisDay += choosenDay;
			cout << "Number of days passed from " << to_string(choosenYear) << ": " << to_string(totalDaysTillThisDay) << endl;
			cout << "Number of days left from " << to_string(choosenYear) << ": " << to_string(utils::calcNumOfDaysPerYear(choosenYear) - totalDaysTillThisDay) << endl;
		}
	}
}
