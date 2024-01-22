#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include "Person.h"
#include <vector>
#include "Book.h"


class Member: public Person {
private:
    int memberID;
    std::vector<Book> booksLoaned;

public:
    Member(int memberID, const std::string& name, const std::string& address, const std::string& email);

    // Accessor methods
    int getMemberID() const;
    const std::vector<Book>& getBooksBorrowed() const;

    std::vector<Book>& getBooksBorrowedReference();

    // Mutator methods
    void setMemberID(int newMemberID);
    void setBooksBorrowed(const Book& book);
};

std::vector<Member> &Memberlist();


#endif // LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H
