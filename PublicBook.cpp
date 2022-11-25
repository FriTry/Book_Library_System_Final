#pragma once
#include<iostream>
#include"Book.cpp"
using namespace std;
class PublicBook :public Book
{

public:
	PublicBook() :Book() {}
	PublicBook( int id, string title, string arthor, string category, int quantity, int day, int month, int year,string type)
		:Book(id, title, arthor, category, quantity, day, month, year,type) {}
	
	void inputBookPublic()
	{
		Book::intputBook();
	}
	void outputBookPublic()
	{
		 Book::outputBook();
	}
};