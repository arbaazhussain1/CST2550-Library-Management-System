#include "Person.h"
#include "Person.cpp"
#include "Librarian.h"
#include "Member.h"
#include <fstream>
#include <sstream>
#include <string>
#include <regex>


int newMemberID = 1;

Librarian::Librarian(int staffID, int salary, const std::string name, const std::string address, const std::string email) {
    this->staffID = staffID;
    this->salary = salary;
    this->setName (name);
    this->setAddress(address);
    this->setEmail(email);
}

Librarian Arbaaz(1000, 1000, "Arbaaz", "MDX University", "AH2010@live.mdx.ac.uk");

void printInfo()  {
    std::cout << "Librarian Information:" << std::endl;
    std::cout << "StaffID: " << Arbaaz.getStaffID() << std::endl;
    std::cout << "Salary: " << Arbaaz.getSalary() << std::endl;
    std::cout << "Name: " << Arbaaz.getName() << std::endl;
    std::cout << "Address: " << Arbaaz.getAddress() << std::endl;
    std::cout << "Email: " << Arbaaz.getEmail() << std::endl;
}

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

    do {
    std::cout << "Enter Member's Email:";
    std::cin >> newEmail;
        // Define a simple regular expression for email validation
        std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

        // Check if the entered email matches the regular expression
        if (std::regex_match(newEmail, emailRegex)) {
            break; // Exit the loop if the email is valid
        } else {
            std::cout << "Invalid Email Format: Please Enter A Valid Email Format.\n";
        }
    } while (true);



    std::cout << "Adding New Member to the System...\n" << std::endl;
    // Create a new member and add it to the system
    Member inputMember(newMemberID, newName, newAddress, newEmail);

    Memberlist.push_back(inputMember);
    newMemberID ++;
    std::cout << "New Member Added to the System.\n" << std::endl;

    // Display the details of the newly added member
    displayMemberDetails(inputMember);
}

void Librarian::displayMemberDetails(const Member& member) {
    std::cout << "Member Details:\n";
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

