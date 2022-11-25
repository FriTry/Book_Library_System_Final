#pragma once
#include<iostream>
#include"Book.cpp"
using namespace std;
class PrivateBook :public Book
{

public:
	PrivateBook() :Book() {}
	PrivateBook( int id, string title, string arthor, string category, int quantity, int day, int month, int year,string type)
		: Book(id, title, arthor, category, quantity, day, month, year,type ){}
	~PrivateBook() {}
	void inputBookPrivate()
	{
		Book::intputBook();
		cout << endl;
	}
	void outputBookprivate()
	{
		Book::outputBook();
		cout << endl;
	}
};