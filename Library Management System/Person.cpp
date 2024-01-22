// The Library Management System for the Person.cpp file.

// This class called Person is the initialiser for the classes within the Library Management System,
// as this class is the Parent class of the following: Member class and Liberian class.

#include "Person.h" // Include the header file of the Person class.

// Accessor methods: for Retrieving information.
std::string Person::getName() const {
    return name; // Return the name of the person.
}

std::string Person::getAddress() const {
    return address; // Return the address of the person.
}

std::string Person::getEmail() const {
    return email; // Return the email address of the person.
}

// Mutator methods: for to updating information.
void Person::setName( std::string newName) {
    this->name = newName;  // Set the name of the person.
}

void Person::setAddress( std::string newAddress) {
    this->address = newAddress; // Set the address of the person.
}

void Person::setEmail( std::string newEmail) {
    this->email = newEmail;  // Set the email address of the person.
}
