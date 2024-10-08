/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:33:48 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/08 13:38:37 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact
{
	private:
		std::string data[5];

	public:
		Contact(void);
		void	fill_contact_data (int index, std::string input);
		std::string get_contact_data(int index);
};

// class Contact
// {
// 	private:
// 		std::string firstName;
// 		std::string lastName;
// 		std::string nickName;
// 		std::string phoneNumber;
// 		std::string darkestSecret;
// 	public:
// 	void getdata(int index);
// 	void Add();
// 	std::string getFirstName()
// 	{
// 		return (firstName);
// 	}
// 	std::string getLastName()
// 	{
// 		return (lastName);
// 	}
// 	std::string getNickName()
// 	{
// 		return (nickName);
// 	}
// };

#endif