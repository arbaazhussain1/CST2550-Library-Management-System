// The Library Management System for the Book.h header file.
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <ctime>
#include <vector>



// Forward declaration of the Member class to fix any circular dependancies, causing compiling errors.
class Member;

// Declaration of the Book class, representing a book in the Library Management System.
class Book {
private:
    int bookID; // Unique identifier for the book.
    std::string bookName;   // Name of the book.
    std::string authorFirstName; // Author's first name.
    std::string authorLastName; // Author's last name.
    std::string bookType;  // Type of the book.
    std::time_t dueDate;   // Due date for the book.
    class Member* borrower;  // Pointer to the Member object for who borrowed the book.
    bool isIssued; // Flag indicating whether the book is currently issued to member.


public:
    // Constructor
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName,std::string bookType, bool isIssued);

    // Accessor methods: for Retrieving information.
    int getBookID() const; // Get the book's unique identifier.
    std::string getBookName() const; // Get the name of the book.
    std::string getAuthorFirstName() const; // Get the author's first name.
    std::string getAuthorLastName() const; // Get the author's last name.
    std::string getBookType() const; // Get the type of the book.
    std::time_t getDueDate() const;  // Get the due date for the book.

    // Mutator methods: for to updating information.
    void setDueDate(std::time_t dueDate); // Set a new due date for the book.
    void returnBook();  // Mark the book as returned.
    void borrowBook(Member *borrower, std::time_t dueDate); // Borrow the book by a member.
    bool isBookIssued() const;  // Check if the book is currently issued to member.
    void setBookAsIssued(bool bookIssued); // Set the issuance status of the book.
};
// Function to get a reference to the Book list in the Library Management System.
std::vector<Book>& getBookList();

#endif // BOOK_H
