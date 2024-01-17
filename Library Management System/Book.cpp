#include "Book.h"
#include "Member.h"


// Constructor
Book::Book(int bookID, const std::string& bookName, const std::string& authorFirstName, const std::string& authorLastName)
        : bookID(bookID), bookName(bookName), authorFirstName(authorFirstName), authorLastName(authorLastName), dueDate(0), borrower(nullptr) {}

// Accessor methods
int Book::getBookID() const {
    return bookID;
}

std::string Book::getBookName() const {
    return bookName;
}

std::string Book::getAuthorFirstName() const {
    return authorFirstName;
}

std::string Book::getAuthorLastName() const {
    return authorLastName;
}

std::string Book::getBookType() const {
    return bookType;
}

std::time_t Book::getDueDate() const {
    return dueDate;
}

// Mutator methods
void Book::setDueDate(std::time_t dueDate) {
    this->dueDate = dueDate;
}

void Book::returnBook() {
    borrower = nullptr;
    dueDate = 0;
}

void Book::borrowBook(Member* borrower, std::time_t dueDate) {
    this->borrower = borrower;
    this->dueDate = dueDate;
}
