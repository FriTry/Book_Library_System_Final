#pragma once

#include <iostream>
#include "Book.cpp"
#include <fstream>
#include "PublicBook.cpp"
#include"PrivateBook.cpp"
#include "BookDAO.cpp"
using namespace std;
class Library :public BookDAO
{
private:
    string name;
    Book* books[100];
    int count = 0;
public:
    Library() : name("Null") {
        Book* book = new Book(1, "happytree", "firtry", "happy", 10, 0, 0, 0,"unknow");
        addBook(book);
    }
    Library(string name):name(name){}
   ~ Library() {

    }
    // Add Book
    void addBook(Book* book) {
        books[count] = new Book();
        books[count] = book;
        count++;
    }
    // View Book
    void viewBooklist() {
        for (int i = 0; i < count; i++) {
          books[i]->outputBookList();
        }
    }
    void viewBook() {
        for (int i = 0; i < count; i++) {
            books[i]->outputBook();
        }
    }

    // get Book by id
    int findBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i]->get_id() == id)
                return i;
        }
        return -1;
    }

   Book* getBook(int id) {
        Book* book = nullptr;
        for (int i = 0; i < count; i++) {
            if (books[i]->get_id() == id) {
                return books[i];
            }
        }
        return book;
    }
    // edit Book id
   void editBook(int book_id, int choice) {
       int id;
       int quantity;
       string arthor;
       string title;
       

       int found = findBook(book_id);
       if (found != -1) {
           if (choice == 1)
           {
               cout << "[-] Enter new Book id: ";
               cin >> id;
               books[found]->set_id(id);
           }
           else if (choice == 2)
           {
               cout << "[-] Enter new quantity book: ";
               cin >> quantity;
               books[found]->set_quantity(quantity);
           }
           else if (choice == 4)
           {
               cout << "[-] Enter new arthor :" ;
               cin >> arthor;
               books[found]->set_arthor(arthor);
           }
           else
           {
               cout << "Invalid option!!!";
            }
        }
       }

    void deleteBook(int id ) {
        int found = findBook(id);
        if (found != -1) {
            for (int i = found; i < count; i++) {
                books[i] = books[i + 1];
            }
            count--;
         
        }
        else {
            cout << "Not found" << endl;
        }
    }
   
        void sort_Book_ID() {
            for (int i = 0; i < count; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (books[j]->get_id() > books[j + 1]->get_id()) {
                        Book* temp = books[j];
                        books[j] = books[j + 1];
                        books[j + 1] = temp;
                    }
                }
            }
    }

    void write_file()
    {
       Book* book;
        ofstream outFile;
        outFile.open("book.txt", ios::binary);
        for (int i = 0; i < count; i++) {
            book = books[i];
            outFile.write(reinterpret_cast<char*> (book), sizeof(Book));
        }
        outFile.close();
    }
    void read_file()
    {
        Book book;
        bool flag = false;
        ifstream inFile;
        inFile.open("book.txt", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            return;
        }

        while (inFile.read(reinterpret_cast<char*> (&book), sizeof(Book)))
        {
            book.outputBookList();

        }
        inFile.close();
    }
};