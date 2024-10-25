/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:21:24 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/18 16:54:02 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main (void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// std::cout << "\n";

	// std::cout << "a is " << a.toFloat() << " as Float" << std::endl;
	// std::cout << "b is " << b.toFloat() << " as Float" << std::endl;
	// std::cout << "c is " << c.toFloat() << " as Float" << std::endl;
	// std::cout << "d is " << d.toFloat() << " as Float" << std::endl;
	return (0);
}

/*WHY ONLY 6 digits? 
*** float type can represent numbers with a precision of about 6–7 significant digits. 
This includes both the digits before and after the decimal point.
1234.4321f ->1234.43f    
***std::cout only displays 6 significant digits of floating-point values 
by default.  */