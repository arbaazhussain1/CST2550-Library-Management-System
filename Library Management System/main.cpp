#include <iostream>
#include "Person.h"
#include "Person.cpp"
#include "Librarian.h"
#include "Librarian.cpp"
#include "Member.h"
#include "Member.cpp"
#include "Book.h"
#include "Book.cpp"


int main() {
    std::cout << "Hello, World!" << std::endl;

    // Create a Librarian instance
    Librarian librarianInstance(1000, 1000, "Arbaaz", "MDX University", "AH2010@live.mdx.ac.uk");

    // Call the addMember function
    librarianInstance.addMember();
    return 0;
}
