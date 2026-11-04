#include "Point.hpp"

static Fixed	side(Point const p, Point const a, Point const b) {
	return (p.getX() - b.getX()) * (a.getY() - b.getY())
		- (a.getX() - b.getX()) * (p.getY() - b.getY());
}

bool	bsp(Point const a, Point const b, Point const c, Point const p) {
	Fixed	d1 = side(p, a, b);
	Fixed	d2 = side(p, b, c);
	Fixed	d3 = side(p, c, a);
	Fixed	zero(0);

	if (d1 == zero || d2 == zero || d3 == zero)
		return false;

	bool	allPositive = (d1 > zero) && (d2 > zero) && (d3 > zero);
	bool	allNegative = (d1 < zero) && (d2 < zero) && (d3 < zero);
	return allPositive || allNegative;
}
