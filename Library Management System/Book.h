#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <ctime>  // Include for std::time_t
#include <vector>




class Member;

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    std::time_t dueDate;  // Using std::time_t for due date
    class Member* borrower;     // Pointer to Member object
    bool isIssued;


public:
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName,std::string bookType, bool isIssued);
//    Book newBook(bookID, isIssued, bookName, pageCount, authorFirstName, authorLastName, bookType);
//    std::string bookName, std::string authorFirstName, std::string authorLastName, bool isIssued);

    // Accessor methods
    int getBookID() const;
    std::string getBookName() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    std::string getBookType() const;
    std::time_t getDueDate() const;

    // Mutator methods
    void setDueDate(std::time_t dueDate);
    void returnBook();
    void borrowBook(Member *borrower, std::time_t dueDate);
    bool isBookIssued() const;
    void setBookAsIssued(bool bookIssued);
};

std::vector<Book>& getBookList();

#endif // LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
