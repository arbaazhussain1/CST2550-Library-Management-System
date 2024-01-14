
#ifndef LIBRARY_MANAGEMENT_SYSTEM_LIBRARIAN_H
#define LIBRARY_MANAGEMENT_SYSTEM_LIBRARIAN_H


#include <string>
#include <iostream>
#include <vector>
#include "Member.h"




class Librarian{
private:
      int staffID;
      int salary;

public:
    // Constructors
    Librarian(); // The Default Constructor
    Librarian(int staffID, int salary, const std::string& name, const std::string& address, const std::string& email);

    // Accessor methods
    int getStaffID() const;
    int getSalary() const;

    // Mutator methods
    void setStaffID(int staffID);
    void setSalary(int salary);

    // Other member functions
    void addMember();
    void displayMemberDetails(const Member& member);
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    void displayBorrowedBooks(int memberID);
    void calcFine(int memberID);
};

std::vector<Member> Memberlist;


#endif //LIBRARY_MANAGEMENT_SYSTEM_LIBRARIAN_H
