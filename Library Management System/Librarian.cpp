#include "Person.cpp"
#include "Librarian.h"
#include "Member.h"
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

void Librarian::printLibrarianInfo()  {
    std::cout << "Librarian Information:" << std::endl;
    std::cout << "StaffID: " << getStaffID() << std::endl;
    std::cout << "Salary: " << getSalary() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Address: " << getAddress() << std::endl;
    std::cout << "Email: " << getEmail() << std::endl;
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

//    std::string newName, newAddress, newEmail;
//
//    std::cout << "Enter Member's Name: ";
//    std::cin >> newName;
//
//    std::cout << "Enter Member's Address: ";
//    std::cin >> newAddress;
//
//    do {
//    std::cout << "Enter Member's Email:";
//    std::cin >> newEmail;
//        // Define a simple regular expression for email validation
//        std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
//
//        // Check if the entered email matches the regular expression
//        if (std::regex_match(newEmail, emailRegex)) {
//            break; // Exit the loop if the email is valid
//        } else {
//            std::cout << "Invalid Email Format: Please Enter A Valid Email Format.\n";
//        }
//    } while (true);

    std::string newName, newAddress, newEmail;

    // Regex pattern expressions to validate user input
    std::regex nameRegexPattern(R"([a-zA-Z\s]+)"); // A member's name can only be characters and spaces.
    std::regex addressRegexPattern("^[0-9A-Za-z ,.'-]+$"); // A member's address can contain numbers characters and specific symbols.
    std::regex emailRegexPattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)"); // Email pattern

    std::cout << "Enter Member's Name: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, newName);

    // Validate the name using a while loop and Regex
    while (!std::regex_match(newName, nameRegexPattern)) {
        std::cout << "Invalid Name Format: Please Enter a Valid Name.\n";
        std::cout << "Enter Member's Name: ";
        std::getline(std::cin, newName);
    }

    std::cout << "Enter Member's Address: ";
    std::getline(std::cin, newAddress);

    // Validate the address using a while loop and Regex
    while (!std::regex_match(newAddress, addressRegexPattern)) {
        std::cout << "Invalid Address Format: Please Enter a Valid Address.\n";
        std::cout << "Enter Member's Address: ";
        std::getline(std::cin, newAddress);
    }

    // Email validation loop (similar to the original code)
    do {
        std::cout << "Enter Member's Email:";
        std::cin >> newEmail;

        if (std::regex_match(newEmail, emailRegexPattern)) {
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

