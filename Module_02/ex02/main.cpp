/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:21:24 by vmyshko           #+#    #+#             */
/*   Updated: 2024/10/22 16:30:02 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main (void)
{
Fixed		a; // it is 0 -> 0/256 = 0.0
Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
/*Fixed(5.05f): The float constructor multiplies 5.05 by 256 
(the internal fixed-point scaling factor), 
RESULT: _value = roundf(5.05 * 256) = 1293 
Fixed(2): The integer constructor shifts 2 left by 8 bits (2 << 8), 
RESULT in _value = 2 * 256 = 512

Fixed(5.05f) * Fixed(2) = 5.05 * 2 = 10.1
10.1 -> _value = roundof (10.1 * 256) -> 2586
*/


std::cout << a << std::endl; //0 -> 0/256 = 0.0
std::cout << ++a << std::endl; // 1/256 = 0.00390625.
std::cout << a << std::endl; //_value = 0.00390625.
std::cout << a++ << std::endl; //old value before incr = 0.00390625.
std::cout << a << std::endl; //incremented value 2/256 = 0.0078125

std::cout << b << std::endl; //2586/256 (toFloat) -> 10,1015625

std::cout << Fixed::max( a, b ) << std::endl;
/*
a = 0.0078125
b = 10,1015625 */

return 0;
}

// int main(void)
// {
// 	Fixed c(10); // c = 10 << 8 = 2560
// 	Fixed d(5); // d = 5 << 8 = 1280

// 	std::cout << "----------- BASIC OPERATIONS ---------" << std::endl;
// 	std::cout << "TRUE: " << (c > d) << std::endl; //output: 1
// 	std::cout << "FALSE: " << (c < d) << std::endl; //output: 0

// 	std::cout << c + d << std::endl;
// 	std::cout << c - d << std::endl;
// 	std::cout << c * d << std::endl;
// 	std::cout << c / d << std::endl;

// 	Fixed a;
// 	Fixed const b(Fixed(5.05f) * Fixed(2));

// 	std::cout << "----------- OPERATOR OVERLOAD ---------" << std::endl;

// 	std::cout << "1. = ";
// 	std::cout << a << std::endl; //is zero in constructor
// 	std::cout << "2. = ";
// 	std::cout << ++a << std::endl;// +1, so 0->1 (1/256 = 0.00390625)
// 	std::cout << "3. = ";
// 	std::cout << a << std::endl; //float (a = 1, so 1/256 = 0.00390625)
// 	std::cout << "4. = ";
// 	std::cout << a++ << std::endl; //value is old (same and after incremented 1->2)
// 	std::cout << "5. = ";
// 	std::cout << a << std::endl; //new a = 2-> 2/256 = 0.0078125
// 	std::cout << "6. = ";
// 	std::cout << b << std::endl; 
// 	//Fixed(5.05f) = 5.05 * 256 = 1292.8 -> 1293
// 	// Fixed(2) = 2 << 8 = 2*256 = 512.
// 	// b = 1293 * 512 = 662016
// 	// back to float: 62016 / 256 / 256 = 10.1015625
// 	std::cout << "MAX: " << Fixed::max( a, b ) << std::endl;
// 	// a was last time 2/256 = 0.0078125, so b(10.1015625) is bigger
// 	std::cout << "MIN: " << Fixed::min( a, b ) << std::endl;
// 	std::cout << --a << std::endl; // a is 2, -> 2-1 = 1 -> 1/256 = 0.00390625
// 	std::cout << a-- << std::endl; // before decrementing value is printed and then a=1 - >a=0
// 	std::cout << a << std::endl; //printing new value after 1->0 (0.0)

// 	return (0);
// }


// int main(void)
// {
//     Fixed a;                      // Default constructor (0)
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );  // Float constructor, b = 10.1
//     Fixed c(7);                   // Int constructor, c = 7 (7 *256 = 1792)

//     std::cout << "----------- MODIFIABLE MIN/MAX -----------" << std::endl;

//     // Using non-const (modifiable) min/max
//     Fixed& smaller = Fixed::min(a, c);   // Compare a (0) and c (7), should return a (0)
//     std::cout << "Smaller (before modification): " << smaller << std::endl;

//     smaller.setRawBits(50);   // Modify the smaller value (this will modify `a` because it's returned by reference)
//     std::cout << "Smaller (after modification): " << smaller << std::endl; // 50/256 = 0.1953125
//     std::cout << "Value of a (after modification): " << a << std::endl;  // `a` was modified!

//     Fixed& larger = Fixed::max(a, c);    // Compare modified a (50) and c (7), should return a (50)
//     std::cout << "Larger: " << larger << std::endl;

//     std::cout << "----------- NON-MODIFIABLE MIN/MAX -----------" << std::endl;

//     // Using const (non-modifiable) min/max
//     const Fixed& constSmaller = Fixed::min(b, c);  // Compare b (10.1) and c (7), should return c (7)
//     std::cout << "Smaller (const): " << constSmaller << std::endl;

//     // Trying to modify the result -> compilation error
//     // constSmaller.setRawBits(100);

//     const Fixed& constLarger = Fixed::max(b, c);  // Compare b (10.1) and c (7), should return b (10.1)
//     std::cout << "Larger (const): " << constLarger << std::endl;

//     return 0;
// }
