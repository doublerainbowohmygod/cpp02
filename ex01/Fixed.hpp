#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_value;
	static int const	_fractionalBits =8;

public:
	Fixed();
	Fixed(Fixed const& other);
	Fixed& operator=(Fixed const& other);
	~Fixed();
	Fixed(int const n);
	Fixed(float const f);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& f);

#endif

