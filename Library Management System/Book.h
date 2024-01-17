#ifndef LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
#define LIBRARY_MANAGEMENT_SYSTEM_BOOK_H

#include <string>
#include <ctime>  // Include for std::time_t
class Member;
class Librarian;

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    std::time_t dueDate;  // Using std::time_t for due date
    Member* borrower;     // Pointer to Member object

public:
    Book(int bookID, const std::string bookName, const std::string authorFirstName, const std::string authorLastName);

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
    void borrowBook(Member* borrower, std::time_t dueDate);
};

#endif // LIBRARY_MANAGEMENT_SYSTEM_BOOK_H
