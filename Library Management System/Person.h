#ifndef LIBRARY_MANAGEMENT_SYSTEM_PERSON_H
#define LIBRARY_MANAGEMENT_SYSTEM_PERSON_H

#include "string"

class Person{
protected:
    std::string name;
    std::string address;
    std::string email;

public:
    // Constructors
    Person(); // The Default Constructor
    Person(const std::string& name, const std::string& address, const std::string& email );

    // Accessor methods
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;

    // Mutator methods
    void setName (const std::string& name);
    void setAddress (const std::string& address);
    void setEmail (const std::string& email);

};
#endif //LIBRARY_MANAGEMENT_SYSTEM_PERSON_H
