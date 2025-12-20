#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iomanip>

class PhoneBook {
	
    private:
		Contact contacts[8];
    
    public:
		PhoneBook();

};

#endif