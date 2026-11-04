#ifndef	POINT_HPP
#define	POINT_HPP

#include	"Fixed.hpp"
#include	<iostream>
#include	<string>

class Point
{
private:
	Fixed const	_x;
	Fixed const	_y;
	std::string	_color;

public:
	Point();
	Point(float const x, float const y);
	Point(Point const& other);
	Point& operator=(Point const& other);
	~Point();

	Fixed		getX(void) const;
	Fixed 		getY(void) const;
	std::string	getColor(void) const;
	void		setColor(std::string const& color);
};

std::ostream&	operator<<(std::ostream& out, Point const& p);
bool			bsp(Point const a, Point const b, Point const c, Point const point);

#endif
