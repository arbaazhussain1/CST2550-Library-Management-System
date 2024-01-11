#include "Member.h"

// Constructor
Member::Member(int memberID, const std::string& name, const std::string& address, const std::string& email)
        : memberID(memberID), name(name), address(address), email(email) {}

// Accessor methods
int Member::getMemberID() const {
    return memberID;
}

std::string Member::getName() const {
    return name;
}

std::string Member::getAddress() const {
    return address;
}

std::string Member::getEmail() const {
    return email;
}

const std::vector<Book>& Member::getBooksBorrowed() const {
    return booksLoaned;
}

// Mutator methods
void Member::setMemberID(int newMemberID) {
    memberID = newMemberID;
}

void Member::setName(const std::string& newName) {
    name = newName;
}

void Member::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void Member::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void Member::setBooksBorrowed(const Book& book) {
    booksLoaned.push_back(book);
}
