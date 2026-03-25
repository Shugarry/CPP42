#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"
#include <iostream>

class PhoneBook
{
	private:
		Contact contacts[8];
		int count;

	public:
		PhoneBook(): count(0){};
		~PhoneBook() {};

		int get_count(void);
		void set_count(int count);
		void add(std::string first_name, std::string last_name, \
				std::string nickname, std::string number, std::string secret);
		void print_contacts();
		void print_index(int index);
		int get_len();
};

#endif
