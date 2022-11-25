
#pragma once

#include <iostream>
#include "Library.cpp"
#include "PublicBook.cpp"
#include "PrivateBook.cpp"
#include "Date.cpp"
#include "User.cpp"
#include "Usermanager.cpp"
 using namespace std;
 class RunApp {
 public:
     
     void user() {
         char ch;
         int num = 0;
         int op = 0;
         UserManager userManager;
         do
         {
             cout << "\t\t\t==================================================" << endl;
             cout << "\t\t\t\tAdmin Menu" << endl;
             cout << "\t\t\t1. Add New User" << endl;
             cout << "\t\t\t2. View All User" << endl;
             cout << "\t\t\t3. Edit User" << endl;
             cout << "\t\t\t4. Delete User" << endl;
             cout << "\t\t\t0. Exit" << endl;
             cout << "\t\t\tPlease Choose Option 0 - 4 :  ";
             cin >> ch;
             switch (ch)
             {
             case '1': {
                 User user;
                 user.inputUser();
                 userManager.addUser(user);
                 break;
             }
             case '2':
                 userManager.viewUser();
                 break;
             case '3': {
                 string username;
                 cout << "Enter username:";
                 cin >> username;
                 userManager.editUser(username);
                 break;
             }
             case '4': {
                 string username;
                 char question;
                  cout << "Enter username:";
                     cin >> username;
                 do
                 {
                     userManager.deleteUser(username);
                     cout << "Are you sure you want to delete this user   (y,n)";
                     cin >> question;
                
                 } while (question!='y');
                 break;
                
             }
             default:
                 cout << "\a";
             }
             cin.ignore();
             cin.get();
         } while (ch != '0');
     }
         void app() {
             int chosseopt=0;
             int count = 0;
             int menu_choice = 0;
             int search_number = 0;
             int quantity = 0;
             char title = 0;
             char chosse;
             int index = 0;
             int id = 0;

             char question;
             enum menu_name { EXIT, ADD, VIEW, SEARCH, EDIT, DELETE, SORT, SAVE, LOAD };
             char type_choice;
             enum type_name { BACK_TO_MENU = '0', PrivateBookadd = '1',PublicBookadd = '2' };
             Library library("Library STEP");
             Book* book= nullptr;
             PublicBook* publicbook = nullptr;
            PrivateBook* priavtebook = nullptr;
             do {
                 system("cls");
                 cout << "\t\t\t============================" << endl;
                 cout << " \t\t\t\t MENU   " << endl;
                 cout << "\t\t\t1. Add Book" << endl;
                 cout << "\t\t\t2. View  Book " << endl;
                 cout << "\t\t\t3. Search  Book" << endl;
                 cout << "\t\t\t4. Edit  Book" << endl;
                 cout << "\t\t\t5. Delete  Book " << endl;
                 cout << "\t\t\t7. Save Data Into File" << endl;
                 cout << "\t\t\t8. Load Data Into File" << endl;
                 cout << "\t\t\t0. Exit" << endl;
                 cout << "\t\t\t============================" << endl;
                 cout << "\t\t\tPlease Choose Option 0 - 7: ";
                 cin >> menu_choice;
                 cout << endl;
                 switch (menu_choice) {
                 case menu_name::ADD:
                     do {
                         system("cls");
                         cout << "\t\t\t==========================" << endl;
                         cout << " \t\t\t\t Type Book" << endl;
                         cout << "\t\t\t1. Add public Book " << endl;
                         cout << "\t\t\t2. Add Private Book " << endl;
                         cout << "\t\t\t==========================" << endl;
                         cout << "\t\t\tEtner Option ? : ";
                         cin >> type_choice;
                         cout << endl;
                         switch (type_choice) {
                         case type_name::PublicBookadd: {
                          
                             cout << "======================= Add Public Book ======================" << endl;
                            publicbook= new PublicBook();
                            publicbook->inputBookPublic();
                             library.addBook(publicbook);
                            
                      
                             break;
                         }
                                            
                         case type_name::PrivateBookadd: {
                           
                             cout << "\t\t\t ================ AddPrivate Book ===================" <<endl;
                            priavtebook = new PrivateBook();
                            priavtebook->inputBookPrivate();
                            library.addBook(priavtebook);
                          
                        
                  
                             break;
                         }
                         case type_name::BACK_TO_MENU: {
                             app();
                             break;
                         }
                         default:
                             cout << "Invalid Number..." << endl;
                         }
                         cout << "\t\t\tDo you want to continue ( Y or N ) ??? : ";
                         cin >> question;
                     } while (question != 'n');
                     break;
                 case menu_name::VIEW:
                     system("cls");
                     library.viewBooklist();
                     system("pause");
                     break;
                 case menu_name::SEARCH:
                     system("cls");
                
                     int op;
                     cout << "\t\t\tEnter ID Book  to Search : ";
                     cin >> search_number;
                     cout << endl<<endl;
                     if (book = library.getBook(search_number)) {
                         book->outputBook();
                         system("pause");
                     }
                     else {
                         cout << "Search Not Found" << endl;
                         system("phuse");
                     }
                     break;
                 case menu_name ::EDIT:
                     system("cls");
                   
                     cout << "[-] Enter The room you want to Edit : ";
                     cin>>id;
                     choice_book();
                     cout << "choose your option : ";
                     cin>>chosseopt;

                     library.editBook(id, chosseopt);

                     system("cls");
                     cout << "\n[-] Result : ";
                     library.getBook(id);
                   
                     break;
                     
                 case menu_name::DELETE:
                 
                     system("cls");
                         cout << "\t\t\tEnter ID Book to Search : ";
                         cin >> search_number;
                         if (book = library.getBook(search_number)) {
                             cout << endl;
                             book->outputBook();
                         }
                         cout << endl;
                         do
                         {
                             library.deleteBook(search_number);
                             cout << "Are you sure you want to delete this book (y,n)";
                             cin >> question;
                         } while (question != 'y');
                         cout << "Book has been delete !!";
                         system("pause");
                     break;

                 case menu_name::SAVE:
                     library.write_file();
                     cout << "Save Successful" << endl;
                     break;
                 case menu_name::LOAD:
                    library.read_file();
                     cout << "Load File Successful" << endl;
                     break;
                 case menu_name::SORT:
                     system("cls");


                     cout << "[-] Result After sorting from Lower to higher Room ID :";
                     library.sort_Book_ID();
                     cout << "Rooms Have Been Sorted!!!";
                     library.viewBooklist();
                     system("pause");
                     break;

                 case menu_name::EXIT:
                     break;

                 default:
                     cout << "Invalid Number..." << endl;
                 }
             } while (menu_choice != 0);
           

         }
         void choice_book()
         {
             cout << "\t\t\t [1].Edit Id" << endl;
             cout << "\t\t\t [2].Edit quantity" << endl;
             cout << "\t\t\t [4].Edit arthor" << endl;
         }
};
  