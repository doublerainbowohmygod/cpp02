#include "Point.hpp"

Point::Point() : _x(0), _y(0) , _color("pink") {}

Point::Point(float const x, float const y) : _x(x), _y(y), _color("pink") {}

Point::Point(Point const& other) : _x(other._x), _y(other._y), _color(other._color){}

Point& Point::operator=(Point const& other) {
	if(this != &other)
		_color = other._color;
	return *this;
}

Point::~Point() {}

Fixed		Point::getX(void) const {return _x;}

Fixed		Point::getY(void) const {return _y;}

std::string	Point::getColor(void) const {return _color;}

void		Point::setColor(std::string const& color) {
	_color = color;
}

std::ostream& operator<<(std::ostream& out, Point const& p) {
	out << "(" << p.getX() <<", " << p.getY()<< ") "<< p.getColor();
	return out;
}
