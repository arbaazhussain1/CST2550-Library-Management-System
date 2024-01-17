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



//void readFileData(const std::string& filename) {
//    std::ifstream inputFile(filename);
//    if (!inputFile.is_open()) {
//        std::cout << "Error: File '" << filename << "' not found." << std::endl;
//        return;
//    }
//
//    std::string line;
//    while (getline(inputFile, line)) {
//        std::istringstream iss(line);
//        std::string token;
//
//        // Process each token (assuming comma-separated values)
//        while (getline(iss, token, ',')) {
//            // Process each token as needed
//            std::cout << token << " ";
//        }
//
//        std::cout << std::endl;  // Move to the next line for the next record
//    }
//
//    inputFile.close();
//}


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
    std::cin >> option;

    // Validating the input
    while (option != 'n' && option != 'N' && option != 'Y' && option != 'y') {
        std::cout << "ERROR DETECTED! INVALID INPUT WHICH HAS BEEN ENTERED, PLEASE TRY AGAIN.\n";
        std::cout << "Do You Want to Proceed into the system? [Y/N] Y = Yes & N = No: ";
        std::cin >> option;
    }

    // Check if the user chose to proceed
    if (option == 'y' || option == 'Y') {
        // Include the code here if you want it to be part of the program
    } else {
        std::cout << "Exiting the program.\n";
        return 0;  // End the program
    }

//    std::string EnterFile;
//    bool fileOpened = false;
//
//    while (!fileOpened) {
//        std::cout << "Please Enter The File Which Comprises Of The Book Database: \n";
//        std::cin >> EnterFile;
//
//        std::ifstream inputFile(EnterFile);
//
//        if (inputFile.is_open()) {
//            std::cout << "The File " << EnterFile << " is able to read.\n";
//            readFileData(EnterFile);
//            fileOpened = true;
//        } else {
//            std::cout << "The File " << EnterFile << "  is unable to read: Please Try Again.\n";
//        }
//    }


    // Create a Librarian instance
    // Librarian librarianInstance(1000, 1000, "Arbaaz", "MDX University", "AH2010@live.mdx.ac.uk");


    Arbaaz.printInfo();

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
                librarianInstance.addMember();
                break;
            case 2:
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

                librarianInstance.issueBook(memberID, bookID);
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

                librarianInstance.returnBook(memberID, bookID);
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

                librarianInstance.displayBorrowedBooks(memberID);
                break;
            case 5:
//                librarianInstance.exitAndCloseProgram();
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);


            return 0;
}

