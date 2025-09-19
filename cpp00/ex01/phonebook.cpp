/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <frey-gal@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:27:45 by frey-gal          #+#    #+#             */
/*   Updated: 2025/09/19 16:04:51 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}

Phonebook& Phonebook::operator= (const Phonebook &phonebook)
{
	for (int i = 0; i < 8; i++)
		this->contacts[i] = phonebook.contacts[i];
	return *this;
}

int main()
{
}
