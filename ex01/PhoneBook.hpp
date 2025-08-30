#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
	Contact _contacts[8];
	int _contactCount;
	int _oldestIndex;

public:
	PhoneBook();
	~PhoneBook();

	void addContact();
	void searchContacts() const;
};

#endif
