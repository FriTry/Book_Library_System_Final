#pragma once
#include<iostream>
#include"Book.cpp"
using namespace std;
class BookDAO
{
public:

    virtual  void addBook(Book* book) = 0;

    // View Book
    virtual   void viewBooklist() = 0;
    
    virtual   void viewBook() = 0;
 
    virtual  Book* getBook(int id) = 0;

    virtual  void editBook(int id, int choice) = 0;


    virtual  int findBook(int id) = 0;

    virtual  void deleteBook(int id) = 0;

   virtual void sort_Book_ID() = 0;

};