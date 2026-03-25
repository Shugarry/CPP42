#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	secret;
		std::string	number;

	public:
		Contact() {};
		~Contact() {};

		void		set_first_name(std::string s);
		void		set_last_name(std::string s);
		void		set_nickname(std::string s);
		void		set_secret(std::string s);
		void		set_number(std::string s);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_number(void) const;
		std::string	get_secret(void) const;

		Contact		contact_copy(void) const;
};

# endif
