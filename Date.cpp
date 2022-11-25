#pragma once
#include<iostream>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date() :day(0), month(0), year(0) {}
	Date(int day, int month, int year) :day(day), month(month), year(year) {}
	~Date() {}
	void set_day(int day)
	{
		this->day = day;
	}
	int get_day()
	{
		return day;
	}
	void set_month(int month)
	{
		this->month = month;
	}
	int get_month()
	{
		return month;
	}
	void set_year(int year)
	{
		this->year = year;
	}
	int get_year()
	{
		return year;
	}
	void inputDate()
	{

		cout << "\t\t\tEnter Day : "; cin >> day;
		cout << "\t\t\tEnter Month : "; cin >> month;
		cout << "\t\t\tEnter year : "; cin >> year;
	}
	void outputDate()
	{

		cout << day << "/" << month << "/" << year;
	}
};