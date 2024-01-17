#include "Person.h"
#include "Member.h"

// Constructor
Member::Member(int memberID, const std::string& name, const std::string& address, const std::string& email)
     : memberID(memberID), booksLoaned() {
    setName(name);
    setAddress(address);
    setEmail(email);
}
// Accessor methods
int Member::getMemberID() const {
    return memberID;
}

const std::vector<Book>& Member::getBooksBorrowed() const {
    return booksLoaned;
}

// Mutator methods
void Member::setMemberID(int newMemberID) {
    memberID = newMemberID;
}

void Member::setBooksBorrowed(const Book& book) {
    booksLoaned.push_back(book);
}
