#include "Person.h"

// Default constructor
Person::Person() {
}

// Parameterized constructor
Person::Person(const std::string& name, const std::string& address, const std::string& email)
        : name(name), address(address), email(email) {
}

// Accessor methods
std::string Person::getName() const {
    return name;
}

std::string Person::getAddress() const {
    return address;
}

std::string Person::getEmail() const {
    return email;
}

// Mutator methods
void Person::setName(const std::string& newName) {
    name = newName;
}

void Person::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void Person::setEmail(const std::string& newEmail) {
    email = newEmail;
}
