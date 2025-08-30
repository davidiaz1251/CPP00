#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {}
PhoneBook::~PhoneBook() {}

static std::string truncate(const std::string &str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::addContact() {
	std::string input;
	Contact c;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	c.setFirstName(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	c.setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	c.setNickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	c.setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty()) return;
	c.setDarkestSecret(input);

	_contacts[_oldestIndex] = c;
	_oldestIndex = (_oldestIndex + 1) % 8;
	if (_contactCount < 8) _contactCount++;
}

void PhoneBook::searchContacts() const {
	std::cout << std::setw(10) << "Index" << "|"
	          << std::setw(10) << "First Name" << "|"
	          << std::setw(10) << "Last Name" << "|"
	          << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _contactCount; i++) {
		std::cout << std::setw(10) << i << "|"
		          << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
		          << std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
		          << std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
	}

	std::cout << "Enter index: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.length() != 1 || input[0] < '0' || input[0] >= ('0' + _contactCount)) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	int i = input[0] - '0';
	std::cout << "First name: " << _contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[i].getDarkestSecret() << std::endl;
}
