#include "Person.h"


//Person::Person(const std::string name, const std::string address, const std::string email)
//        : name(name), address(address), email(email) {
//}

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
void Person::setName( std::string newName) {
    this->name = newName;
}

void Person::setAddress( std::string newAddress) {
    this->address = newAddress;
}

void Person::setEmail( std::string newEmail) {
    this->email = newEmail;
}
