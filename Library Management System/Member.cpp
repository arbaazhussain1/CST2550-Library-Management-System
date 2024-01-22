// The Library Management System for the Member.cpp file.

// The derived class from Person, here the class will inherit/add the members of the Person class directly.

#include "Member.h" // Include the header file of the Member class.

// The constructor of the Member object that is using in the Person class itself.
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
    return booksLoaned; // Return a reference to the list of books borrowed by the member.
}

// Mutator methods: for to updating information.
void Member::setMemberID(int newMemberID) {
    memberID = newMemberID; // Set a new member ID for the member.
}

void Member::setBooksBorrowed(const Book& book) {
    booksLoaned.push_back(book); // Add a book to the list of books borrowed by the member.
}
// Function to get a reference to the Member list in the Library Management System.
std::vector<Member> &Memberlist(){
    static std::vector<Member> memberList;
    return memberList;
}

