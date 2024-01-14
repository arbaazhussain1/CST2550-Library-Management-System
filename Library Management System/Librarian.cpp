#include "Person.h"
#include "Librarian.h"
#include "Member.h"

int newMemberID = 001;
// Default constructor
Librarian::Librarian() {
}

// Parameterized constructor
Librarian::Librarian(int staffID, int salary, const std::string& name, const std::string& address, const std::string& email) {
    this->staffID = staffID;
}

Librarian Arbaaz(1000, 1000, "Arbaaz", "MDX University", "AH2010@live.mdx.ac.uk");


// Accessor methods
int Librarian::getStaffID() const {
    return staffID;
}

int Librarian::getSalary() const {
    return salary;
}

// Mutator methods
void Librarian::setStaffID(int staffID) {
    this->staffID = staffID;
}

void Librarian::setSalary(int salary) {
    this->salary = salary;
}

// Other member functions (placeholder implementations)
void Librarian::addMember() {

    std::string newName, newAddress, newEmail;

    std::cout << "Enter Member's Name: ";
    std::cin >> newName;

    std::cout << "Enter Member's Address: ";
    std::cin >> newAddress;

    std::cout << "Enter Member's Email: ";
    std::cin >> newEmail;

    std::cout << "Adding New Member to the System..." << std::endl;
    // Create a new member and add it to the system
    class Member inputMember (newMemberID, newName, newAddress, newEmail);

    Memberlist.push_back(inputMember);
    newMemberID ++;
    std::cout << "New Member Added to the System." << std::endl;

    // Display the details of the newly added member
    displayMemberDetails(inputMember);
}

void Librarian::displayMemberDetails(const Member& member) {
    std::cout << "Member ID: " << member.getMemberID() << std::endl;
    std::cout << "Name: " << member.getName() << std::endl;
    std::cout << "Address: " << member.getAddress() << std::endl;
    std::cout << "Email: " << member.getEmail() << std::endl;
}


void Librarian::issueBook(int memberID, int bookID) {
    // Placeholder implementation
    std::cout << "Issuing book to member " << memberID << " with book ID " << bookID << std::endl;
}

void Librarian::returnBook(int memberID, int bookID) {
    // Placeholder implementation
    std::cout << "Returning book from member " << memberID << " with book ID " << bookID << std::endl;
}

void Librarian::displayBorrowedBooks(int memberID) {
    // Placeholder implementation
    std::cout << "Displaying borrowed books for member " << memberID << std::endl;
}

void Librarian::calcFine(int memberID) {
    // Placeholder implementation
    std::cout << "Calculating fine for member " << memberID << std::endl;
}
