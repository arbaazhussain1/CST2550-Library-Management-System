// The Library Management System for the Person.h header file.
#ifndef PERSON_H
#define PERSON_H

#include <string>

// Declaration of the Person class, representing its methods, identifiers & variables within the in the Library Management System.

class Person{
protected:
    std::string name;    // The name of the person.
    std::string address; // The address of the person.
    std::string email;   // The email address of the person.

public:

    // Accessor methods: for Retrieving information.
    std::string getName() const;    // Get the name of the person.
    std::string getAddress() const; // Get the address of the person.
    std::string getEmail() const;   // Get the address of the person.

    // Mutator methods: for to updating information.
    void setName ( std::string name);       // Set the name of the person.
    void setAddress ( std::string address); // Set the address of the person.
    void setEmail ( std::string email);     // Set the email address of the person.

};
#endif // PERSON_H
