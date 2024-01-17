#ifndef LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H
#define LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H

#include <string>
#include "Person.h"
#include <vector>
#include "Book.h"


class Member: public Person {
private:
    int memberID;
    std::string name;
    std::string address;
    std::string email;
    std::vector<Book> booksLoaned;

public:
//    Member(int memberID, const std::string& name, const std::string& address, const std::string& email);

    // Accessor methods
    int getMemberID() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;
    const std::vector<Book>& getBooksBorrowed() const;

    // Mutator methods
    void setMemberID(int newMemberID);
    void setName(const std::string newName);
    void setAddress(const std::string newAddress);
    void setEmail(const std::string newEmail);
    void setBooksBorrowed(const Book& book);
};

#endif // LIBRARY_MANAGEMENT_SYSTEM_MEMBER_H
