#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Person.h"
#include "Person.cpp"
#include "Librarian.h"
#include "Librarian.cpp"
#include "Member.h"
#include "Member.cpp"
#include "Book.h"
#include "Book.cpp"



void readFileData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: File '" << filename << "' not found." << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        // Process each token (assuming comma-separated values)
        while (getline(iss, token, ',')) {
            // Process each token as needed
            std::cout << token << " ";
        }

        std::cout << std::endl;  // Move to the next line for the next record
    }

    file.close();
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
    std::cin >> option;

    // Validating the input
    while (option != 'n' && option != 'N' && option != 'Y' && option != 'y') {
        std::cout << "ERROR DETECTED! INVALID INPUT WHICH HAS BEEN ENTERED, PLEASE TRY AGAIN.\n";
        std::cout << "Do You Want to Proceed into the system? [Y/N] Y = Yes & N = No: ";
        std::cin >> option;
    }

    // Check if the user chose to proceed
    if (option == 'y' || option == 'Y') {

    }
    std::string EnterFile;
    std::cout << "Please enter the file that contains the book data: \n";
    std::cin >> EnterFile;

    // Open the inputted file
    std::ifstream inputFile(EnterFile);

    // Check to see if the file can be opened
    if (inputFile.is_open()) {
        std::cout << "The file " << EnterFile << " can be read.\n";

        readFileData(EnterFile);

    } else {
        std::cout << "The File " << EnterFile << " cannot be read.\n";
    }

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
    std::cout << "\n";
//    std::cin >> " " ;



    // Create a Librarian instance
    Librarian librarianInstance(1000, 1000, "Arbaaz", "MDX University", "AH2010@live.mdx.ac.uk");

    // Call the addMember function
    librarianInstance.addMember();
    return 0;
}

