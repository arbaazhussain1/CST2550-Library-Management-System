#ifndef LIBRARIAN_H
#define LIBRARIAN_H


#include <string>
#include <iostream>
#include <vector>

#include "Member.h"
#include "Person.h"




class Librarian: public Person{
private:
    int staffID;
    int salary;

public:
//    // Constructors
    Librarian(int staffID, int salary, const std::string name, const std::string address, const std::string email);

    // Accessor methods
    int getStaffID() const;
    int getSalary() const;

    // Mutator methods
    void setStaffID(int staffID);
    void setSalary(int salary);

    // Other member functions
    void addMember();
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    void displayBorrowedBooks(int memberID);
    void calcFine(int memberID);

    void printLibrarianInfo();
    void displayMemberDetails(const Member &member);
    Book* findBookInSystem(int bookID);
    Member* findMemberInSystem(int memberID);
};

extern Librarian Arbaaz;



#endif //LIBRARIAN_H
