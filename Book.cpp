#pragma once
#include<iostream>
#include<iomanip>
#include"Date.cpp"
#include <iomanip>
using namespace std;
class Book :public Date
{
private:
	int id;
	string title;
	string arthor;
	string category;
	int quantity;
	string type;
public:
	Book() :Date(), id(0), title("unkknow"), arthor("unkknow"), category("unkknow"), quantity(0),type("unknow") {}
	Book(int id, string title, string arthor, string category, int quantity, int day, int month, int year,string type) :Date(day, month, year), id(id), title(title), arthor(arthor), category(category), quantity(quantity) ,type(type) {}
	~Book() {}
	void set_id(int id)
	{
		this->id = id;
	}
	int  get_id()
	{
		return id;
	}
	void set_title(string name)
	{
		this->title = title;

	}
	string get_title()
	{
		return title;

	}
	void set_arthor(string arthor)
	{
		this->arthor = arthor;
	}
	string get_arthor()
	{
		return arthor;
	}
	void set_category(string category)
	{
		this->category = category;
	}
	string  get_category()
	{
		return category;
	}
	void set_quantity(int quantity)
	{
		this->quantity = quantity;
	}
	int get_quantity()
	{
		return quantity;
	}
	void set_type(string type)
	{
		this->type = type;
	}
	string get_type()
	{
		return type;
	}
	virtual void intputBook()
	{

		cout << "\t\t\tEnter ID : "; cin >> id;
		cout << "\t\t\tEnter Title : "; cin >> title;
		cout << "\t\t\tEnter Arthor : "; cin >> arthor;
		cout << "\t\t\tEnter Category : "; cin >> category;
		cout << "\t\t\tEtner Quantity : "; cin >> quantity;
		cout << "\t\t\t Enter type :"; cin >> type;
		Date::inputDate();
		cout << endl;

	}
	virtual	void  outputBook()
	{
		cout << "\t\t\tID : " << id << endl;
		cout << "\t\t\tTitle : " << title << endl;
		cout << "\t\t\tArhor : " << arthor << endl;
		cout << "\t\t\tCategory : " << category << endl;
		cout << "\t\t\tQuantity : " << quantity << endl;
		cout << "\t\t\t type : " << type << endl;
		cout << "\t\t\tDate : "; Date::outputDate();
		cout << endl;

	}
	virtual void outputBookList()
	{
		cout << "\nId: \t" << id << "\n";
		for (int i = 80; i > 0; i--)

			cout << '-';

		cout << "\ntitle: \t" << title << "\tArthor: "

			<< arthor << "\tCategory : " << category

			<< "\nQuantity: " << quantity << "\tDate : \t";Date::outputDate();
		cout << "Type :"<<type;
			cout << "\n\n";
		for (int i = 80; i > 0; i--)

		{ 
			cout << '-';
		}
		cout << endl;
			
	}
};