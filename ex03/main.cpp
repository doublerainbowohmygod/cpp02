#include "Point.hpp"
#include <iostream>

static void	test(Point const p) {
	Point const	a(0, 0);
	Point const	b(10, 0);
	Point const	c(0, 10);
	std::cout << p << " -> " << (bsp(a, b, c, p) ? "inside" : "outside") << std::endl;
}

int	main(void) {
	std::cout << "=== BSP, triangle (0,0) (10,0) (0,10) ===" << std::endl;
	test(Point(1, 1));
	test(Point(10, 10));
	test(Point(5, 0));
	test(Point(0, 0));
	test(Point(5, 5));

	std::cout << std::endl << "=== Color & operator= ===" << std::endl;
	Point	p1(1, 2);
	Point	p2(3, 4);
	p1.setColor("red");
	std::cout << "before: p1 = " << p1 << ", p2 = " << p2 << std::endl;
	p2 = p1;
	std::cout << "after:  p1 = " << p1 << ", p2 = " << p2 << std::endl;

	return 0;
}
