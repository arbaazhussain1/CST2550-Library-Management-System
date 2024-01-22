// The Library Management System for the Librarian.h header file.
#ifndef LIBRARIAN_H
#define LIBRARIAN_H


#include <string>
#include <iostream>
#include <vector>

#include "Member.h"
#include "Person.h"

// Declaration of the Librarian class, representing its methods, identifiers & variables within the in the Library Management System.
class Librarian: public Person{
private:
    int staffID; // Unique identifier for the librarian.
    int salary; // Salary of the librarian.

public:
    // Constructors
    Librarian(int staffID, int salary, const std::string name, const std::string address, const std::string email);

    // Accessor methods for both StaffID & Salary.
    int getStaffID() const; // Get the librarian's staff ID.
    int getSalary() const; // Get the librarian's salary.

    // Mutator methods for both StaffID & Salary.
    void setStaffID(int staffID);  // Set a new staff ID for the librarian.
    void setSalary(int salary);    // Set a new salary for the librarian.

    // Other member functions that is used in Library Management System
    void addMember(); // Add a new member to the system.
    void issueBook(int memberID, int bookID); // Issue a book to a member.
    void returnBook(int memberID, int bookID); // Return a book from a member.
    void displayBorrowedBooks(int memberID); // Display the books borrowed by a member.
    void calcFine(int memberID, Book* bookBeingReturned); // Calculate fine for a returned book.

    void printLibrarianInfo(); // Print information about the librarian.
    void displayMemberDetails(const Member &member);  // Display details of a member.
    Book* findBookInSystem(int bookID); // Find a book in the system by its ID.
    Member* findMemberInSystem(int memberID); // Find a member in the system by their ID.

};
// Declaring the librarian Arbaaz an external variable Therefore it might be called from the main.cpp code itself.
extern Librarian Arbaaz;


#endif // LIBRARIAN_H
