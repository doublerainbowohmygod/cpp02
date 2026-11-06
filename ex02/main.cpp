#include <iostream>
#include "Fixed.hpp"

int	main( void ) {
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}


// ///// const / not const
// int	main( void ) {
// 	Fixed x(10);
// 	Fixed y(20);
// 	Fixed const	cx(10);
// 	Fixed const	cy(20);

// 	Fixed::min(x,y) = Fixed(5);
// 	std::cout << "x after: :" << x <<std::endl;
// 	std::cout << Fixed::min(cx,cy) <<std::endl;

	
// 	return 0;
// }
