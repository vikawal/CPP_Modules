/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:51:00 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/08 13:28:13 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	
	for (int i (1); i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
				std::cout << (char)(toupper(argv[i][j]));
		if (i < argc - 1)
			std::cout << " ";

	}
	 std::cout << std::endl;
	 return 0;
	
}