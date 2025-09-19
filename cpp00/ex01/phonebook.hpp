/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frey-gal <frey-gal@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:33:42 by frey-gal          #+#    #+#             */
/*   Updated: 2025/09/19 16:35:48 by frey-gal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "contact.hpp"

class Phonebook
{
	public:
		Phonebook();
		Phonebook(const Phonebook &phonebook);
		~Phonebook();
		Phonebook &operator= (const Phonebook &phonebook);
	private:
		Contact contacts[8];
};

#endif
