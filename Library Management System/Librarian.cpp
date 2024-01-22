#include <sstream>
#include <string>
#include <regex>
#include <ctime>
#include <cmath>


#include "Librarian.h"

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

    Memberlist().push_back(inputMember);
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


Member* Librarian::findMemberInSystem(int memberID) {
    std::vector<Member>& members = Memberlist();
    for (Member& member : members) {
        std::cout << "Member ID in vector: " << member.getMemberID() << std::endl;
        if (member.getMemberID() == memberID) {
            return &member;
        }
    }
    return nullptr;
}

Book* Librarian::findBookInSystem(int bookID) {
    std::vector<Book>& books = getBookList();
    for (Book& book : books) {
        std::cout << "Book ID in vector: " << book.getBookID() << std::endl;
        if (book.getBookID() == bookID) {
            return &book;  // Return a dynamically allocated copy of the found book
        }
    }
    return nullptr;
}

void Librarian::issueBook(int memberID, int bookID) {
    std::vector<Book>& books = getBookList();
    std::cout << "Number of books in the system: " << books.size() << std::endl;  // Add this line

    Member* memberBorrowingBook = findMemberInSystem(memberID);
    Book* bookToBorrow = findBookInSystem(bookID);

    if (memberBorrowingBook == nullptr || bookToBorrow == nullptr) {
        std::cout << "Member or book not found. Unable to issue the book." << std::endl;
        return;
    }

    if (bookToBorrow->isBookIssued()) {
        std::cout << "The book with ID " << bookID << " is already issued and cannot be borrowed at the moment." << std::endl;
        return;
    }

    std::cout << "\nMember Name: " << memberBorrowingBook->getName() << std::endl;
    std::cout << "Member ID: " << memberBorrowingBook->getMemberID() << std::endl;
    std::cout << "Book Title: " << bookToBorrow->getBookName() << std::endl;
    std::cout << "Book ID: " << bookToBorrow->getBookID() << std::endl;

    time_t currentTime = time(nullptr);
    std::cout << "The book's issue date is: " << ctime(&currentTime);

    time_t dueDate = currentTime + (3 * 24 * 60 * 60);
    std::cout << "The book's due date is: " << ctime(&dueDate);

    bookToBorrow->setBookAsIssued(true);
    bookToBorrow->borrowBook(memberBorrowingBook, dueDate);
    memberBorrowingBook->setBooksBorrowed(*bookToBorrow);
    std::cout << "Book ID " << bookID << " has been successfully issued to Member ID " << memberID << std::endl;
}


void Librarian::returnBook(int memberID, int bookID) {
    Member* memberReturningBook = findMemberInSystem(memberID); // Find the member from the parameter given when calling the function.
    if (!memberReturningBook) {
        std::cout << "Member with ID " << memberID << " not found." << std::endl;
        return;
    }

    Book* bookBeingReturned = findBookInSystem(bookID); // Find the book from the parameter given when calling the function.
    if (!bookBeingReturned) {
        std::cout << "Book with ID " << bookID << " not found." << std::endl;
        return;
    }

    // Attempt to find the book in the member's list of borrowed books.
    std::vector<Book>& borrowedBooks = memberReturningBook->getBooksBorrowedReference();
    // Use auto to find the book within borrowedBooks. 
    auto bookSearch = std::find_if(borrowedBooks.begin(), borrowedBooks.end(),
        [bookID](const Book& book) {
            return book.getBookID() == bookID;
        }
    );

    // If the book is found in the member's borrowed books.
    if (bookSearch != borrowedBooks.end()) {
        borrowedBooks.erase(bookSearch);// Remove the book from the member's borrowed books.
        calcFine(memberID, bookBeingReturned); // Calculate the fine for the member if the book is past its due date.
        bookBeingReturned->returnBook(); // Return the book.
        bookBeingReturned->setBookAsIssued(false); // set the bookIssued boolean back to false allowing it to be loaned by another member.
    } else {
        std::cout << "Member ID " << memberID << " did not borrow book ID " << bookID << std::endl;
    }
}

void Librarian::displayBorrowedBooks(int memberID) {
    Member* member = Arbaaz.findMemberInSystem(memberID);
    if (member != nullptr) // If member is not equal to nullpointer.
    {
        std::vector<Book> borrowedBooks = member->getBooksBorrowed(); // Create a local vector to store the members books.
        if (borrowedBooks.empty())
        {
            std::cout << "No books currently borrowed by member ID " << memberID << std::endl;
        }
        else
        {
            std::cout << "\nThe books borrowed by:" << std::endl;

            std::cout << "Member Information:\n";
            std::cout << "Member ID: " << member->getMemberID() << std::endl;
            std::cout << "Name: " << member->getName() << std::endl;
            std::cout << "Address: " << member->getAddress() << std::endl;
            std::cout << "Email: " << member->getEmail() << std::endl;
            
            for (Book book : borrowedBooks)
            {
                time_t date = book.getDueDate();
                std::cout << "\nBook ID: " << book.getBookID() << ", "
                          << "Book name: " << book.getBookName() << ", "
                          << "Author full name: " << book.getAuthorFirstName() << " " << book.getAuthorLastName() << ", "
                          << "Due date for book: " << ctime(&date);
            }
        }
    }
    else
    {
        std::cout << "Member with ID " << memberID << " not found." << std::endl;
    }
}

void Librarian::calcFine(int memberID, Book* bookBeingReturned) {
    time_t currentTime = time(nullptr); // The current system time.

    std::cout << "Current time of return: " << ctime(&currentTime) << std::endl;
    if (currentTime > bookBeingReturned->getDueDate()){
        double daysLate = difftime(currentTime, bookBeingReturned->getDueDate()) / (60 * 60 * 24);
        double fine = daysLate * 1;

        std::cout << "The book is " << daysLate << "days late, incuring a fine of " << fine << std::endl;
        std::cout << "Fine due: £" << floor(fine) << std::endl;
        std::cout << "MemberID: " << memberID << "returning: " << bookBeingReturned << std::endl;
    } else {
        std::cout << "You are within the books due date, so you will not incur a fine" << std::endl;
    }
}