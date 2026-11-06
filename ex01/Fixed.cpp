#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(Fixed const& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if( this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const n) : _value(n << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : _value(roundf(f * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits( int const raw ) {
	_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)_value / (1 << _fractionalBits);
}

int		Fixed::toInt( void ) const {
	return _value >> _fractionalBits;
}

std::ostream&	operator<<(std::ostream& out, Fixed const& f) {
	out << f.toFloat();
	return out;
}
