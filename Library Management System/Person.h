#ifndef LIBRARY_MANAGEMENT_SYSTEM_PERSON_H
#define LIBRARY_MANAGEMENT_SYSTEM_PERSON_H

#include <string>

class Person{
protected:
    std::string name;
    std::string address;
    std::string email;

public:

    // Accessor methods
    std::string getName() const;
    std::string getAddress() const;
    std::string getEmail() const;

    // Mutator methods
    void setName ( std::string name);
    void setAddress ( std::string address);
    void setEmail ( std::string email);

};
#endif //LIBRARY_MANAGEMENT_SYSTEM_PERSON_H
