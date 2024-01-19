#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Person.h"
#include "Librarian.h"
#include "Librarian.cpp"
#include "Member.h"
#include "Member.cpp"
#include "Book.h"
#include "Book.cpp"
#include <limits>
#include <cctype>

#include <sstream>
#include <vector>
#include <regex>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


struct Books {
    int bookID;
    bool isIssued;
    std::string bookName;
    std::string pageCount;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
};

void readAndProcessBooks(const std::string& filename, std::vector<Books>& books) {
    std::string fileName;
    std::ifstream inputFile;

    std::cout << "\nPlease enter the book data filename for the library management system (e.g. librarybooks.csv)"
              << std::endl;
    std::getline(std::cin, fileName);

    // A validation check using a while loop, guard statement.
    while (fileName.size() <= 4 || fileName.substr(fileName.size() - 4) != ".csv") {
        std::cout << "Invalid file extension. Please ensure the file is a .csv file." << std::endl;
        std::cout << "Please enter the book data filename for the library management system (e.g. librarybooks.csv): ";
        std::getline(std::cin, fileName);
    }
    inputFile.open(fileName); // Attempt to open the filename provided.

    // A validation check using a while loop, guard statement.
    while (!inputFile.is_open()) {
        std::cout << "Failed to open file: " << fileName << std::endl;
        std::cout << "Please check if the file exists in the current directory." << std::endl;
        std::cout << "Please enter the book data filename for the library management system (e.g. librarybooks.csv): ";
        std::getline(std::cin, fileName);
        inputFile.open(fileName);
    }

    std::cout << "Attempting to open file: " << fileName << std::endl;
    inputFile.open(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return; // Exit the function or handle the error appropriately
    }

    std::cout << "File opened successfully." << std::endl;

    std::string line = "";
    std::getline(inputFile, line); // Debug: Print the first line from the document, the cell headings.
    std::cout << "First Line: " << line << std::endl;
    line = "";                     // Debug: Discard the first headings line, as we only want to add books to the book vector.

    while (std::getline(inputFile, line)) {
        int bookID;
        bool isIssued = false;
        std::string bookName;
        std::string pageCount;
        std::string authorFirstName;
        std::string authorLastName;
        std::string bookType;
        std::string temporaryString;

        std::stringstream inputString(line);

        getline(inputString, temporaryString, ',');
        bookID = std::atoi(temporaryString.c_str());
        getline(inputString, bookName, ',');
        getline(inputString, pageCount, ',');
        getline(inputString, authorFirstName, ',');
        getline(inputString, authorLastName, ',');
        getline(inputString, bookType, ',');

        Books newBook{bookID, isIssued, bookName, pageCount, authorFirstName, authorLastName, bookType};
        books.push_back(newBook);

        // Debug: Print the book details
        std::cout << "Read book: " << bookID << ", " << bookName << ", " << authorFirstName << " " << authorLastName
                  << std::endl;
    }

    std::cout << "Books added successfully." << std::endl;
}

void printBooks(const std::vector<Books>& books) {
    for (const auto& book : books) {
        std::cout << "Book ID: " << book.bookID << ", "
                  << "Book Name: " << book.bookName << ", "
                  << "Author: " << book.authorFirstName << " " << book.authorLastName << ", "
                  << "Issued: " << book.isIssued << std::endl;
    }
}



int main() {

    // Printing The Welcome Message to the LIBRARY MANAGEMENT SYSTEM
    std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "\t------\t WELCOME TO THE LIBRARY MANAGEMENT SYSTEM CREATED BY ARBAAZ HUSSAIN\t------\n";
    std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "\n";

    // Prompting user to proceed further
    std::cout << "[NOTE]: To Progress Further Into The Program As User Librarian\n\n";
    std::cout << "Do You Want to Proceed into the system? [Y/N] Y = Yes & N = No: ";
    char option;
    std::cin >> option; // Read only the first character

    // Validating the input
    while (!(std::cin.peek() == '\n' && (std::toupper(option) == 'N' || std::toupper(option) == 'Y'))) {
        std::cout << "ERROR DETECTED! INVALID INPUT WHICH HAS BEEN ENTERED, PLEASE TRY AGAIN.\n";
        std::cout << "Do You Want to Proceed into the system? [Y/N] Y = Yes & N = No: ";
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cin >> option; // Read only the first character
    }

    // Check if the user chose to proceed
    if (std::toupper(option == 'y' || option == 'Y') ) {
        std::cout << "Proceeding into the system...\n";

    } else {
        std::cout << "Exiting the program.\n";
        return 0;  // End the program
    }

    std::vector<Books> books;  // Declare the vector to store Books
    readAndProcessBooks("library_books.csv", books);
    printBooks(books);


    Arbaaz.printLibrarianInfo();

    int memberID;
    int bookID;
    int choice;

    do {
        // Main menu
        std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
        std::cout << "\t\t\t\t\t------ LIBRARY MANAGEMENT SYSTEM PORTAL MENU------\n";
        std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
        std::cout << "\n";
        std::cout << "[1] ADD MEMBER\n";
        std::cout << "\n";
        std::cout << "[2] ISSUE BOOK\n";
        std::cout << "\n";
        std::cout << "[3] Return BOOK\n";
        std::cout << "\n";
        std::cout << "[4] DISPLAY BORROWED BOOKS\n";
        std::cout << "\n";
        std::cout << "[5] EXIT NAD CLOSE PROGRAM\n";
        std::cout << "\n";

        std::cout << "ENTER YOUR CHOICE HERE: ";
        std::cin >> choice;

        // Validate input for choice
        while (std::cin.fail() || choice < 1 || choice > 5) {
            std::cout << "Invalid input. Please enter a number between 1 and 5.\n";
            std::cin.clear(); // clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
            std::cout << "ENTER YOUR CHOICE HERE: ";
            std::cin >> choice;
        }

        switch (choice) {
            case 1:
                Arbaaz.addMember();
                break;
            case 2:
//                // Validate input for memberID and bookID
//                std::cout << "Enter Member ID: ";
//                std::cin >> memberID;
//                std::cout << "Enter Book ID: ";
//                std::cin >> bookID;
//
//                while (std::cin.fail() || memberID < 0 || bookID < 0) {
//                    std::cout << "Invalid input. Please enter non-negative integers for Member ID and Book ID.\n";
//                    std::cin.clear();
//                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//                    std::cout << "Enter Member ID: ";
//                    std::cin >> memberID;
//                    std::cout << "Enter Book ID: ";
//                    std::cin >> bookID;
//                }

                Arbaaz.issueBook(memberID, bookID);
                break;
            case 3:
                // Validate input for memberID and bookID
                std::cout << "Enter Member ID: ";
                std::cin >> memberID;
                std::cout << "Enter Book ID: ";
                std::cin >> bookID;

                while (std::cin.fail() || memberID < 0 || bookID < 0) {
                    std::cout << "Invalid input. Please enter non-negative integers for Member ID and Book ID.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Enter Member ID: ";
                    std::cin >> memberID;
                    std::cout << "Enter Book ID: ";
                    std::cin >> bookID;
                }

                Arbaaz.returnBook(memberID, bookID);
                break;
            case 4:
                // Validate input for memberID
                std::cout << "Enter Member ID: ";
                std::cin >> memberID;

                while (std::cin.fail() || memberID < 0) {
                    std::cout << "Invalid input. Please enter a non-negative integer for Member ID.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Enter Member ID: ";
                    std::cin >> memberID;
                }

                Arbaaz.displayBorrowedBooks(memberID);
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);


            return 0;
}

