#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
#include <vector>
#include <regex>

#include "Person.h"
#include "Librarian.h"
#include "Member.h"
#include "Book.h"

void readAndPrintBooks() {
    std::string EnterFile;
    std::ifstream inputFile;
    bool fileOpened = false;

    while (!fileOpened) {
        std::cout << "Please Enter The File Which Comprises Of The Book Database: \n";
        std::cin >> EnterFile;

        inputFile.open(EnterFile);

        if (inputFile.is_open()) {
            std::cout << "The File " << EnterFile << " is able to read.\n";
            fileOpened = true;
        } else {
            std::cout << "The File " << EnterFile << " is unable to read. Please Try Again.\n";
        }
        // Clear any remaining characters in the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }

    std::string line = "";
    std::getline(inputFile, line); // Discard the first line (headers)
    line = "";

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

        Book newBook (bookID, bookName, authorFirstName, authorLastName, bookType, isIssued);

        // Use the appropriate vector or container to store books
        getBookList().push_back(newBook);
        // Print the book details
        std::cout << "Read book: BookID: " << bookID << ", Book Name: " << bookName << ", Page Count: " << pageCount
                  << ", Author: " << "First Name: " << authorFirstName << ", Last Name: " << authorLastName
                  << ", Type: " << bookType << std::endl;
    }


    std::cout << "Books added successfully." << std::endl;

    inputFile.clear();
    inputFile.seekg(0, std::ios::beg); // Move back to the beginning of the file

    std::cout << "Printing books:\n";
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string token;

        while (std::getline(iss, token, ',')) {
            std::cout << token << " ";
        }

        std::cout << std::endl;
    }

    inputFile.close();
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

    readAndPrintBooks();
    Arbaaz.printLibrarianInfo();

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
        std::cout << "[5] EXIT AND CLOSE PROGRAM\n";
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

                int memberID, bookID;

                std::cout << "Enter Member ID: ";
                std::cin >> memberID;

                // Clear the input buffer, including the newline character
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter Book ID: ";
                std::cin >> bookID;

                // Call the issueBook function with user inputs
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

