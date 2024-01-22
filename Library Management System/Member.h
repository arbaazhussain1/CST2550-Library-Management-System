// The Library Management System for the Member.h header file.
#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include "Person.h"
#include <vector>

#include "Book.h"
#include "Person.h"

// Declaration of the Member class, representing its methods, identifiers & variables within the in the Library Management System.
class Member: public Person {
private:
    int memberID;   // A unique identifier for the memberID.
    std::vector<Book> booksLoaned;  // List of books currently loaned by the member.

public:
    // Constructor
    Member(int memberID, const std::string& name, const std::string& address, const std::string& email);

    // Accessor methods for Retrieving information.
    int getMemberID() const; // Get the member's unique identifier.
    const std::vector<Book>& getBooksBorrowed() const;  // Get the list of books borrowed by the member.

    std::vector<Book>& getBooksBorrowedWithSystem(); // Get a non-const reference to the list of borrowed books for modification in the system.

    // Mutator methods for to updating information.
    void setMemberID(int newMemberID); // Set a new member ID for the member.
    void setBooksBorrowed(const Book& book); // Add a book to the list of books borrowed by the member.
};
// A function to get reference to the Member list in the Library Management System.
std::vector<Member> &Memberlist();


#endif // MEMBER_H
