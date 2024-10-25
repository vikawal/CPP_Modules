/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:21:24 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/18 15:42:03 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* A fixed-point number is a representation of a real number
using a certain number of bits of a type for the integer part,
and the remaining bits of the type for the fractional part.
The number of bits representing each part is fixed (hence the name, fixed-point).
An integer type is usually used to store fixed-point values. */

int main (void)
{
	Fixed a; //default creating object A, value is 0
	Fixed b(a); // new object B as copy of A (initialization of b via a, copy value)
	Fixed c; // deault creating C value is 0
	
	c = b; //assignment operator copies value of B -> to C
	// C already exists, may have other data inside which will be overwritten
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return (0);
}