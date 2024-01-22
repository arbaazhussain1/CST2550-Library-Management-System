// The Library Management System for the Book.cpp file.
#include "Book.h"


// Constructor
Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName,std::string bookType, bool isIssued) {
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
    this->bookType = bookType;
    this->isIssued = isIssued;
}

// Accessor methods: for Retrieving information.
int Book::getBookID() const {
    return bookID;  // Return the book's unique identifier.
}

std::string Book::getBookName() const {
    return bookName;  // Return the name of the book.
}

std::string Book::getAuthorFirstName() const {
    return authorFirstName; // Return the author's first name.
}

std::string Book::getAuthorLastName() const {
    return authorLastName; // Return the author's last name.
}

std::string Book::getBookType() const {
    return bookType;  // Return the type of the book.
}

std::time_t Book::getDueDate() const {
    return dueDate; // Return the due date for the book.
}

bool Book::isBookIssued() const {
    return isIssued;  // Check if the book is currently issued.
}
// Mutator methods: for to updating information.
void Book::setDueDate(std::time_t dueDate) {
    this->dueDate = dueDate; // Set a new due date for the book.
}

void Book::setBookAsIssued(bool bookIssued) {
    isIssued = bookIssued; // Set the issuance status of the book.
}

void Book::returnBook() {
    borrower = nullptr; // Clear the borrower information.
    dueDate = 0; // Reset the due date.
}

void Book::borrowBook(Member* borrower, std::time_t dueDate) {
    this->borrower = borrower; // Set the borrower information.
    this->dueDate = dueDate;  // Set the due date.
}
// Function to get a reference to the Book list in the Library Management System.
std::vector<Book> &getBookList(){
    // Static vector to persist the list of books across function calls.
    static std::vector<Book> bookList;
    return bookList;
}
