// The Library Management System for the Member.cpp file.

#include "Member.h" // Include the header file of the Member class.

// Constructor
Member::Member(int memberID, const std::string& name, const std::string& address, const std::string& email)
        : memberID(memberID), booksLoaned() {
    setName(name);
    setAddress(address);
    setEmail(email);
}
// Accessor methods: for Retrieving information.
int Member::getMemberID() const {
    return memberID; // Return the member's unique identifier.
}

const std::vector<Book>& Member::getBooksBorrowed() const {
    return booksLoaned; // Return the list of books borrowed by the member.
}

std::vector<Book>& Member::getBooksBorrowedWithSystem(){
    return booksLoaned;
}

// Mutator methods: for to updating information.
void Member::setMemberID(int newMemberID) {
    memberID = newMemberID;
}

void Member::setBooksBorrowed(const Book& book) {
    booksLoaned.push_back(book);
}

std::vector<Member> &Memberlist(){
    static std::vector<Member> memberList;
    return memberList;
}

