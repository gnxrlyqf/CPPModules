#ifndef _POINT_HPP_
#define _POINT_HPP_

#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
		static Fixed area(const Point a, const Point b, const Point c);
		static bool bsp(const Point a, const Point b, const Point c, const Point point);
};
	
#endif
