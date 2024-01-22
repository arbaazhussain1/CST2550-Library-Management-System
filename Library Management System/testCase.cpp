#define CATCH_CONFIG_MAIN
// Include all the libraries for the code to run.
#include "catch.hpp"
#include "Person.h"
#include "Book.h"
#include "Member.h"
#include "Librarian.h"

// Initialising objects that will be tested using the test cases below.
Librarian librarianSam(1, 300000, "Sam", "London", "sam@email.com");
Librarian librarianJohn(2, 150000, "John", "LA", "john@email.com");
Member member(300, "Joey", "22 Night Road", "Joey@email.com");
Book book(100, "BookName", "AuthorFirstName", "AuthorLastName","Testing", false);
Person person;

// Test case for all accessor functions in the Book class.
TEST_CASE("Book get functionality", "[Book]"){
    REQUIRE(book.getBookID() == 100);
    REQUIRE(book.getBookName() == "BookName");
    REQUIRE(book.getAuthorFirstName() == "AuthorFirstName");
    REQUIRE(book.getAuthorLastName() == "AuthorLastName");
    REQUIRE(book.getBookType() == "Testing");
    REQUIRE(book.isBookIssued() == false);
}

// Test case for all accessor functions in the member class.
TEST_CASE("Member get functionality", "[Member]"){
    REQUIRE(member.getMemberID() == 300);
    REQUIRE(member.getName() == "Joey");
    REQUIRE(member.getAddress() == "22 Night Road");
    REQUIRE(member.getEmail() == "Joey@email.com");

    // Adding wrong test cases as an example.
    REQUIRE_FALSE(member.getName() == "Arbaaz");
    REQUIRE_FALSE(member.getName() == "A");
}

// Test case for all accessor functions in the librarian class.
TEST_CASE("Librarian get functionality", "[Librarian]"){
    // Librarian Sam.
    REQUIRE(librarianSam.getStaffID() == 1);
    REQUIRE(librarianSam.getSalary() == 300000);
    REQUIRE(librarianSam.getName() == "Sam");
    REQUIRE(librarianSam.getAddress() == "London");
    REQUIRE(librarianSam.getEmail() == "sam@email.com");
    // Librarian John.
    REQUIRE(librarianJohn.getStaffID() == 2);
    REQUIRE(librarianJohn.getSalary() == 150000);
    REQUIRE(librarianJohn.getName() == "John");
    REQUIRE(librarianJohn.getAddress() == "LA");
    REQUIRE(librarianJohn.getEmail() == "john@email.com");
}

// Test case for all accessor functions in the librarian class.
TEST_CASE("Person set and get functionality", "[Person]"){
    person.setName("Arbaaz");
    person.setAddress("University");
    person.setEmail("a@uni.com");

    REQUIRE(person.getName() == "Arbaaz");
    REQUIRE(person.getAddress() == "University");
    REQUIRE(person.getEmail() == "a@uni.com");

    // Adding wrong test cases as an example.
    REQUIRE_FALSE(person.getName() == "Adam");
    REQUIRE_FALSE(person.getAddress() == "London");
    REQUIRE_FALSE(person.getEmail() == "adam@email.com");
}

// Test case for adding member objects to memory.
TEST_CASE("Librarian add member tests", "[Librarian]"){
    Member newMember(5, "Star", "Manchester", "star@email.com");
    Member newMember2(6, "Night", "Newcastle", "night@email.com");
    Memberlist().push_back(newMember);
    Memberlist().push_back(newMember2);
    REQUIRE(Memberlist().size() == 2);
    librarianSam.displayMemberDetails(newMember);
    librarianJohn.displayMemberDetails(newMember2);
}